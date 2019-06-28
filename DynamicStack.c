#include "DynamicStack.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct lista_no Lista_no;

struct lista_no{
 struct aluno dado;
 Lista_no *prox;
};


struct stack{
    Lista_no *top;
    int size;
};


Stack* stack_create(){
    Stack *st;
    st = malloc(sizeof(Stack));
    if(st != NULL){
        st->top = NULL;
        st->size = 0;
    }
    return st;
}

void stack_free(Stack* li){
    if(li != NULL){
        Lista_no *p;
        while(li->top != NULL){
            p = li->top;
            li->top = li->top->prox;
            free(p);
        }
    free(li);
    }
}


int stack_push(Stack* li, struct aluno al){
    if(li == NULL)
        return NULA;
    Lista_no *elemento = malloc(sizeof(Lista_no));
    if(elemento == NULL)
        return OUT_OF_MEMORY;
    elemento->dado = al;
    if(li->top == NULL){
        li->top = elemento;
        elemento->prox = NULL;
        li->size++;
        return SUCCESS;
    }
    else{
        elemento->prox = li->top;
        li->top = elemento;
        li->size++;
        return SUCCESS;
    }
}


int stack_pop(Stack* li){
    if(li == NULL)
        return NULA;
    Lista_no *p = NULL;
    p = li->top;
    li->top = p->prox;
    free(p);
    li->size--;
    return SUCCESS;
}

int stack_top(Stack *st, struct aluno *al){
    if(st == NULL)
        return NULA;
    if(st->size == 0)
        return ELEM_NOT_FOUND;
    *al = st->top->dado;
    return SUCCESS;
}


int stack_size(Stack* li){
    if(li == NULL)
        return NULA;
    if(li->top == NULL)
        return 0;
    return li->size;
}


int stack_empty(Stack* li){
    if(li == NULL)
        return NULA;
    if(li->top == NULL){
        return 1;
    }else{
        return 0;
    }
}

