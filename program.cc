#include "program.hh"

Program::Program(Instruction *code) : code(code) {}

Program::~Program(){ delete(code); }

void Program::visit(Visitor& visitor) const{
	return visitor.visitProgram(this);
}
