#include "lista.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct StNode{ //0x55555555ec30
  char* type;
  Item info;  //lixo: 0x65672f656d6f682f   paux->info: 0x55555555ebd0
  struct StNode *prox, *ant;
} Node;

typedef struct StLista{
  Node *prim; //0x55555555ec30
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
  free(paux);
  return item;
}

void removeLst(Lista L, Posic p){
  ListaImpl *lst = (ListaImpl *)L;
}


Item getLst(Posic p){
  Node *paux;
  paux = (Node *)p;
  Item item = paux->info;
  return item;
}

Posic insertBefore(Lista L, Posic p, Item info, char* type){
  ListaImpl *lst = ( ListaImpl *)L;
  Node *paux = lst->prim;
  Node *paux2 = p;
  while (true)
  {
    if (paux->prox == paux2){
      Node *newNode = (Node *) malloc (sizeof(Node));
      newNode->info = info;
      newNode->type = type;
      newNode->prox = paux2;
      newNode->ant = getPreviousLst(L,paux2);
      paux->prox = newNode;
      lst->length++;
      break;
    }
    else{
      paux = paux->prox;
    }
  }
  
}

Posic insertAfter(Lista L, Posic p, Item info, char* type){
 ListaImpl *lst = ( ListaImpl *)L;
  Node *paux = lst->prim;
  Node *paux2 = p;
  while (true)
  {
    if (paux->ant == paux2){
      Node *newNode = (Node *) malloc (sizeof(Node));
      newNode->info = info;
      newNode->type = type;
      newNode->prox = getNextLst(L,paux2);
      newNode->ant = paux2;
      paux->prox = newNode;
      lst->length++;
      break;
    }
    else{
      paux = paux->prox;
    }
  }
}

Posic getFirstLst(Lista L){
  ListaImpl *lst = ( ListaImpl *)L;
  return lst->prim;
}

Posic getNextLst(Lista L,Posic p){
  ListaImpl *lst = ( ListaImpl *)L;
  Node *paux = p;
  return paux->prox;
  
}

Posic getLastLst(Lista L){
  ListaImpl *lst = ( ListaImpl *)L;
  return lst->ult;
}

Posic getPreviousLst(Lista L,Posic p){
  ListaImpl *lst = ( ListaImpl *)L;
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

bool isIteratorEmpty(Lista L, Iterador it){
  IteratorImpl *itimpl = (IteratorImpl *)it;
  return itimpl->curr == NULL;
}
Item getIteratorNext(Lista L, Iterador it){
   IteratorImpl *itimpl = (IteratorImpl *)it;
   Item valor =itimpl->curr->info;
   if (itimpl->reverso){
     itimpl->curr = (Node *)getPreviousLst(L,itimpl->curr);
   }
   else{
     itimpl->curr = (Node *)getNextLst(L,itimpl->curr);
   }
   return valor;
 }

void killIterator(Lista L, Iterador it){
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

    while (!isIteratorEmpty(L, it))
    {
        Item info = getIteratorNext(L, it);
        Item novoInfo = f(info, c);
        insertLst(novaLst, novoInfo, getType(info, L));
    }

    killIterator(novaLst, it);

    return novaLst;
}

Lista filter(Lista L, Check f, Clausura c)
{
    Lista novaLst = createLst(-1);
    Iterador it = createIterador(L, false);

    while (!isIteratorEmpty(L, it))
    {
        Item info = getIteratorNext(L, it);
        if (f(info, c))
        {
            insertLst(novaLst, info, getType(info, L));
        }
    }

    killIterator(novaLst, it);

    return novaLst;
}

void fold(Lista L, ApplyClosure f, Clausura c)
{
    Iterador it = createIterador(L, false);

    while (!isIteratorEmpty(L, it))
    {
        Item info = getIteratorNext(L, it);
        f(info, c);
    }

    killIterator(L, it);
}

char* getType(Item info, Lista lst){
    Posic p = getFirstLst(lst);
    while (p != NULL)
    {
        if (getLst(p) == info)
        {
            Node *paux = (Node *)p;
            return paux->type;
        }else{
            p = getNextLst(lst, p);
        }
    }
}