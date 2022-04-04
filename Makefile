output: main.o input_mgmt.o generator.o opener.o dijkstra.o bfs.o
	gcc main.o input_mgmt.o generator.o opener.o dijkstra.o bfs.o -o output

.PHONY: clean

clean:
	-rm *.o output
