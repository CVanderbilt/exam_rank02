#include "get_next_line.h"

int ft_find_eol(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n' || str[i] == '\r')
            return (i);
    return (-1);
}

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}

char *ft_strdup(char *str)
{
    int len = ft_strlen(str);

    char *ret;

    if (!(ret = (char*)malloc(len + 1)))
        return (0);
    for (int i = 0; i < len; i++)
        ret[i] = str[i];
    ret[len] = 0;
    return (ret);
}

char *ft_append(char *trg, char *str)
{
    int len1, len2;
    char *ret;

    len1 = ft_strlen(trg);
    len2 = ft_strlen(str);

    if (!(ret = (char*)malloc(len1 + len2 + 1)))
        return (0);
    for (int i = 0; i < len1; i++)
        ret[i] = trg[i];
    for (int i = 0; i < len2; i++)
        ret[i + len1] = str[i];
    ret[len1 + len2] = 0;
    free(trg);
    return (ret);
}