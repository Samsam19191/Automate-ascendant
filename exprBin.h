#include "expr.h"

class ExprBin : public Expr {
    private:
        Expr * gauche;
        Expr * droite;
    public:
        ExprBin(Expr * g, Expr * d) : gauche(g), droite(d) {}
        virtual double eval(const map<string, double>
            & valeurs) = 0;
        Expr * getGauche() { return gauche; }
        Expr * getDroite() { return droite; }
};