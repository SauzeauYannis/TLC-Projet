#ifndef _LINE_H
#define _LINE_H

#include "instruction.hh"
#include "expression.hh"

class Line : public Instruction {
	Expression* start;
	Expression* end;
 public:
	Line(Expression *start, Expression *end);
	~Line();

	inline const Expression* getStart() const {return start;}
	inline const Expression* getEnd() const {return end;}

	void visit(Visitor& visitor) const;

};
#endif
