CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libgnl.a
AR		= ar rcs
RM		= rm -f

MANDATORY_SRCS = get_next_line.c\
				 get_next_line_utils.c

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

allc: all clean
