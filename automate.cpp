#include "automate.h"
#include "etats.h"
#include "expr.h"
#include "symbole.h"
#include <iostream>

Automate::Automate(std::string input) {
  lexer = new Lexer(input);
  pileEtat.push(new E0());
}

Symbole *Automate::popSymbol() {
  if (pileSymbole.empty()) {
    std::cerr << "Erreur : pileSymbole est vide !" << std::endl;
    return nullptr;
  }

  Symbole *s = pileSymbole.top();
  pileSymbole.pop();

  if (s->operator int() == INT) {
    Expr *p = new Nombre(((Entier *)s)->getValeur());
    return p;
  } else if (s->operator int() == EXPR) {
    return s;
  }
}

void Automate::popAndDestroySymbol() { pileSymbole.pop(); }

Automate::~Automate() {
  delete lexer;
  while (!pileEtat.empty()) {
    delete (pileEtat.top());
    pileEtat.pop();
  }
}

void Automate::lecture() {
  Symbole *s;
  int n = 0;
  while (!this->stop and n <= 100) {
    s = lexer->Consulter();
    this->infoEtat();
    s->Affiche();

    cout << endl << "+++++++" << endl;
    pileEtat.top()->transition(*this, s);
    n++;
  }
}

void Automate::decalage(Symbole *s, Etat *e) {
  pileSymbole.push(s);
  pileEtat.push(e);
  lexer->Avancer();
}

void Automate::reduction(int n, Symbole *s) {
  for (int i = 0; i < n; i++) {
    delete (pileEtat.top());
    pileEtat.pop();
  }

  pileEtat.top()->transition(*this, s);

}

void Automate::transitionsimple(Symbole *s, Etat *e) {
  pileSymbole.push(s);
  pileEtat.push(e);
}

void Automate::accepter() {
  this->stop = true;
  Expr *result = (Expr *)pileSymbole.top();
  cout << "Résultat final : " << result->eval() << endl;
}

void Automate::infoEtat() {
  cout << "Pile Etat | Pile Symbole | Symbole Actuel" << endl;
  pileEtat.top()->print();
  cout << " | ";
  if (!pileSymbole.empty()) {
    pileSymbole.top()->Affiche();
    cout << " | ";
  } else {
    std::cout << "empty"
              << " | ";
  }
}