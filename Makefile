DIRSRC = ./srcs/

DIRCINC = ./includes/

DIRLIB = ./libft/

DIRMLX = ./mlx/

SRC =	main \
		get_map \
		parse_map \
		get_texture \
		parsing_utils00 \
		parsing_utils01 \
		window \
		free00 \
		free01 \
		hooks \
		raycasting \
		utils \
		colors \
		moves \
		rotations \
		initialization \
		display \
				
SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

OBJS = ${SRCS:.c=.o}

NAME = cub3d
LFT = libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -I . -lXext -lX11

.c.o:
	@${CC} ${CFLAGS} -c -I${DIRCINC} -I${DIRLIB} -I${DIRMLX} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@cd ${DIRLIB} && ${MAKE}
	@cd ${DIRMLX} && ${MAKE}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIRLIB} -lft -L${DIRMLX} -lmlx -lXext -lX11 -lm
	@echo "✅ cub3d created"

all: ${NAME}

clean:
	@${RM} ${OBJS}
	@cd ${DIRLIB} && ${MAKE} clean
	@echo "🧽 Directory is clean"

fclean:
	@${RM} ${OBJS}
	@${RM} ${NAME}
	@cd ${DIRLIB} && ${MAKE} fclean
	@echo "🧹 Directory is fclean"

re : fclean all

.PHONY : all clean fclean re