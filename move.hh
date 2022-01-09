#ifndef _MOVE_H
#define _MOVE_H

#include "position.hh"
#include "instruction.hh"

class Move : public Instruction {
	Position *pos;
public:
	Move(Position *pos);
	~Move();

	inline const Position* getPosition() const {return pos;}

	void visit(Visitor& visitor) const;

};

#endif
