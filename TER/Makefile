CXX = @g++
CFLAGS = 
SUPPR = @rm -f
EXEC = TER
FSRC = src/
FINC = include/
SRC = main.cpp $(FSRC)/*.cpp 
OBJ = $(SRC: .cpp=.o)

all: $(EXEC)
	./$(EXEC)

compil: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $^

Planification.o: $(FSRC)Planification.cpp $(FINC)Planification.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Bus.o: $(FSRC)Bus.cpp $(FINC)Bus.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Algo.o: $(FSRC)Algo.cpp $(FINC)Algo.h
	$(CXX) -o $@ -c $< $(CFLAGS)

IO.o: #(FSRC)IO.cpp $(FINC)IO.h
	£(CXX) -o $@ -c $< $(CFLAGS)

main.o: main.cpp $(FINC)Salle.h $(FINC)Etudiant.h $(FINC)Enseignant.h $(FINC)Contraintes.h $(FINC)Planification.h $(FINC)Bus.h $(FINC)Algo.h
	$(CXX) -o $@ -c $< $(CFLAGS)

clean: 
	$(SUPPR) *.o
	$(SUPPR) $(EXEC)