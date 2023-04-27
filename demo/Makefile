CXX=clang++-11
CXXFLAGS = -Wall -Wextra -g -O2
SRCDIR=src
BINDIR=bin
BCDIR=bc
LLDIR=ll

SRC=$(wildcard $(SRCDIR)/*.cpp)
EXE=$(patsubst $(SRCDIR)/%.cpp, $(BINDIR)/%, $(SRC))
BCS=$(patsubst $(SRCDIR)/%.cpp,$(BCDIR)/%.bc,$(SRC))
LLS=$(patsubst $(BCDIR)/%.bc,$(LLDIR)/%.ll,$(BCS))

.PHONY: clean all

all: $(EXE) $(BCS) $(LLS)

$(BINDIR)/%: $(SRCDIR)/%.cpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) $< -lkleeRuntest -o $@

$(BCDIR)/%.bc: $(SRCDIR)/%.cpp | $(BCDIR)
	$(CXX) $(CXXFLAGS) -emit-llvm -c $< -o $@

$(LLDIR)/%.ll: $(BCDIR)/%.bc | $(LLDIR)
	llvm-dis $< -o $@

$(BINDIR):
	mkdir $(BINDIR)
$(BCDIR):
	mkdir $(BCDIR)
$(LLDIR):
	mkdir $(LLDIR)

clean:
	rm -rf $(BINDIR)/*.exe $(BCDIR)/*.bc $(LLDIR)/*.ll
	rm -r $(BINDIR) $(BCDIR) $(LLDIR)
