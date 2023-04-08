#ifndef VECTOR_H
#define VECTOR_H
#include "stdlib.h"
#include "stddef.h"
#include "stdint.h"
typedef struct
{
    uint32_t len;
    uint32_t size;
    float data[];
} vector_float_t;

vector_float_t *vector_float_new(uint32_t size)
{
    vector_float_t *v = (vector_float_t *)malloc(sizeof(vector_float_t) + sizeof(float) * size);
    v->len = 0;
    v->size = size;
    return v;
}

void vector_float_push(vector_float_t *v, float x)
{
    if (v->len + 1 > v->size) {
        v->size *= 2;
        v = (vector_float_t *)realloc(v, sizeof(vector_float_t) + sizeof(float) * v->size);
    }
    v->data[v->len++] = x;
}

float vector_float_pop(vector_float_t *v)
{
    return v->data[--v->len];
}

typedef struct
{
    uint32_t len;
    uint32_t size;
    double data[];
} vector_double_t;

vector_double_t *vector_double_new(uint32_t size)
{
    vector_double_t *v = (vector_double_t *)malloc(sizeof(vector_double_t) + sizeof(double) * size);
    v->len = 0;
    v->size = size;
    return v;
}

void vector_double_push(vector_double_t *v, double x)
{
    if (v->len + 1 > v->size) {
        v->size *= 2;
        v = (vector_double_t *)realloc(v, sizeof(vector_double_t) + sizeof(double) * v->size);
    }
    v->data[v->len++] = x;
}

double vector_double_pop(vector_double_t *v)
{
    return v->data[--v->len];
}

typedef struct
{
    uint32_t len;
    uint32_t size;
    int data[];
} vector_int_t;

vector_int_t *vector_int_new(uint32_t size)
{
    vector_int_t *v = (vector_int_t *)malloc(sizeof(vector_int_t) + sizeof(int) * size);
    v->len = 0;
    v->size = size;
    return v;
}

void vector_int_push(vector_int_t *v, int x)
{
    if (v->len + 1 > v->size) {
        v->size *= 2;
        v = (vector_int_t *)realloc(v, sizeof(vector_int_t) + sizeof(int) * v->size);
    }
    v->data[v->len++] = x;
}

int vector_int_pop(vector_int_t *v)
{
    return v->data[--v->len];
}

typedef struct
{
    uint32_t len;
    uint32_t size;
    uint32_t data[];
} vector_uint32_t_t;

vector_uint32_t_t *vector_uint32_t_new(uint32_t size)
{
    vector_uint32_t_t *v = (vector_uint32_t_t *)malloc(sizeof(vector_uint32_t_t) + sizeof(uint32_t) * size);
    v->len = 0;
    v->size = size;
    return v;
}

void vector_uint32_t_push(vector_uint32_t_t *v, uint32_t x)
{
    if (v->len + 1 > v->size) {
        v->size *= 2;
        v = (vector_uint32_t_t *)realloc(v, sizeof(vector_uint32_t_t) + sizeof(uint32_t) * v->size);
    }
    v->data[v->len++] = x;
}

uint32_t vector_uint32_t_pop(vector_uint32_t_t *v)
{
    return v->data[--v->len];
}

typedef struct
{
    uint32_t len;
    uint32_t size;
    uint64_t data[];
} vector_uint64_t_t;

vector_uint64_t_t *vector_uint64_t_new(uint32_t size)
{
    vector_uint64_t_t *v = (vector_uint64_t_t *)malloc(sizeof(vector_uint64_t_t) + sizeof(uint64_t) * size);
    v->len = 0;
    v->size = size;
    return v;
}

void vector_uint64_t_push(vector_uint64_t_t *v, uint64_t x)
{
    if (v->len + 1 > v->size) {
        v->size *= 2;
        v = (vector_uint64_t_t *)realloc(v, sizeof(vector_uint64_t_t) + sizeof(uint64_t) * v->size);
    }
    v->data[v->len++] = x;
}

uint64_t vector_uint64_t_pop(vector_uint64_t_t *v)
{
    return v->data[--v->len];
}

typedef struct
{
    uint32_t len;
    uint32_t size;
    char data[];
} vector_char_t;

vector_char_t *vector_char_new(uint32_t size)
{
    vector_char_t *v = (vector_char_t *)malloc(sizeof(vector_char_t) + sizeof(char) * size);
    v->len = 0;
    v->size = size;
    return v;
}

void vector_char_push(vector_char_t *v, char x)
{
    if (v->len + 1 > v->size) {
        v->size *= 2;
        v = (vector_char_t *)realloc(v, sizeof(vector_char_t) + sizeof(char) * v->size);
    }
    v->data[v->len++] = x;
}

char vector_char_pop(vector_char_t *v)
{
    return v->data[--v->len];
}

#endif /* VECTOR_H */
