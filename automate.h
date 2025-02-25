#include "lexer.h"
#include <stack>

class Etat;
class Expr;

class Automate {
    public:
        Automate(std::string input);
        ~Automate();
        Symbole * popSymbol();
        void popAndDestroySymbol();
        void lecture();
        void decalage(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        void accepter();
        void erreur();
        void transitionsimple(Symbole * s, Etat * e);

        void infoEtat();

    private:
        Lexer * lexer;
        std::stack<Symbole*> pileSymbole;
        std::stack<Etat*> pileEtat;
        bool stop = false; //TODO trouver une meilleur solution pour arrêter la boucle de lecture
};
