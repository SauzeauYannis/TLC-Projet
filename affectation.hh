#ifndef _AFFECTATION_H
#define _AFFECTATION_H

#include "instruction.hh"
#include "expression.hh"

#include <iostream>

class Affect : public Instruction {
	std::string var;
	Expression* expr;
 public:
	Affect(std::string var, Expression* expr);
	~Affect();

	inline std::string getVar() const { return var; }
	inline const Expression* getExpr() const { return expr; }

	void visit(Visitor& visitor) const;
};


#endif
