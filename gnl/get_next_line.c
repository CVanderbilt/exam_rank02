#include "get_next_line.h"

int get_next_line(char **line)
{
    static char *prev;
    char buff[33];
    int rb;

    if (!prev)
    {
        rb = read(0, buff, 32);
        buff[rb] = 0;
        prev = ft_strdup(buff);
        printf("primera vez que lee, ha leido >%s<\n", buff);
        return (get_next_line(line));
    }

    int eol;

    eol = ft_find_eol(prev);
    if (eol >= 0)
    {
        //recorta porque ha encontrado un salto de línea
        char *new_prev;
        prev[eol] = 0;
        *line = ft_strdup(prev);
        new_prev = ft_strdup(prev + eol + 1);
        free (prev);
        prev = new_prev;
        return (1); //return 1 porque ha leído una línea correctamente
    }
    else
    {
        //bucle de lectura hasta que encuentra eol
        while((rb = read(0, buff, 32)) > 0)
        {
            buff[rb] = 0;
            printf("vuelve a leer %d, ha leído >%s<\n", rb, buff);
            prev = ft_append(prev, buff);
            eol = ft_find_eol(prev);
            if (eol >= 0)
            {
                char *new_prev;
                prev[eol] = 0;
                *line = ft_strdup(prev);
                new_prev = ft_strdup(prev + eol + 1);
                free (prev);
                prev = new_prev;
                return (1); //return 1 porque ha leído una línea correctamente

            }
            // si no lo encuentra le toca volver a leer
        }
        if (rb == 0)
        {
            *line = prev;
            return (0); //return (0), ha encontrado el eof
        }
        return (-1); //error, no debería llegar aquí
    }
    
}