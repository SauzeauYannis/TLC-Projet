#ifndef _TRAVEL_H
#define _TRAVEL_H

#include "instruction.hh"
#include "expression.hh"

class Travel : public Instruction {
	Expression* pos;
public:
	Travel(Expression* pos);
	~Travel();

	inline const Expression* getPosition() const {return pos;}

	void visit(Visitor& visitor) const;

};

#endif
