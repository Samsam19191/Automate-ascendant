#include <iostream>
#include "lexer.h"
#include "expr.h"
#include "automate.h"


int main(void) {
   string chaine("(1+34)*123");
   Automate automate(chaine);
   automate.lecture();

   Expr * expr = new ExprMult(new ExprPlus(new Nombre(1), new Nombre(34)), new Nombre(123));
   std::cout << expr->eval() << std::endl;
   delete expr;
   return 0;
}

