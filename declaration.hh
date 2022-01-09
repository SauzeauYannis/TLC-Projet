#ifndef _DECL_H
#define _DECL_H

#include "instruction.hh"

#include <iostream>

class Declaration : public Instruction {
	std::string var;
 public:
	Declaration(std::string var);
	~Declaration();

    inline const std::string getVar() const { return var; }
		  
	void visit(Visitor& visitor) const;
};

#endif
