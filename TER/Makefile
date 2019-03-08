################
### Makefile ###
################

CXX = @g++
CFLAGS = 
SUPPR = @rm -f
EXEC = TER
FSRC = src/
FINC = include/
SRC = main.cpp src/Cours.cpp src/Salle.cpp src/Eleve.cpp src/Enseignant.cpp
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

Eleve.o: $(FSRC)Eleve.cpp $(FINC)Eleve.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Enseignant.o: $(FSRC)Enseignant.cpp $(FINC)Enseignant.h
	$(CXX) -o $@ -c $< $(CFLAGS)

main.o: main.cpp $(FINC)Salle.h $(FINC)Eleve.h $(FINC)Enseignant.h
	$(CXX) -o $@ -c $< $(CFLAGS)

clean: 
	$(SUPPR) *.o
	$(SUPPR) $(EXEC)