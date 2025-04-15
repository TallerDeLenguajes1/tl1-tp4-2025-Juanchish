#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} Tarea;

typedef struct
{
    Tarea T;
    Nodo *Siguiente;
} Nodo;

Nodo *CrearListaVacia();
Nodo *CrearNodo(Tarea T);
void InsertarNodo(Nodo **Start, Nodo *Nodo);
void InsertarAlFinal(Nodo **Start, Nodo *Nodo);
Nodo *buscarNodo(Nodo *Start, int idBuscado);
void EliminarNodo(Nodo *Nnodo);

int main()
{
    Nodo *listaTareasPendientes = CrearListaVacia();
    Nodo *listaTareasRealizadas = CrearListaVacia();

    int idSistema = 999;
    int confirma;
    int duracion;
    Tarea *T;
    do
    {
        Nodo *Nnodo = CrearNodo(*T);
        printf("Ingrese una descripcion: \n");
        T->Descripcion = (char *)malloc(sizeof(char));
        gets(T->Descripcion);

        do
        {
            printf("Ingrese una duracion: \n");
            scanf("%d", T->Duracion);
        } while (T->Duracion < 100 && T->Duracion > 10);

        printf("Desea ingresar una nueva tarea? 1-si || 2-no \n");
        scanf("%d", confirma);
        idSistema = ++idSistema;
        idSistema = T->TareaID;
        InsertarAlFinal(&listaTareasPendientes, T);
    } while (confirma == 1);

    return 0;
}

Nodo *CrearListaVacia()
{
    return NULL;
}

Nodo *CrearNodo(Tarea T)
{
    Nodo *Nnodo = (Nodo *)malloc(sizeof(Nodo));
    Nnodo->T = T;
    Nnodo->Siguiente = NULL;
    return Nnodo;
}

void InsertarNodo(Nodo **Start, Nodo *Nnodo)
{
    Nnodo->Siguiente = *Start;
    *Start = Nnodo;
}

void InsertarAlFinal(Nodo **Start, Nodo *Nnodo)
{
    Nodo *Aux = Start;
    while (Aux->Siguiente)
    {
        Aux = Aux->Siguiente;
    }
    Aux->Siguiente = Nnodo;
}

Nodo *buscarNodo(Nodo *Start, int idBuscado)
{
    Nodo *aux = Start;
    while (aux && aux->T.TareaID != idBuscado)
    {
        aux = aux->Siguiente;
    }
    return aux;
}

void EliminarNodo(Nodo *Nnodo)
{
    if (Nnodo)
    {
        free(Nnodo);
    }
}