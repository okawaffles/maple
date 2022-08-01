INC 	:= $(wildcard include/*.c)
CC		:= gcc
NAME	:= maple

linux:
	$(CC) main.c $(INC) -o $(NAME) -Iinclude

windows:
	$(CC) main.c $(INC) -o $(NAME).exe -Iinclude

clean:
	rm -rf maple
	rm -rf maple.exe