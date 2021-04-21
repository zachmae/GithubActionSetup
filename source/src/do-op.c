//
// Created by vasek on 19/09/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "do-op.h"

/**
 * Compute function
 *
 * @param nb1 - First number
 * @param op - Operator
 * @param nb2 - Second number
 * @return - Computed numbers
 * @throw Invalid operator
 * @throw Divide by 0
 * @throw Modulo by 0
 */
size_t do_op(long int nb1, char op, long int nb2)
{
    switch (op) {
        case ADD:
            return nb1 + nb2;
        case SUB:
            return nb1 - nb2;
        case MUL:
            return nb1 * nb2;
        case MOD:
            if (nb2 == 0) {
                EXIT_ERROR("%ld %c %ld: modulo by 0\n", nb1, op, nb2);
            }
            return nb1 % nb2;
        case DIV:
            if (nb2 == 0) {
                EXIT_ERROR("%ld %c %ld: modulo by 0\n", nb1, op, nb2);
            }
            return nb1 / nb2;
        default:
            EXIT_ERROR("%c: Invalid operator\n", op);

    }
}