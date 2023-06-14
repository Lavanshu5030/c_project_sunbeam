CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = myprogram

SRCS = main.c user_control.c user_dal.c user_service.c book_control.c book_dal.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
