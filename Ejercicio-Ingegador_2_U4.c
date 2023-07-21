#include <stdio.h>
#include <string.h>

int main()
{
    int opcion = 0;

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
