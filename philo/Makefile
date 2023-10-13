SRC		:=	src/printing.c \
			src/monitor.c \
			src/philo_init.c \
			src/ft_stdlib/ft_strtol.c \
			src/ft_stdlib/ft_strtoi.c \
			src/ft_stdlib/ft_atoi.c \
			src/philosopher_sleep.c \
			src/is_philosopher_dead.c \
			src/philo_parse_args.c \
			src/philosopher_think.c \
			src/ft_math/ft_absi.c \
			src/ft_math/ft_getdigits.c \
			src/ft_math/ft_digitat.c \
			src/ft_math/ft_min.c \
			src/ft_math/ft_powi.c \
			src/philo_exit.c \
			src/is_philo_finished.c \
			src/ft_ctype/ft_isalpha.c \
			src/ft_ctype/ft_isdigit.c \
			src/ft_ctype/ft_isspace.c \
			src/gettimestamp.c \
			src/set_philo_finished.c \
			src/have_philosopher_eaten.c \
			src/ft_string/ft_strchr1.c \
			src/ft_string/ft_countc.c \
			src/ft_string/ft_memmove.c \
			src/ft_string/ft_itoa.c \
			src/ft_string/ft_strremove.c \
			src/ft_string/ft_memelemset.c \
			src/ft_string/ft_memcpy.c \
			src/ft_string/ft_strcpy.c \
			src/ft_string/ft_strdup.c \
			src/ft_string/ft_strcmp.c \
			src/ft_string/ft_strreplace.c \
			src/ft_string/ft_strchr.c \
			src/ft_string/ft_strlen.c \
			src/ft_string/ft_strcat.c \
			src/ft_string/rotate.c \
			src/ft_string/ft_memset.c \
			src/ft_string/ft_strinsert.c \
			src/ft_string/ft_strncpy.c \
			src/ft_string/ft_memdup.c \
			src/philosopher_die.c \
			src/philosopher_eat.c \
			src/algo.c \
			src/philo_init_mutex.c \
			main.c

OBJ		:= ${SRC:.c=.o}

NAME	:= philo
CFLAGS	:= -I./include -I../libft -Wall -Wextra -Werror -g
LINK	:= -lpthread
CC	:= cc

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

re:
	${MAKE} fclean
	${MAKE} all

.PHONY	:= all clean fclean re ${NAME}
