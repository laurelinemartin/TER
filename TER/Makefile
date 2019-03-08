################
### Makefile ###
################

CXX = g++
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

Lesson.o: $(FSRC)Lesson.cpp include/Lesson.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Room.o: $(FSRC)Room.cpp include/Room.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Students.o: $(FSRC)Students.cpp include/Students.h
	$(CXX) -o $@ -c $< $(CFLAGS)

Teacher.o: $(FSRC)Teacher.cpp include/Teacher.h
	$(CXX) -o $@ -c $< $(CFLAGS)

main.o: main.cpp include/Room.h include/Students.h include/Teacher.h
	$(CXX) -o $@ -c $< $(CFLAGS)

clean: 
	$(SUPPR) *.o
	$(SUPPR) $(EXEC)