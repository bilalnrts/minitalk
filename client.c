#include "minitalk.h"

void ft_send_bits(int pid, char c)
{
    static int bit;

    while (bit < 8)
    {
        if (c & (0x01 << bit) != 0)
            kill(pid, SIGONE);
        else
            kill(pid, SIGZERO);
        usleep(100);
        bit++;
    }

}

int main(int ac, char **av)
{
    int pid;
    int i;

    i = 0;
    if (ac == 3)
    {
        pid = ft_atoi(av[1]);
        while (av[2][i])
        {
            ft_send_bits(pid, av[2][i]);
            i++;
        }
        ft_send_bits(pid, '\n');
    }
    else
    {
        ft_printf("Wrong format. You have to use like this :\n");
        ft_printf("./client <PID> <MESSAGE>\n");
    }
    return (0);
}