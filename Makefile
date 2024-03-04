COMPILER = g++

.PHONY = token parser project

token:
	$(COMPILER) -c -o bin/tokens.o -Iinclude src/tokens.cpp
	@echo "Built tokens.o"

parser: token
	$(COMPILER) -c -o bin/parser.o -Iinclude src/parser.cpp
	@echo "Built parser.o"

project: parser
	$(COMPILER) -c -o bin/main.o -Iinclude src/main.cpp
	@echo "Built main.o"
	$(COMPILER) -o bin/calculator bin/*.o
	@echo "Built calculator"
