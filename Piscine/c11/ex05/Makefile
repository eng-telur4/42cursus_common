CC		= cc
CFLAGS	= -Wall -Wextra -Werror
TARGET	= do-op

$(TARGET):operations.o ft_add.o ft_sub.o ft_mul.o ft_div.o ft_mod.o ft_putstr.o ft_strcmp.o ft_atoi.o
	$(CC) $(CFLAGS) operations.o ft_add.o ft_sub.o ft_mul.o ft_div.o ft_mod.o ft_putstr.o ft_strcmp.o ft_atoi.o -o $(TARGET)

operations.o:operations.c
	$(CC) -c operations.c

ft_add.o:ft_add.c
	$(CC) -c ft_add.c

ft_sub.o:ft_sub.c
	$(CC) -c ft_sub.c

ft_mul.o:ft_mul.c
	$(CC) -c ft_mul.c

ft_div.o:ft_div.c
	$(CC) -c ft_div.c

ft_mod.o:ft_mod.c
	$(CC) -c ft_mod.c

ft_putstr.o:ft_putstr.c
	$(CC) -c ft_putstr.c

ft_strcmp.o:ft_strcmp.c
	$(CC) -c ft_strcmp.c

ft_atoi.o:ft_atoi.c
	$(CC) -c ft_atoi.c

clean:
	rm -rf $(TARGET) *.o
