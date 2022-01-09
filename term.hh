#ifndef _TERM_H
#define _TERM_H

#include <iostream>
#include <string>

#include "visitor.hh"

class Term {
 public:
	virtual ~Term() { }

	virtual void visit(Visitor& visitor) const = 0;
};

#endif
