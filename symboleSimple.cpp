#include "symboleSimple.h"
#include <iostream>

void SymboleSimple::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   SymboleSimple::Affiche();
   cout<<"("<<valeur<<")";
}

