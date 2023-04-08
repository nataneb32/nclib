#include "vector.h"
#include "string.h"
#include <stdio.h>

int main() {
  vector_float_t *v = vector_float_new(2);
  vector_float_push(v, 2.0);
  
  string_t *s = string_new_from("Hello");
  
  printf("%s\n", s->data);

  while (v->len > 0) {
    float f = vector_float_pop(v);
    printf("%f\n", f);
  }
}
