import ctypes
import sys
import numpy

from . import structs


errors = {
    0: "No error",
    1: "Null pointer",
    2: "Zero length passed",
    3: "Addition or multiply overflows",
    4: "Index is out of bound",
    5: "Error reading stdin",
    6: "Error opening file",
    7: "Error requesting stdin",
    8: "Error writting file",
    9: "Error allocating memory (Malloc)",
    10: "Error copying data between buffers",
    11: "Error seeking file",
    12: "Subtraction underflows"
}

class OPErrorFromC(Exception):
    def __init__(self, code):
        self.message = errors.get(code, "Unknown error")        
        super().__init__(self.message)

lib = None

if sys.platform == "win32":
    lib = ctypes.cdll.LoadLibrary(r".\opcodes16_connector\opcodes16.dll")    
elif sys.platform == "linux":
    lib = ctypes.cdll.LoadLibrary("./opcodes16_connector/lib/opcodes16.so")
else:
    raise OSError("Your OS is not supported")

"""
------------------------------------
            context.c
-----------------------------------    
"""

lib.op_context_init_blank.argtypes = [
    ctypes.POINTER(structs.Context),
    ctypes.POINTER(structs.EnrichedInstructionConfig)
]

lib.op_context_init_blank.restype = ctypes.c_int

def context_init_blank(cfg):
    ctx = structs.Context()

    response = lib.op_context_init_blank(ctypes.byref(ctx), ctypes.byref(cfg))

    if response != 0:
        raise OPErrorFromC(response)

    return ctx

lib.op_context_step.argtypes = [
    ctypes.POINTER(structs.Context),
]

lib.op_context_step.restype = ctypes.c_int

def context_step(ctx):
    response = lib.op_context_step(ctypes.byref(ctx))

    if response != 0:
        raise OPErrorFromC(response)

    return response

lib.op_context_run.argtypes = [
    ctypes.POINTER(structs.Context),
]

lib.op_context_run.restype = ctypes.c_int

def context_run(ctx):
    response = lib.op_context_run(ctypes.byref(ctx))

    if response != 0:
        raise OPErrorFromC(response)

    return response

lib.op_context_reset.argtypes = [
    ctypes.POINTER(structs.Context),
]

lib.op_context_reset.restype = ctypes.c_int

def context_reset(ctx):
    response = lib.op_context_reset(ctypes.byref(ctx))

    if response != 0:
        raise OPErrorFromC(response)

    return response

"""
------------------------------------
            decode.c
-----------------------------------    
"""


lib.op_decode_instruction.argtypes = [
    ctypes.c_uint16,
    ctypes.POINTER(structs.InstructionResult)
]

lib.op_decode_instruction.restype = ctypes.c_int

def decode_instruction(instruction):
    ins_res = structs.InstructionResult()
    
    response = lib.op_decode_instruction(instruction, ctypes.byref(ins_res))

    if response != 0:
        raise OPErrorFromC(response)

    return ins_res

lib.op_enrich_decode_result.argtypes = [
    ctypes.POINTER(structs.EnrichedInstruction),
    ctypes.POINTER(structs.InstructionResult),
    ctypes.c_uint16,
    ctypes.c_uint8,
]

lib.op_enrich_decode_result.restype = ctypes.c_int

def enrich_result(decoded, address=0, bank=0):
    enriched = structs.EnrichedInstruction()
    
    response = lib.op_enrich_decode_result(ctypes.byref(enriched), ctypes.byref(decoded), address, bank)

    if response != 0:
        raise OPErrorFromC(response)

    return enriched

"""
------------------------------------
            callbacks.c
-----------------------------------    
"""

lib.op_context_fetch_bank.argtypes = [
    ctypes.POINTER(structs.Context),
    ctypes.POINTER(ctypes.c_uint8),
]

lib.op_context_fetch_bank.restype = ctypes.c_int

