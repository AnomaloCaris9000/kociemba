CXX = g++
EXEC = prog.out


SRCDIR = src 
BINDIR = bin
OBJDIR = obj
INCDIR = src/inc


all: $(EXEC)


run: $(EXEC)
	./$(BINDIR)/$(EXEC)


$(EXEC): main.o
	$(CXX) -o $(BINDIR)/$(EXEC) $(OBJDIR)/main.o


%.o: src/%.cpp
	$(CXX) -I $(INCDIR) -o $(OBJDIR)/$@ -c $<


clean:
	rm -rf $(BINDIR)/*.out
	rm -rf $(OBJDIR)/*.o



