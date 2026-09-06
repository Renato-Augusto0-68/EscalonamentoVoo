scheduler: main.c
				gcc main.c -o scheduler

run: scheduler
	./scheduler

clean:
	rm -f *.o *.txt *.out *.pgm scheduler

.PHONY: run clean
