BIN:=contact
OBJ:=main.o app.o contactbook.o contact.o table.o 
$(BIN): $(OBJ)
	g++ -fexec-charset=GBK -static -g -o $(BIN) $(OBJ)
main.o: main.cpp app.h contact.h contactbook.h table.h
	g++ -fexec-charset=GBK -static -g -c main.cpp
app.o: app.cpp app.h contact.h contactbook.h table.h
	g++ -fexec-charset=GBK -static -g -c app.cpp
contactbook.o: contactbook.h contactbook.cpp contact.h table.h 
	g++ -fexec-charset=GBK -static -g -c contactbook.cpp
contact.o: contact.cpp contact.cpp
	g++ -fexec-charset=GBK -static -g -c contact.cpp
table.o: table.h table.cpp
	g++ -fexec-charset=GBK -static -g -c table.cpp
