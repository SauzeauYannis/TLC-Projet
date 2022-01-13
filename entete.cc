#include "entete.hh"

Entete::Entete(Expression *taille, std::string name, Instruction *couleur, bool affiche) :
	taille(taille), name(name), couleur(couleur), affiche(affiche)
{
}

Entete::~Entete(){
	delete(taille);
	delete(couleur);
}

void Entete::visit(Visitor& visitor) const {
	return visitor.visitEntete(this);

}


