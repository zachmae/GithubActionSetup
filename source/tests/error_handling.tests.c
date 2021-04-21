//
// Created by vasek on 20/09/2020.
//

#include <criterion/criterion.h>
#include "do-op.h"

long int get_number(char *number);

/**
 * Basic functional
 */
Test(basic, convertion)
{
    const long int result = get_number("56");
    cr_expect_eq(56, result);
}

/**
 * Error handling
 */
Test(error_handling, no_number, .exit_code=84)
{
    get_number("abcsdfgh");
}

Test(error_handling, invalid_string, .exit_code=84)
{
    get_number("-34234564323456765432RE453C");
}
