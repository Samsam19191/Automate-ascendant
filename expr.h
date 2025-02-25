class Symbole;
#include "symbole.h"

class Expr : public Symbole {
    public:
        Expr():Symbole(EXPR) {}
        virtual ~Expr() {}
        virtual double eval() = 0;
};

class ExprBin : public Expr {
    public:
        ExprBin(Expr * e1, Expr * e2):Expr(),gauche(e1),droite(e2) {}
        virtual ~ExprBin() { delete gauche; delete droite; }

    protected:
        Expr * gauche;
        Expr * droite;
};

class ExprPlus : public ExprBin {
    public:
        ExprPlus(Expr * e1, Expr * e2):ExprBin(e1,e2) {}
        virtual ~ExprPlus() {}
        virtual double eval();
};

class ExprMult : public ExprBin {
    public:
        ExprMult(Expr * e1, Expr * e2):ExprBin(e1,e2) {}
        virtual ~ExprMult() {}
        virtual double eval();
};

class Nombre : public Expr {
    public:
        Nombre(double v):Expr(),valeur(v) {}
        virtual ~Nombre() {}
        virtual double eval();
    protected:
        double valeur;
};