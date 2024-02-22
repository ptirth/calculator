#include <iostream>
#include "tokens.h"
#include "parser.h"

using std::cout;

int main()
{
    cout << "Calculator v0.1.0\n";
    while (true)
    {
        cout << "> ";

        Token t = get();
        switch (t.type)
        {
        case 'q':
            goto program_end;
        default:
            putback(t);
        }
        double result{expression()};
        cout << " = " << result << '\n';
    }
    program_end: ;
}
