#include "opener.h"
#include "generator.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef SPACE
#define SPACE 32
#endif

#ifndef ENTER
#define ENTER 10
#endif

#ifndef COLON
#define COLON 58
#endif

void readnumber(char* textline, int i)
{
    //index od i do dwokropka
}

graph* file_open(FILE *inf)
{
    graph temporarygraph;
    temporarygraph.columns = 0;
    temporarygraph.rows = 0;
    temporarygraph.list = NULL;
    graph *temporarypointer = malloc(sizeof(graph));
    char textline[128];
    int character = 0;
    char *ch_columns = NULL;
    char *ch_rows = NULL;
    int columns = 0;
    int rows = 1;
    int index = 0;
    double length;
    int vnumber;

    while (character != SPACE)
    {
      character = fgetc(inf);
      textline[index] = (char)character;
      index++;
      printf("character: %d\n", character);
    }
    index =0;
    temporarygraph.rows = atoi(textline);
    printf("Liczba wierszy: %d\n", temporarygraph.rows);
    while (character != ENTER)
    {
      character = fgetc(inf);
      textline[index] = (char)character;
      index++;
      printf("character: %d\n", character);
    }
    temporarygraph.columns = atoi(textline);
    printf("Liczba kolumn: %d\n", temporarygraph.columns);
    character = 0;
    index = 0;
    //for (int vortexnumber = 0; vortexnumber < temporarygraph.columns * temporarygraph.rows; vortexnumber++)
    int vortexnumber = 0;
    while(!feof(inf))
    {
      printf("%d\n", vortexnumber);
      while (character != ENTER)
      {
        index = 0;
        while (character != COLON)
        {
          character = fgetc(inf);
          textline[index] = (char)character;
          index++;
        }
        vnumber = atoi(textline);
        index = 0;
        while (character != SPACE)
        {
          character = fgetc(inf);
          textline[index] = (char)character;
          index++;
        }
        length = atof(textline);
        pair_list *head = temporarygraph.list;
        pair_list temporarylist;

        while (temporarygraph.list != NULL)
        {
          temporarygraph.list = temporarygraph.list->next;
        }
        temporarygraph.list = malloc(sizeof(pair_list));
        temporarylist.node = vnumber;
        temporarylist.path = length;
        temporarylist.next = NULL;
        *(temporarygraph.list) = temporarylist;
        temporarygraph.list = head;
        printf("dupa1\n");
        if (temporarypointer->list == NULL) {
          printf("aaa\n");
        }
      }
      vortexnumber++;
    }
    /*while ((c = fgetc(inf)) != EOF) // nie usuwac!
    {
        fputc(c, inf);

        if(c != '\n')
        {
            printf("%c", c);
        }
        else
        {
            printf("%c %d",  c, i);
            i++;
        }
    }*/
    *temporarypointer = temporarygraph;
    return temporarypointer;
}
void deallocate_graph(graph* redundantgraph)
{
  pair_list* auxiliarypointer;
  while(redundantgraph->list != NULL)
  {
    auxiliarypointer = redundantgraph->list;
    redundantgraph->list = redundantgraph->list->next;
    free(redundantgraph->list);
  }
  free(redundantgraph);
}
void showgraph(graph* testedgraph)
{
  while(testedgraph->list != NULL)
  {
    printf("Numer wezla: %d\nDlugosc sciezki: %f\n", testedgraph->list->node, testedgraph->list->path);
  }
}
