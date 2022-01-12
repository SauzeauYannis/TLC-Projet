#ifndef _ENTETE_H
#define _ENTETE_H

#include "instruction.hh"
#include "expression.hh"

class Entete : public Instruction {
	Expression* taille;
	std::string name;
	bool affiche;
public:
	Entete(Expression *taille, std::string name, bool affiche);
	~Entete();

	inline const Expression *getTaille() const {return taille;}
	inline const std::string getName() const {return name;}
	inline const bool getAffiche() const {return affiche;}

	void visit(Visitor& visitor) const;

};

#endif
