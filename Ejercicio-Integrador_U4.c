// Ejercicio de programacion; de PSeInt pasado a C.
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define efectivo 0.15
#define debito 0.10
#define credito 0
#define iva 1.21
// #define descuentos [0] efectivo
// #define descuentos [1] debito
// #define descuentos [2] credito
#define CANT_MAX 10
#define CHAR_MAX 100
struct Producto
{
    int codigo;
    float precio;
    char descripcion[CHAR_MAX];
};

void cargarProducto(struct Producto p[]);

int main()
{
    int opcion=0;
    struct Producto productos[CANT_MAX];
    cargarProducto(productos);
    do
    {
        printf("\n\t\tSelecione las siguientes opciones: \n 1. Registrar Ventas.\n 2. Ver listado de productos ordenados por descripcion.\n 3. Ver Resumen del dia.\n 4. Salir.");
        scanf("%d", &opcion);




    } while (opcion == 4);
    
    




    return 0;
}

void cargarProducto(struct Producto p[])
{

    p[0].codigo = 1;
    p[0].precio = 3500.00;
    // p[0].descripcion[CHAR_MAX] = "Mantel 2x2";
    strcpy(p[0].descripcion, "Mantel 2x2");
    p[1].codigo =2;
    p[1].precio =800.99;
    p[1].descripcion[CHAR_MAX] = "Plat playo 24cm";
    p[2].codigo =03;
    p[2].precio =1450.50;
    p[2].descripcion[CHAR_MAX] = "Copa vino";
    p[3].codigo =04;
    p[3].precio =650.50;
    p[3].descripcion[CHAR_MAX] = "Plato hondo 22cm";
}
