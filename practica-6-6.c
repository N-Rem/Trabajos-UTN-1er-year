// Crear una función que reciba un caracter y un número, y escriba un “triángulo”
// formado por ese caracter, que tenga como anchura inicial la que se ha indicado. Por


#include <stdio.h>
#include <string.h>

void crearTriangulo(int tamanio, char caracrer);
int main()
{
    char caracter;
    int largo, inicio = 0;
    while (inicio < 4)
    {
        inicio++;
        printf("\nIngrese en largo del triangulo: ");
        scanf("%d", &largo);
        printf("\nIngrese un caracter que dese para el triangulo: ");
        scanf("%s", &caracter);
        crearTriangulo(largo, caracter);
    }
    return 0;
}

void crearTriangulo(int tamanio, char caracrer)
{
    for (int i = 0; i < tamanio; i++)
    {
        printf("\n");
        for (int j = i; j < tamanio; j++)
        {
            printf(" %c ", caracrer);
        }
    }
}
