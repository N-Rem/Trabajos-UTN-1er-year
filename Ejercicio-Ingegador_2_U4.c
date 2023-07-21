#include <stdio.h>
#include <string.h>
#define MAX_CHAR 100
#define MAX_SEGUROS 4;
#define MAX_CLIENT 9999;
struct SegurosA
{
    char automotor[MAX_CHAR];
    float cuotaAuto;
};
struct SeguroH
{
    char hogar[MAX_CHAR];
    float cuotaHogar;
};

struct Cliente
{
    char nameLastname[MAX_CHAR]; 
    long int dni; 
    char tipoSeguro[MAX_CHAR];
    float montoAsegurar; 
    char debitoAuto [MAX_CHAR];
};


int main()
{
    int opcion = 0, client=0;
    //!Funcion que agrega los seguros de la compania;



    while (opcion != 4)
    {
        printf("Seleccione una de las opciones que sigue... \n\t1. Registrar nuevo asegurado\n\t2. Buscar asegurado por DNI\n\t3. Ver asegurados ordenados por Tipo Seguro y Cobertura\n\t4. Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("\n\tProximamente...");
            break;
        case 2:
            printf("\n\tProximamente...");
            break;
        case 3:
            printf("\n\tProximamente...");
            break;
        case 4:
            printf("\n\tFin del progama\nGracias...");
            break;
        default:
            printf("\n\tOpcion incorrecta, vuelva a intentarlo.");
            break;
        }
    }

    return 0;
}
