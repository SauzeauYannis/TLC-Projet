#ifndef VISITOR_H
#define VISITOR_H

class Code;
class Declaration;
class Affectation;
class Loop;
class Move;
class Color;
class Value;
class Operator;
class Position;

class Visitor {
 public:
	virtual void visitCode(const Code *c) = 0;
	virtual void visitDeclaration(const Declaration *d) = 0;
	virtual void visitAffectation(const Affectation *a) = 0;
	virtual void visitLoop(const Loop *l) = 0;
	virtual void visitMove(const Move *m) = 0;
	virtual void visitColor(const Color *c) = 0;
	virtual void visitValue(const Value *v) = 0;
	virtual void visitOperator(const Operator *o) = 0;
	virtual void visitPosition(const Position *p) = 0;
};

#endif
