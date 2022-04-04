output: main.o input_mgmt.o generator.o opener.o dijkstra.o
	gcc main.o input_mgmt.o generator.o opener.o dijkstra.o -o output

.PHONY: clean

clean:
	-rm *.o output
