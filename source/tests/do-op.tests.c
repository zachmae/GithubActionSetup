//
// Created by vasek on 19/09/2020.
//

#include <criterion/criterion.h>
#include "do-op.h"

size_t do_op(long int nb1, char op, long int nb2);

/**
 * Operations tests suite
 */
Test(basic, addition)
{
    const size_t result = do_op(2, ADD, 54);
    cr_expect_eq(2 + 54, result);
}

Test(basic, substraction)
{
    const size_t result = do_op(9, SUB, 4);
    cr_expect_eq(9 - 4, result);
}

Test(basic, multiplication)
{
    const size_t result = do_op(75, MUL, 3);
    cr_expect_eq(75 * 3, result);
}

Test(basic, modulo)
{
    const size_t result = do_op(3432, MOD,4);
    cr_expect_eq(3432 % 4, result);
}

Test(basic, divide)
{
    const size_t result = do_op(6, DIV, 3);
    cr_expect_eq(6 / 3, result);
}

/**
 * Error handling on do_op
 */
Test(error_handling, modulo_by_0, .exit_code=84)
{
    do_op(2, MOD, 0);
}

Test(error_handling, divide_by_0, .exit_code=84)
{
    do_op(2, DIV, 0);
}

Test(error_handling, invalid_operator, .exit_code=84)
{
    do_op(2, 'x', 0);
}

