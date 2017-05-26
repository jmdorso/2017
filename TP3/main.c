#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "pelis.h"
#include "dorso.h"

int main()
{
    eMovie pelis[150];
    char seguir = 'S';
    int opcion;

    peli_inicializar(pelis,150);
    peli_cargarPeliculas(pelis,150);

    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1: //AGREGAR PELICULA
            peli_nueva(pelis,150);
            break;
        case 2://BORRAR PELICULA
            peli_borrar(pelis,150);
            break;
        case 3://MODIFICAR PELICULA
            peli_modificar(pelis,150);
            break;
        case 4://GENERAR PAGINA WEB
            peli_paginaWeb(pelis,150);
            break;
        case 5:
            seguir='n';
            printf("\n\nSu Programa se cerrara...\n\n");
            system("pause");
            break;
        }
    }while(seguir == 'S');

    peli_guardarPeliculas(pelis,150);

    return 0;
}

