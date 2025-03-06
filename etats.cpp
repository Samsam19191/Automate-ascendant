#include "etats.h"
#include "automate.h"
#include "exceptions.h"
#include "expr.h"
#include "symbole.h"
#include <iostream>

Etat::Etat(){};
Etat::~Etat(){};

E0::E0(){};
E1::E1(){};
E2::E2(){};
E3::E3(){};
E4::E4(){};
E5::E5(){};
E6::E6(){};
E7::E7(){};
E8::E8(){};
E9::E9(){};

E0::~E0(){};
E1::~E1(){};
E2::~E2(){};
E3::~E3(){};
E4::~E4(){};
E5::~E5(){};
E6::~E6(){};
E7::~E7(){};
E8::~E8(){};
E9::~E9(){};

void Etat::print() const { std::cout << "Etat" << endl; };

bool E0::transition(Automate &automate, Symbole *s) {
  switch (*s) {
  case INT:
    automate.decalage(s, new E3);
    break;
  case OPENPAR:
    automate.decalage(s, new E2);
    break;
  case EXPR:
    automate.transitionsimple(s, new E1);
    break;
  default:
    // Erreur
    delete s;
    throw TransitionException();
  }
  return false;
};

bool E1::transition(Automate &automate, Symbole *s) {
  switch (*s) {
  case PLUS:
    automate.decalage(s, new E4);
    break;
  case MULT:
    automate.decalage(s, new E5);
    break;
  case FIN:
    delete s;
    automate.accepter();
    break;
  default:
    // Erreur
    delete s;
    throw TransitionException();
  }
  return false;
};

bool E2::transition(Automate &automate, Symbole *s) {
  switch (*s) {
  case INT:
    automate.decalage(s, new E3);
    break;
  case OPENPAR:
    automate.decalage(s, new E2);
    break;
  case EXPR:
    automate.transitionsimple(s, new E6);
    break;
  default:
    // Erreur
    delete s;
    throw TransitionException();
  }
  return false;
};

bool E3::transition(Automate &automate, Symbole *s) {
  Expr *s1 = nullptr;
  try {
    switch (*s) {
    case PLUS:
      s1 = (Expr *)automate.popSymbol();
      automate.reduction(1, s1);
      break;
    case MULT:
      s1 = (Expr *)automate.popSymbol();
      automate.reduction(1, s1);
      break;
    case CLOSEPAR:
      s1 = (Expr *)automate.popSymbol();
      automate.reduction(1, new Nombre(s1->eval()));
      delete s1;
      break;
    case FIN:
      s1 = (Expr *)automate.popSymbol();
      automate.reduction(1, new Nombre(s1->eval()));
      delete s1;
      break;
    default:
      // Erreur
      throw TransitionException();
    }
  } catch (const std::exception &e) {
    // Gestion d'erreur popSymbol
    throw std::runtime_error(std::string("Erreur de transition: ") + e.what() +
                             "\n");
  }
  return false;
};

bool E4::transition(Automate &automate, Symbole *s) {
  switch (*s) {
  case INT:
    automate.decalage(s, new E3);
    break;
  case OPENPAR:
    automate.decalage(s, new E2);
    break;
  case EXPR:
    automate.transitionsimple(s, new E7);
    break;
  default:
    // Erreur
    delete s;
    throw TransitionException();
  }
  return false;
};

bool E5::transition(Automate &automate, Symbole *s) {
  switch (*s) {
  case INT:
    automate.decalage(s, new E3);
    break;
  case OPENPAR:
    automate.decalage(s, new E2);
    break;
  case EXPR:
    automate.transitionsimple(s, new E8);
    break;
  default:
    // Erreur
    delete s;
    throw TransitionException();
  }
  return false;
};

bool E6::transition(Automate &automate, Symbole *s) {
  switch (*s) {
  case PLUS:
    automate.decalage(s, new E4);
    break;
  case MULT:
    automate.decalage(s, new E5);
    break;
  case CLOSEPAR:
    automate.decalage(s, new E9);
    break;
  default:
    // Erreur
    delete s;
    throw TransitionException();
  }
  return false;
};

