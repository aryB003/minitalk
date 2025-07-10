CLIENT 		= 	client

SERV		=	server

LIBFT_DIR	=	./libft

LIBFT		=	./libft/libft.a

OBJS		=	${SRCS:.c=.o}

CFLAGS		=	-Wall -Wextra -Werror

all			:	${CLIENT} ${SERV}

SRCS		=	server.c client.c utils.c

%.o			:	%.c
		cc ${CFLAGS} -I ${LIBFT_DIR} -c $< -o $@

${LIBFT}	:
		make -C ${LIBFT_DIR}

$(CLIENT): client.o utils.o $(LIBFT)
		$(CC) $(CFLAGS) client.o utils.o $(LIBFT) -o $@

$(SERV): server.o utils.o $(LIBFT)
		$(CC) $(CFLAGS) server.o utils.o $(LIBFT) -o $@

clean		:
		rm -f ${OBJS}
		make -C ${LIBFT_DIR} clean

fclean		:	clean
		rm -f ${CLIENT} ${SERV}
		make -C ${LIBFT_DIR} fclean

re			:	fclean all

.PHONY		:	all clean fclean re