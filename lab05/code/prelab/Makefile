CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=TreeCalc.o TreeNode.o TreeCalcTest.o

TreeCalc: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeNode.o: TreeNode.cpp TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
