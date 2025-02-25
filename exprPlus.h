#include "expr.h"
#include "exprBin.h"

class ExprPlus : public ExprBin {
    public:
        ExprPlus(Expr * g, Expr * d) : ExprBin(g, d) {}
        virtual double eval(const map<string, double> & valeurs) {
            return getGauche()->eval(valeurs) + getDroite()->eval(valeurs);
        };
};