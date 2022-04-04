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
    graph temporarygraph; //struktura graf do której będą umieszczane dane
    graph* temporarypointer; //zwracany wskaźnik na graf
    temporarygraph.columns = 0;
    temporarygraph.rows = 0;
    temporarygraph.list = NULL;
    temporarypointer = NULL;
    temporarypointer = malloc(sizeof(graph));
    *(temporarypointer) = temporarygraph;
    pair_list *head; //Wskaźnik na początek listy wewnątrz struktury graph
    char textline[512]; //Tutaj zapisywane są litery
    int character = 0; //Zmienna przechowująca wynik fgetc()
    int columns = 0; //Zmienna przechowująca liczbę kolumn z pliku
    int rows = 1; //Zmienna przechowująca liczbę wierszy z pliku
    int index = 0; //Zmienna iterująca po textline
    double length; //Długość krawędzi między węzłami
    int vnumber; //Numer węzła do którego skierowana jest krawędź
    static int loophelper = 0; //zmienna licząca ile razy przeszła pętla while
    int licznik = 0; //zmienna która liczy ile rzeczy jest na liście

    while (character != SPACE) //Początek wczytywania liczby rzędów
    {
      character = fgetc(inf);
      textline[index] = (char)character;
      index++;
    }
    index =0;
    temporarypointer->rows = atoi(textline); //Koniec wczytywania liczby rzędów
    printf("Liczba wierszy: %d\n", temporarypointer->rows);
    while (character != ENTER) //Początek wczytywania liczby kolumn
    {
      character = fgetc(inf);
      textline[index] = (char)character;
      index++;
    }
    temporarypointer->columns = atoi(textline); //Koniec wczytywania liczby kolumn
    printf("Liczba kolumn: %d\n", temporarypointer->columns);
    character = 0;
    index = 0;
    int vortexnumber = 0; //Zmienna przechowująca informacje OD którego węzła prowadzona jest krawędź
    while (!feof(inf)) //Pętla wczytująca dane dotyczące węzłów i długości między nimi
    {

      while (character != ENTER && character != '\t')
      {
        pair_list temporarylist;
        character = 0;
        index = 0;
        licznik = 0
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
        //Tu zaczyna się zapisywanie do listy które nie działa
        while (temporarypointer->list != NULL)
          {
            temporarypointer->list = temporarypointer->list->next;
            licznik++;
            printf("Licznik: %d\n",licznik);
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
          //Tu kończy się zapisywanie do listy które nie działa
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
