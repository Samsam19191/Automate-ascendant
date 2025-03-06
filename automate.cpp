#include "automate.h"
#include "etats.h"
#include "exceptions.h"
#include "expr.h"
#include "symbole.h"
#include <iostream>

Automate::Automate(std::string input) {
  lexer = new Lexer(input);
  pileEtat.push(new E0());
}

Symbole *Automate::popSymbol() {
  if (pileSymbole.empty()) {
    throw std::runtime_error("Erreur : pileSymbole est vide !");
  }

  Symbole *s = pileSymbole.top();
  pileSymbole.pop();

  if (s->operator int() == INT) {
    Expr *p = new Nombre(((Entier *)s)->getValeur());
    delete s;
    return p;
  } else if (s->operator int() == EXPR) {
    return s;
  } else {
    delete s;
    throw std::runtime_error("Erreur : symbole non reconnu !");
  }
}

void Automate::popAndDestroySymbol() {
  if (!pileSymbole.empty()) {
    delete pileSymbole.top();
    pileSymbole.pop();
  }
}

Automate::~Automate() {
  delete lexer;
  while (!pileEtat.empty()) {
    delete (pileEtat.top());
    pileEtat.pop();
  }
}

void Automate::lecture() {
  Symbole *s;
  try {
    while (true) {
      s = lexer->Consulter();
      this->infoEtat();
      s->Affiche();

      cout << endl << "+++++++" << endl;

      pileEtat.top()->transition(*this, s);
    }
  } catch (const AcceptException &e) {
    cout << e.what() << endl;
  } catch (const TransitionException &e) {
    cerr << e.what() << endl;
  } catch (const std::runtime_error &e) {
    cerr << "Runtime error: " << e.what() << endl;
  } catch (const std::exception &e) {
    cerr << "Exception: " << e.what() << endl;
  } catch (...) {
    cerr << "Unknown exception occurred" << endl;
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
  Expr *result = (Expr *)pileSymbole.top();
  cout << "Résultat final : " << result->eval() << endl;
  throw AcceptException();
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