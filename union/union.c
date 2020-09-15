#include <unistd.h>

int main(int argc, char *argv[])
{
    int array[127];

    for (int i = 0; i < 127; i++)
        array[i] = 1;
    
    if (argc == 3)
    {
        for (int i = 0; argv[1][i]; i++)
            if (array[(int)argv[1][i]])
            {
                array[(int)argv[1][i]] = 0;
                write(1, argv[1] + i, 1);
            }
        for (int i = 0; argv[2][i]; i++)
            if (array[(int)argv[2][i]])
            {
                array[(int)argv[2][i]] = 0;
                write(1, argv[2] + i, 1);
            }
    }
    
    write(1, "\n", 1);
}