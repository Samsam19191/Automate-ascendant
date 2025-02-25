#include "expr.h"

double ExprPlus::eval() {
    return gauche->eval() + droite->eval();
}

double ExprMult::eval() {
    return gauche->eval() * droite->eval();
}

double Nombre::eval() {
    return valeur;
}

