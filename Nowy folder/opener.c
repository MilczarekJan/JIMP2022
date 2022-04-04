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

graph* file_open(FILE *inf)
{
    graph temporarygraph;
    graph* temporarypointer;
    temporarygraph.columns = 0;
    temporarygraph.rows = 0;
    temporarygraph.list = NULL;
    temporarypointer = NULL;
    temporarypointer = malloc(sizeof(graph));
    *(temporarypointer) = temporarygraph;
    pair_list *head;
    char textline[512];
    int character = 0;
    int columns = 0;
    int rows = 1;
    int index = 0;
    double length;
    int vnumber;
    static int loophelper = 0;

    while (character != SPACE)
    {
      character = fgetc(inf);
      textline[index] = (char)character;
      index++;
    }
    index =0;
    temporarypointer->rows = atoi(textline);
    printf("Liczba wierszy: %d\n", temporarypointer->rows);
    while (character != ENTER)
    {
      character = fgetc(inf);
      textline[index] = (char)character;
      index++;
    }
    temporarypointer->columns = atoi(textline);
    printf("Liczba kolumn: %d\n", temporarypointer->columns);
    character = 0;
    index = 0;
    int vortexnumber = 0;
    while (!feof(inf))
    {
      pair_list temporarylist;
      while (character != ENTER && character != '\t')
      {
        character = 0;
        index = 0;
        while (character != COLON)
        {
          character = fgetc(inf);
          textline[index] = (char)character;
          index++;
        }
        vnumber = atoi(textline);
        index = 0;
        while (character != SPACE && character != ENTER)
        {
          character = fgetc(inf);
          textline[index] = (char)character;
          index++;
        }
        length = atof(textline);
        printf("%d\n", vortexnumber);
        printf("Wezel: %d Dlugosc: %f\n", vnumber, length);
        while (temporarypointer->list != NULL)
          {
            temporarypointer->list = temporarypointer->list->next;
          }
          temporarypointer->list = malloc(sizeof(pair_list));
          if (loophelper == 0)
          {
            head = temporarypointer->list;
          }
          temporarylist.startnode = vortexnumber;
          temporarylist.endnode = vnumber;
          temporarylist.path = length;
          temporarylist.next = NULL;
          *(temporarypointer->list) = temporarylist;
          character = fgetc(inf);
          loophelper++;
      }
      character = fgetc(inf);
      character = fgetc(inf);
      //Początek błędu

      //koniec błędu
      vortexnumber++;
    }
    temporarypointer->list = head;
    return temporarypointer;
}
void deallocate_graph(graph* redundantgraph)
{
  //Początek błędu
  pair_list* auxiliarypointer;
  while(redundantgraph->list != NULL)
  {
    auxiliarypointer = redundantgraph->list;
    redundantgraph->list = redundantgraph->list->next;
    free(auxiliarypointer);
  }
  //Koniec błędu
  free(redundantgraph);
}
void showgraph(graph* testedgraph)
{
  printf("dupa3\n");
  pair_list* head = testedgraph->list;
  while(testedgraph->list != NULL)
  {
    printf("Numer wezla poczatkowego: %d\nNumer wezla koncowego: %d\nDlugosc sciezki: %f\n", testedgraph->list->startnode,testedgraph->list->endnode, testedgraph->list->path);
    testedgraph->list = testedgraph->list->next;
  }
  testedgraph->list = head;
}
