##
## ESGI PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRCS	=	Game.c	\
			Bonus.c\

OBJS	=	$(SRCS:.c=.o)

NAME	=	Casse-briques

CPPFLAGS	=	-I./include/ -W -Wextra -Wall

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(SRCS:.c=.c~)
	$(RM) $(SRCS:.c=.c#)
	$(RM) Makefile~
	$(RM) include/*.h~
	$(RM) include/*.h~#
	$(RM) rm -f *.o

fclean:	clean
	$(RM) $(NAME)

re: fclean all
