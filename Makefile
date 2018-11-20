output: privatevault.o
	gcc privatevault.o -o output

privatevault.o: privatevault.c
	gcc -c privatevault.c

clean:
	rm *.o output
