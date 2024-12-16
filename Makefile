SRC =	ft_printf.c ft_printf_utils.c
SRCB = ft_printf_bonus.c ft_printf_utils_bonus_1.c ft_printf_utils_bonus_2.c
NAME = libftprintf.a
CC = cc
LCC = ar rcs
FLAGS = -Wall -Wextra -Werror

OBJF = $(SRC:.c=.o)

BOBJF = $(SRCB:.c=.o)

all : $(NAME)

$(NAME) : $(OBJF)
	$(LCC) $(NAME) $^

bonus: $(BOBJF)
	$(LCC) $(NAME) $^

%.o : %.c $(HF)
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	rm -f $(OBJF) $(BOBJF)

fclean : clean
	rm -f $(NAME)

re : fclean all