import ctypes

OP_INSTRUCTION_REGISTER_COUNT = 2

class Register(ctypes.Structure):
    _fields_ = [
        ("isActive",         ctypes.c_bool),
        ("mask",             ctypes.c_uint16),
        ("shift",            ctypes.c_uint8),
        ("register",         ctypes.c_int),
        ("display",         ctypes.c_int),
    ]

class Instruction(ctypes.Structure):
    _fields_ = [
        ("name",             ctypes.c_char_p),
        ("description",      ctypes.c_char_p),
        ("cycles",           ctypes.c_uint8),
        ("status_affected",  ctypes.c_uint16),
        ("mask",             ctypes.c_uint16),
        ("shift",            ctypes.c_uint8),
        ("opcode",           ctypes.c_uint16),
        ("instruction_type", ctypes.c_int),
        ("register",         Register * OP_INSTRUCTION_REGISTER_COUNT),
        ("callback",         ctypes.c_void_p),
    ]
    
class RegisterResult(ctypes.Structure):
    _fields_ = [
        ("register",        ctypes.c_int),
        ("value",           ctypes.c_uint16),
        ("active",          ctypes.c_bool),
    ]
    
class InstructionResult(ctypes.Structure):
    _fields_ = [
        ("value",           ctypes.c_uint16),
        ("instruction",     ctypes.POINTER(Instruction)),
        ("unknown",         ctypes.c_bool),
        ("registers",       RegisterResult * OP_INSTRUCTION_REGISTER_COUNT),
    ]

class RegisterBit(ctypes.Structure):
    _fields_ = [
        ("isActive",         ctypes.c_bool),
        ("name",             ctypes.c_char_p),
    ]
    
class RegisterFileMap(ctypes.Structure):
    _fields_ = [
        ("reserved",         ctypes.c_bool),
        ("name",             ctypes.c_char_p),
        ("bits",             RegisterBit * 8),
    ]
    
class EnrichedRegisterConfig(ctypes.Structure):
    _fields_ = [
        ("showRegname",       ctypes.c_bool),
        ("showValue",         ctypes.c_bool),
        ("showName",          ctypes.c_bool),
    ]

class EnrichedInstructionConfig(ctypes.Structure):
    _fields_ = [
        ("showAddress",       ctypes.c_bool),
        ("showName",          ctypes.c_bool),
        ("showValue",         ctypes.c_bool),
        ("showFlagname",      ctypes.c_bool),
        ("F",                 EnrichedRegisterConfig),
        ("W",                 EnrichedRegisterConfig),
        ("K",                 EnrichedRegisterConfig),
        ("B",                 EnrichedRegisterConfig),
        ("D",                 EnrichedRegisterConfig),
    ]

class EnrichedRegister(ctypes.Structure):
    _fields_ = [
        ("active",           ctypes.c_bool),
        ("value",            ctypes.c_uint16),
        ("name",             ctypes.c_char_p),
        ("display",          ctypes.c_int),
    ]

class EnrichedInstruction(ctypes.Structure):
    _fields_ = [
        ("address",          ctypes.c_uint16),
        ("value",            ctypes.c_uint16),
        ("name",             ctypes.c_char_p),
        ("description",      ctypes.c_char_p),
        ("F",                EnrichedRegister),
        ("W",                EnrichedRegister),
        ("K",                EnrichedRegister),
        ("D",                EnrichedRegister),
        ("B",                EnrichedRegister),
        ("flag_name",        ctypes.c_char_p),
    ]

OP_BANK_COUNT = 4
OP_BANK_SIZE  = 128
OP_INSTRUCTION_MEMORY_SIZE = 4096
OP_STACK_SIZE = 8

class Context(ctypes.Structure):
    _fields_ = [
        ("vtable",       ctypes.c_void_p),
        ("memory",       (ctypes.c_uint8 * OP_BANK_SIZE) * OP_BANK_COUNT),
        ("instruction_memory", ctypes.c_uint16 * OP_INSTRUCTION_MEMORY_SIZE),
        ("pc",           ctypes.c_uint16),
        ("cycle_count",  ctypes.c_size_t),
        ("stack",        ctypes.c_uint16 * OP_STACK_SIZE),
        ("sp",           ctypes.c_uint16),
        ("w",            ctypes.c_uint16),
        ("f",            ctypes.c_uint16),
        ("wait_cycles",  ctypes.c_size_t),
        ("config",       EnrichedInstructionConfig),
        ("lastInstruction", EnrichedInstruction),
        ("callback",     ctypes.c_void_p),
        ("external_data", ctypes.c_void_p),
    ]
    
class VariableSupervisor(ctypes.Structure):
    _fields_ = [
        ("active",       ctypes.c_bool),
        ("bank",         ctypes.c_uint8),
        ("address",      ctypes.c_uint8),
    ]

OP_MAX_VARIABLE_COUNT = 16
OP_MAX_ARGV_COUNT = 8

class ToolConfig(ctypes.Structure):
    _fields_ = [
        ("print",        ctypes.c_bool),
        ("print_w",      ctypes.c_bool),
        ("variables",    VariableSupervisor * OP_MAX_VARIABLE_COUNT),
    ]
    
class CommandArgument(ctypes.Structure):
    _fields_ = [
        ("print",        ctypes.c_bool),
        ("argc",         ctypes.c_size_t),
        ("argv",         ctypes.c_uint32 * OP_MAX_ARGV_COUNT),
    ]
