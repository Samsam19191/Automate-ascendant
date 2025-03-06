#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class AcceptException : public std::exception {
public:
  const char *what() const noexcept override { return "Expression acceptée"; }
};

class TransitionException : public std::exception {
public:
  const char *what() const noexcept override {
    return "Analyse arrêtée : erreur syntaxique détectée";
  }
};

#endif // EXCEPTIONS_H