CC = cc

CFLAGS = -Wall -Wextra -Werror

B_SRC = main_bonus.c input_check_bonus.c time_print_bonus.c \
		start_bonus.c philos_life_bonus.c monitoring_bonus.c \
		unlink_free_bonus.c

B_OBJ = ${B_SRC:%.c=%.o}

RM = rm -f

NAME_BONUS = philo_bonus

all: ${NAME_BONUS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME_BONUS}: ${B_OBJ}
	${CC} ${CFLAGS} ${B_SRC} -o $@

clean:
	${RM} ${B_OBJ}

fclean: clean
	${RM} ${NAME_BONUS}

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus

.SECONDARY: ${B_OBJ}