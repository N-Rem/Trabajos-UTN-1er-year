#include <stdio.h>
#define MAX_CHAR 100
#define CANTIDAD_EMP 2
#define SUELDO_PLANTA 2000
#define SUELDO_ADMIN 1500
#define SUELDO_VEND 1000

struct Empleado
{
    int legajo;
    char name[MAX_CHAR];
    char lname[MAX_CHAR];
    int hs;
    int categoria;
};
//! Prototipos.
int validarLegajo(int legajo);
int validarHoras(int hs);
int validarCategoria(int categoria);
void cargarEmpleados(struct Empleado empleados[], int *carga);

void mostrarEmpleados(struct Empleado empleados[]);

int comprobarExistencia(struct Empleado emp[], int legajo);
int buscarEmpleado(struct Empleado emp[], int legajo);
int calcularSueldo(struct Empleado emp[], int ind);
void mostrarSueldo(struct Empleado emp[], int legajo); //! puedo poner emp porque es irrelebante el nombre, si es importante el tipo (estruc) y el nombre del padre.

void cambiarCategoria(struct Empleado emp[], int legajo);

int main()
{
    int inicio, legajo, carga;
    carga = 0;
    struct Empleado empleados[CANTIDAD_EMP];
    inicio = 1;

    while (inicio != 5)
    {
        printf("\n\tSeleccione una opcion. \n1.Cargar empleados.\n2.Mostrar empleados.\n3.Mostrar el sueldo de un empleado.\n4.Modificar la categoria de un empleado.\n5.Salir.\n");
        scanf("%d", &inicio);
        switch (inicio)
        {
        case 1:
            printf("\tCargar Empleados: ");
            cargarEmpleados(empleados, &carga);
            break;
        case 2:
            if (carga == 1)
            {
                printf("\t----->Lista Empleados<-----");
                mostrarEmpleados(empleados);
            }
            else
            {
                printf("\nPrimero Cargue los Empelados.\n");
            }
            break;
        case 3:
            if (carga == 1)
            {
                printf("Digite el Legajo del empleado: ");
                scanf("%d", &legajo);
                mostrarSueldo(empleados, legajo);
            }
            else
            {
                printf("\nPrimero Cargue los Empelados.\n");
            }
            break;
        case 4:
            if (carga == 1)
            {
                printf("Digite el legajo del empleado: ");
                scanf("%d", &legajo);
                cambiarCategoria(empleados, legajo);
            }
            else
            {
                printf("\nPrimero Cargue los Empelados.\n");
            }
            break;
        case 5:
            printf("\t\tUsted salio de la aplicacion. Muchas Gracias.");
            break;

        default:
            printf("\nOpcion incorrecta, vuelva a intentarlo.");
            break;
        }
    }
}

void cargarEmpleados(struct Empleado empleados[], int *carga)
{ // se pone como parametro el tipo de dato struct mas el nombre de la estructura padre MAS el nombre de la estrucutra deseada.
    int valido;
    for (int i = 0; i < CANTIDAD_EMP; i++)
    {
        printf("\nDigite el legajo del empleado Numero %d:  ", i + 1);
        scanf("%d", &empleados[i].legajo);
        valido = validarLegajo(empleados[i].legajo);

        while (valido == 0)
        {
            printf("\nEl legajo debe estar entre 10000 y 99999. Vuelva a intentar: ");
            scanf("%d", &empleados[i].legajo);
            valido = validarLegajo(empleados[i].legajo);
        }

        printf("\nDigite el Nombre del empleado Numero %d:  ", i + 1);
        scanf("%s", empleados[i].name);

        printf("\nDigite el Apellido del empleado Numero %d:  ", i + 1);
        scanf("%s", empleados[i].lname);

        printf("\nDigite las horas trabajadas del empleado Numero %d.\n(solo numeros redondos)\n\t", i + 1);
        scanf("%d", &empleados[i].hs);
        valido = validarHoras(empleados[i].hs);
        while (valido == 0)
        {
            printf("\nLas horas deben ser mayor a 0. Vuelva a intentar: ");
            scanf("%d", &empleados[i].hs);
            valido = validarHoras(empleados[i].hs);
        }

        printf("\nDigite la categoria del empleado Numero %d.\n1.Planta \n2.Administrativo \n3.Vendedor\n\t", i + 1);
        scanf("%d", &empleados[i].categoria);
        valido = validarCategoria(empleados[i].categoria);
        while (valido == 0)
        {
            printf("\nLas categoria es incorrecta debe ser \n1.Planta \n2.Administrativo \n3.Vendedor. \nVuelva a intentar: ");
            scanf("%d", &empleados[i].categoria);
            valido = validarCategoria(empleados[i].categoria);
        }
    }
    *carga = 1;
}

