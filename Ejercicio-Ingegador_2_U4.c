
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 100
#define MAX_SEGUROS 3
#define MAX_CLIENT 999

#define IVA 1.21
#define AUTOMOTOR 0.05
#define HOGAR 0.1
#define DEBAUTO 0.5

struct Seguros
{
    char nombreSegu[MAX_CHAR];
    float cuotaSegu;
};
struct Cliente
{
    char nameLastname[MAX_CHAR];
    long int dni;
    int tipoSeguro;
    float montoAsegurar;
    char debitoAuto[MAX_CHAR];
    float cuotaMenusal;
};

void creaSeguros(struct Seguros a[], struct Seguros h[]);
void mostrarSeguros(struct Seguros a[], struct Seguros h[]);

int main()
{
    printf("Hola");
    struct Seguros automotor[MAX_SEGUROS];
    struct Seguros hogar[MAX_SEGUROS];
    struct Cliente clientes [MAX_CLIENT];
    creaSeguros(automotor, hogar);
    mostrarSeguros(automotor, hogar);
    int opcion = 0, client = 0;
    while (opcion != 4)
    {
        printf("\n\nSeleccione una de las opciones que sigue... \n\t1. Registrar nuevo asegurado\n\t2. Buscar asegurado por DNI\n\t3. Ver asegurados ordenados por Tipo Seguro y Cobertura\n\t4. Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("\n\t...");
            client++;
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
    // seguros Auto.
    strcpy(a[0].nombreSegu, "Tercero Basico");
    a[0].cuotaSegu = 1000;

    strcpy(a[1].nombreSegu, "Tercero Completo");
    a[1].cuotaSegu = 1500;

    strcpy(a[2].nombreSegu, "Todo Riesgo con Franquicia");
    a[2].cuotaSegu = 3000;

    // seguros Hogar.

    strcpy(h[0].nombreSegu, "Hogar Base");
    h[0].cuotaSegu = 500;

    strcpy(h[1].nombreSegu, "Hogar Plus");
    h[1].cuotaSegu = 750;

    strcpy(h[2].nombreSegu, "Hogar Completo");
    h[2].cuotaSegu = 600;
}

void agregaCliente(struct Cliente client[], int c, struct Seguros a[], struct Seguros h[])
{
    int valido;
    float cuota, cuotaFinal;

    printf("\nDigite el nombre y apellido del nuevo Cliente: ");
    fgets(client[c].nameLastname, MAX_CHAR, stdin);
    getchar();

    printf("\nIngrese el DNI del nuevo Cliente: ");
    scanf("%ld", &client[c].dni);

    printf("\nSelecciones el tipo de seguro\n\t");
    mostrarSeguros(a, h);
    scanf("%d", &client[c].tipoSeguro);

    printf("Ingrese el monto a asegurar: ");
    scanf("%f", &client[c].montoAsegurar);

    printf("Elige Debito automatico: Si/No");
    fgets(client[c].debitoAuto, MAX_CHAR, stdin);
    getchar();

    // CALCULAR cuota mensual:
    if (client[c].tipoSeguro > 3)
    {
        // descuento de hogar.
    }
    else
    {
        // descuento de auto.
    }
    if (client[c].debitoAuto == "Si") //Buscar una funcion que compare caracteres.
    {
        // descuento 5%
    }
    // agrega iva..
    client[c].cuotaMenusal = cuotaFinal;

    printf("\n\nAcegurado Registrado...\n\n");
    
}

void mostrarSeguros(struct Seguros a[], struct Seguros h[])
{
    int cont = 0;
    printf("\n\tSeguros Para Automotores");
    for (int i = 0; i < MAX_SEGUROS; i++)
    {
        cont++;
        printf("\n\t %d. %s -> %f\n", cont, a[i].nombreSegu, a[i].cuotaSegu);
    }

    printf("\n\n\tSeguros Para el Hogar");
    for (int i = 0; i < MAX_SEGUROS; i++)
    {
        cont++;
        printf("\n\t%d. %s -> %f\n", cont, h[i].nombreSegu, h[i].cuotaSegu);
    }
}



