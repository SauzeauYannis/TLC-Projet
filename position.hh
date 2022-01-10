#ifndef _POSITION_H
#define _POSITION_H

#include "expression.hh"

class Position : public Expression {
	Expression *x;
	Expression *y;
 public:
	Position(Expression *x,Expression *y);
	~Position();

	inline Expression* getX() const {return x;}
	inline Expression* getY() const {return y;}

	void visit(Visitor& visitor) const;
};

#endif
