#ifndef _DECL_H
#define _DECL_H

#include "instruction.hh"

#include <iostream>

class Decl : public Instruction {
	std::string var;
 public:
	Decl(std::string var);
	~Decl();

    inline const std::string getVar() const { return var; }
		  
	void visit(Visitor& visitor) const;
};

#endif
