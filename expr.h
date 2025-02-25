#include "symbole.h"
#include <string>
#include <map>
using namespace std;


class Expr : public Symbole {
    public:
    Expr():Symbole(EXPR) {}
    virtual ~Expr() {}
    virtual double eval(const map<string, double>
        & valeurs) = 0;
    };