# Nom de l'exécutable
EXEC = programme

# Fichiers sources
SRC = main.cpp symbole.cpp lexer.cpp expr.cpp automate.cpp

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

clean:
	rm -f $(OBJ) $(EXEC)

# Nettoyage avancé
mrproper: clean
	rm -f *~

.PHONY: all clean mrproper
