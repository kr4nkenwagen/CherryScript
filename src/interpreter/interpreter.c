#include "../debug.h"
#include "../error.h"
#include "../object/object_array.h"
#include "../object/object_comparison.h"
#include "../object/object_operations.h"
#include "../object/object_string.h"
#include "../program.h"
#include "../stack.h"
#include "../syntax/syntax.h"
#include "../token/token.h"
#include "../vm.h"
#include "eval_expressions.h"
#include "eval_function.h"
#include "eval_logic.h"
#include "eval_variables.h"
#include <string.h>

jl_object_t *interprete(jl_program_t *program, vm_t *vm) {
  if (program == NULL) {
    return NULL;
  }
  program->pointer = 0;
  jl_object_t *value;
  while (program->pointer < program->count) {
    if (program->exit) {
      break;
    }
    if (program->continueing) {
      program->pointer++;
      program->continueing = false;
      continue;
    }
    value = eval_primary_expression(program->statements[program->pointer++], vm,
                                    program);
  }
  if (program->exit) {
    return program->ret_value;
  }
  return NULL;
}

jl_object_t *interprete_branch(jl_syntax_t *syntax, vm_t *vm) {
  if (syntax->args != NULL) {
    jl_object_t *arg_vals =
        eval_array_declaration(syntax->value, vm, syntax->branch);
    vm_push_frame(vm, stack_new(), false);
    interprete(syntax->args, vm);
    stack_t *curr_stack = vm_curr_frame(vm);
    if (curr_stack->count - curr_stack->parent_references !=
        arg_vals->data.v_array->count) {
      err_incorrect_number_of_references(syntax->token);
    }
    for (int i = curr_stack->parent_references; i < curr_stack->count; i++) {
      curr_stack->data[i]->data =
          arg_vals->data.v_array->elements[i - curr_stack->parent_references]
              ->data;
      curr_stack->data[i]->type =
          arg_vals->data.v_array->elements[i - curr_stack->parent_references]
              ->type;
    }
  } else {
    vm_push_frame(vm, stack_new(), true);
  }
  jl_object_t *value =
      jl_object_instantiate_copy(interprete(syntax->branch, vm));
  vm_pop_frame(vm);
  return value;
}
