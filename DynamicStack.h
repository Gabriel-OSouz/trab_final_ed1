#ifndef DynamicStack_H
#define DynamicStack_H

#define SUCCESS 0
#define OUT_OF_MEMORY -1
#define ELEM_NOT_FOUND -2
#define NULA -3
#define NOT_FULL -4

struct aluno {
  int x;
  int y;
};


typedef struct stack Stack;

Stack *stack_create();
void stack_free(Stack *st);

int stack_push(Stack *st, struct aluno al);
int stack_pop(Stack *st);
int stack_top(Stack *st, struct aluno *al);
int stack_empty(Stack *st);
int stack_size(Stack *st);
#endif