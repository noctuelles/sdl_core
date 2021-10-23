SRCS		=	srcs/sdl_core.c srcs/sdl_text.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=

SDL2		=	/usr/include/SDL2

CC		=	gcc

NAME		=	libsdl_core.a

RM		=	rm -rf

.c.o:
	${CC} ${CFLAGS} -I ./includes `sdl2-config --cflags --libs` -lSDL2_ttf -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			ar -rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:	all clean fclean re
