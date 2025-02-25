#include "expr.h"

class Variable : public Expr {
    private:
        string nom;
    public:
        Variable(string n) : nom(n) {}
        virtual ~Variable() {}
        virtual double eval(const map<string, double> & valeurs) {
            return valeurs.find(nom)->second;
        };
        string getNom() { return nom; };
};