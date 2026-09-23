import opcodes16_connector
import ctypes
import numpy

res = opcodes16_connector.InstructionResult()
errorcode = opcodes16_connector.lib.op_decode_instruction(0x0FD5, ctypes.byref(res))
print(res.instruction.contents.name)
print(errorcode)

decoded = opcodes16_connector.decode_instruction(0x0FD5)
print(decoded)

c = opcodes16_connector.checked_size_mul(2**64 - 2, 1)
print(c)

ctx = opcodes16_connector.Context()

data = numpy.linspace(0, 0x7FF, 0x800, dtype=numpy.uint16)

res = opcodes16_connector.context_replace_instruction_memory(ctx, data, 0x400)
print(res)

res = opcodes16_connector.context_replace_instruction_memory(ctx, data, 0x1000)
print(res)
