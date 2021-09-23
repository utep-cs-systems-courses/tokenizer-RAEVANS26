#include "history.h"
#include "tokenizer.h"
#include <stdio.h>
#include "malloc.h"

List *init_history()
{
    List *list = malloc( sizeof( List));
    (*list).root=malloc(sizeof(Item));
    return list;
}

int str_length(char *str)//returns length of string with spaces included
{
  short length = 0;
  int i;
  for (i = 0; *(str+i) != '\0'; i++) {
    length += 1; 
  }
  return length;
}

void add_history(List *list, char *str)//adds string to history list
{
    
    Item *newStr = malloc(sizeof(Item));
    (*newStr).word =  copy_str(str,str_length(str));
    if ((*(*list).root).word == NULL)// will store string in head of list is head is empty 
    { 
        (*newStr).id = 1;
        (*list).root = newStr;
    }
    else{
        int pos = 2;//stores string and records position of next empty node in list 
        Item *tmp = (*list).root;
        while((*tmp).next){
            tmp = (*tmp).next;
            pos++;
        }
        (*newStr).id = pos;
        (*tmp).next = newStr;
    }
}

char *get_history(List *list, int id)//returns stored sentence of node where id equals node position
{
    Item *tmp = (*list).root;
    if ((*tmp).word == NULL){//returns empty string if there is no history
        printf("History is empty, please enter some sentences.\n");
        return "";
        }
    
    while (tmp!=NULL){
        
    
        if ((*tmp).id==id){
            return (*tmp).word;
        }
        tmp=(*tmp).next;
    }
    printf("No history saved at that index.");//returns empty string if there is no history at position
    return "";
}

void print_history(List *list)//prints all sentences stored in history
{
    Item *tmp = (*list).root;
    if (tmp == NULL){//returns empty string if there is no history
        printf("History is empty, please enter some sentences.\n");
    }
    else{
        while(tmp!=NULL){
            printf("%d: %s",(*tmp).id,(*tmp).word);
            tmp = (*tmp).next;
        }
        printf("\n");
    }
}

void free_history(List *list)//cleans history to free memory 
{
    Item *tmp;
    Item *head = (*list).root;
    while(head){
        tmp = head;
        head = (*head).next;
        free(tmp);
    }
    free(list);
}


