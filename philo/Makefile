SRC		:=	./src/philosopher_think.c \
			./src/is_philo_finished.c \
			./src/philosopher_eat.c \
			./src/set_philo_finished.c \
			./src/have_philosopher_eaten.c \
			./src/gettimestamp.c \
			./src/philosopher_sleep.c \
			./src/philo_exit.c \
			./src/philo_init.c \
			./src/philosopher_die.c \
			./src/algo.c \
			./src/monitor.c \
			./src/is_philosopher_dead.c \
			./src/printing.c \
			./src/philo_parse_args.c \
			./main.c
OBJ		:= ${SRC:.c=.o}

NAME	:= philo
LIBFT	:= ../libft/libft.a
CFLAGS	:= -I./include -I../libft -Wall -Wextra -Werror -g
LINK	:= -lpthread -L../libft -lft
CC		:= cc

all: ${NAME} ;

${NAME}: ${LIBFT} ${OBJ}
	${CC} ${CFLAGS} ${OBJ} ${LINK} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
	${MAKE} -C ../libft

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: | fclean all

.PHONY	:= all clean fclean re ${NAME}