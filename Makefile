CXX=g++
SRC=lex.yy.c parseur.tab.cc
SRCH=
OBJ=$(SRC:.cc=.o)

prog: $(OBJ)
	$(CXX) -o $@ $(OBJ) -ll

lex.yy.c: lexeur.ll parseur.tab.cc
	flex $<

parseur.tab.cc: parseur.yy
	bison -d $<

.PHONY: clean

clean: 
	rm -fr $(OBJ) lex.yy.c parseur.tab.cc parseur.tab.hh

quadrilatere: clean prog
	./prog < quadrilatere

quadrillage: clean prog
	./prog < quadrillage