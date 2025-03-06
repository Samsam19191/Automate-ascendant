// #include <iostream>
// #include "lexer.h"
// #include "expr.h"
// #include "automate.h"

// int main(void) {
//    //string chaine("7+8");
//    string chaine("2*3+4");
//    Automate automate(chaine);
//    automate.lecture();

// //   Expr * expr = new ExprMult(new ExprPlus(new Nombre(1), new Nombre(34)),
// new Nombre(123));
// //   std::cout << expr->eval() << std::endl;
// //   delete expr;
//    return 0;
// }

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
    try {
      automate.lecture();
      cout << "\n✅ Analyse terminée avec succès !" << endl;
    } catch (const exception &e) {
      cerr << "\n❌ Erreur durant l'analyse : " << e.what() << endl;
    }
  }

  return 0;
}
