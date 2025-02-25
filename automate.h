#include "lexer.h"
#include <stack>

class Etat;

class Automate {
public:
    Automate(std::string input) : lexer(input) {}
    void lecture();

private:
    Lexer lexer;
    std::stack<Symbole*> pileSymbole;
    std::stack<Etat*> pileEtat;
};
