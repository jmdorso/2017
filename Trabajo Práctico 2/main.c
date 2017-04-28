#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dorso.h"

int main()
{
    int opcion;
    char seguir='s';
    ePersona vecPersona[20];
    ePersona auxVecPersona[20];

    inicVec(vecPersona,auxVecPersona, 20);
    do
    {
        fflush(stdin);
        system("cls");
        printf("\t\tTrabajo Practico n2.\n\n");
        printf("1. Agregar una persona\n");
        printf("2. Borrar una persona\n");
        printf("3. Imprimir lista ordenada por nombre\n");
        printf("4. Imprimir grafico de edades\n");
        printf("5. Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        printf("\n");


        while(!validarRangoInt(opcion,1,5))
        {
            printf("\n¡¡¡ ERROR !!! Reingrese opcion, entre 1 y 5: ");
            scanf("%d", &opcion);
        }
        switch(opcion)
        {
            case 1:
                    cargarVecPersona(vecPersona, 20);
                    fflush(stdin);
                    break;
            case 2:
                    eliminarVecPersona(vecPersona,20);
                    fflush(stdin);
                    break;
            case 3:
                    listarVecPersona(vecPersona, 20, 1);
                    fflush(stdin);
                    break;
            case 4:
                    graficoEdades(vecPersona,20);
                    fflush(stdin);
                    break;
            case 5:
                    seguir='n';
                    break;
        }

    }while(seguir!='n');
return 0;
}
