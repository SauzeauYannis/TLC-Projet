#ifndef _POSITION_H
#define _POSITION_H

#include "expression.hh"

class Position : public Expression {
	double x;
	double y;
 public:
	Position(double x, double y);
	~Position();

	inline double getX() const {return x;}
	inline double getY() const {return y;}

	void visit(Visitor& visitor) const;
};

#endif
