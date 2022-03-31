output: main.o input_mgmt.o generator.o opener.o
	gcc main.o input_mgmt.o generator.o opener.o -o output

.PHONY: clean

clean:
	-rm *.o output
