################
### Makefile ###
################

CXX = @g++
CFLAGS = 
SUPPR = @rm -f
EXEC = TER
FSRC = src/
FINC = include/
SRC = main.cpp src/Lesson.cpp src/Room.cpp src/Students.cpp src/Teacher.cpp
OBJ = $(SRC: .cpp=.o)

all: $(EXEC)
	./$(EXEC)

compil: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $^

Lesson.o: $(FSRC)Lesson.cpp $(FINC)Lesson.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Room.o: $(FSRC)Room.cpp $(FINC)Room.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Students.o: $(FSRC)Students.cpp $(FINC)Students.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Teacher.o: $(FSRC)Teacher.cpp $(FINC)Teacher.h
	$(CXX) -o $@ -c $< $(CFLAGS)

main.o: main.cpp $(FINC)Room.h $(FINC)Students.h $(FINC)Teacher.h
	$(CXX) -o $@ -c $< $(CFLAGS)

clean: 
	$(SUPPR) *.o
	$(SUPPR) $(EXEC)