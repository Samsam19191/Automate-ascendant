# Analyseur Syntaxique LALR(1)

Ce projet est une implémentation d'un **analyseur syntaxique ascendant LALR(1)** en C++, permettant d'analyser et d'évaluer des expressions arithmétiques. Il utilise le **design pattern State** et gère des opérations telles que `+`, `*`, et les parenthèses.

## Fonctionnalités
- **Analyse syntaxique ascendante** basée sur une **table LALR(1)**.
- **Évaluation d'expressions arithmétiques** avec gestion des priorités (`*` avant `+`).
- **Gestion des erreurs syntaxiques** avec exceptions.
- **Tests automatisés et vérification des fuites mémoire** avec **Valgrind**.

## Compilation et exécution
```bash
make
./programme
make valgrind