int validarLegajo(int legajo)
{
    int min, max;
    max = 99999;
    min = 10000;

    if (legajo > max || legajo < min)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int validarHoras(int hs)
{
    int min;
    min = 1;
    if (hs >= min)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarCategoria(int categoria)
{
    int plant, admin, vend;
    plant = 1;
    admin = 2;
    vend = 3;
    if (categoria == plant || categoria == admin || categoria == vend)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void mostrarEmpleados(struct Empleado empleados[])
{
    for (int i = 0; i < CANTIDAD_EMP; i++)
    {
        printf("\nLegajo: %d.", empleados[i].legajo);
        printf("\nNombre: %s. \nApellido: %s. \nHoras trabajadas: %d hs.", empleados[i].name, empleados[i].lname, empleados[i].hs);
        printf("\nCategoria: ");
        switch (empleados[i].categoria)
        {
        case 1:
            printf("Planta.");
            break;
        case 2:
            printf("Administrativo.");
            break;
        case 3:
            printf("Vendedor.");
            break;
        }
        printf("\n\t-------------------------------------------\n");
    }
}

void mostrarSueldo(struct Empleado emp[], int legajo)
{
    int ind, sueldo, existe;
    existe = comprobarExistencia(emp, legajo);
    if (existe == 1)
    {
        ind = buscarEmpleado(emp, legajo);
        sueldo = calcularSueldo(emp, ind);
        printf("\n\tSueldo del empleado %s, %s de legajo: %d\n\t---%d$---\n", emp[ind].lname, emp[ind].name, emp[ind].legajo, sueldo);
    }
    else
    {
        printf("El legajo no existe.");
    }
}

int buscarEmpleado(struct Empleado emp[], int legajo)
{
    for (int i = 0; i < CANTIDAD_EMP; i++)
    {
        if (emp[i].legajo == legajo)
        {
            return i;
            break;
        }
    }
}
int comprobarExistencia(struct Empleado emp[], int legajo)
{
    for (int i = 0; i < CANTIDAD_EMP; i++)
    {
        if (emp[i].legajo == legajo)
        {
            return 1;
            break;
        }
    }
    return 0;
}
int calcularSueldo(struct Empleado emp[], int ind)
{
    int sueldo, categoria;
    categoria = emp[ind].categoria;
    switch (categoria)
    {
    case 1:
        sueldo = SUELDO_PLANTA * emp[ind].hs;
        return sueldo;
        break;
    case 2:
        sueldo = SUELDO_ADMIN * emp[ind].hs;
        return sueldo;
        break;
    case 3:
        sueldo = SUELDO_VEND * emp[ind].hs;
        return sueldo;
        break;
    }
}

void cambiarCategoria(struct Empleado emp[], int legajo)
{
    int existe, ind, valido;
    existe = comprobarExistencia(emp, legajo);
    if (existe == 1)
    {
        ind = buscarEmpleado(emp, legajo);
        printf("\nDigite la categoria del empleado %d.\n1.Planta \n2.Administrativo \n3.Vendedor\n\t", emp[ind].legajo);
        scanf("%d", &emp[ind].categoria);
        valido = validarCategoria(emp[ind].categoria);
        while (valido == 0)
        {
            printf("\nLas categoria es incorrecta debe ser \n1.Planta \n2.Administrativo \n3.Vendedor. \nVuelva a intentar: ");
            scanf("%d", &emp[ind].categoria);
            valido = validarCategoria(emp[ind].categoria);
        }
    }
    else
    {
        printf("El legajo no existe.");
    }
}
