#include "automate.h"
#include "expr.h"
#include "lexer.h"
#include <iostream>

using namespace std;

int main(void) {
  cout << "===== Analyseur syntaxique d'expressions =====" << endl;

  while (true) {
    // Demande une expression à l'utilisateur
    cout << "\nEntrez une expression (ou 'exit' pour quitter) : ";
    string chaine;
    getline(cin, chaine);

    // Vérifier si l'utilisateur veut quitter
    if (chaine == "exit" || chaine == "") {
      cout << "Fin du programme." << endl;
      break;
    }

    // Création de l'automate avec l'expression saisie
    Automate automate(chaine);
    automate.lecture();
  }

  return 0;
}
