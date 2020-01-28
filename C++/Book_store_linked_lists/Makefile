OBJ = main.o BMScontrol.o UImanager.o BookArray.o Course.o Book.o Dlist.cc

a2:	$(OBJ)
	g++ -o a2 $(OBJ)

main.o:	main.cc
	g++ -c main.cc

BMScontrol.o:	BMScontrol.cc BMScontrol.h defs.h
	g++ -c BMScontrol.cc

UImanager.o:	UImanager.cc UImanager.h 
	g++ -c UImanager.cc

BookArray.o:	BookArray.cc BookArray.h Book.h
	g++ -c BookArray.cc

Course.o:	Course.cc Course.h defs.h
	g++ -c Course.cc

Book.o:	Book.cc Book.h defs.h
	g++ -c Book.cc

Dlist.o: Dlist.cc Dlist.h 
	g++ -c Dlist.cc

clean:
	rm -f *.o a1