def context_fetch_bank(ctx):
    bank = ctypes.c_uint8
    
    response = lib.op_context_fetch_bank(ctypes.byref(ctx), ctypes.byref(bank))

    if response != 0:
        raise OPErrorFromC(response)

    return bank.value

lib.op_context_fetch_memory.argtypes = [
    ctypes.POINTER(structs.Context),
    ctypes.c_uint8,
    ctypes.c_uint8,
    ctypes.POINTER(ctypes.c_uint16),
]

lib.op_context_fetch_memory.restype = ctypes.c_int

def context_fetch_memory(ctx, bank, address):
    value = ctypes.c_uint8
    
    response = lib.op_context_fetch_memory(ctypes.byref(ctx), bank, address,  ctypes.byref(value))

    if response != 0:
        raise OPErrorFromC(response)

    return value.value

lib.op_context_store_memory.argtypes = [
    ctypes.POINTER(structs.Context),
    ctypes.c_uint8,
    ctypes.c_uint8,
    ctypes.c_uint8,
]

lib.op_context_store_memory.restype = ctypes.c_int

def context_store_memory(ctx, bank, address, value):
    response = lib.op_context_store_memory(ctypes.byref(ctx), bank, address, value)

    if response != 0:
        raise OPErrorFromC(response)

    return response

lib.op_context_conditional_d_store.argtypes = [
    ctypes.POINTER(structs.Context),
    ctypes.c_bool,
    ctypes.c_uint8,
    ctypes.c_uint8,
    ctypes.c_uint8,
]

lib.op_context_conditional_d_store.restype = ctypes.c_int

def context_conditional_d_store(ctx, d, value, bank, address):
    response = lib.op_context_conditional_d_store(ctypes.byref(ctx), d, value, bank, address)

    if response != 0:
        raise OPErrorFromC(response)

    return response

"""
------------------------------------
            checked_math.c
-----------------------------------    
"""

lib.op_checked_size_add.argtypes = [
    ctypes.c_size_t,
    ctypes.c_size_t,
    ctypes.POINTER(ctypes.c_size_t),
]

lib.op_checked_size_add.restype = ctypes.c_int

def checked_size_add(a, b):
    c = ctypes.c_size_t(0)
    
    response = lib.op_checked_size_add(a, b, ctypes.byref(c))

    if response != 0:
        raise OPErrorFromC(response)

    return c.value

lib.op_checked_size_sub.argtypes = [
    ctypes.c_size_t,
    ctypes.c_size_t,
    ctypes.POINTER(ctypes.c_size_t),
]

lib.op_checked_size_sub.restype = ctypes.c_int

def checked_size_sub(a, b):
    c = ctypes.c_size_t(0)
    
    response = lib.op_checked_size_sub(a, b, ctypes.byref(c))

    if response != 0:
        raise OPErrorFromC(response)

    return c.value

lib.op_checked_size_mul.argtypes = [
    ctypes.c_size_t,
    ctypes.c_size_t,
    ctypes.POINTER(ctypes.c_size_t),
]

lib.op_checked_size_mul.restype = ctypes.c_int

def checked_size_mul(a, b):
    c = ctypes.c_size_t(0)
    
    response = lib.op_checked_size_mul(a, b, ctypes.byref(c))

    if response != 0:
        raise OPErrorFromC(response)

    return c.value

"""
------------------------------------
            repl.c
-----------------------------------    
"""

lib.op_context_replace_instruction_memory.argtypes = [
    ctypes.POINTER(structs.Context),
    ctypes.POINTER(ctypes.c_uint16),
    ctypes.c_size_t,
    ctypes.c_size_t,
]

lib.op_context_replace_instruction_memory.restype = ctypes.c_int

def context_replace_instruction_memory(ctx, data, address=0):
    length = len(data)
    data_c = data.ctypes.data_as(ctypes.POINTER(ctypes.c_uint16))
    
    response = lib.op_context_replace_instruction_memory(ctypes.byref(ctx), data_c, length, address)

    if response != 0:
        raise OPErrorFromC(response)

    return response

