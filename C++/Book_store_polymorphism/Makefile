OBJ = main.o BMScontrol.o UImanager.o BookArray.o Course.o Product.o Book.o Computer.o Apparel.o Pen.o

a4:	$(OBJ)
	g++ -o a4 $(OBJ)

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

Book.o:	Book.cc Book.h Product.h defs.h
	g++ -c Book.cc

Product.o: Product.cc Product.h defs.h
	g++ -c Product.cc

Computer.o: Computer.cc Computer.h Product.h 
	g++ -c Computer.cc

Pen.o: Pen.cc Pen.h Product.h 
	g++ -c Pen.cc

Apparel.o: Apparel.cc Apparel.h Product.h
	g++ -c Apparel.cc

tar:
	tar -cvf a3.tar *.cc *.h Makefile README

clean:
	rm -f *.o a4


