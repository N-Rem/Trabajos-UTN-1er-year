
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 100
#define MAX_SEGUROS 3
#define MAX_CLIENT 999

#define IVA 1.21
#define AUTOMOTOR 0.05
#define HOGAR 0.01
#define DEB_AUTO 0.95

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
void agregaCliente(struct Cliente client[], int c, struct Seguros a[], struct Seguros h[]);

void ordenarClientes(struct Cliente client[], int max);
void mostrarClientes(struct Cliente client[], int max);

void buscarCliente(struct Cliente client[], int max);
int compruebaDni(struct Cliente c[], int max, long int dni);
int buscarDni(struct Cliente c[], int max, long int dni);
void imprimeClientes(struct Cliente c[], int i);
int main()
{
    struct Seguros automotor[MAX_SEGUROS];
    struct Seguros hogar[MAX_SEGUROS];
    struct Cliente clientes[MAX_CLIENT];
    creaSeguros(automotor, hogar);
    mostrarSeguros(automotor, hogar);

    int opcion = 0,
        client = 0;
    while (opcion != 4)
    {
        printf("\n\nSeleccione una de las opciones que sigue... \n\t1. Registrar nuevo asegurado\n\t2. Buscar asegurado por DNI\n\t3. Ver asegurados ordenados por Tipo Seguro y Cobertura\n\t4. Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            agregaCliente(clientes, client, automotor, hogar);
            client++;
            break;
        case 2:
            if (client != 0)
            {
                buscarCliente(clientes, client);
            }
            else
            {
                printf("\n\t\tIngrese al menos un cliente.\n");
            }
            break;
        case 3:
            if (client != 0)
            {
                mostrarClientes(clientes, client);
            }
            else
            {
                printf("\n\t\tIngrese al menos un cliente.\n");
            }
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
    cuota = 1;
    cuotaFinal = 0;
    printf("\nDigite el nombre y apellido del nuevo Cliente: ");
    getchar();
    fgets(client[c].nameLastname, MAX_CHAR, stdin);
    client[c].nameLastname[strcspn(client[c].nameLastname, "\n")] = '\0';

    printf("\nIngrese el DNI del nuevo Cliente: ");
    scanf("%ld", &client[c].dni);

    printf("\nSelecciones el tipo de seguro\n\t");
    mostrarSeguros(a, h);
    scanf("%d", &client[c].tipoSeguro);

    switch (client[c].tipoSeguro)
    {
    case 1:
        cuota = a[0].cuotaSegu;
        break;
    case 2:
        cuota = a[1].cuotaSegu;
        break;
    case 3:
        cuota = a[2].cuotaSegu;
        break;
    case 4:
        cuota = h[0].cuotaSegu;
        break;
    case 5:
        cuota = h[1].cuotaSegu;
        break;
    case 6:
        cuota = h[2].cuotaSegu;
        break;
    }
    printf("Ingrese el monto a asegurar:\t");
    scanf("%f", &client[c].montoAsegurar);

    printf("Elige Debito automatico: Si/No\t");
    getchar();
    fgets(client[c].debitoAuto, MAX_CHAR, stdin);
    client[c].debitoAuto[strcspn(client[c].debitoAuto, " \n")] = '\0';
    // CALCULAR cuota mensual:
    if (client[c].tipoSeguro > 3)
    {
        cuotaFinal = (client[c].montoAsegurar * HOGAR) + cuota;
    }
    else
    {
        cuotaFinal = (client[c].montoAsegurar * AUTOMOTOR) + cuota;
    }
    if (strcmp(client[c].debitoAuto, "Si") == 0) // Buscar una funcion que compare caracteres.
    {
        cuotaFinal *= DEB_AUTO;
    }
    cuotaFinal *= IVA;

    client[c].cuotaMenusal = cuotaFinal;

    printf("\nAcegurado Registrado...\n\n");
}

void mostrarSeguros(struct Seguros a[], struct Seguros h[])
{
    int cont = 0;
    printf("\n\tSeguros Para Automotores");
    for (int i = 0; i < MAX_SEGUROS; i++)
    {
        cont++;
        printf("\n\t %d. %s -> %.2f\n", cont, a[i].nombreSegu, a[i].cuotaSegu);
    }

    printf("\n\n\tSeguros Para el Hogar");
    for (int i = 0; i < MAX_SEGUROS; i++)
    {
        cont++;
        printf("\n\t%d. %s -> %.2f\n", cont, h[i].nombreSegu, h[i].cuotaSegu);
    }
}

void mostrarClientes(struct Cliente client[], int max)
{
    ordenarClientes(client, max);
    char tipoSeguro[MAX_CHAR];
    printf("Nombre\t\tDNI\t\tTipo de seguro\t\tDebito automatico\tCuota a bonar\n");
    for (int i = 0; i < max; i++)
    {
        imprimeClientes(client, i);
    }
}

void ordenarClientes(struct Cliente client[], int max)
{
    int ordenar = 0, auxInt;
    float auxFloat;
    char auxChar[MAX_CHAR];
    long int auxLongI;

    while (ordenar == 0)
    {
        ordenar = 1;
        for (int i = 0; i < max - 1; i++)
        {
            if (client[i].tipoSeguro > client[i + 1].tipoSeguro)
            {
                ordenar = 0;
                strcpy(auxChar, client[i].nameLastname);
                strcpy(client[i].nameLastname, client[i + 1].nameLastname);
                strcpy(client[i + 1].nameLastname, auxChar);

                strcpy(auxChar, client[i].debitoAuto);
                strcpy(client[i].debitoAuto, client[i + 1].debitoAuto);
                strcpy(client[i + 1].debitoAuto, auxChar);

                auxLongI = client[i].dni;
                client[i].dni = client[i + 1].dni;
                client[i + 1].dni = auxLongI;

                auxInt = client[i].tipoSeguro;
                client[i].tipoSeguro = client[i + 1].tipoSeguro;
                client[i + 1].tipoSeguro = auxInt;

                auxFloat = client[i].montoAsegurar;
                client[i].montoAsegurar = client[i + 1].montoAsegurar;
                client[i + 1].montoAsegurar = auxFloat;

                auxFloat = client[i].cuotaMenusal;
                client[i].cuotaMenusal = client[i + 1].cuotaMenusal;
                client[i + 1].cuotaMenusal = auxFloat;
            }
        }
    }
}

void buscarCliente(struct Cliente client[], int max)
{
    long int dni;
    int valido, ind;
    printf("\nDigite el DNI del cliente: ");
    scanf("%ld", &dni);
    valido = compruebaDni(client, max, dni);
    if (valido != 1)
    {
        printf("El DNI no existe.");
    }
    else
    {
        printf("Nombre\t\tDNI\t\tTipo de seguro\t\tDebito automatico\tCuota a bonar\n");
        ind = buscarDni(client, max, dni);
        imprimeClientes(client, ind);
    }
}

int buscarDni(struct Cliente c[], int max, long int dni)
{
    for (int i = 0; i < max; i++)
    {
        if (dni == c[i].dni)
        {
            return i;
        }
    }
}

int compruebaDni(struct Cliente c[], int max, long int dni)
{
    for (int i = 0; i < max; i++)
    {
        if (dni == c[i].dni)
        {
            return 1;
            break;
        }
    }
    return 0;
};

void imprimeClientes(struct Cliente c[], int i)
{
    char tipoSeguro[MAX_CHAR];
    switch (c[i].tipoSeguro)
    {
    case 1:
        strcpy(tipoSeguro, "Tercero Basico");
        break;
    case 2:
        strcpy(tipoSeguro, "Tercero Completo");
        break;
    case 3:
        strcpy(tipoSeguro, "Todo Riesgo con Franquicia");
        break;
    case 4:
        strcpy(tipoSeguro, "Hogar Base");
        break;
    case 5:
        strcpy(tipoSeguro, "Hogar Plus");
        break;
    case 6:
        strcpy(tipoSeguro, "Tercero Basico");
        break;
    }
    printf("%s\t%ld\t\t%s\t\t%s\t\t\t%.2f\n", c[i].nameLastname, c[i].dni, tipoSeguro, c[i].debitoAuto, c[i].cuotaMenusal);
}

