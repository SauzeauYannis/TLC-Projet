#ifndef _VISITOR_H
#define _VISITOR_H

class Code;
class Pen;
class Declaration;
class Affectation;
class Loop;
class Travel;
class Color;
class Value;
class Operator;
class Position;
class Var;
class Rectangle;
class Program;
class Entete;

class Visitor {
 public:
	virtual void visitProgram(const Program *p) =0;
	virtual void visitCode(const Code *c) = 0;
	virtual void visitPen(const Pen *p) = 0;
	virtual void visitDeclaration(const Declaration *d) = 0;
	virtual void visitAffectation(const Affectation *a) = 0;
	virtual void visitLoop(const Loop *l) = 0;
	virtual void visitTravel(const Travel *t) = 0;
	virtual void visitColor(const Color *c) = 0;
	virtual void visitValue(const Value *v) = 0;
	virtual void visitOperator(const Operator *o) = 0;
	virtual void visitPosition(const Position *p) = 0;
	virtual void visitVar(const Var *v) = 0;
	virtual void visitRectangle(const Rectangle *r) = 0;
	virtual void visitEntete(const Entete *e) = 0;
};

#endif
