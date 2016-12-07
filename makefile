CC = gcc
LEX = lex
YACC = yacc -d
CFLAGS = -O2 -Wall -g
LDFLAGS = -ly -ll # Linux: -lfl / OSX: -ll
EXEC = texcc
SRC = src/symbol_array.c src/quad.c
OBJ = $(SRC:.c=.o)


all: $(OBJ) y.tab.c lex.yy.c
	$(CC) -o bin/$(EXEC) $^ $(LDFLAGS)

y.tab.c: grammar/$(EXEC).y
	$(YACC) grammar/$(EXEC).y

lex.yy.c: grammar/$(EXEC).l
	$(LEX) grammar/$(EXEC).l 

%.o: %.c %.h
	$(CC) -o $@ -c $^ $(CFLAGS)
	@echo $(LEX)

clean:
	/bin/rm $(EXEC) *.o y.tab.c y.tab.h lex.yy.c src/*.o

rebuild:
	make clean
	make all
