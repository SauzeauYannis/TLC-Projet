SRC = affectation.cc \
	code.cc \
	color.cc \
	declaration.cc \
	entete.cc \
	loop.cc \
	operator.cc \
	pen.cc \
	position.cc \
	program.cc \
	rectangle.cc \
	travel.cc \
	value.cc \
	var.cc \
	printer.cc \
	lex.yy.c \
	parseur.tab.cc \
	main.cc 
SRCH = affectation.hh \
	color.hh \
	code.hh \
	declaration.hh \
	entete.hh \
	expression.hh \
	instruction.hh \
	loop.hh \
	operator.hh \
	pen.hh \
	position.hh \
	program.hh \
	rectangle.hh \
	term.hh  \
	travel.hh \
	value.hh \
	var.hh \
	visitor.hh \
	printer.hh \
	parseur.tab.hh
FLAGS =-lX11 -lpthread -ll
OBJ = $(SRC:.cc=.o)

prog: $(OBJ)
	$(CXX) -o $@ $(OBJ) $(FLAGS)

lex.yy.c: lexeur.ll parseur.tab.cc
	flex $<

parseur.tab.cc: parseur.yy
	bison -d $<

graph: graph.dot
	dot -Tpng $< > Arbre_Syntaxique/$@.png

graph.dot: parseur.yy
	bison --graph=graph.dot parseur.yy

all: prog graph

cube: prog
	./prog < Exemple/cube

erreur: prog
	./prog < Exemple/erreur

quadrilatere: prog
	./prog < Exemple/quadrilatere

quadrillage: prog
	./prog < Exemple/quadrillage

test: prog
	./prog < Exemple/test

.PHONY: clean

clean: 
	rm -fr $(OBJ) lex.yy.c parseur.tab.cc parseur.tab.hh graph.dot graph prog
