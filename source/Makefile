##
## PERSONAL PROJECT, 2020
## DO OP
## File description: Makefile
##

## Var def ##
SHELL		=	/bin/sh
CC			= 	gcc
RM			= 	rm -f
##############

## Sources ##
MAIN		=	main.c

# Enable CLION job
SRC			=	**/*.c

BIN_SRC		=	src/do-op.c		  	 \
				src/error_handling.c \

TEST_SRC	=	tests/do-op.tests.c				\
				tests/error_handling.tests.c

INC			= -I./include/
#############

## Obj     ##
MAIN_OBJ	=	$(MAIN:.c=.o)
SRC_OBJ		=	$(BIN_SRC:.c=.o)
TEST_OBJ	=	$(TEST_SRC:.c=.o)
#############

## Flags   ##
CFLAGS		=	-Wall -Wextra
CPPFLAGS	=	$(INC)
LDFLAGS		=
#############

## Names   ##
BIN			=	do-op
TEST_BIN	=	unit_tests
#############

## Rules   ##
.PHONY: all
all:	$(BIN)
$(BIN):	$(MAIN_OBJ) $(SRC_OBJ)
	$(CC) -o $(BIN) $(MAIN_OBJ) $(SRC_OBJ)

## Debug
.PHONY:	debug
debug: fclean
debug:	CFLAGS += -g3 -DDEBUG
debug:	$(BIN)

## Run test
.PHONY: tests_run
tests_run:  CFLAGS += --coverage
tests_run:  LDFLAGS += -lcriterion -DUNIT_TEST
tests_run:	$(SRC_OBJ) $(TEST_OBJ)
	$(CC) -o $(TEST_BIN) $(SRC_OBJ) $(TEST_OBJ) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS)
	./$(TEST_BIN)

## Get coverage
.PHONY: coverage
coverage:
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests

## Clear rules
.PHONY: clean
clean:
	@$(RM)	$(MAIN_OBJ)
	@$(RM)	$(SRC_OBJ)
	@$(RM)	$(TEST_OBJ)

.PHONY: fclean
fclean: clean
	@$(RM)	$(BIN)
	@$(RM)  $(TEST_BIN)
	@$(RM)	**/*.gc*

.PHONY: re
re:	fclean all clean


