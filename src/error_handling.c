//
// Created by vasek on 19/09/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <errno.h>
#include "do-op.h"

/**
 * Extract number from string
 *
 * @param number - Given string
 * @return - Converted number
 * @throw - Invalid number
 * @throw- No number found
 */
long int get_number(char *number)
{
    char *endptr = NULL;
    long int converted_value;

    errno = 0;

    converted_value = strtol(number, &endptr, 10);

    if (errno != 0) {
        EXIT_ERROR("%s: Invalid number\n", number);
    }

    if (endptr == number) {
        EXIT_ERROR("%s: No numbers found\n", number);
    }
    return converted_value;
}