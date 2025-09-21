all: parser

parser: lexer.l parser.y main.cpp
	bison -d parser.y
	flex lexer.l
	g++ -o parser parser.tab.c lex.yy.c main.cpp

clean:
	rm -f parser.tab.* lex.yy.c parser
