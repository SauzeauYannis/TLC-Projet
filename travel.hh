#ifndef _TRAVEL_H
#define _TRAVEL_H

#include "instruction.hh"
#include "position.hh"

class Travel : public Instruction {
	Position* pos;
public:
	Travel(Position* pos);
	~Travel();

	inline const Position* getPosition() const {return pos;}

	void visit(Visitor& visitor) const;

};

#endif
