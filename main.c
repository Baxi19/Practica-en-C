#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { VERDADERO_FALSO, SELECCION_UNICA } Tipo;

struct VerdaderoFalso{
    char* pregunta;
    char* s1;
    char* s2;
    char* correcta;
};

struct SeleccionUnica{
    char* pregunta;
    char* s1;
    char* s2;
    char* s3;
    char* s4;
    char* correcta;
};

struct nodoPregunta{
    void* pregunta;
    Tipo tipo;
    struct nodoPregunta* sig;
} *cabeza;


void* nuevaPreguntaVerdaderoFalso (char* pregunta, char* s1, char* s2,  char* correcta){
    struct VerdaderoFalso* verdaderoFalso;
    verdaderoFalso = (struct VerdaderoFalso*) malloc(sizeof(struct VerdaderoFalso));
    verdaderoFalso->pregunta = pregunta;
    verdaderoFalso->s1 = s1;
    verdaderoFalso->s2 = s2;
    verdaderoFalso->correcta = correcta;
    return verdaderoFalso;
}



void insertarPregunta(void* nuevaPregunta, Tipo tipo){
    struct nodoPregunta* nn = NULL;
    nn = (struct nodoPregunta*) malloc(sizeof(struct nodoPregunta));

    nn->pregunta=nuevaPregunta;
    nn->tipo = tipo;
    nn->sig=NULL;

    if (cabeza == NULL)
        cabeza=nn;
    else{
        nn->sig = cabeza;
        cabeza = nn;
    }

}

void imprimirPreguntas(){
    struct nodoPregunta* act = cabeza;
    printf("********* Lista de Preguntas *********\n");
    if (act == NULL)
        printf("Lista Vacia");
    else
        while(act!=NULL){
            if (act->tipo==0){
                printf("(Pregunta Verdadero o Falso): %s  (Opcion 1): %s  (Opcion 2): %s  (Opcion Correcta): %s \n",
                        ((struct VerdaderoFalso*)act->pregunta)->pregunta,
                        ((struct VerdaderoFalso*)act->pregunta)->s1,
                        ((struct VerdaderoFalso*)act->pregunta)->s2,
                        ((struct VerdaderoFalso*)act->pregunta)->correcta);

            }
            else {
                printf("(Pregunta Seleccion Unica): %s, (Opcion 1): %s, (Opcion 2): %s, (Opcion 3): %s, (Opcion 4): %s, (Opcion Correcta): %s\n",
                        ((struct SeleccionUnica*)act->pregunta)->pregunta,
                        ((struct SeleccionUnica*)act->pregunta)->s1,
                        ((struct SeleccionUnica*)act->pregunta)->s2,
                        ((struct SeleccionUnica*)act->pregunta)->s3,
                        ((struct SeleccionUnica*)act->pregunta)->s4,
                        ((struct SeleccionUnica*)act->pregunta)->correcta);

            }
            act = act->sig;
        }
}

void obtenerDatosVerdaderoFalso(){
    char* pregunta = (char *) malloc(1);
    char* s1 = (char *) malloc(1);
    char* s2 = (char *) malloc(1);
    char* correcta = (char *) malloc(1);

    fflush(stdin);
    printf( "\nIngrese la pregunta:");
    scanf("%[^\n]s",pregunta);
    fflush(stdin);
    printf( "\nIngrese la respuesta #1:");
    scanf("%[^\n]s",s1);
    fflush(stdin);
    printf( "\nIngrese la respuesta #2:");
    scanf("%[^\n]s",s2);
    fflush(stdin);
    printf( "\nSeleccione la respuesta correcta (1-2)");
    scanf("%[^\n]s", correcta);
    fflush(stdin);

    insertarPregunta(nuevaPreguntaVerdaderoFalso(pregunta,s1,s2, correcta), VERDADERO_FALSO);
}

int main() {
    int  opcion;
    do
    {   printf("*********************************************************************************");
        printf( "\n   1. Crear Examen", 163 );
        printf( "\n   2. Solucionar el Examen", 163 );
        printf( "\n   3. Imprimir Examen", 163 );
        printf( "\n   4. Salir." );
        printf( "\n\n   Introduzca opci%cn (1-4): ", 162 );
        scanf( "%d", &opcion );

        switch ( opcion )
        {
            case 1: printf( "*********************************************************************************"
                            "\n   Introduzca el tipo de pregunta que desee crear: \n", 163 );
                int  opcion;
                do
                {
                    printf( "\n   1. Falso o Verdadero", 163 );
                    printf( "\n   2. Seleccion Unica", 163 );
                    printf( "\n   3. Salir." );
                    printf( "\n\n   Introduzca opci%cn (1-3): ", 162 );
                    scanf( "%d", &opcion );

                    switch ( opcion )
                    {
                        case 1: printf( "\n   Falso o Verdadero: \n", 163 );
                            obtenerDatosVerdaderoFalso();
                            break;
                        case 2: printf( "\n   Seleccion Unica: \n", 163 );

                            break;
                    }

                } while ( opcion != 3 );
                break;

            case 2: printf( "*********************************************************************************"
                            "\n   Inicio de Examen: \n", 163 );
                //scanf( "%d", &n );
                //printf( "\n   La mitad de %d es %f\n\n", n, ( float ) n / 2 );
                break;

            case 3: printf( "*********************************************************************************"
                            "\n   Datos de Examen: \n", 163 );
                imprimirPreguntas();
                break;
        }


    } while ( opcion != 4 );

    return 0;
/*

    char* laMarca = (char*) malloc(1);
    strcpy(laMarca,"Nike");

    insertarArchivo(nuevoExamen(laMarca, 35, 30000), VERDADERO_FALSO);
    insertarArchivo(nuevaSolucion("Arena", 15000, "Camiseta", 'H'), SELECCION_UNICA);
    insertarArchivo(nuevaPreguntaVerdaderoFalso("Adidas", 40, 27500), VERDADERO_FALSO);
    insertarPregunta(nuevaPreguntaSeleccionUnica("Loft", 12000, "Blusa", 'M'), SELECCION_UNICA);
    imprimirArchivos();
    eliminarArchivo(1);
    imprimirArchivos();
    eliminarArchivo(4); //DEBE GENERAR ERROR DE ELIMINACIÓN
    imprimirArchivos();
    eliminarArchivo(0);
    imprimirArchivos();
    eliminarArchivo(1);
    imprimirArchivos();
    eliminarArchivo(1); //DEBE GENERAR ERROR DE ELIMINACIÓN
    imprimirArchivos();
    eliminarPregunta(0);
    imprimirPreguntas();

    return 0;
    */
}

