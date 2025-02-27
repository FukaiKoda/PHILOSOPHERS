CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c input_checks.c philos_life.c monitoring.c time_print.c destroy_free.c

OBJ = ${SRC:%.c=%.o}

RM = rm -f

NAME = philo

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${SRC} -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: ${OBJ}
