#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "dorso.h"

/** \brief valida si los numeros se encuentran dentro de un rango
 * \param int x es el numero a validar
 * \param int inf es el limite inferior para validar
 * \param int sup es el limite superior para validar
 * \return si pertenece o no al rango el numero.
 *
 */

 int validarRangoInt(int x, int inf, int sup)
 {
    int esValido=0;
    if (x>=inf && x<=sup)
    {
        esValido= 1;
    }
 return esValido;
 }

 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

int menu(void)
{
        int opcion;
        fflush(stdin);
        system("cls");
        printf("\t\tTRABAJO PRACTICO 3.\n\n");
        printf("1. Agregar Pelicula\n");
        printf("2. Borrar Pelicula\n");
        printf("3. Modificar Pelicula\n");
        printf("4. Generar Pagina Web\n");
        printf("5. Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        printf("\n");


        while(!validarRangoInt(opcion,1,5))
        {
            printf("\n¡¡¡ ERROR !!! Reingrese opcion, entre 1 y 5: ");
            scanf("%d", &opcion);
        }
        return opcion;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 void getString(char* cadena,char* msj,char* msjCasoError,int lim)
{
    char auxCad[500];

    printf("\n%s",msj);
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad) > lim)
    {
        printf("\n%s", msjCasoError);
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(cadena,auxCad);

}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void primerLetraMayus(char* cadena)
{
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int getInt(char* msj, char* msjCasoError, int inf, int sup)
{
    int num;
    char auxNum[256];

    printf("\n%s", msj);
    fflush(stdin);
    scanf("%s", auxNum);
    while(validarRangoInt(auxNum,inf,sup))
    {
        printf("\n%s", msjCasoError);
        fflush(stdin);
        scanf("%s", auxNum);
    }

    num = atoi(auxNum);

    return num;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void getLink(char* cadena,char* msj,char* msjCasoError,int lim)
{
    char auxCad[1000];

    printf("\n%s",msj);
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad) > lim)
    {
        printf("\n%s", msjCasoError);
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(cadena,auxCad);

}
