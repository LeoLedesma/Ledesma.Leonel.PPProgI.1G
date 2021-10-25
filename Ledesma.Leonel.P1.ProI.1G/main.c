#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_V 7


typedef struct
{
    int id;
    char nombre[50];
    char tipo[20];
    float efectividad;
} eVacuna;


float aplicarAumento(float precio);
int reemplazarCaracteres(char cadena[], char caracterUno, char caracterDos);

int ordenarVacunas(eVacuna vacunas[], int tam, int criterio);
int mostrarVacunas(eVacuna vacunas[], int tam_V);
void mostrarVacuna(eVacuna unaVacuna);

int mostrarVacunas(eVacuna vacunas[], int tam_V);




int main()
{

    eVacuna vacunas[TAM_V]=
    {
        {1, "Sputnik", "ARN", 70 },
        {2, "Varicela","ARN", 60 },
        {3, "Malaria","Viva", 90 },
        {4, "Polio","Atenuada", 75 },
        {5,"Gripe A","Adenovirus", 90},
        {6,"Fiebre amarilla","ARN",80 },
        {7,"Varicela","ADN",90 },

    };





    float precio = 10000;
    float precioDesc;


//---------AUMENTO DE PRECIOS---------------------

    precioDesc = aplicarAumento(precio);
    printf("precio con desc es %f\n", precioDesc);



//---------CONTAR Y CAMBIAR CARACTERES-------------------------

    char cadenaPrueba[]="Maria Salaza";
    int cantidad;

    cantidad = reemplazarCaracteres(cadenaPrueba, 'a', 'c');
    printf("La cantidad de 'a' es de: %d\n", cantidad);

    printf("%s\n\n", cadenaPrueba); //Prueba



//---------ORDENAR VACUNAS--------------------------

    printf("----ANTES----\n");
    if(!mostrarVacunas(vacunas, TAM_V))
    {
        printf("Ocurrio un error al mostrar");
    }



    printf("\n----ORDENADOS----\n");

    if(ordenarVacunas(vacunas, TAM_V, 1)) //1 para ordenar ascendente o 0 para descendente
    {
        if(!mostrarVacunas(vacunas, TAM_V))
        {
            printf("Ocurrio un error al mostrar");
        }

    };


    return 0;
}

float aplicarAumento(float precio)
{
    int descuento = 5;
    float resultado;

    resultado = precio+(precio*descuento/100);


    return resultado;
}


int reemplazarCaracteres(char cadena[], char caracterUno, char caracterDos)
{
    int cantidad=0;
    int largoCadena = strlen(cadena);


    if(cadena!=NULL && largoCadena>0)
    {

        for(int i=0; i<largoCadena; i++)
        {

            if(cadena[i] == caracterUno)
            {
                cadena[i] = caracterDos;
                cantidad++;
            }

        }

    }



    return cantidad;
}



int ordenarVacunas(eVacuna vacunas[], int tam, int criterio)
{
    int todoOk=0;
    eVacuna auxVacuna;

    if(vacunas!=NULL && tam>0 && (criterio==1 || criterio==0))
    {
        todoOk = 1;
        if(criterio==1)
        {
            for(int i=0; i<tam-1; i++)
            {

                for (int j=i+1; j<tam; j++)
                {

                    if(strcmp(vacunas[i].tipo, vacunas[j].tipo)>0 || (strcmp(vacunas[i].tipo, vacunas[j].tipo)==0 && vacunas[i].efectividad>vacunas[j].efectividad))
                    {

                        auxVacuna = vacunas[i];
                        vacunas[i] = vacunas[j];
                        vacunas[j] = auxVacuna;
                    }

                }

            }
        }
        else
        {
            for(int i=0; i<tam-1; i++)
            {

                for (int j=i+1; j<tam; j++)
                {

                    if(strcmp(vacunas[i].tipo, vacunas[j].tipo)<0 || (strcmp(vacunas[i].tipo, vacunas[j].tipo)==0 && vacunas[i].efectividad<vacunas[j].efectividad))
                    {

                        auxVacuna = vacunas[i];
                        vacunas[i] = vacunas[j];
                        vacunas[j] = auxVacuna;
                    }
                }

            }


        }

    }
    return todoOk;
}


void mostrarVacuna(eVacuna unaVacuna)
{
    printf("%2d    %-20s   %-25s   %.2f%%\n", unaVacuna.id,
           unaVacuna.nombre,
           unaVacuna.tipo,
           unaVacuna.efectividad);


}



int mostrarVacunas(eVacuna vacunas[], int tam_V)
{
    int todoOk = 0;

    if(vacunas!=NULL && tam_V>0)
    {


        todoOk=1;
        printf("                    *** LISTA DE VACUNAS ***\n");
        printf("--------------------------------------------------------------------------\n");
        printf("ID     NOMBRE                 TIPO                   EFECTIVIDAD\n");
        printf("--------------------------------------------------------------------------\n");

        for(int i = 0; i<tam_V; i++)
        {
            mostrarVacuna(vacunas[i]);

        }

    }
    return todoOk;
}
