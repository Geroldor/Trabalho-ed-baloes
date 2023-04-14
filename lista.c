#include "lista.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct StNode{
  char* type;
  Item info;  
  struct StNode *prox, *ant;
} Node;

typedef struct StLista{
  Node *prim; 
  Node *ult;
  int capac;
  int length;
} ListaImpl;

struct StIterator{
  Node *curr;
  bool reverso;
};

typedef struct StIterator IteratorImpl;

Lista createLst(int capacidade){
  ListaImpl *newLista = (ListaImpl *) malloc (sizeof(ListaImpl));
  newLista->prim = NULL;
  newLista->ult = NULL;
  newLista->capac = capacidade;
  newLista->length = 0;
  return newLista;
}

int lengthLst(Lista L){
  ListaImpl *lst = ( ListaImpl *)L;
  return lst->length;
}


int maxLengthLst(Lista L){
  ListaImpl *lst = ( ListaImpl *)L;
  return lst->capac;
}


bool isEmptyLst(Lista L){
  ListaImpl *lst = ( ListaImpl *)L;
  return lst->length == 0;
}


bool isFullLst(Lista L){
  ListaImpl *lst = ( ListaImpl *)L;
  return lst->length == lst->capac;
}

Posic insertLst(Lista L, Item info, char* type){
  ListaImpl *lst = ( ListaImpl *)L;
  Node *newNode = (Node *) malloc (sizeof(Node));
  newNode->info = info;
  newNode->prox = NULL;
  newNode->type = type;
  if (isEmptyLst(L)){
    lst->prim = newNode;
  }
  else{
    lst->ult->prox = newNode;
  }    
  newNode->ant = lst->ult;
  lst->ult = newNode;
  lst->length++;
  return lst->ult;
}

Item popLst(Lista L){
  ListaImpl *lst = (ListaImpl *)L;
  if(isEmptyLst(L)){
    return NULL;
  }
  Item item = lst->prim->info;
  Node *paux;
  paux = lst->prim;
  lst->prim = paux->prox;
  if(paux->prox == NULL){
    // lista vai ficar vazia
    lst->ult = NULL;
  }
  else{
    paux->prox->ant = NULL;
  }
  lst->length--;
  return item;
}

void removeLst(Lista L, Posic p){
  ListaImpl *lst = (ListaImpl *)L;
  Node *paux = (Node *)p;
  Node *paux2 = paux->ant;
  Node *paux3 = paux->prox;
  paux2->prox = paux3;
  paux3->ant = paux2;
}


Item getLst(Posic p){
  Node *pen = p;
  if (pen == NULL)
  {
    return NULL;
  } 
  return pen->info;
}

Posic insertBefore(Lista L, Posic p, Item info, char* type){
  ListaImpl *lst = ( ListaImpl *)L;
  Node *paux = lst->prim;
  Node *paux2 = p;
   Node *newNode = (Node *) malloc (sizeof(Node));
  while (true)
  {
    if ((paux->prox == paux2) && (paux->prox != NULL)){
      
      newNode->info = info;
      newNode->type = type;
      newNode->prox = paux2;
      newNode->ant = getPreviousLst(paux2);
      paux->prox = newNode;
      lst->length++;
      break;
    }
    else{
      paux = paux->prox;
    }
  }
  return newNode;
}

Posic insertAfter(Lista L, Posic p, Item info, char* type){
 ListaImpl *lst = ( ListaImpl *)L;
  Node *paux = lst->prim;
  Node *paux2 = p;
  Node *newNode = (Node *) malloc (sizeof(Node));
  while (true)
  {
    if ((paux->ant == paux2) && (paux->ant != NULL)){
      
      newNode->info = info;
      newNode->type = type;
      newNode->prox = getNextLst(paux2);
      newNode->ant = paux2;
      paux->prox = newNode;
      lst->length++;      
      break;
    }
    else{
      paux = paux->prox;
    }
  }
  return newNode;
}

Posic getFirstLst(Lista L){
  ListaImpl *lst = ( ListaImpl *)L;
  return lst->prim;
}

Posic getNextLst(Posic p){
  Node *paux = p;
  if(paux == NULL) return NULL;
  return paux->prox;
  
}

Posic getLastLst(Lista L){
  ListaImpl *lst = ( ListaImpl *)L;
  return lst->ult;
}

Posic getPreviousLst(Posic p){
  Node *paux = (Node *)p;
  return paux->ant;
  
}

void killLst(Lista L){
  ListaImpl *lst = ( ListaImpl *)L;
  Node *paux;
  while (lst->prim != NULL){
    paux = lst->prim;
    lst->prim = paux->prox;
    free(paux);
  }
  free(lst);
}

/*
 * Iterador
 */

Iterador createIterador(Lista L, bool reverso){
  ListaImpl *lst = ( ListaImpl *)L;
  IteratorImpl *it = (IteratorImpl *) malloc (sizeof(IteratorImpl));
  it->curr = lst->prim;
  it->reverso = reverso;
  return it;
}

bool isIteratorEmpty(Iterador it){
  IteratorImpl *itimpl = (IteratorImpl *)it;
  return itimpl->curr == NULL;
}
Item getIteratorNext(Iterador it){
   IteratorImpl *itimpl = (IteratorImpl *)it;
   Item valor =itimpl->curr->info;
   if (itimpl->reverso){
     itimpl->curr = (Node *)getPreviousLst(itimpl->curr);
   }
   else{
     itimpl->curr = (Node *)getNextLst(itimpl->curr);
   }
   return valor;
 }

void killIterator(Iterador it){
  IteratorImpl *itimpl = (IteratorImpl *)it;
  free(itimpl);
}
 /*
  * High-order functions
  */

Lista map(Lista L, Apply f, Clausura c)
{
    Lista novaLst = createLst(-1);
    Iterador it = createIterador(L, false);

    while (!isIteratorEmpty(it))
    {
        Item info = getIteratorNext(it);
        Item novoInfo = f(info, c);
        insertLst(novaLst, novoInfo, getType(info));
    }

    killIterator(it);

    return novaLst;
}

Lista filter(Lista L, Check f, Clausura c)
{
    Lista novaLst = createLst(-1);
    Iterador it = createIterador(L, false);

    while (!isIteratorEmpty(it))
    {
        Item info = getIteratorNext(it);
        if (f(info, c))
        {
            insertLst(novaLst, info, getType(info));
        }
    }

    killIterator(it);

    return novaLst;
}

void fold(Lista L, ApplyClosure f, Clausura c)
{
    Iterador it = createIterador(L, false);

    while (!isIteratorEmpty(it))
    {
        Item info = getIteratorNext(it);
        f(info, c);
    }

    killIterator(it);
}

char* getType(Posic p){
    Node *paux = (Node *) p;
    return paux->type;
}