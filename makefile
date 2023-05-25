CXX =g++
EXEC =main # fuck le debugger 
CFLAGS =
MAIN_OBJ =coord.o main.o


# debug mode 
ifeq ($(DEBUG), yes)
	CFLAGS +=-g -DEBUG
else
	CFLAGS +=
endif

all: $(EXEC)


# run exec 
run:
	@echo "Lancement du programme"
	@./$(EXEC)

# build exec 
$(EXEC): $(MAIN_OBJ)
ifeq ($(DEBUG), yes)
	@echo "Compilation en mode debug"
else
	@echo "Compilation en mode release"
endif
	$(CXX) -o $(EXEC) $(MAIN_OBJ) $(CFLAGS)

# object pattern 
%.o: %.cpp
	@$(CXX) -c $< -o $@

clean:
	@echo "Suppression des fichiers objets et de l'executable"
	@rm -f $(EXEC)
	@rm -f *.o