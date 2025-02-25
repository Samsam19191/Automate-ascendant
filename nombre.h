#include "expr.h"

class Nombre : public Expr {
    private:
        double valeur;
    public:
        Nombre(double v) : valeur(v) {}
        virtual ~Nombre() {}
        virtual double eval(const map<string, double> & valeurs) {
            return valeur;
        };
        double getValeur() { return valeur; };
};