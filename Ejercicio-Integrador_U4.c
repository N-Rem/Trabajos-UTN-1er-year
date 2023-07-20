// Ejercicio de programacion; de PSeInt pasado a C.
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define EFECTIVO 0.85
#define DEBITO 0.90
#define CREDITO 1
#define IVA 1.21

#define CANT_MAX 4
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

void mostrarProductos(struct Producto p[]);
void resumenDelDia(struct Venta v[], int numVent);
// array Global--
float DESCUENTO[3] = {EFECTIVO, EFECTIVO, CREDITO};

int main()
{
    int opcion = 0, vent = 0;
    struct Producto productos[CANT_MAX];
    cargarProducto(productos);
    struct Venta ventas[vent];
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
            printf("\nResumen Del Dia: ");
            resumenDelDia(ventas, vent);
            break;
        case 4:
            printf("\n\tFin del progama.\n Gracias...");
            break;
        default:
            printf("\n\t\tOpcion mal escrita..");
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
    p[2].codigo = 03;
    p[2].precio = 1450.50;
    strcpy(p[2].descripcion, "Copa vino");
    p[3].codigo = 04;
    p[3].precio = 650.50;
    strcpy(p[3].descripcion, "Plato hondo 22cm");
}

void registrarVenta(struct Venta v[], int numVent, struct Producto p[])
{
    int des, ind;
    float totalFinal;

    printf("\n\tIngrese el DNI: ");
    scanf("%ld", &v[numVent].dni);
    printf("\n\tIngrese medio de pago. \n.1Efectivo\n.2Debito\n.3Credito\n");
    scanf("%d", &des);
    v[numVent].desc = DESCUENTO[des - 1];
    printf("\n\tIngrese el codigo: ");
    scanf("%d", &v[numVent].codigo);
    printf("\n\tIngrese la cantidad: ");
    scanf("%d", &v[numVent].cant);

    ind = buscarIndice(v[numVent].codigo, p);
    totalFinal = (v[numVent].cant * p[ind].precio) * v[numVent].desc*IVA;
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

void mostrarProductos(struct Producto p[])
{
    printf("\nCodigo\t\tPrecio\t\t\tDescipcion.");
    for (int i = 0; i < CANT_MAX; i++)
    {
        printf("\n%d\t\t%.2f\t\t\t%s\n", p[i].codigo, p[i].precio, p[i].descripcion);
    }
}

void resumenDelDia(struct Venta v[], int numVent)
{
    for (int i = 0; i < numVent; i++)
    {
        printf("\nDNI: %ld \nPorsentaje de Descuento %.2f %% \nCodigo Producto %d \nCantidad Pedida: %d\nTotal: %.2f", v[i].dni, v[i].desc, v[i].codigo, v[i].cant, v[i].total);
    }
}


