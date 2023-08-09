NAME		=	cub3d

CC			=	cc

CFLAGS		=	-g -Wall -Wextra -Werror

RM			=	rm -rf

HEADER		=	incl/cub3d.h

LIBFT		=	-L libft -lft

INCLUDE		=	-lmlx -framework OpenGL -framework AppKit

#colors
DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GREY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

MAIN		=	doublelst free_utils init_data main split01 util01 util02

CHECK_MAP	=	check_cub convert_colors element_map parsing_map \
				read_cub read_cub_util01 read_cub_util02 take_cub

SRCS		=	$(addsuffix .c, $(addprefix srcs/, $(MAIN))) \
				$(addsuffix .c, $(addprefix srcs/check_map/, $(CHECK_MAP))) \

OBJS		=	$(SRCS:c=o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\n"
			@make -C libft/
			@echo "$(YELLOW)compiling cub3d...$(DEF_COLOR)"
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDE) $(LIBFT)
			@echo "$(GREEN)cub3d - ready to play$(DEF_COLOR)"

%.o:		%.c
				@printf "$(BLUE)creating objects for cub3d... %-33.33s\r" $@
				@$(CC) $(CFLAGS) -c $< -o $@

fclean:
				@echo "$(GREY)cleaning all...$(DEF_COLOR)"
				@make fclean -C libft/
				@$(RM) $(OBJS)
				@$(RM) $(NAME)
				@$(RM) cub3d.dSYM
				@echo "$(GREY)Done!$(DEF_COLOR)"