#ifndef _LOOP_H
#define _LOOP_H

#include "instruction.hh"

class Loop : public Instruction {
	Instruction *body;
 public:
	Loop(Instruction *body);
	~Loop();

	inline const Instruction* getBody() const{ return body;}

	void visit(Visitor& visitor) const;

};

#endif
