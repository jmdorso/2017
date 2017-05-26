typedef struct
{
    int id;
    char titulo[100];
    char descripcion[150];
    char genero[50];
    int duracion;
    int puntaje;
    char linkImagen[200];
    int estado;
}eMovie;

void peli_nueva(eMovie* peli,int cant);
int peli_buscarLibre(eMovie* peli,int cant);
void peli_inicializar(eMovie* peli,int cant);
int peli_generarId(eMovie* peli,int cant,int inf);
int peli_buscarId(eMovie* peli,int cant,int id);
void peli_borrar(eMovie* peli,int cant);
int menuPeli(void);
void peli_modificar(eMovie* peli,int cant);
void peli_mostrarPelicula(eMovie* peli,int cant,int indice);
void peli_mostrarPeliculas(eMovie* peli,int cant);
void peli_guardarPeliculas(eMovie* peli,int cant);
void peli_cargarPeliculas(eMovie* peli, int cant);
 void peli_paginaWeb(eMovie* peli,int cant);
