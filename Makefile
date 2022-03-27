output: main.o input_errors.o
	gcc main.o input_errors.o -o output

.PHONY: clean

clean:
	-rm *.o output
