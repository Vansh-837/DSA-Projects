
infixeval:	Scanner.o Eval.o
	g++ -o infixeval Scanner.o Eval.o 

Scanner.o:	Scanner.cpp Scanner.h
	g++ -c Scanner.cpp 
	
Eval.o:	Eval.cpp Scanner.h Stack.h
	g++ -c Eval.cpp 
	
clean:	
	rm -f *.o infixeval

