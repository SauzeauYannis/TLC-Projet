#ifndef _PRINTER_H
#define _PRINTER_H

#include "CImg.h"
#include "visitor.hh"
#include "code.hh"
#include "pen.hh"
#include "declaration.hh"
#include "affectation.hh"
#include "loop.hh"
#include "travel.hh"
#include "color.hh"
#include "value.hh"
#include "operator.hh"
#include "position.hh"
#include "var.hh"
#include "rectangle.hh"
#include "line.hh"

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstring>

class Printer : public Visitor {
	bool is_down;
	std::unordered_map<std::string, float> vars;
	double buffer_expr;
	std::pair<double, double> bufferPosition;
	std::vector<std::string> protectedVar;
	cimg_library::CImg<unsigned char> img;
	unsigned char color[3] 	= {0, 0, 0};
	struct {
		unsigned int r;
		unsigned int g;
		unsigned int b;
	} rgb;
 public:
	Printer() : is_down(false), vars{}, buffer_expr(0)
				, bufferPosition(0, 0), protectedVar() { }
	void visitCode(const Code *c);
	void visitPen(const Pen *p);
	void visitDeclaration(const Declaration *d);
	void visitAffectation(const Affectation *a);
	void visitLoop(const Loop *l);
	void visitTravel(const Travel *m);
	void visitColor(const Color *c);
	void visitValue(const Value *v);
	void visitOperator(const Operator *o);
	void visitPosition(const Position *p);
	void visitVar(const Var *v);
	void visitRectangle(const Rectangle *r);
	void visitLine(const Line *l);
};

#endif
