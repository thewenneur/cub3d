# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 12:47:20 by tbrouill          #+#    #+#              #
#    Updated: 2019/11/28 14:30:01 by tbrouill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := ft_isalnum.c \
           ft_isdigit.c \
           ft_memcpy.c \
           ft_strlcat.c \
           ft_strncmp.c \
           ft_toupper.c \
           ft_atoi.c \
           ft_isalpha.c \
           ft_isprint.c \
           ft_memset.c \
           ft_strlcpy.c \
           ft_strrchr.c \
           ft_bzero.c \
           ft_isascii.c \
           ft_memccpy.c \
           ft_strchr.c \
           ft_strlen.c \
           ft_tolower.c \
           ft_memmove.c \
           ft_memchr.c \
           ft_memcmp.c \
           ft_calloc.c \
           ft_strnstr.c \
           ft_putchar_fd.c \
           ft_substr.c \
           ft_strjoin.c \
           ft_strtrim.c \
           ft_itoa.c \
           ft_putstr_fd.c \
           ft_putendl_fd.c \
           ft_putnbr_fd.c \
           ft_strmapi.c \
           ft_strdup.c \
           ft_split.c

SRCB = ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c \
            ft_lstlast_bonus.c \
			ft_lstlast_bonus.c \
            ft_lstmap_bonus.c \
            ft_lstnew_bonus.c \
            ft_lstsize_bonus.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

NAME = libft.a

CC = gcc

LINK = ar

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

LFLAGS = rcs $(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
			$(LINK) $(LFLAGS) $(OBJ)

all:		$(NAME)

bonus:		$(OBJ) $(OBJB)
			$(LINK) $(LFLAGS) $(OBJ) $(OBJB)

clean:
			$(RM) $(OBJ) $(OBJB)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all fclean clean re bonus