bool E7::transition(Automate &automate, Symbole *s) {
  Expr *s1 = nullptr;
  Expr *s2 = nullptr;
  try {
    switch (*s) {
    case PLUS:
      s1 = (Expr *)automate.popSymbol();
      automate.popAndDestroySymbol();
      s2 = (Expr *)automate.popSymbol();
      automate.reduction(3, new ExprPlus(s2, s1));
      break;
    case MULT:
      automate.decalage(s, new E5);
      break;
    case CLOSEPAR:
      s1 = (Expr *)automate.popSymbol();
      automate.popAndDestroySymbol();
      s2 = (Expr *)automate.popSymbol();
      automate.reduction(3, new ExprPlus(s2, s1));
      break;
    case FIN:
      s1 = (Expr *)automate.popSymbol();
      automate.popAndDestroySymbol();
      s2 = (Expr *)automate.popSymbol();
      automate.reduction(3, new ExprPlus(s2, s1));
      break;
    default:
      // Erreur
      throw TransitionException();
    }
  } catch (const std::exception &e) {
    // Gestion d'erreur popSymbol
    throw std::runtime_error(std::string("Erreur de transition: ") + e.what() +
                             "\n");
  }
  return false;
};

bool E8::transition(Automate &automate, Symbole *s) {
  Expr *s1 = nullptr;
  Expr *s2 = nullptr;
  try {
    switch (*s) {
    case PLUS:
      s1 = (Expr *)automate.popSymbol();
      automate.popAndDestroySymbol();
      s2 = (Expr *)automate.popSymbol();
      automate.reduction(3, new ExprMult(s2, s1));
      break;
    case MULT:
      s1 = (Expr *)automate.popSymbol();
      automate.popAndDestroySymbol();
      s2 = (Expr *)automate.popSymbol();
      automate.reduction(3, new ExprMult(s2, s1));
      break;
    case CLOSEPAR:
      s1 = (Expr *)automate.popSymbol();
      automate.popAndDestroySymbol();
      s2 = (Expr *)automate.popSymbol();
      automate.reduction(3, new ExprMult(s2, s1));
      break;
    case FIN:
      s1 = (Expr *)automate.popSymbol();
      automate.popAndDestroySymbol();
      s2 = (Expr *)automate.popSymbol();
      automate.reduction(3, new ExprMult(s2, s1));
      break;
    default:
      // Erreur
      throw TransitionException();
    }
  } catch (const std::exception &e) {
    // Gestion d'erreur popSymbol
    throw std::runtime_error(std::string("Erreur de transition: ") + e.what() +
                             "\n");
  }
  return false;
};

bool E9::transition(Automate &automate, Symbole *s) {
  Expr *s1 = nullptr;
  try {
    switch (*s) {
    case PLUS:
      automate.popAndDestroySymbol();
      s1 = (Expr *)automate.popSymbol();
      automate.popAndDestroySymbol();
      automate.reduction(3, new Nombre(s1->eval()));
      delete s1;
      break;
    case MULT:
      automate.popAndDestroySymbol();
      s1 = (Expr *)automate.popSymbol();
      automate.popAndDestroySymbol();
      automate.reduction(3, new Nombre(s1->eval()));
      delete s1;
      break;
    case CLOSEPAR:
      automate.popAndDestroySymbol();
      s1 = (Expr *)automate.popSymbol();
      automate.popAndDestroySymbol();
      automate.reduction(3, new Nombre(s1->eval()));
      delete s1;
      break;
    case FIN:
      automate.popAndDestroySymbol();
      s1 = (Expr *)automate.popSymbol();
      automate.popAndDestroySymbol();
      automate.reduction(3, new Nombre(s1->eval()));
      delete s1;
      break;
    default:
      // Erreur
      throw TransitionException();
    }
  } catch (const std::exception &e) {
    // Gestion d'erreur popSymbol
    throw std::runtime_error(std::string("Erreur de transition: ") + e.what() +
                             "\n");
  }
  return false;
};

void E0::print() const { std::cout << "E0"; };

void E1::print() const { std::cout << "E1"; };

void E2::print() const { std::cout << "E2"; };

void E3::print() const { std::cout << "E3"; };

void E4::print() const { std::cout << "E4"; };

void E5::print() const { std::cout << "E5"; };

void E6::print() const { std::cout << "E6"; };

void E7::print() const { std::cout << "E7"; };

void E8::print() const { std::cout << "E8"; };

void E9::print() const { std::cout << "E9"; };
