#include "minitalk.h"


void ft_handler(int signal)
{
    static int              bit;
    static unsigned char    i;

    if (signal == SIGONE)
        i |= (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", i);
        bit = 0;
        i = 0;
    }
}

int main(int ac, char **av)
{
    if (ac != 1)
    {
        ft_printf("You should use like that :\n./server");
        return (0);
    }
    ft_print_pid();
    while (ac == 1)
    {
        signal(SIGONE, ft_handler);
        signal(SIGZERO, ft_handler);
        pause();
    }
    return (0);
}
