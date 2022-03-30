output: main.o input_mgmt.o generator.o
	gcc main.o input_mgmt.o generator.o -o output

.PHONY: clean

clean:
	-rm *.o output
