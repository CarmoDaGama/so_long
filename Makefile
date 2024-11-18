NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lmlx -lmlx_Linux -lX11 -lXext -lm

REMOVE = rm -rf

LIBFT = libft
MLX_PATH = ../minilibx-linux/

SRCS_FILES = map_validate.c \
	map_init.c \
	error_free.c \
	game_init.c \
	game_events.c \
	game_events_utils.c \
	builder.c \
	exit_actions.c \
	map_init_utils.c \
	ft_food_fill.c

OBJS_FILES = map_validate.o \
	map_init.o \
	error_free.o \
	game_init.o \
	game_events.o \
	game_events_utils.o \
	builder.o \
	exit_actions.o \
	map_init_utils.o \
	ft_food_fill.o

PATH_LIBS = $(LIBFT)/libft.a -L$(MLX_PATH)

all : $(NAME)

$(NAME) : $(OBJS_FILES)
	make -C $(LIBFT) bonus
	make -C $(MLX_PATH) 
	$(CC) $(CFLAGS) $(OBJS_FILES) -o $(NAME) so_long.c $(PATH_LIBS) $(LFLAGS)

clean :
	@$(REMOVE) $(OBJS_FILES)
	@make clean -C $(LIBFT) 
	@make clean -C $(MLX_PATH) 

fclean : clean
	@$(REMOVE) $(NAME) $(OBJS_FILES)
	@make fclean -C $(LIBFT) 
	@make clean -C $(MLX_PATH) 

re : fclean all