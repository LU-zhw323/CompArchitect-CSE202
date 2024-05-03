AFLAGS=-g -o
CFLAGS=-g -c -Wall -Wextra -Wwrite-strings
LFLAGS=-g

a.out: prog1.o fn1arg.o fn2args.o fn3args.o fn6args.o fn8args.o
	gcc ${LFLAGS} prog1.o fn1arg.o fn2args.o fn3args.o fn6args.o fn8args.o

prog1.o: prog1.c 
	gcc ${CFLAGS} prog1.c

fn1arg.o: fn1arg.S
	as ${AFLAGS} fn1arg.o fn1arg.S

fn2args.o: fn2args.S
	as ${AFLAGS} fn2args.o fn2args.S

fn3args.o: fn3args.S
	as ${AFLAGS} fn3args.o fn3args.S

fn6args.o: fn6args.S
	as ${AFLAGS} fn6args.o fn6args.S

fn8args.o: fn8args.S
	as ${AFLAGS} fn8args.o fn8args.S

clean:
	rm -rf a.out
	rm -rf prog1.o 
	rm -rf fn?arg*.o 
