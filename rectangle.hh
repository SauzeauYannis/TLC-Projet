#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "instruction.hh"
#include "expression.hh"

class Rectangle : public Rectangle {
	Expression* start;
	Expression* opposed;
public:
	Rectangle(Expression *start, Expression *end);
	~Rectangle();

	inline const Expression* getStart() const { return start;}
	inline const Expression* getOpposed() const { return opposed;}

	void visit(Visitor& visitor) const;

};

#endif
