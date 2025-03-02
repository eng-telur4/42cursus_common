CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
NORM		= norminette
NAME		= push_swap
SRC_DIR		= ./src
INC_DIR		= ./inc
SRCS		= main.c\
			  $(wildcard ./utils/*.c)
OBJS		= $(SRCS:.c=.o)


### LIBRARIES ###
LIBFT_FLAG	 	= -lft # libftを使うときに必要なフラグ
LIBFT_DIR 		= $(SRC_DIR)/libft
FT_PRINTF_FLAG	= -lftprintf # ft_printfを使うときに必要なフラグ
FT_PRINTF_DIR	= $(SRC_DIR)/ft_printf
GNL_FLAG		= -lgnl # get_next_lineを使うときに必要なフラグ
GNL_DIR			= $(SRC_DIR)/get_next_line


### RULES ###
all: $(NAME)

.c.o:
	$(CC) -I $(INC_DIR) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(MAKE) -C $(GNL_DIR)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT_FLAG) $(FT_PRINTF_FLAG) $(GNL_FLAG) -L $(LIBFT_DIR) -L $(FT_PRINTF_DIR) -L $(GNL_DIR) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	$(RM) $(NAME)

re: fclean all
