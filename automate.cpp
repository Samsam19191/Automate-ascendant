#include "automate.h"
#include <iostream>
#include "etats.h"
#include "symbole.h"
#include "expr.h"

Automate::Automate(std::string input) {
    lexer = new Lexer(input);
    pileEtat.push(new E0());
}

Symbole * Automate::popSymbol() {
    if (pileSymbole.empty()) {
        std::cerr << "Erreur : pileSymbole est vide !" << std::endl;
        return nullptr;
    }

    Symbole *s = pileSymbole.top();
    s->Affiche();
    pileSymbole.pop();

    if (s->operator int() == INT) {
            Expr * p = new Nombre(((Entier*)s)->getValeur());
            cout << "Nombre : " << p->eval() << endl;
            return p;
        }
        else if (s->operator int() == EXPR) {
            return s;
        }
}


void Automate::popAndDestroySymbol() {
    pileSymbole.pop();
}

Automate::~Automate() {
    delete lexer;
    while (!pileEtat.empty())
    {
        delete(pileEtat.top());
        pileEtat.pop();
    }
}

void Automate::lecture() {
    Symbole * s = lexer->Consulter();
    int n = 0;
    while (!this->stop and n<=10)
    {
        s = lexer->Consulter();
        this->infoEtat();
        s->Affiche();

        std::cout << "Taille pile symbole : " << pileSymbole.size() << std::endl;
        cout << endl << "+++++++" << endl;
        pileEtat.top()->transition(*this,s);
        n++;


    }
}

void Automate::decalage(Symbole * s, Etat * e) {
    pileSymbole.push(s);
    pileEtat.push(e);
    lexer->Avancer();
}

void Automate::reduction(int n,Symbole * s) {
    for (int i=0;i<n;i++)
    {
        delete(pileEtat.top());
        pileEtat.pop();
    }
    Expr* result = dynamic_cast<Expr*>(s);
    cout << "Resultat : " << result->eval() << endl;

    pileEtat.top()->transition(*this,s);

    pileSymbole.top()->Affiche();
    pileEtat.top()->print();
}


void Automate::transitionsimple(Symbole * s, Etat * e) {
    pileSymbole.push(s);
    pileEtat.push(e);
}

void Automate::accepter() {
    this->stop = true;
    Expr * result = (Expr*)pileSymbole.top();
    cout << "Acceptation acceptée : " << result->eval() << endl;
}

void Automate::infoEtat() {
    cout << "Pile Etat | Pile Symbole | Symbole Actuel" << endl;
    pileEtat.top()->print();
    cout << " | ";
    if(!pileSymbole.empty()) {
        pileSymbole.top()->Affiche();
        cout << " | ";
    }
    else
    {
        std::cout << "no Sym" << " | ";
    }
}