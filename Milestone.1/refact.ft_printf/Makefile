CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a
AR		= ar rcs
RM		= rm -f

MANDATORY_SRCS = ft_itoa_ull.c\
				 ft_printf.c\
				 ft_putchar_fd.c\
				 ft_putnbr_fd.c\
				 ft_putnbr_fd_base.c\
				 ft_putnbr_fd_u.c\
				 ft_putstr_fd.c\
				 ft_printf_funcs01.c\
				 ft_printf_funcs02.c

BONUS_SRCS = ft_printf_bonus.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
OBJS = $(MANDATORY_OBJS)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
