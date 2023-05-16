NAME = connect4.a

OUT = connect4

SRCS = main.c draw_terminal.c take_input.c put.c utils.c random.c ai.c check_positions.c gui_init.c hooks.c draw.c

OBJS = ${SRCS:.c=.o}

CC = cc

LINKS =  minilibx-linux/libmlx.a -lXext -lX11 -lm

RM = rm -f

CFLAGS = -Wall -Werror -Wextra 

LIBFT = libft

LIBFTNAME = libft.a

%.o: %.c
	${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	make bonus -C ${LIBFT}
	mv ${LIBFT}/${LIBFTNAME} ${NAME}
	make -sC minilibx-linux all
	${CC} ${CFLAGS} ${OBJS} ${NAME} -o ${OUT} ${LINKS}

all: ${NAME}

bonus:	${OBJS}
	make bonus -C ${LIBFT}
	mv ${LIBFT}/${LIBFTNAME} ${NAME}
	${CC} ${FLAGS} ${OBJS} ${NAME} -o ${OUT}

clean:
	${RM} ${OBJS}
	make -sC minilibx-linux clean
	make clean -C ${LIBFT}

fclean: clean
	${RM} ${NAME}
	${RM} ${OUT}
	make fclean -C ${LIBFT}

re: fclean all
