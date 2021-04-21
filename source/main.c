//
// Created by vasek on 19/09/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "do-op.h"

size_t do_op(long int nb1, char op, long int nb2);
long int get_number(char *number);

int main(int ac, char **av)
{
    if (ac != 4) {
        EXIT_ERROR("Invalid arguments\n", NULL);
    }

    if (strlen(av[2]) != 1) {
        EXIT_ERROR("%s: Invalid operator\n", av[2]);
    }

    const char op = av[2][0];
    long int nb1 = get_number(av[1]);
    long int nb2 = get_number(av[3]);

    const size_t result = do_op(nb1, op, nb2);
    printf("Result: %ld\n", result);

    exit(0);
}