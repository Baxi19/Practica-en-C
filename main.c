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

void* nuevaPreguntaSeleccionUnica (char* pregunta, char* s1, char* s2, char* s3, char* s4,  char* correcta){
    struct SeleccionUnica* seleccionUnica;
    seleccionUnica = (struct SeleccionUnica*) malloc(sizeof(struct SeleccionUnica));
    seleccionUnica->pregunta = pregunta;
    seleccionUnica->s1 = s1;
    seleccionUnica->s2 = s2;
    seleccionUnica->s3 = s3;
    seleccionUnica->s4 = s4;
    seleccionUnica->correcta = correcta;
    return seleccionUnica;
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
                printf("(Pregunta Verdadero o Falso): %s  (Opcion 1): %s  (Opcion 2): %s  (Correcta): %s \n",
                        ((struct VerdaderoFalso*)act->pregunta)->pregunta,
                        ((struct VerdaderoFalso*)act->pregunta)->s1,
                        ((struct VerdaderoFalso*)act->pregunta)->s2,
                        ((struct VerdaderoFalso*)act->pregunta)->correcta);

            }
            else {
                printf("(Pregunta Seleccion Unica): %s, (Opcion 1): %s, (Opcion 2): %s, (Opcion 3): %s, (Opcion 4): %s, (Correcta): %s\n",
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

void obtenerDatosSeleccionUnica(){
    char* pregunta = (char *) malloc(1);
    char* s1 = (char *) malloc(1);
    char* s2 = (char *) malloc(1);
    char* s3 = (char *) malloc(1);
    char* s4 = (char *) malloc(1);
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
    printf( "\nIngrese la respuesta #3:");
    scanf("%[^\n]s",s3);
    fflush(stdin);
    printf( "\nIngrese la respuesta #4:");
    scanf("%[^\n]s",s4);
    fflush(stdin);
    printf( "\nSeleccione la respuesta correcta (1-4)");
    scanf("%[^\n]s", correcta);
    fflush(stdin);

    insertarPregunta(nuevaPreguntaSeleccionUnica(pregunta,s1,s2,s3, s4, correcta), SELECCION_UNICA);
}

double largoLista(){
    double i = 0.0;
    struct nodoPregunta* temp=cabeza;
    if (cabeza!=NULL){
        do {
            i+=1;
            temp = temp->sig;
        }
        while(temp!=NULL);
    }
    return i;
}

char solucionarPreguntas(){
    struct nodoPregunta* act = cabeza;
    printf("\n********* Preguntas de Examen*********\n");
    if (act == NULL){
        printf("\nExamen sin preguntas");
    }else{
        int puntos = 0;
        while(act!=NULL){
            if (act->tipo==0){
                char* correcta = (char *) malloc(1);
                printf("\n\n(Pregunta Verdadero o Falso): %s\n" , ((struct VerdaderoFalso*)act->pregunta)->pregunta);
                printf("\n(Opcion 1): %s" , ((struct VerdaderoFalso*)act->pregunta)->s1);
                printf("\n(Opcion 2): %s" , ((struct VerdaderoFalso*)act->pregunta)->s2);

                printf( "\nSeleccione la respuesta correcta (1-2)");
                fflush(stdin);
                scanf("%[^\n]s", correcta);
                fflush(stdin);

                int result;
                result = strcmp(correcta, ((struct VerdaderoFalso*)act->pregunta)->correcta);
                if(result == 0){
                    puntos +=1;
                }

            }

            else {
                char* correcta = (char *) malloc(1);
                printf("\n\n(Pregunta Seleccion Unica): %s\n" , ((struct SeleccionUnica*)act->pregunta)->pregunta);
                printf("\n(Opcion 1): %s" , ((struct SeleccionUnica*)act->pregunta)->s1);
                printf("\n(Opcion 2): %s" , ((struct SeleccionUnica*)act->pregunta)->s2);
                printf("\n(Opcion 3): %s" , ((struct SeleccionUnica*)act->pregunta)->s3);
                printf("\n(Opcion 4): %s" , ((struct SeleccionUnica*)act->pregunta)->s4);

                printf( "\nSeleccione la respuesta correcta (1-4)");
                fflush(stdin);
                scanf("%[^\n]s", correcta);
                fflush(stdin);

                int result;
                result = strcmp(correcta, ((struct SeleccionUnica*)act->pregunta)->correcta);
                if(result == 0){
                    puntos +=1;
                }

            }
            act = act->sig;
        }
        double preguntas = largoLista();
        double resultado = ((puntos/preguntas)*100);
        printf("\nResultado de Examen %f \n", resultado);
    }
    return 't';
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
            case 1: printf( "*********************************************************************************");
                int  opcion;
                do
                {
                    printf( "\n   Introduzca el tipo de pregunta que desee crear:\n" );
                    printf( "\n   1. Falso o Verdadero" );
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
                            obtenerDatosSeleccionUnica();
                            break;
                    }

                } while ( opcion != 3 );
                break;

            case 2: printf( "*********************************************************************************");
                solucionarPreguntas();
                break;

            case 3: printf( "*********************************************************************************"
                            "\n   Datos de Examen: \n", 163 );
                imprimirPreguntas();
                break;
        }


    } while ( opcion != 4 );

    return 0;

}

