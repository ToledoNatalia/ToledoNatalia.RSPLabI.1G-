#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path, LinkedList* pListaBicicletas);
int controller_ListarBicicletas(LinkedList* pListaBicicletas);
int controller_guardarComoTexto(char* path, LinkedList* pListaBicicletas);
int controller_sortBicicletas(LinkedList* pListaBicicletas);

#endif // CONTROLLER_H_INCLUDED
