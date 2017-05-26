#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "pelis.h"
#include "dorso.h"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void peli_nueva(eMovie* peli,int cant)
{
    int indice;


    if(peli != NULL && cant > 0)
    {

        indice = peli_buscarLibre(peli,cant);

        peli[indice].id = peli_generarId(peli,cant,1000);

        getString(peli[indice].titulo,"Ingrese Titulo: ","Error! Reingrese un titulo valido (menor a 100 caracteres): ",100);
        primerLetraMayus(peli[indice].titulo);

        getString(peli[indice].descripcion,"Ingrese Descripcion: ","Error! Reingrese descripcion valida (menor a 150 caracteres): ",150);
        primerLetraMayus(peli[indice].descripcion);

        getString(peli[indice].genero,"Ingrese Genero: ","Error! Reingrese genero valido (menor a 50 caracteres): ",50);
        primerLetraMayus(peli[indice].genero);

        peli[indice].duracion = getInt("Ingrese duracion en min: ","Error! reingrese duracion valida (hasta 300 minutos->5hs): ",1,300);

        peli[indice].puntaje = getInt("Ingrese puntaje, del 1 al 10: ","Error! reingrese puntaje valido (del 1 al 10): ",1,10);

        getLink(peli[indice].linkImagen,"Ingrese link de la imagen: ","Error! El link es muy largo, reingrese (menor a 200 caracteres): ",200);

        peli[indice].estado = 1;

        system("cls");
        printf("\n\n\n\tSe ha agregado la pelicula correctamente!\n\n\n");
        system("pause");
    }
    else
    {
        printf("\nError! Falla en el programa, este se cerrara...\n");
        system("pause");
        exit(1);
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int peli_buscarLibre(eMovie* peli,int cant)
{
    int i;
    int indice;

    for(i=0;i<cant;i++)
    {
        if(peli[i].id == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void peli_inicializar(eMovie* peli,int cant)
{
    int i;
    if(peli == NULL)
    {
       printf("\nError! No hay memoria suficiente\n");
       system("pause");
       exit(1);
    }

    for(i=0;i<cant;i++)
    {
         (peli+i)->id = 0;
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int peli_generarId(eMovie* peli,int cant,int inf)
{
    int id, i, max;
    int flag = 0;

    for(i=0;i<cant;i++)
    {
        if(peli[i].id != 0)
        {
            max = peli[i].id;
            flag = 1;
        }
    }

    if(flag == 0)
    {
        id = inf + 1;
    }
    if(flag == 1)
    {
        id = max + 1;
    }

    return id;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int peli_buscarId(eMovie* peli,int cant,int id)
{
    int i;
    int indice = -1;

    for(i=0;i<cant;i++)
    {
        if(peli[i].id == id && peli[i].estado == 1)
        {
            indice = i;
        }
    }
    return indice;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void peli_borrar(eMovie* peli,int cant)
{
    int id, indice;
    char baja[256];

    peli_mostrarPeliculas(peli,cant);

    id = getInt("Ingrese el id de la pelicula a borrar: ","Error! Reingrese un ID valido (del 1000 al 2000): ",1000,2000);
    indice = peli_buscarId(peli,cant,id);

    if(indice == -1)
    {
        printf("\nNo existe pelicula con ese ID en el sistema...\n\n ");
        system("pause");
    }
    else
    {
        system("cls");
        peli_mostrarPelicula(peli,cant,indice);

        getString(baja,"\nEsta seguro que desea borrar esta pelicula? s/n: ","Ingrese 's' o 'n': ",1);
        baja[0] = tolower(baja[0]);

        if(baja[0] == 's')
        {

            peli[indice].estado = 0;
            printf("\n\nSe ha eliminado la pelicula correctamente!\n\n");
        }
        else
        {
            printf("\n\nLa baja ha sido cancelada\n\n");
        }
        system("pause");
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int menuPeli(void)
{
        int opcion;
        fflush(stdin);
        printf("\t\tQue desea modificar:\n\n");
        printf("1. Titulo\n");
        printf("2. Descripcion\n");
        printf("3. Genero\n");
        printf("4. Duracion\n");
        printf("5. Puntaje\n");
        printf("6. Link\n");
        printf("7. Terminar\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        printf("\n");


        while(!validarRangoInt(opcion,1,7))
        {
            printf("\n¡¡¡ ERROR !!! Reingrese opcion, entre 1 y 7: ");
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

void peli_modificar(eMovie* peli,int cant)
{
    int id, indice,opcion;
    char seguir = 'S';


    peli_mostrarPeliculas(peli,cant);

    id = getInt("Ingrese el id de la pelicula a modificar: ","Error! Reingrese un ID valido (del 1000 al 2000): ",1000,2000);
    indice = peli_buscarId(peli,cant,id);

    if(indice == -1)
    {
        printf("\nNo existe pelicula con ese ID en el sistema...\n\n ");
        system("pause");
    }
    else
    {
        do{
            system("cls");
            peli_mostrarPelicula(peli,cant,indice);

            opcion = menuPeli();
            switch(opcion)
            {
                case 1:
                    getString(peli[indice].titulo,"Ingrese Titulo: ","Error! Reingrese un titulo valido (menor a 100 caracteres): ",100);
                    primerLetraMayus(peli[indice].titulo);
                    break;

                case 2:
                    getString(peli[indice].descripcion,"Ingrese Descripcion: ","Error! Reingrese descripcion valida (menor a 150 caracteres): ",150);
                    primerLetraMayus(peli[indice].descripcion);
                    break;

                case 3:
                    getString(peli[indice].genero,"Ingrese Genero: ","Error! Reingrese genero valido (menor a 50 caracteres): ",50);
                    primerLetraMayus(peli[indice].genero);
                    break;

                case 4:
                    peli[indice].duracion = getInt("Ingrese duracion en min: ","Error! reingrese duracion valida (hasta 300 minutos->5hs): ",1,300);
                    break;

                case 5:
                    peli[indice].puntaje = getInt("Ingrese puntaje, del 1 al 10: ","Error! reingrese puntaje valido (del 1 al 10): ",1,10);
                    break;

                case 6:
                    getLink(peli[indice].linkImagen,"Ingrese link de la imagen: ","Error! El link es muy largo, reingrese (menor a 200 caracteres): ",200);
                    break;
                case 7:
                    seguir='n';
                    printf("\n\nLa modificacion ha sido terminada\n\n");
                    system("pause");
                    break;
            }
        }while(seguir == 'S');

    }

    system("cls");
    printf("\n\nSe ha modificado la pelicula correctamente!\n\n");
    system("pause");

}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 void peli_mostrarPelicula(eMovie* peli,int cant,int indice)
{
    printf("|ID     |Titulo\t\t     |Genero      |Puntaje|Duracion\n");
    printf("---------------------------------------------------------------\n");
    printf("|%d   |%-19s |%-11s |%-7d|%-7d\n",peli[indice].id, peli[indice].titulo, peli[indice].genero, peli[indice].puntaje, peli[indice].duracion);
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void peli_mostrarPeliculas(eMovie* peli,int cant)
{
    int i;

    printf("|ID     |Titulo\t\t     |Genero      |Puntaje|Duracion\n");
    printf("---------------------------------------------------------------\n");
    for(i=0;i<cant;i++)
    {
        if(peli[i].id != 0 && peli[i].estado == 1)
        {
            printf("|%d   |%-19s |%-11s |%-7d|%-7d\n",peli[i].id, peli[i].titulo, peli[i].genero, peli[i].puntaje, peli[i].duracion);
        }
    }
    printf("\n\n");
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void peli_guardarPeliculas(eMovie* peli,int cant)
{
    int i;
    FILE* f;

    if((f = fopen("peliculas.dat","ab")) == NULL)
    {
        system("cls");
        printf("\nERROR! No se puede generar el archivo...\n");
        system("pause");
    }

    for(i=0;i<cant;i++)
    {
        if(fwrite(peli+i,sizeof(eMovie),1,f) != 1)
        {
            printf("\nERROR! No se pudo escribir el archivo...\n");
            system("pause");
        }
    }

    if((fclose(f)) == -1)
    {
        printf("\nERROR! No se pudo cerrar el archivo...\n");
    }
    else
    {
        printf("\nEl archivo ha sido cerrado correctamente!\n");
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void peli_cargarPeliculas(eMovie* peli, int cant)
{
    FILE* f;
    int i = 0;

    if((f = fopen("peliculas.dat","rb")) == NULL)
    {
        printf("\nERROR! No hay espacio en memoria!\n\n");
        system("pause");
        return;
    }

    while(!feof(f))
    {
        fread(peli+i,sizeof(eMovie),1,f);
        i++;
    }
    if((fclose(f)) == -1)
    {
        printf("\nERROR! No se pudo cerrar el archivo...\n");
    }
    else
    {
        printf("\nEl archivo ha sido cerrado correctamente!\n");
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 void peli_paginaWeb(eMovie* peli,int cant)
{
    int i;
    FILE* f;

    if((f = fopen("ListaPeliculas.html","w")) == NULL)
    {
        system("cls");
        printf("\nERROR! No se puede generar el archivo...\n");
        system("pause");
    }

    for(i=0;i<cant;i++)
    {
        if(peli[i].estado == 1)
        {
            fprintf(f,"<html>\n<head>\n<title>Lista de Peliculas TP3</title>\n</head>\n\n<body>\n<font face='verdana'>\n<h1><marquee>Peliculas TP3 | Dorso, Juan Martín</marquee></h1>\n<br></br>\n");
            fprintf(f,"<article class='col-md-4 article-intro'>\n <a href='#'> \n<img class='img-responsive img-rounded' src='");
            fprintf(f,"%s",peli[i].linkImagen);
            fprintf(f,"'alt=''> \n</a> \n <h3> \n <a href='#'> %s </a>\n",peli[i].titulo);
            fprintf(f,"</h3> \n <ul> \n <li>Género: %s </li> \n",peli[i].genero);
            fprintf(f,"<li>Puntaje: %d </li>\n ",peli[i].puntaje);
            fprintf(f,"<li>Duración: %d </li> \n",peli[i].duracion);
            fprintf(f,"</ul> \n <p> %s </p> \n",peli[i].descripcion);
            fprintf(f, "</article> \n</font>\n</body>\n\n</html>\n\n");
        }
    }



    if((fclose(f)) == -1)
    {
        printf("\nERROR! No se pudo cerrar el archivo...\n");
    }

   printf("\n\n\n \tLa pagina web ha sido creada correctamente!\n\n\n");
   system("pause");
}
