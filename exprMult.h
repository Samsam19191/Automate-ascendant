#include "expr.h"
#include "exprBin.h"

class ExprMult : public ExprBin {
    public:
        ExprMult(Expr * g, Expr * d) : ExprBin(g, d) {}
        virtual double eval(const map<string, double> & valeurs)  {
            return getGauche()->eval(valeurs) * getDroite()->eval(valeurs);
        };
};