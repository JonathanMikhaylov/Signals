compile: signal.c
	gcc signal.c
clean:
	rm *~	
	rm a.out
	rm signals
run: a.out
	./a.out
