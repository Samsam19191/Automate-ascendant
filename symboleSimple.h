#pragma once

#include <string>
#include "symbole.h"
using namespace std;

class SymboleSimple : public Symbole {
   public:
      SymboleSimple(int i) : Symbole(i), ident(i) { }
      virtual ~SymboleSimple() { }
      operator int() const { return ident; }
      virtual void Affiche();

   protected:
      int ident;
};

class Entier : public SymboleSimple {
   public:
      Entier(int v) : SymboleSimple(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
   protected:
      int valeur;
};

