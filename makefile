scheduler: main.c
				gcc main.c -o scheduler

run: scheduler
	./scheduler

clean:
	rm -f *.o *.out *.pgm scheduler

.PHONY: run clean
