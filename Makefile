NAME =		philo

HEADER =	includes/*.h
FLAGS =		-Wall -Werror -Wextra

SRC_DIR =	srcs/

CFILE =		philo.c \
			ft_isdigit.c \
			ft_utils.c \


OFILE =		$(CFILE:.c=.o)

SRC =		$(addprefix $(SRC_DIR), $(OFILE))
OBJ =		$(addprefix $(SRC_DIR), $(OFILE))

all: $(NAME)

$(OBJ) : $(HEADER)

$(NAME): $(OBJ)
		gcc -g $(FLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

%.o : %.c
		gcc -g $(FLAGS) -c $< -o $@

clean:
		@/bin/rm -f $(OBJ)
		@echo Cleaned $(NAME) object files

fclean: clean
		@/bin/rm -f $(NAME)
		@echo Cleaned $(NAME)

re: fclean all

.PHONY: all clean flcean re
