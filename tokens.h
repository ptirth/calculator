#include <string>

class Bad_token_error {};
class Buffer_full_error {};

class Token
{
public:
    char type;
    double value;
    std::string to_string();
};

Token get();
void putback(Token t);
