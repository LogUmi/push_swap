NAME = 	push_swap.a
EXEC =	push_swap
DIRSR =	srcs/
DIROB =	objs/
DIRLI =	includes/
FILEH = push_swap.h
FILEC = push_swap.c \
		conformity.c \
		setstack.c \
		ft_swap_push.c \
		ft_rotate.c \
		ft_reverse.c \
		algo.c \
		execute.c \
		algo_radix.c
SRCS =	$(addprefix $(DIRSR), $(FILEC))
OBJS =	$(addprefix $(DIROB), $(FILEC:.c=.o))
HDRS =	$(addprefix $(DIRLI), $(FILEH))
LDIR = libft
LIBR = $(LDIR)/libft.a
FLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar -rcs

all:		initdir $(NAME)		

$(NAME):	$(OBJS)	$(LIBR)
			$(AR) $(NAME) $(OBJS)
			$(CC) $(FLAGS) $(word 1, $(SRCS)) $(NAME) -o $(EXEC)	

$(DIROB)%.o:		$(DIRSR)%.c	
					$(CC) $(FLAGS) -c $< -o $@ -I.$(DIRLI) -I$(LDIR)

# Création du dossier obj/ si nécessaire
initdir:
			@mkdir -p $(DIROB)
			
$(LIBR):		
			[ -d $(LDIR) ] && $(MAKE) -C $(LDIR) all		
			cp $(LIBR) .
			mv $(notdir $(LIBR)) $(NAME)
clean:		
			rm -rf	$(OBJS)
			$(MAKE) -C $(LDIR) clean	

fclean:		clean	
			rm -rf $(NAME)	
			rm -rf $(EXEC)
			$(MAKE) -C $(LDIR) fclean	

re:			fclean all

.PHONY:		all clean fclean re
