SRC=code.cc pen.cc printer.cc lex.yy.c parseur.tab.cc main.cc affectation.cc declaration.cc color.cc loop.cc travel.cc operator.cc position.cc value.cc var.cc rectangle.cc line.cc
SRCH=affectation.hh code.hh color.hh declaration.hh expression.hh instruction.hh loop.hh travel.hh operator.hh parseur.tab.hh pen.hh position.hh printer.hh term.hh value.hh visitor.hh var.hh rectangle.hh line.hh
CXX=g++
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

test: clean prog
	./prog < test

quadrilatere: clean prog
	./prog < quadrilatere

quadrillage: clean prog
	./prog < quadrillage

.PHONY: clean

clean: 
	rm -fr $(OBJ) lex.yy.c parseur.tab.cc parseur.tab.hh graph graph.dot prog
