#include <stdio.h>

int		ft_printf(const char *str, ...);

int main(void)
{
    int n = ft_printf("prueba str >%14.3s<\n", "holapa");
    int t = printf("prueba str >%14.3s<\n", "holapa");
    printf("mio: %d\nsys: %d\n", n, t);

    printf("\nTEST %%s\n");

    ft_printf("0 w> -%10s-\n", "hola");
    printf("0 w> -%10s-\n", "hola");
    printf("\n");

    ft_printf("1 w< -%3s-\n", "hola");
    printf("1 w< -%3s-\n", "hola");
    printf("\n");

    ft_printf("2 p> -%.10s-\n", "hola");
    printf("2 p> -%.10s-\n", "hola");
    printf("\n");

    ft_printf("3 p< -%.3s-\n", "hola");
    printf("3 p< -%.3s-\n", "hola");
    printf("\n");

    ft_printf("4 w>p -%7.3s-\n", "holamundo");
    printf("4 w>p -%7.3s-\n", "holamundo");
    printf("\n");

    ft_printf("5 p>w -%4.7s-\n", "holamundo");
    printf("5 p>w -%4.7s-\n", "holamundo");
    printf("\n");

    ft_printf("6 w>p -%10.4s-\n", "holamundo");
    printf("6 w>p -%10.4s-\n", "holamundo");
    printf("\n");

    ft_printf("7 p>w -%10.15s-\n", "holamundo");
    printf("7 p>w -%10.15s-\n", "holamundo");
    printf("\n");

    printf("\nTEST %%d\n");                         //PRUEBAS DE ENTEROS

    printf("0 w> -%10d-\n", 12345);
    ft_printf("0 w> -%10d-\n", 12345);
    printf("\n");

    printf("1 w< -%3d-\n", 12345);
    ft_printf("1 w< -%3d-\n", 12345);
    printf("\n");

    printf("2 p> -%.10d-\n", 12345);
    ft_printf("2 p> -%.10d-\n", 12345);
    printf("\n");

    printf("3 p< -%.3d-\n", 12345);
    ft_printf("3 p< -%.3d-\n", 12345);
    printf("\n");

    printf("4 w>p -%4.3d-\n", 123456);
    ft_printf("4 w>p -%4.3d-\n", 123456);
    printf("\n");

    printf("5 p>w -%3.4d-\n", 123456);
    ft_printf("5 p>w -%3.4d-\n", 123456);
    printf("\n");

    printf("6 w>p -%10.7d-\n", 123456);
    ft_printf("6 w>p -%10.7d-\n", 123456);
    printf("\n");

    printf("7 p>w -%10.15d-\n", 123456);
    ft_printf("7 p>w -%10.15d-\n", 123456);
    printf("\n");

    printf("\nTEST %%d\n");                         //PRUEBAS DE HEXADECIMALES

    printf("w> -%10x-\n", 12345);
    ft_printf("w> -%10x-\n", 12345);
    printf("\n");

    printf("w< -%3x-\n", 12345);
    ft_printf("w< -%3x-\n", 12345);
    printf("\n");

    printf("p> -%.10x-\n", 12345);
    ft_printf("p> -%.10x-\n", 12345);
    printf("\n");

    printf("p< -%.3x-\n", 12345);
    ft_printf("p< -%.3x-\n", 12345);
    printf("\n");

    printf("w>p -%4.3x-\n", 123456);
    ft_printf("w>p -%4.3x-\n", 123456);
    printf("\n");

    printf("p>w -%3.4x-\n", 123456);
    ft_printf("p>w -%3.4x-\n", 123456);
    printf("\n");

    printf("w>p -%10.7x-\n", 123456);
    ft_printf("w>p -%10.7x-\n", 123456);
    printf("\n");

    printf("p>w -%10.15x-\n", 123456);
    ft_printf("p>w -%10.15x-\n", 123456);
    printf("\n");

    return (0);
}