CXX = g++
EXEC = prog.out


SRCDIR = src 
BINDIR = bin
OBJDIR = obj
INCDIR = src/inc


all: $(EXEC)


run: $(EXEC)
	./$(BINDIR)/$(EXEC)


$(EXEC): main.o cube.o 
	$(CXX) -o $(BINDIR)/$(EXEC) $(OBJDIR)/cube.o $(OBJDIR)/main.o 


%.o: src/%.cpp
	$(CXX) -I $(INCDIR) -o $(OBJDIR)/$@ -c $<


clean:
	rm -rf $(BINDIR)/*.out
	rm -rf $(OBJDIR)/*.o



