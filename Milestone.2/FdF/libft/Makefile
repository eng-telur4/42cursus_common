CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a
AR		= ar rcs
RM		= rm -f
SRCS	= $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

_BLUE=\e[34m
_PURPLE=\e[35m
_END=\e[0m

$(NAME): $(OBJS)
	@printf "\nLibft Objects	[$(_BLUE)✓$(_END)]\n"
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "Libft		[$(_BLUE)✓$(_END)]\n"

%.o: %.c
	@printf "Libft object : $(_BLUE)%-33.33s\r$(_END)" $@
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) # different from $(NAME) because it executes clean
clean:
	@$(RM) *.o */*.o
	@printf "$(_PURPLE)libft object	deleted$(_END)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(_PURPLE)libft		deleted$(_END)\n"

re: fclean all
