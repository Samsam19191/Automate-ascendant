# Nom de l'exécutable
EXEC = programme

# Fichiers sources
SRC = main.cpp symbole.cpp lexer.cpp expr.cpp automate.cpp etats.cpp

# Fichiers objets
OBJ = $(SRC:.cpp=.o)

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++17

# Règle principale
all: $(EXEC)

# Création de l'exécutable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@
	rm -f $(OBJ)  # Suppression des fichiers objets après la compilation

# Compilation des fichiers sources en fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJ) $(EXEC)

# Nettoyage avancé
mrproper: clean
	rm -f *~

# Exécution de Valgrind pour détecter les fuites de mémoire
valgrind: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC)

.PHONY: all clean mrproper
