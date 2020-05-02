#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*--------------------------------------------------------------------------------------------------------------------*/
/*Randald Villegas Brenes*/
/*2-05-2020*/
/*Practica de lenguajes de programacion*/
/*--------------------------------------------------------------------------------------------------------------------*/
typedef enum { VERDADERO_FALSO, SELECCION_UNICA } Tipo;
/*--------------------------------------------------------------------------------------------------------------------*/
struct VerdaderoFalso{
    char* pregunta;
    char* s1;
    char* s2;
    char* correcta;
    char* respuestaUsuario;
};
/*--------------------------------------------------------------------------------------------------------------------*/
struct SeleccionUnica{
    char* pregunta;
    char* s1;
    char* s2;
    char* s3;
    char* s4;
    char* correcta;
    char* respuestaUsuario;
};
/*--------------------------------------------------------------------------------------------------------------------*/
struct nodoPregunta{
    void* pregunta;
    Tipo tipo;
    struct nodoPregunta* sig;
} *cabeza;
/*--------------------------------------------------------------------------------------------------------------------*/
void* nuevaPreguntaVerdaderoFalso (char* pregunta, char* s1, char* s2,  char* correcta){
    struct VerdaderoFalso* verdaderoFalso;
    verdaderoFalso = (struct VerdaderoFalso*) malloc(sizeof(struct VerdaderoFalso));
    verdaderoFalso->pregunta = pregunta;
    verdaderoFalso->s1 = s1;
    verdaderoFalso->s2 = s2;
    verdaderoFalso->correcta = correcta;
    return verdaderoFalso;
}
/*--------------------------------------------------------------------------------------------------------------------*/
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
/*--------------------------------------------------------------------------------------------------------------------*/
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
/*--------------------------------------------------------------------------------------------------------------------*/
double largoExamen(){
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
/*--------------------------------------------------------------------------------------------------------------------*/
void imprimirPreguntas(){
    printf("*********************************************************************************\n");
    printf(" *******************Mostrando Preguntas y solucion********************************\n");

    struct nodoPregunta* act = cabeza;
    if (act == NULL){
        printf("Primero debe agregar las preguntas del Examen\n");
        return;
    }else if(((struct VerdaderoFalso*)act->pregunta)->respuestaUsuario == NULL){
        printf("Aun debe solucionar el examen\n");
        return;
    }else{
        int puntos = 0;
        while(act!=NULL){
            printf("\n*********************************************************************************");
            if (act->tipo==0){
                printf("\n(Pregunta Verdadero o Falso): %s\n" , ((struct VerdaderoFalso*)act->pregunta)->pregunta);
                printf("\n(Opcion 1): %s" , ((struct VerdaderoFalso*)act->pregunta)->s1);
                printf("\n(Opcion 2): %s" , ((struct VerdaderoFalso*)act->pregunta)->s2);
                printf("\n(Respuesta Correcta): %s" , ((struct VerdaderoFalso*)act->pregunta)->correcta);
                printf("\n(Respuesta del Usuario): %s" , ((struct VerdaderoFalso*)act->pregunta)->respuestaUsuario);
                int result;
                result = strcmp(((struct VerdaderoFalso*)act->pregunta)->correcta, ((struct VerdaderoFalso*)act->pregunta)->respuestaUsuario);
                if(result == 0){
                    puntos +=1;
                    printf("\n->Respuesta Correcta (+1)" );
                }else{
                    printf("\n->Respuesta Incorrecta (X)" );
                }
            }
            else {
                printf("\n(Pregunta Seleccion Unica): %s\n" , ((struct SeleccionUnica*)act->pregunta)->pregunta);
                printf("\n(Opcion 1): %s" , ((struct SeleccionUnica*)act->pregunta)->s1);
                printf("\n(Opcion 2): %s" , ((struct SeleccionUnica*)act->pregunta)->s2);
                printf("\n(Opcion 3): %s" , ((struct SeleccionUnica*)act->pregunta)->s3);
                printf("\n(Opcion 4): %s" , ((struct SeleccionUnica*)act->pregunta)->s4);
                printf("\n(Respuesta Correcta): %s" , ((struct SeleccionUnica*)act->pregunta)->correcta);
                printf("\n(Respuesta del Usuario): %s" , ((struct SeleccionUnica*)act->pregunta)->respuestaUsuario);
                int result;
                result = strcmp(((struct SeleccionUnica*)act->pregunta)->correcta, ((struct SeleccionUnica*)act->pregunta)->respuestaUsuario);
                if(result == 0){
                    puntos +=1;
                    printf("\n->Respuesta Correcta (+1)" );
                }else{
                    printf("\n->Respuesta Incorrecta (X)" );
                }
            }
            act = act->sig;
        }
        double preguntas = largoExamen();
        double resultado = ((puntos/preguntas)*100);
        printf("\nResultado de Examen %f \n", resultado);
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/
void obtenerDatosVerdaderoFalso(){
    printf("*********************************************************************************\n");
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
    printf( "\nSeleccione el numero de la respuesta correcta (1-2)");
    scanf("%[^\n]s", correcta);
    fflush(stdin);
    insertarPregunta(nuevaPreguntaVerdaderoFalso(pregunta,s1,s2, correcta), VERDADERO_FALSO);
}
/*--------------------------------------------------------------------------------------------------------------------*/
void obtenerDatosSeleccionUnica(){
    printf("*********************************************************************************\n");
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
    printf( "\nSeleccione el numero de la respuesta correcta (1-4)");
    scanf("%[^\n]s", correcta);
    fflush(stdin);
    insertarPregunta(nuevaPreguntaSeleccionUnica(pregunta,s1,s2,s3, s4, correcta), SELECCION_UNICA);
}
/*--------------------------------------------------------------------------------------------------------------------*/
void solucionarPreguntas(){
    printf("*********************************************************************************\n");
    printf(" ************************ Preguntas de Examen*************************************\n");
    struct nodoPregunta* act = cabeza;
    if (act == NULL){
        printf("El Examen se encuentra sin preguntas!!\n");
        return;
    }else{
        int puntos = 0;
        while(act!=NULL){
            if (act->tipo==0){
                char* correcta = (char *) malloc(1);
                printf("\n(Pregunta Verdadero o Falso): %s\n" , ((struct VerdaderoFalso*)act->pregunta)->pregunta);
                printf("\n(Opcion 1): %s" , ((struct VerdaderoFalso*)act->pregunta)->s1);
                printf("\n(Opcion 2): %s" , ((struct VerdaderoFalso*)act->pregunta)->s2);
                printf( "\nSeleccione el numero de la opcion con la respuesta correcta (1-2)");
                fflush(stdin);
                scanf("%[^\n]s", correcta);
                ((struct VerdaderoFalso*)act->pregunta)->respuestaUsuario = correcta;
                fflush(stdin);
                int result;
                result = strcmp(((struct VerdaderoFalso*)act->pregunta)->respuestaUsuario, ((struct VerdaderoFalso*)act->pregunta)->correcta);
                if(result == 0){
                    puntos +=1;
                }
            }else {
                char* correcta = (char *) malloc(1);
                printf("\n(Pregunta Seleccion Unica): %s\n" , ((struct SeleccionUnica*)act->pregunta)->pregunta);
                printf("\n(Opcion 1): %s" , ((struct SeleccionUnica*)act->pregunta)->s1);
                printf("\n(Opcion 2): %s" , ((struct SeleccionUnica*)act->pregunta)->s2);
                printf("\n(Opcion 3): %s" , ((struct SeleccionUnica*)act->pregunta)->s3);
                printf("\n(Opcion 4): %s" , ((struct SeleccionUnica*)act->pregunta)->s4);
                printf( "\nSeleccione el numero de la opcion con la respuesta correcta (1-4)");
                fflush(stdin);
                scanf("%[^\n]s", correcta);
                ((struct SeleccionUnica*)act->pregunta)->respuestaUsuario=correcta;
                fflush(stdin);
                int result;
                result = strcmp(((struct SeleccionUnica*)act->pregunta)->respuestaUsuario, ((struct SeleccionUnica*)act->pregunta)->correcta);
                if(result == 0){
                    puntos +=1;
                }
            }
            act = act->sig;
        }
        double preguntas = largoExamen();
        double resultado = ((puntos/preguntas)*100);
        printf("\nResultado de Examen %f \n", resultado);
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/
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

        switch ( opcion ){
            case 1:
                printf( "");
                int  opcion;
                do{
                    printf( "*********************************************************************");
                    printf( "\n   Introduzca el tipo de pregunta que desee crear:\n" );
                    printf( "\n   1. Falso o Verdadero" );
                    printf( "\n   2. Seleccion Unica", 163 );
                    printf( "\n   3. Salir." );
                    printf( "\n\n   Introduzca opci%cn (1-3): ", 162 );
                    scanf( "%d", &opcion );
                    switch ( opcion ){
                        case 1:
                            printf( "\n   ->Falso o Verdadero: \n", 163 );
                            obtenerDatosVerdaderoFalso();
                            break;
                        case 2: printf( "\n   ->Seleccion Unica: \n", 163 );
                            obtenerDatosSeleccionUnica();
                            break;
                    }
                }while ( opcion != 3 );
                break;

            case 2:
                solucionarPreguntas();
                break;
            case 3:
                imprimirPreguntas();
                break;
        }
    } while ( opcion != 4 );
    return 0;
}
/*--------------------------------------------------------------------------------------------------------------------*/
