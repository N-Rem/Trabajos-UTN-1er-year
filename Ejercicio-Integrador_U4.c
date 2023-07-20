// Ejercicio de programacion; de PSeInt pasado a C.
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define efectivo 0.15
#define debito 0.10
#define credito 0
#define iva 1.21
#define descuentos [] { efectivo, debito, credito }

#define CANT_MAX 10
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
    int desc;
    int codigo;
    int cant;
    float total;
};

void cargarProducto(struct Producto p[]);
void registrarVenta(struct Venta v[], int cantVent);

int main()
{
    int opcion = 0, vent = 1;
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
            printf("-Ingreso de Ventas-");
            registrarVenta(ventas, vent);
            vent++;
            break;
        case 2:
            printf("Proximamente");
            break;
        case 3:
            printf("\nResumen Del Dia: ");
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
    // p[0].descripcion[CHAR_MAX] = "Mantel 2x2";
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

void registrarVenta(struct Venta v[], int cantVent)
{
    int descuento;
    printf("\n\tIngrese el DNI: ");
    scanf("%ld", &v[cantVent - 1].dni);

    printf("\n\tIngrese medio de pago. \n.1Efectivo\n.2Debito\n.3Credito\n");
    scanf("%d", &descuento);
    v[cantVent - 1].desc = descuento - 1;

    printf("\n\tIngrese el codigo: ");
    scanf("%d", &v[cantVent - 1].codigo);

    printf("\n\tIngrese la cantidad: ");
    scanf("%d", &v[cantVent - 1].cant);

}