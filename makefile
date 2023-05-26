CXX =g++
EXEC =prog.out # fuck le debugger 
MAIN_OBJ = obj/coord.o obj/cubie.o obj/facelet.o obj/cube.o obj/main.o

OBJDIR = obj
SRCDIR = src
INCDIR = src/inc 

CFLAGS = -Wall
LDFLAGS = -I $(INCDIR)


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
	@ $(CXX) -o $(EXEC) $(MAIN_OBJ) $(CFLAGS)

# object pattern 
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@ echo +$@
	@ $(CXX) -c $< -o $@ $(LDFLAGS)

clean:
	@echo "Suppression des fichiers objets et de l'executable"
	@rm -f $(EXEC)
	@rm -f $(OBJDIR)/*.o


$(SRCDIR)/%.cpp: $(INCDIR)/%.hpp