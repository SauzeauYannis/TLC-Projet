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


graph: graph.dot
	dot -Tpng $< > $@.png

graph.dot: parseur.yy
	bison --graph=graph.dot parseur.yy

all: prog graph


.PHONY: clean

clean: 
	rm -fr $(OBJ) lex.yy.c parseur.tab.cc parseur.tab.hh graph graph.dot

quadrilatere: clean prog
	./prog < quadrilatere

quadrillage: clean prog
	./prog < quadrillage