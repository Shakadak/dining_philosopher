# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:39:32 by npineau           #+#    #+#              #
#    Updated: 2014/05/08 15:48:07 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	philo

### DIRECTORIES ###

DIRSRC	:=	sources
DIROBJ	:=	objects
DIRINC	:=	includes
DIRLIB	:=	libft

### FILES ###

SRC		:=	main.c \
			philosopher.c \
			eat.c \
			rest.c \
			think.c \
			init_table.c
OBJ		:=	$(SRC:.c=.o)

HEAD	:=	philo.h
LIB		:=	libft.a

### PATHS ###

POBJ	:=	$(addprefix $(DIROBJ)/, $(OBJ))
PHEAD	:=	$(DIRINC)/$(HEAD)
PLIB	:=	$(DIRLIB)/$(LIB)

### COMPILATION VARIABLES ###

CC		:=	llvm-gcc
C_FLAG	:=	-Wall -Wextra -Werror
O_FLAG	:=	-O3
L_FLAG	:=	-L $(DIRLIB) -lft
C_INC	:=	-I $(DIRINC) -I $(DIRLIB)/$(DIRINC)

COMPIL	=	$(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
LINK	=	$(CC) -o $@ $^ $(L_FLAG)

### RULES ###

all: $(PLIB) $(NAME)

### LIBFT ###

$(PLIB):
	make -C $(DIRLIB) all

### OBJECTS ###

$(DIROBJ):
	mkdir $(DIROBJ)

$(POBJ): |$(DIROBJ)

$(DIROBJ)/%.o: $(DIRSRC)/%.c $(PHEAD)
	$(COMPIL)

### EXECUTABLE ###

$(NAME): $(POBJ)
	$(LINK)

### CLEAN UP ###

clean:
	rm -f $(POBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
