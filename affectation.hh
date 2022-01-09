#ifndef _AFFECTATION_H
#define _AFFECTATION_H

#include "instruction.hh"
#include "expression.hh"

#include <iostream>

class Affectation : public Instruction {
	std::string var;
	Expression* expr;
 public:
	Affectation(std::string var, Expression* expr);
	~Affectation();

	inline std::string getVar() const { return var; }
	inline const Expression* getExpr() const { return expr; }

	void visit(Visitor& visitor) const;
};


#endif
