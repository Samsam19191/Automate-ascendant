#include "etats.h"
#include "symbole.h"

bool E0::transition(Automate & automate, Symbole * s) {
    switch(*s) {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    default :
        automate.transitionsimple(s, new E1);
        breal;
    }
    return false;
}

bool E1::transition(Automate & automate, Symbole * s) {
    switch(*s) {
    case PLUS:
        automate.decalage(s, new E4);
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case FIN:
        //TODO accepter
    }
    return false;
}

bool E2::transition(Automate & automate, Symbole * s) {
    switch(*s) {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    default :
        automate.transitionsimple(s, new E6);
        break;
    }
    return false;
}

bool E3::transition(Automate & automate, Symbole * s) {
    switch(*s) {
    case PLUS:
        automate.reduction(5, s);
        break;
    case MULT:
        automate.reduction(5, s);
        break;
    case CLOSEPAR :
        automate.reduction(5, s);
        break;
    case FIN:
            automate.reduction(5, s);
            break;
    }
    return false;
}

bool E4::transition(Automate & automate, Symbole * s) {
    switch(*s) {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    default :
            automate.transitionsimple(s, new E7);
            break;
    }
    return false;
}

bool E5::transition(Automate & automate, Symbole * s) {
    switch(*s) {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    default :
            automate.transitionsimple(s, new E8);
            break;
    }
    return false;
}

bool E6::transition(Automate & automate, Symbole * s) {
    switch(*s) {
    case PLUS:
        automate.decalage(s, new E4);
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case CLOSEPAR:
        automate.decalage(s, new E9);
        break;
    }
    return false;
}

bool E7::transition(Automate & automate, Symbole * s) {
    switch(*s) {
    case PLUS:
        automate.reduction(2, s);
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case CLOSEPAR:
        automate.reduction(2, s);
        break;
    case FIN:
        automate.reduction(2, s);
        break;
    }
    return false;
}

bool E8::transition(Automate & automate, Symbole * s) {
    switch(*s) {
    case PLUS:
        automate.reduction(3, s);
        break;
    case MULT:
        automate.reduction(3, s);
        break;
    case CLOSEPAR:
        automate.reduction(3, s);
        break;
    case FIN:
        automate.reduction(3, s);
        break;
    }
    return false;
}

bool E9::transition(Automate & automate, Symbole * s) {
    switch(*s) {
    case PLUS:
        automate.reduction(4, s);
        break;
    case MULT:
        automate.reduction(4, s);
        break;
    case CLOSEPAR:
        automate.reduction(4, s);
        break;
    case FIN:
        automate.reduction(4, s);
        break;
    }
    return false;
}