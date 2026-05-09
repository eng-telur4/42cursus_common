CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INC_DIR	= includes
TARGET	= libft.a
SRC_DIR = srcs
SRCS	= $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strcmp.c $(SRC_DIR)/ft_strlen.c  $(SRC_DIR)/ft_swap.c
OBJS	= $(SRCS:.c=.o)

$(TARGET):$(OBJS)
	ar rcs $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

all:$(TARGET)

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(TARGET)

re:fclean all
