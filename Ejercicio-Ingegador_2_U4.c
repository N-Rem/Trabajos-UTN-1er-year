#include <stdio.h>
#include <string.h>
#define MAX_CHAR 100
#define MAX_SEGUROS 3
#define MAX_CLIENT 9999

struct Seguros
{
    char nombeSegu[MAX_CHAR];
    float cuotaSegu;
};

struct Cliente
{
    char nameLastname[MAX_CHAR];
    long int dni;
    char tipoSeguro[MAX_CHAR];
    float montoAsegurar;
    char debitoAuto[MAX_CHAR];
};


void creaSeguros(struct Seguros a[], struct Seguros h[]);

int main()
{
    int opcion = 0, client = 0;
    //! Funcion que agrega los seguros de la compania;
    struct Seguros automotor[MAX_SEGUROS];
    struct Seguros hogar[MAX_SEGUROS];
    struct Cliente clientes[MAX_CLIENT];
    creaSeguros(automotor, hogar);
    while (opcion != 4)
    {
        printf("Seleccione una de las opciones que sigue... \n\t1. Registrar nuevo asegurado\n\t2. Buscar asegurado por DNI\n\t3. Ver asegurados ordenados por Tipo Seguro y Cobertura\n\t4. Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("\n\t...");
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

void creaSeguros(struct Seguros a[], struct Seguros h[])
{
//seguros Auto.
    stycpy(a[0].nombeSegu, "Tercero Básico");
    a[0].cuotaSegu = 1000;

    stycpy(a[1].nombeSegu, "Tercero Completo");
    a[1].cuotaSegu = 1500;

    stycpy(a[2].nombeSegu, "Todo Riesgo con Franquicia");
    a[2].cuotaSegu = 3000;

//seguros Hogar. 

    stycpy(h[0].nombeSegu, "Hogar Base");
    h[0].cuotaSegu = 500;

    stycpy(h[1].nombeSegu,"Hogar Plus");
    h[1].cuotaSegu = 750;

    stycpy(h[2].nombeSegu,"Hogar Completo");
    h[2].cuotaSegu = 600;
}
