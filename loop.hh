#ifndef _LOOP_H
#define _LOOP_H

#include "instruction.hh"
#include "expression.hh"

class Loop : public Instruction {
	std::string incr;
	Expression* min;
	Expression* max;
	Instruction *body;
 public:
	Loop(std::string incr, Expression* min, Expression* max, Instruction *body);
	~Loop();

	inline const std::string getIncr() const {return incr;}
	inline const Expression* getMax() const {return max;}
	inline const Expression* getMin() const{return min;}
	inline const Instruction* getBody() const{ return body;}

	void visit(Visitor& visitor) const;

};

#endif
