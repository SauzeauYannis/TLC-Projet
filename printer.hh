#ifndef _PRINTER_H
#define _PRINTER_H

#include "visitor.hh"
#include "code.hh"
#include "pen.hh"
#include "declaration.hh"
#include "affectation.hh"
#include "loop.hh"
#include "move.hh"
#include "color.hh"
#include "value.hh"
#include "operator.hh"
#include "position.hh"

class Printer : public Visitor {
	bool is_down = false;
 public:
	void visitCode(const Code *c);
	void visitPen(const Pen *p);
	void visitDeclaration(const Declaration *d);
	void visitAffectation(const Affectation *a);
	void visitLoop(const Loop *l);
	void visitMove(const Move *m);
	void visitColor(const Color *c);
	void visitValue(const Value *v);
	void visitOperator(const Operator *o);
	void visitPosition(const Position *p);
};

#endif