#include "../program.h"
#include "../syntax/syntax.h"
#include "../token/token_list.h"

jl_program_t *parse(jl_token_list_t *tokens, jl_program_t *parent);
jl_program_t *parse_branch(jl_token_list_t *tokens, jl_program_t *parent);
jl_syntax_t *parse_line(jl_token_list_t *tokens, jl_program_t *parent);
