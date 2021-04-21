//
// Created by vasek on 19/09/2020.
//

#ifndef WORKSHOPGA_DO_OP_H
#define WORKSHOPGA_DO_OP_H

// Available operators
#define NB_OP 5
#define ADD '+'
#define SUB '-'
#define DIV '/'
#define MUL '*'
#define MOD '%'

#define EXIT_ERROR(format, ...)                        \
do {                                                   \
  fprintf(stderr, format, __VA_ARGS__);  \
  exit(84);                                            \
} while(0)

#endif //WORKSHOPGA_DO_OP_H
