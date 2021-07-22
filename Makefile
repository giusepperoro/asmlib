SRCS		=	ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_read.s \
				ft_write.s \
				ft_strdup.s \

BONUS_SRCS	=	ft_list_push_front_bonus.s \
				ft_list_size_bonus.s \

OBJS		=	$(SRCS:.s=.o)

BONUS_OBJS	=	$(BONUS_SRCS:.s=.o)

NASM		=	nasm
NASM_FLAGS	=	-f macho64
FLAGS 		=	-Wall -Werror -Wextra
NAME		=	libasm.a

%.o:			%.s
				@$(NASM) $(NASM_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				@rm -rf $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@rm -rf $(NAME) $(BONUS)

re:				fclean $(NAME)

bonus: 			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			clean fclean re test
