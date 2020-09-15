#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int get_next_line(char **);

int ft_find_eol(char *str);
int ft_strlen(char *str);
char *ft_append(char *trg, char *str);
char *ft_strdup(char *str);

#endif