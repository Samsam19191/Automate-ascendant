#include "automate.h"
#include <iostream>

void Automate::lecture() {
    Symbole * s;
    std::cout << "Affichage ... " << endl;
    while(*(s=lexer.Consulter())!=FIN) {
        s->Affiche();
        std::cout<<std::endl;
        lexer.Avancer();
    }
}
