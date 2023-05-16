CXX=clang-11
CXXFLAGS = -Wall -Wextra -g -O2
SRCDIR=src
BCDIR=bc
LLDIR=ll

KLEE_LIB=~/klee_build/lib

SRC=$(wildcard $(SRCDIR)/*.c)
BCS=$(patsubst $(SRCDIR)/%.c,$(BCDIR)/%.bc,$(SRC))
LLS=$(patsubst $(BCDIR)/%.bc,$(LLDIR)/%.ll,$(BCS))

.PHONY: clean all

all:  $(BCS) $(LLS)

$(BCDIR)/%.bc: $(SRCDIR)/%.c | $(BCDIR)
	$(CXX) $(CXXFLAGS) -emit-llvm -c $< -o $@

$(LLDIR)/%.ll: $(BCDIR)/%.bc | $(LLDIR)
	llvm-dis-11 $< -o $@

$(BCDIR):
	mkdir $(BCDIR)
$(LLDIR):
	mkdir $(LLDIR)

clean:
	rm -rf $(BCDIR)/*.bc $(LLDIR)/*.ll
	rm -r $(BCDIR) $(LLDIR)
