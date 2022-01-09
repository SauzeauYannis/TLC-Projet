#ifndef _VALUE_H
#define _VALUE_H

#include "expression.hh"

class Value : public Expression {
	double value;
 public:
	Value(double v);
	~Value();

	inline double getValue() const {return value;}

	void visit(Visitor& visitor) const;

};

#endif
