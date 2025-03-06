#include "expr.h"

Expr::~Expr() {}

ExprBin::~ExprBin() {
    delete gauche;
    delete droite;
}

ExprMult::~ExprMult() {}

ExprPlus::~ExprPlus() {}

Nombre::~Nombre() {}

double ExprPlus::eval() {
    return gauche->eval() + droite->eval();
}

double ExprMult::eval() {
    return gauche->eval() * droite->eval();
}

double Nombre::eval() {
    return valeur;
}

