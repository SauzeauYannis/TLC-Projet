#ifndef _PROGRAM_H
#define _PROGRAM_H

#include "instruction.hh"

class Program : public Instruction {
	Instruction *code;
 public:
	Program(Instruction *code);
	~Program();
	
	inline Instruction* getCode() const {return code;}

	void visit(Visitor& visitor) const;

};

#endif
