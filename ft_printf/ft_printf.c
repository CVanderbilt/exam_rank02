#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define PUTCHAR(c) write(1, &c, 1)
#define ISDIGIT(c) (c >= 48 && c <= 57)

typedef struct  s_data
{
    int size;
    int pos;
    const char *str;
    char type;
    int p;
    int w;
    int error;
    va_list args;
}               t_data;

int ft_atoi(const char *str)
{
    int num = 0;
    for (int i = 0; ISDIGIT(str[i]); i++)
    {
        num *= 10;
        num += str[i] - 48;
    }
    return (num);
}

void ft_setwp(t_data *data)
{
    if (ISDIGIT(data->str[data->pos]))
    {
        //calcula width
        data->w = ft_atoi(data->str + data->pos);
        while (ISDIGIT(data->str[data->pos]))
            data->pos++;
    }
    if (data->str[data->pos] == '.')
    {
        //calcula precision
        data->pos++;
        data->p = ft_atoi(data->str + data->pos);
        while (ISDIGIT(data->str[data->pos]))
            data->pos++;
    }
}

void ft_reinit(t_data *data)
{
    data->p = -1;
    data->w  = 0;
    data->type = 0;
}

int ft_strlen(const char* str)
{
    int len = 0;
    while(str[len])
        len++;
    return (len);
}

char *ft_strdup(const char *str)
{
    int len = ft_strlen(str);

    char *ret;

    if (!(ret = (char*)malloc(len + 1)))
        return (0);
    
    for (int i = 0; str[i]; i++)
        ret[i] = str[i];
    ret[len] = 0;
    return (ret);
}

int ft_digitsbase(long int num, int base)
{
    int ret = 0;
    while (num)
    {
        ret++;
        num /= base;
    }
    return (ret);
}

char *ft_itoa(long int num)
{
    int dgts = ft_digitsbase(num, 10);
    char *ret;

    if (!(ret = (char*)malloc(dgts + 1)))
        return (0);
    ret[dgts] = 0;
    
    for (int i = 0; i < dgts; i++)
    {
        ret[dgts - 1 - i] = 48 + num % 10;
        num /= 10;
    }
    return (ret);
}

char *ft_xtoa(long int num)
{
    int dgts = ft_digitsbase(num, 16);
    char *ret;
    char base[] = "0123456789abcdef";

    if (!(ret = (char*)malloc(dgts + 1)))
        return (0);
    ret[dgts] = 0;

    for (int i = 0; i < dgts; i++)
    {
        ret[dgts - 1 - i] = base[num % 16];
        num /= 16;
    }
    return (ret);
}

char *ft_append(char *tgt, char *str)
{
    char *ret;
    int len1 = ft_strlen(tgt);
    int len2 = ft_strlen(str);

    if (!(ret = (char*)malloc(len1 + len2 + 1)))
        return (0);
    
    for (int i = 0; i < len1 + len2; i++)
        ret[i] = i < len1 ? tgt[i] : str[i - len1];

    ret[len1 + len2] = 0;

    return (ret);
}

char *ft_pmod(t_data *data, char *str)
{
    int len = ft_strlen(str);
    char *ret = str;

    if (data->p < 0)
        return (str);

    if (data->type == 's')
    {
        if (len > data->p)
        {
            if(!(ret = (char*)malloc(data->p + 1)))
                return (0);
            for (int i = 0; i < data->p; i++)
                ret[i] = str[i];
            free (str);
            ret[data->p] = 0;
        }
    }
    else //type = d o x pero se comportan exactamente igual
        if (data->p > len)
        {
            if(!(ret = (char*)malloc(data->p - len + 1)))
                return (0);
            for (int i = 0; i < data->p - len; i++)
                ret[i] = '0';
            ret = ft_append(ret, str);
            free (str);
        }
    return (ret);
}

char *ft_wmod(t_data *data, char *str)
{
    int len = ft_strlen(str);
    char *ret = str;

    if (data->w > len)
    {
        if(!(ret = (char*)malloc(data->w - len + 1)))
                return (0);
        for (int i = 0; i < data->w - len; i++)
            ret[i] = ' ';
        ret[data->w - len] = 0;
        ret = ft_append(ret, str);
    }
    return (ret);
}

char *ft_mod(t_data *data, char *str)
{
    //printf("va a modificar >%s<\n", str);
    str = ft_pmod(data, str);
    //printf("precision aplicada %d >%s<\n", data->p, str);
    str = ft_wmod(data, str);
    //printf("width aplicada %d >%s<\n", data->w, str);
    return (str);
}

void ft_putstr(const char *str)
{
    for (int i = 0; str[i]; i++)
        PUTCHAR(str[i]);
}

void ft_print_segment(t_data *data)
{
    char *str;
    if (data->type == 's')
        str = ft_strdup(va_arg(data->args, char*));
    else if (data->type == 'd')
        str = ft_itoa(va_arg(data->args, int));
    else if (data->type == 'x')
        str = ft_xtoa(va_arg(data->args, unsigned int));
    else
    {
        data->error++;
        return ;
    }

    str = ft_mod(data, str);
    ft_putstr(str);
    data->size += ft_strlen(str);
    free (str);
}

int ft_printf(const char *str, ... )
{
    t_data data;
    
    va_start(data.args, str);

    data.pos = 0;
    data.size = 0;
    data.str = str;
    data.type = 0;
    data.p = -1;
    data.w = 0;
    data.error = 0;

    while (str[data.pos])
    {
        if (str[data.pos] != '%')
        {
            PUTCHAR(str[data.pos]);
            data.pos++;
            data.size++;
        }
        else
        {
            data.pos++;
            ft_reinit(&data);
            ft_setwp(&data);
            data.type = str[data.pos];
            //printf("el tipo es >%c<\n", data.type);
            ft_print_segment(&data);
            data.pos++;
        }
    }
    return (data.size);
}