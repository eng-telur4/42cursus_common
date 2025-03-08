CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf
NAME			= fdf
SRCS_DIR		= ./srcs
SRCS			= read_file.c
OBJS			= $(SRCS:.c=.o)

### LIBRARIES ###
LIBFT_FLAGS		= -lft
LIBFT_DIR		= ./libft
LIBMLX_FLAGS	= -lmlx -lXext -lX11 -lm -lz
LIBMLX_DIR		= ./minilibx-linux

### RULES ###

all: $(NAME)

.c.o:
	$(CC) -I $(LIBFT_DIR) -I $(LIBMLX_DIR) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBMLX_DIR)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT_FLAGS) -L $(LIBFT_DIR) $(LIBMLX_FLAGS) -L $(LIBMLX_DIR) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBMLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
