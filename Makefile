CXX = g++ # compilateur
CFLAGS = -Wall #options de compilation (debug par exemple)
LDFLAGS = #options de link (librairies)
 
SRC = $(wildcard *.cpp) # création automatique de la liste des sources
OBJ = $(SRC:.cpp=.o)
 
OUTPUT = test # nom du programme
 
all: $(OBJ)
	$(CXX) $(LDFLAGS) -o $(OUTPUT) $^
 
$(OBJ): %.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
 
 
.PHONY: clean mrproper
 
clean:
	rm -rf *.o
 
mrproper: clean
	rm -rf $(OUTPUT)