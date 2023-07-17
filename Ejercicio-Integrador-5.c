#include <stdio.h>
#include <stdlib.h>
#define MAX_TAM 2

int numerosID[MAX_TAM];
float pesos[MAX_TAM];
int destinos[MAX_TAM];
int horasPlanificadas[MAX_TAM];
int estados[MAX_TAM];

void cargarEnvios(int *cargado);
void mostrarEnvios(int cargado);
void modificarEstadoDeUnEnvio(int cargado);
void mostrarEnvioParaDestino(int destino, int cargado);

void main()
{
    int opcion = 0;
    int destino = 0;
    int envioCargado = 0;
    do
    {
        printf("\n1- Cargar env%cos planificados.", 161);
        printf("\n2- Mostrar env%cos planificados.", 161);
        printf("\n3- Modificar estado de un env%co.", 161);
        printf("\n4- Mostrar env%cos para un destino.", 161);
        printf("\n5- Mostrar envíos pendientes.");
        printf("\n6- Mostrar envíos despachados.");
        printf("\n7- Mostrar envío de mayor peso.");
        printf("\n8- Mostrar envío de menor peso.");
        printf("\n9- Mostrar envíos de mayor peso (más de un mayor)");
        printf("\10- Mostrar envíos de menor peso (más de un menor)");
        printf("\n11- Mostrar envíos despachados.");
        printf("\n0- Salir.\n\n");
        scanf("%d", &opcion);

        if (opcion != 5)
        {
            switch (opcion)
            {
            case 1:
                // Cargar envíos planificados
                cargarEnvios(&envioCargado);
                break;
            case 2:
                // Mostrar envíos planificados
                mostrarEnvios(envioCargado);
                break;
            case 3:

                // Modificar estado de un envío
                modificarEstadoDeUnEnvio(envioCargado);
                break;
            case 4:

                // Mostrar envíos para un destino
                printf("Destino a buscar: ");
                printf("\n1- Rosario");
                printf("\n2- Funes");
                printf("\n3- Roldan");
                printf("\n4- Baigorria");
                printf("\n");
                scanf("%i", &destino);

                mostrarEnvioParaDestino(destino, envioCargado);

                break;
            case 5:
                printf("Proximamente");

                break;
            case 6:
                printf("Proximamente");

                break;
            case 7:
                printf("Proximamente");

                break;
            case 8:
                printf("Proximamente");

                break;
            case 9:
                printf("Proximamente");
            
                break;
            case 10:
                printf("Proximamente");

                break;
            case 11:
                printf("Proximamente");

                break;
            case 0:
                printf("Proximamente");

                break;
            default:
                printf("La opci%cn ingresada es inv%clida\n", 162, 160);
            }
        }

    } while (opcion != 0);
    printf("Fin del Progama.");
}

void cargarEnvios(int *cargado) // parametro cargado para verificar si se cargaron o no los envios.
{
    int ochoHs = 8, diezHs = 22;
    printf("---Ingrese los datos de los env%cos---\n", 161);

    for (int i = 0; i < MAX_TAM; i++)
    {
        printf("\n\t\tEnvio N%i:\n", i + 1);
        printf("\nNro. de env%co: ", 161);
        scanf("%d", &numerosID[i]);

        printf("\nIngrese el peso: ");
        scanf("%f", &pesos[i]);

        printf("\nIngrese el destino: ");
        printf("\n1- Rosario");
        printf("\n2- Funes");
        printf("\n3- Roldan");
        printf("\n4- Baigorria");
        printf("\n");
        scanf("%i", &destinos[i]);

        printf("\nIngrese la hora entre las 8am y las 22pm: ");
        scanf("%d", &horasPlanificadas[i]);
        while (horasPlanificadas[i] < ochoHs || horasPlanificadas[i] > diezHs)
        {
            printf("\nIngrese un valor valido: ");
            scanf("%d", &horasPlanificadas[i]);
        }

        printf("\nIngrese el estado: ");
        printf("\n0- Pendiente");
        printf("\n1- Despachado");
        printf("\n");
        scanf("%d", &estados[i]);
    }
    *cargado = 1;
}

void mostrarEnvios(int cargado)
{
    if (cargado == 0)
    {
        printf("Usted no cargo los datos debidamente");
    }
    else
    {
        printf("-ID-\t-Peso kg-\t-Destino-\t-Hora-\t\t-Estado-\n");
        for (int i = 0; i < MAX_TAM; i++)
        {
            printf("%d", numerosID[i]);
            printf("\t%.2f \t", pesos[i]);
            switch (destinos[i])
            {
            case 1:
                printf("\tRosario\t");
                break;
            case 2:
                printf("\tFunes\t");
                break;
            case 3:
                printf("\tRoldan\t");
                break;
            case 4:
                printf("\tBaigorria\t");
                break;
            default:
                printf("\tDestino inv%clido\t", 160);
            }

            printf("\t%d hs\t", horasPlanificadas[i]);

            switch (estados[i])
            {
            case 0:
                printf("Pendiente");
                break;
            case 1:
                printf("Despachado");
                break;
            default:
                printf("Estado inv%clido\n", 160);
            }

            printf("\n");
        }
    }
}

void modificarEstadoDeUnEnvio(int cargado)
{
    if (cargado == 0)
    {
        printf("Usted no cargo los datos debidamente");
    }
    else
    {
        int nroID = 0, estado = 0;
        int encontrado = 0;

        printf("Nro del env%co a modificar:", 161);
        scanf("%d", &nroID);
        for (int i = 0; i < MAX_TAM; i++)
        {
            if (nroID == numerosID[i])
            {
                encontrado = i;
            }
        }

        printf("\nIngrese el estado Nuevo: ");
        printf("\n0- Pendiente");
        printf("\n1- Despachado");
        printf("\n");
        scanf("%d", &estados[encontrado]);
    }
}

void mostrarEnvioParaDestino(int destino, int cargado)
{
    if (cargado == 0)
    {
        printf("Usted no cargo los datos debidamente");
    }
    else
    {
        for (int i = 0; i < MAX_TAM; i++)
        {
            if (destinos[i] == destino)
            {
                printf("%d", numerosID[i]);
                printf("\t%.2f \t", pesos[i]);
                switch (destinos[i])
                {
                case 1:
                    printf("\tRosario\t");
                    break;
                case 2:
                    printf("\tFunes\t");
                    break;
                case 3:
                    printf("\tRoldan\t");
                    break;
                case 4:
                    printf("\tBaigorria\t");
                    break;
                default:
                    printf("\tDestino inv%clido\t", 160);
                }

                printf("\t%d hs\t", horasPlanificadas[i]);

                switch (estados[i])
                {
                case 0:
                    printf("Pendiente");
                    break;
                case 1:
                    printf("Despachado");
                    break;
                default:
                    printf("Estado inv%clido\n", 160);
                }

                printf("\n");
            }
        }
    }
}
