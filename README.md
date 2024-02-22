# Calculator: CLI calculator made in C++
This is my first real C++ project. The application is modular. It has two header files, `tokens.h` and `parser.h`. The tokens part include input
stream. It uses `std::cin` to read from console input and create meaningful tokens that can be understood by parser. Tokens are represented by
`Token` objects. Parser has three methods `primary()`, `term()` and `expression()` to parse tokens according to grammar rules.

# Usage Example
```bash
calculator
Calculator v0.1.0
> 2+(3*2);
 = 8
> (2.1+3)/1.7;
 = 3 
> q  # Quits the program
```
