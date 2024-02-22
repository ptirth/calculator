#include "tokens.h"
#include "parser.h"

double primary()
{
    Token t = get();

    if (t.type == '8')
        return t.value;
    else if (t.type == '(')
        return expression();
    else
        throw Bad_expression_error();
}
