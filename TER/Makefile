################
### Makefile ###
################

CXX = @g++
CFLAGS = 
SUPPR = @rm -f
EXEC = TER
FSRC = src/
FINC = include/
SRC = main.cpp src/Cours.cpp src/Salle.cpp src/Etudiant.cpp src/Enseignant.cpp src/Contraintes.cpp src/Planification.cpp src/Bus.cpp src/Algo.cpp
OBJ = $(SRC: .cpp=.o)

all: $(EXEC)
	./$(EXEC)

compil: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $^

Cours.o: $(FSRC)Cours.cpp $(FINC)Cours.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Salle.o: $(FSRC)Salle.cpp $(FINC)Salle.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Etudiant.o: $(FSRC)Etudiant.cpp $(FINC)Etudiant.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Enseignant.o: $(FSRC)Enseignant.cpp $(FINC)Enseignant.h
	$(CXX) -o $@ -c $< $(CFLAGS)
	
Contraintes.o: $(FSRC)Contraintes.cpp $(FINC)Contraintes.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Planification.o: $(FSRC)Planification.cpp $(FINC)Planification.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Bus.o: $(FSRC)Bus.cpp $(FINC)Bus.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Algo.o: $(FSRC)Algo.cpp $(FINC)Algo.h
	$(CXX) -o $@ -c $< $(CFLAGS)

main.o: main.cpp $(FINC)Salle.h $(FINC)Etudiant.h $(FINC)Enseignant.h $(FINC)Contraintes.h $(FINC)Planification.h $(FINC)Bus.h $(FINC)Algo.h
	$(CXX) -o $@ -c $< $(CFLAGS)

clean: 
	$(SUPPR) *.o
	$(SUPPR) $(EXEC)
