#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <time.h>
#include "bicicletas.h"
#include "controller.h"

int menu();


int main()
{

    srand (time(NULL));

    int ordenar = 0;
    int tiempo = 0;
    char seguir = 'n';
    char archivo[51];


    LinkedList* listaBicicletas = ll_newLinkedList();

    do
    {
        switch(menu())
        {
        case 1:
            printf("\nIngrese el nombre del archivo con su extension: ");
            scanf("%s", archivo);
            controller_loadFromText(archivo, listaBicicletas);
            system("pause");
            break;

        case 2:
            if( !ll_isEmpty(listaBicicletas))
            {
                controller_ListarBicicletas(listaBicicletas);
            }
            else
            {
                printf("Primero debe cargar el archivo..\n");
            }
            system("pause");
            break;

        case 3:

            if( !ll_isEmpty(listaBicicletas))
            {
                listaBicicletas = ll_map(listaBicicletas, cambiarTiempo);
                printf(" tiempos asignados con exito!....\n");
                tiempo = 1;
            }
            else
            {
                printf("Primero debe cargar el archivo.\n");
            }
            system("pause");
            break;

        case 4:
            if(!ll_isEmpty(listaBicicletas))
            {
                filtrarPorTipos(listaBicicletas);
            }
            else
            {
                printf("Error..Primero debe cargar el archivo.\n");
            }
            system("pause");
            break;

        case 5:
            if(!ll_isEmpty(listaBicicletas) && tiempo == 1)
            {
                controller_sortBicicletas(listaBicicletas);
                ordenar = 1;
            }
            else
            {
                printf("Error, debe cargar el archivo y asignar los tiempos.\n");
            }
            system("pause");
            break;

        case 6:
            if(!ll_isEmpty(listaBicicletas) && ordenar == 1)
            {
                controller_guardarComoTexto("bicisOrdenadas.csv", listaBicicletas);

                printf("Se genero el archivo bicisOrdenadas.csv\n");
            }
            else
            {
                printf("Primero debe cargar el archivo y ordenarlo.\n");
            }
            system("pause");
            break;

        case 7:
            printf("Presione 's' para confirmar la salida: ");
            fflush(stdin);
            scanf("%c", &seguir);
            break;

        default:
            printf("\n Opcion invalida.\n\n");
            system("pause");
            break;
        }

    }
    while(seguir != 's');

    ll_deleteLinkedList(listaBicicletas);

    return 0;
}


int menu()
{
    int opcion;

    system("cls");

    printf("**************** MENU BICICLETAS ****************** \n\n");
    printf("1. Cargar archivo. \n");
    printf("2. Imprimir lista. \n");
    printf("3. Asignar tiempos.\n");
    printf("4. Filtrar por tipo.\n");
    printf("5. Mostrar posiciones,ordenadas por tipo y tiempo\n");
    printf("6. Guardar posiciones.\n");
    printf("7. Salir.\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}






