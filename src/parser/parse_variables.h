#include "../syntax/syntax.h"
#include "../token/token.h"
#include "../token/token_list.h"

jl_syntax_t *parse_array_declaration(jl_token_list_t *tokens);
jl_syntax_t *parse_variable_remove(jl_token_list_t *tokens);
jl_syntax_t *parse_identifier(jl_token_list_t *tokens);
jl_syntax_t *parse_variable_declarations(jl_token_list_t *tokens);
