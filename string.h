#include "vector.h"
#include <string.h>

typedef vector_char_t string_t;

string_t *string_new(uint32_t size) {
    string_t *s = vector_char_new(size + 1);
    s->data[size] = '\0';
    return s;
}

string_t *string_new_from(const char *str) {
    string_t *s = string_new(strlen(str));
    strncpy(s->data, str, s->size);
    return s;
}
