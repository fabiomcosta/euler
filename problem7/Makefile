all: main

fmath: ../lib/fmath.o

main: main.o ../lib/fmath.o

run:
	./main ${args}

clean:
	@rm -f main
	@rm -f *.o
	@echo "cleaned problem7."
