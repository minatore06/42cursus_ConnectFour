NAME = connect4.a

OUT = connect4

SRCS = main.c take_input.c ai.c check_positions.c utils.c

OBJS = ${SRCS:.c=.o}

CC = cc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

LIBFT = libft

LIBFTNAME = libft.a
	
%.o: %.c
	${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make bonus -C ${LIBFT}
	mv ${LIBFT}/${LIBFTNAME} ${NAME}
	${CC} ${FLAGS} ${OBJS} ${NAME} -o ${OUT}

all: ${NAME}

bonus:	${OBJS}
	make bonus -C ${LIBFT}
	mv ${LIBFT}/${LIBFTNAME} ${NAME}
	${CC} ${FLAGS} ${OBJS} ${NAME} -o ${OUT}

clean: 
	${RM} ${OBJS}
	make clean -C ${LIBFT}

fclean: clean 
	${RM} ${NAME}
	make fclean -C ${LIBFT}

re: fclean all
