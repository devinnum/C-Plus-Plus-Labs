CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=AVLTree.o AVLNode.o AVLPathTest.o

AVLTree: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)

AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h

AVLNode.o: AVLNode.cpp AVLNode.h

AVLPathTest.o: AVLPathTest.cpp AVLTree.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
