output: main.o input_mgmt.o
	gcc main.o input_mgmt.o -o output

.PHONY: clean

clean:
	-rm *.o output
