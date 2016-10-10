#include <stdio.h>
#include <stdlib.h>

struct node{
  int i;
  struct node *next;
};

void print_list(struct node *p){
  printf("list = ");
  while(p){
    printf("%d ",(*p).i);
    p = (*p).next;
  }
  printf("\n\n");
}

struct node * insert_front(int data, struct node *p){
  struct node *new = (struct node *) malloc(sizeof(struct node));
  (*new).i = data;
  (*new).next = p;
  return new;
} 

struct node * free_list(struct node *p){
  struct node *new = p;
  while (new){
    free(new);
    new = (*new).next;
  }
  return p;
}


int main(){
  struct node *a = (struct node *) malloc(sizeof(struct node));
  (*a).i = 1;
  (*a).next = NULL;
  printf("Testing print_list :\n");
  print_list(a);

  printf("Testing insert_front :\n");
  printf("inserting a 5 in front of the previous list\n");
  a = insert_front(5,a);
  print_list(a);
  printf("inserting a 4 in front of the previous list\n");
  a = insert_front(4,a);
  print_list(a);

  printf("Testing free_list : \n");
  print_list(free_list(a));;  
  
  return 0;
}


