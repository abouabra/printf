SRC= ft_printf.c ft_printf_utils.c
BSRC= 
OBJS=$(SRC:.c=.o)
BOBJS=$(BSRC:.c=.o)
AR=ar -rcs
NAME=libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^

bonus: $(NAME) $(BOBJS)
	@$(AR) $(NAME) $^

%.o:%.c
	@$(CC) -Wall -Wextra -Werror -c $<

clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o libftprintf.a

re:fclean all

.PHONY: all clean fclean re bonus