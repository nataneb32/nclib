from ctypes import pointer
from csnake import CodeWriter, Function, Struct, Variable, FormattedLiteral
import numpy as np

def vector(cw: CodeWriter, typ: str):
    vectorT = Struct(f'vector_{typ}_t', True)
    vectorT.add_variable(Variable('len', 'uint32_t'))
    vectorT.add_variable(Variable('size', 'uint32_t'))
    vectorT.add_variable(Variable('data[]', typ))

    vectorNewT = Function(f'*vector_{typ}_new', vectorT.name)
    vectorNewT.add_argument(Variable('size', 'uint32_t'))
    vectorNewT.add_code([
        f'vector_{typ}_t *v = (vector_{typ}_t *)malloc(sizeof(vector_{typ}_t) + sizeof({typ}) * size);',
        'v->len = 0;',
        'v->size = size;',
        'return v;'
    ])

    vectorPushT = Function(f'vector_{typ}_push', 'void')
    vectorPushT.add_argument(Variable('*v', f'vector_{typ}_t'))
    vectorPushT.add_argument(Variable('x', typ))
    vectorPushT.add_code([
        'if (v->len + 1 > v->size) {',
        f'    v->size *= 2;',
        f'    v = (vector_{typ}_t *)realloc(v, sizeof(vector_{typ}_t) + sizeof({typ}) * v->size);',
        '}',
        'v->data[v->len++] = x;'
    ])

    vectorPopT = Function(f'vector_{typ}_pop', typ)
    vectorPopT.add_argument(Variable('*v', f'vector_{typ}_t'))
    vectorPopT.add_code([
        'return v->data[--v->len];'
    ])

    cw.add_struct(vectorT)
    cw.add_line('')
    cw.add_function_definition(vectorNewT)
    cw.add_line('')
    cw.add_function_definition(vectorPushT)
    cw.add_line('')
    cw.add_function_definition(vectorPopT)
    cw.add_line('')

cw = CodeWriter()
cw.start_if_def('VECTOR_H', True)
cw.add_define('VECTOR_H')
cw.include("stdlib.h")
cw.include("stddef.h")
cw.include("stdint.h")
types = ['float', 'double', 'int', 'uint32_t', 'uint64_t', 'char']

for typ in types:
    vector(cw, typ)

cw.end_if_def()
print(cw)
