SRC=
SRCH=
OBJ=$(SRC:.c=.o)=

prog: lex.yy.c parseur.tab.cc
	g++ -o $@ $? -ll

lex.yy.c: lexeur.ll parseur.tab.cc
	flex $<

parseur.tab.cc: parseur.yy
	bison -d $<

clean: 
	rm -fr lex.yy.c parseur.tab.cc parseur.tab.hh
