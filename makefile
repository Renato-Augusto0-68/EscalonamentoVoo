EscalonamentoVoo: main.o
				gcc main.o -o EscalonamentoVoo

main.o: main.c
	gcc -c main.c

run: EscalonamentoVoo
	./EscalonamentoVoo

clean:
	rm -f *.o a.out *.pgm EscalonamentoVoo

PHONY: run clean
