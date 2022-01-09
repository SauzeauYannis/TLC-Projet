#ifndef _OPERATOR_H
#define _OPERATOR_H

#include "expression.hh"

enum OperatorSymbol {
	ADD,
	SUB,
	MUL,
	DIV,
};

class Operator : public Expression {
	Expression *left;
	OperatorSymbol symbol;
	Expression *right;

 public:
	Operator(OperatorSymbol symbol, Expression *left, Expression *right);
	~Operator();

	inline const Expression* getLeft() const {return left;}
	inline const Expression* getRight() const {return right;}
	inline const OperatorSymbol getSymbol() const{ return symbol;}

	void visit(Visitor& visitor) const;

};

#endif
