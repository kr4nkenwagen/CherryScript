#include "../object/object.h"
#include "../program.h"
#include "../syntax/syntax.h"
#include "../vm.h"

jl_object_t *interprete_branch(jl_syntax_t *syntax, vm_t *vm);
jl_object_t *interprete(jl_program_t *program, vm_t *vm);
