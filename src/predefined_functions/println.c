#include "../object/object.h"
#include "../object/object_operations.h"
#include "print.h"
#include <stdio.h>

void jl_println(jl_object_t *obj) {
  if (obj == NULL) {
    return;
  }
  jl_object_t *newline = jl_new_string("\n");
  jl_print(jl_add(obj, newline));
}
