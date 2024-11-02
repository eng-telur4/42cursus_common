CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a
AR		= ar rcs
RM		= rm -f

MANDATORY_SRCS = is_percent.c\
				 ft_isdigit.c\
				 ft_itoa_ull.c\
				 ft_printf.c\
				 ft_putchar_fd.c\
				 ft_putnbr_fd.c\
				 ft_putnbr_fd_base.c\
				 ft_putnbr_fd_u.c\
				 ft_putstr_fd.c\
				 ft_strlen.c

BONUS_SRCS = ft_printf_bonus.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
OBJS = $(MANDATORY_OBJS)
BONUS = 0

ifeq ($(BONUS), 1)
OBJS += $(BONUS_OBJS)
endif

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus:
	@$(MAKE) BONUS=1 all

all: $(NAME)

clean:
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
