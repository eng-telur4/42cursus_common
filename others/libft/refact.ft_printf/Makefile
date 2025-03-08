CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a
AR		= ar rcs
RM		= rm -f
SRCS	= ft_itoa_ull.c\
		  ft_printf.c\
		  ft_putchar_fd.c\
		  ft_putnbr_fd.c\
		  ft_putnbr_fd_base.c\
		  ft_putnbr_fd_u.c\
		  ft_putstr_fd.c\
		  ft_printf_funcs01.c\
		  ft_printf_funcs02.c
OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
