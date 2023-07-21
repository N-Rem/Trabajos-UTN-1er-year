// Ejercicio de programacion; de PSeInt pasado a C.
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define EFECTIVO 0.15
#define DEBITO 0.10
#define CREDITO 0
#define IVA 1.21

#define CANT_MAX 4
#define VENT_MAX 9999
#define CHAR_MAX 100
struct Producto
{
    int codigo;
    float precio;
    char descripcion[CHAR_MAX];
};

struct Venta
{
    long int dni;
    float desc;
    int codigo;
    int cant;
    float total;
};

void cargarProducto(struct Producto p[]);

void registrarVenta(struct Venta v[], int numVent, struct Producto p[]);
int buscarIndice(int codigo, struct Producto p[]);
int validaDni(long int v);
int validaCodigo(int v);
int validaPago(int v);
int validaCantidad(int v);

void mostrarProductos(struct Producto p[]);
void resumenDelDia(struct Venta v[], int numVent);
int validaVenta(int numVenta);

// array Global--
float DESCUENTO[3] = {EFECTIVO, EFECTIVO, CREDITO};

int main()
{
    struct Producto productos[CANT_MAX];
    int opcion = 0, vent = 0;
    cargarProducto(productos);
    struct Venta ventas[VENT_MAX];
    do
    {
        printf("\n\t\tSelecione las siguientes opciones: \n 1. Registrar Ventas.\n 2. Ver listado de productos ordenados por descripcion.\n 3. Ver Resumen del dia.\n 4. Salir.\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("\n\t-Ingreso de Ventas-");
            registrarVenta(ventas, vent, productos);
            vent++;
            break;
        case 2:
            printf("\n\tListados de productos\n\t");
            mostrarProductos(productos);
            break;
        case 3:
            resumenDelDia(ventas, vent);
            break;
        case 4:
            printf("\n\tFin del progama.\n Gracias...");
            break;
        default:
            printf("\n\tOpcion mal escrita..");
            break;
        }
    } while (opcion != 4);
    return 0;
}

void cargarProducto(struct Producto p[])
{
    p[0].codigo = 1;
    p[0].precio = 3500.00;
    strcpy(p[0].descripcion, "Mantel 2x2");
    p[1].codigo = 2;
    p[1].precio = 800.99;
    strcpy(p[1].descripcion, "Plat playo 24cm");
    p[2].codigo = 3;
    p[2].precio = 1450.50;
    strcpy(p[2].descripcion, "Copa vino");
    p[3].codigo = 4;
    p[3].precio = 650.50;
    strcpy(p[3].descripcion, "Plato hondo 22cm");
}

void registrarVenta(struct Venta v[], int numVent, struct Producto p[])
{
    int des, ind, valido;
    float totalFinal, quinse = 0.85, diez = 0.10, cero = 1;

    printf("\nIngrese el DNI: ");
    scanf("%ld", &v[numVent].dni);
    valido = validaDni(v[numVent].dni);
    while (valido != 0)
    {
        printf("\n\tDNI mal ingresado, Vuelva a intentarlo: ");
        scanf("%ld", &v[numVent].dni);
        valido = validaDni(v[numVent].dni);
    }

    printf("\n\tIngrese medio de pago. \n.1Efectivo\n.2Debito\n.3Credito\n");
    scanf("%d", &des);
    valido = validaPago(des);
    while (valido != 0)
    {
        printf("\n\tMedio de Pago mal ingresado, Vuelva a intentarlo: ");
        scanf("%d", &des);
        valido = validaPago(des);
    }
    v[numVent].desc = DESCUENTO[des - 1];

    printf("\nIngrese el codigo: ");
    scanf("%d", &v[numVent].codigo);
    valido = validaCodigo(v[numVent].codigo);
    while (valido != 0)
    {
        printf("\n\tCodigo mal ingresado, Vuelva a intentarlo: ");
        scanf("%d", &v[numVent].codigo);
        valido = validaCodigo(v[numVent].codigo);
    }

    printf("\nIngrese la cantidad: ");
    scanf("%d", &v[numVent].cant);
    valido = validaCantidad(v[numVent].cant);
    while (valido != 0)
    {
        printf("\n\tla Cantidad debe ser mayor a 0, Vuelva a intentarlo: ");
        scanf("%d", &v[numVent].cant);
        valido = validaCantidad(v[numVent].cant);
    }

    ind = buscarIndice(v[numVent].codigo, p);
    totalFinal = (v[numVent].cant * p[ind].precio) * IVA;
    switch (des - 1)
    {
    case 0:
        totalFinal *= quinse;
        break;
    case 1:
        totalFinal *= diez;
        break;
    case 2:
        totalFinal *= cero;
        break;
    default:
        break;
    }
    v[numVent].total = totalFinal;
}
int buscarIndice(int codigo, struct Producto p[])
{
    for (int i = 0; i < CANT_MAX; i++)
    {
        if (codigo == p[i].codigo)
        {
            return i;
            break;
        }
    }
}
int validaDni(long int v)
{
    if (v < 10000000 || v > 99999999)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validaCodigo(int v)
{
    if (v < 1 || v > 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validaPago(int v)
{
    if (v < 1 || v > 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validaCantidad(int v)
{
    if (v <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void mostrarProductos(struct Producto p[])
{
    printf("\nCodigo\t\tPrecio\t\t\tDescipcion.");
    for (int i = 0; i < CANT_MAX; i++)
    {
        printf("\n0%d\t\t%.2f\t\t\t%s\n", p[i].codigo, p[i].precio, p[i].descripcion);
        printf("\n-------------------------------------------------\n");
    }
}

void resumenDelDia(struct Venta v[], int numVent)
{
    if (validaVenta(numVent)==0){
        return;
    }
    printf("\nResumen Del Dia: ");
    for (int i = 0; i < numVent; i++)
    {
        printf("\nDNI: %ld \nPorsentaje de Descuento %.2f %% \nCodigo Producto %d \nCantidad Pedida: %d\nTotal: %.2f", v[i].dni, v[i].desc, v[i].codigo, v[i].cant, v[i].total);
        printf("\n-------------------------------------------------\n");
    
    }
}

int validaVenta(int numVenta)
{
    if (numVenta == 0)
    {
        printf("\n\tNo hay ventas Registradas..");
        return 0;
    }
}
