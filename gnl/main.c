#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *line;
    int contador = 0;

    while (get_next_line(&line))
    {
        printf("linea %d:%s\n", contador, line);
        contador++;
        free(line);
    }
    printf("linea %d:%s\n", contador, line);
    free(line);
    printf("bucle, ahora escribe en otra consola leaks \"nombre_del_programa\"\n");
    while(1);
    return (0);
}