CC = gcc
LEX = lex
YACC = yacc -d
CFLAGS = -O2 -Wall -g -std=gnu99
LDFLAGS = -ly -ll # Linux: -lfl / OSX: -ll
C99FLAGS= -std=gnu99
EXEC = texcc
SRC = src/symbol_array.c src/quad.c src/gen_code.c
OBJ = $(SRC:.c=.o)


all: $(OBJ) y.tab.c lex.yy.c
	$(CC) -o bin/$(EXEC) $^ $(LDFLAGS) $(C99FLAGS)

y.tab.c: grammar/$(EXEC).y
	$(YACC) grammar/$(EXEC).y 

lex.yy.c: grammar/$(EXEC).l
	$(LEX) grammar/$(EXEC).l 

%.o: %.c %.h
	$(CC) -o $@ -c $^ $(CFLAGS)
	@echo $(LEX)

clean:
	/bin/rm $(EXEC) *.o y.tab.c y.tab.h lex.yy.c src/*.o

test: |all
	bin/texcc $(file)

simpletest: |all
	bin/texcc examples/01_empty.tex

rebuild:
	make clean
	make all
