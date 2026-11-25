CFLAGS += -W -Wall -Wextra -g -Werror -fsanitize=address
CC = g++
OBJ = ueb02.o caddress.o cdate.o clocation.o cperson.o ctime.o 
OBJ_3 = ueb03.o caddress.o cdate.o clocation.o cperson.o ctime.o cmedium.o clibrary.o clibrarypool.o

ueb03: $(OBJ_3) 
	$(CC) $(CFLAGS) -o ueb03 $(OBJ_3)

ueb03.o: ueb03.cpp
	$(CC) $(CFLAGS) -c ueb03.cpp

cmedium.o: cmedium.cpp cmedium.h
	$(CC) $(CFLAGS) -c cmedium.cpp

clibrary.o: clibrary.cpp clibrary.h
	$(CC) $(CFLAGS) -c clibrary.cpp
	
clibrarypool.o: clibrarypool.cpp clibrarypool.h
	$(CC) $(CFLAGS) -c clibrarypool.cpp


ueb02: $(OBJ)
	$(CC) $(CFLAGS) -o ueb02 $(OBJ)

ueb02.o: ueb02.cpp 
	$(CC) $(CFLAGS) -c ueb02.cpp

caddress.o: caddress.cpp caddress.h
	$(CC) $(CFLAGS) -c caddress.cpp

cdate.o: cdate.cpp cdate.h
	$(CC) $(CFLAGS) -c cdate.cpp

clocation.o: clocation.cpp clocation.h
	$(CC) $(CFLAGS) -c clocation.cpp

cperson.o: cperson.cpp cperson.h
	$(CC) $(CFLAGS) -c cperson.cpp

ctime.o: ctime.cpp ctime.h
	$(CC) $(CFLAGS) -c ctime.cpp

tools.o: tools.cpp tools.h
	$(CC) $(CFLAGS) -c tools.cpp

clean:
	rm -f *.o ueb03 ueb02 ueb04
