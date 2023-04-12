CXX = g++
EXEC = prog.out
CDB = gdb


SRCDIR = src 
BINDIR = bin
OBJDIR = obj
INCDIR = src/inc

CFLAGS = -I src/inc
CDBFLAGS = -q


ifeq ($(DEBUG),yes)
	CFLAGS += -ggdb
else
	CFLAGS += -DNDEBUG
endif 



all: $(EXEC)


run: $(EXEC)
ifeq ($(DEBUG),yes)
	@ $(CDB) $(CDBFLAGS) $(BINDIR)/$(EXEC)
else
	@ ./$(BINDIR)/$(EXEC)
endif

again: clean $(EXEC)


$(EXEC): main.o cube.o 
ifeq ($(DEBUG),yes)
	@ echo "Debug mode"
else
	@ echo "Release mode"
endif 
	@ $(CXX) -o $(BINDIR)/$(EXEC) $(OBJDIR)/cube.o $(OBJDIR)/main.o $(CFLAGS)


%.o: src/%.cpp
	@ $(CXX) -I $(INCDIR) -o $(OBJDIR)/$@ -c $<


clean:
	@ rm -rf $(BINDIR)/*.out
	@ rm -rf $(OBJDIR)/*.o



