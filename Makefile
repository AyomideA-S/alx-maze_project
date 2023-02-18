# CC specifies the compiler to be used
CC = gcc

# SRC specifies the .c files
SRC = src/main.c

# OBJ specifies the .o files
OBJ = $(SRC:.c=.o)

# NAME specifies the name of our exectuable
NAME = 'The Maze Project'

# RM specifies the program to delete files
RM = rm -f

# CFLAGS specifies your favorite compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic

# LFLAGS specifies the linker flags
# LFLAGS =

# Makefile should work even if there is a file in the folder
# that has the same name as rule
.PHONY: all clean oclean fclean re

# This rule builds our executable
# Makefile should not compile if the header file main.h is missing
all: include/main.h $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

# This rule deletes all Emacs and Vim temporary files along with the executable
clean:
	$(RM) *~ $(NAME)

# This rule deletes the object files
oclean:
	$(RM) $(OBJ)

# This rule deletes all Emacs and Vim temporary files, the executable, and the object files
fclean: clean oclean

# This rule forces recompilation of all source files
re: fclean all