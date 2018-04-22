#include<stdio.h>
#include<stdlib.h>

struct Nodo{
    int info;
    struct Nodo *sig;
    struct Nodo *ant;
};
typedef struct Nodo tNodo;
typedef tNodo *Lista;

Lista CreaNodo(int valor)
{
    Lista aux;

    aux = (Lista)malloc(sizeof(tNodo));
    if (aux != NULL)
    {
        aux->info = valor;
        aux->sig = NULL;
        aux->ant = NULL;
    }
    else
    {
        system("cls");
        printf("\n\tERROR: No hay memoria suficiente para generar un nuevo Nodo.");
        printf("\n\tEste programa se cerrar%c.", 160);
        exit(1);
    }
    return aux;
}

Lista InsertaOrdenado(Lista P, int x)
{
    Lista pNodo, aux1, aux2;

    pNodo = CreaNodo(x);
    if (P == NULL)
        P = pNodo;
    else
    {
        if (x < P->info)
        {
            pNodo->sig = P;
            P->ant = pNodo;
            P = pNodo;
        }
        else
        {
            aux1 = P;
            while (aux1->sig != NULL)
            {
                if (aux1->info < x && aux1->sig->info > x)
                {
                    aux2 = aux1->sig;
                    pNodo->ant = aux1;
                    pNodo->sig = aux2;
                    aux1->sig = pNodo;
                    aux2->ant = pNodo;
                }
                else
                    aux1 = aux1->sig;
            }
            aux1->sig = pNodo;
            pNodo->ant = aux1;
            aux1 = NULL;
        }
    }
    pNodo = NULL;
    return P;
}

void Imprime(Lista P)
{
    Lista aux;

    aux = P;
    printf("\nNULL -> P -> ");
    while(aux != NULL)
    {
        printf("%d <> ", aux->info);
        aux = aux->sig;
    }
    printf("<- U ->");
    printf("NULL\n");

}

int main (){
    Lista L;
    L = NULL;
    L = InsertaOrdenado(L,4);
    InsertaOrdenado(L,6);
    InsertaOrdenado(L,2);

    Imprime(L);

return 0;
}
