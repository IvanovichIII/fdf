NAME = fdf

# Compilador y banderas
CC = cc
#CFLAGS = -Wall -Wextra -Werror -Iinclude -ldl -lglfw -pthread -lm -g
CFLAGS = -Iinclude -pthread -g -I incl
LFLAGS = -ldl -lglfw -lm
RM = rm -rf
MAKE = make --no-print-directory
NO_PRINT = /dev/null

# Librerías
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
GNL_DIR = ./gnl
GNL = $(GNL_DIR)/libftgnl.a
PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX42_DIR = ./MLX42/build
MLX42 = $(MLX42_DIR)/libmlx42.a

# Archivos fuente y objeto
SRCS =	src/fdf.c \
		src/fdf_keys.c \
		src/fdf_bresenham.c \
		src/fdf_utils.c \
		src/fdf_utils2.c \
		src/fdf_write_down.c \
		src/fdf_write_right.c
OBJS = $(SRCS:.c=.o)


# Colores para los mensajes
GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

# Emojis
CHECK = ✅
CROSS = ❌
BUILD = 🚀
CLEAN = 🧹
COMPILE = 🔧
DONE = 🎉

# Reglas principales
all: banner $(NAME)

banner:
	@echo "$(CYAN)🎸 Let's rock! Compiling FdF... $(RESET)"

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(PRINTF) $(MLX42)
	@echo "$(COMPILE) $(YELLOW)Linking everything together...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(GNL) $(PRINTF) $(MLX42) $(LFLAGS)
	@echo "$(CHECK) $(GREEN)Compilation successful!$(RESET)"

%.o: %.c
	@echo "$(COMPILE) $(CYAN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(BUILD) $(YELLOW)Building Libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) all > $(NO_PRINT)

$(GNL):
	@echo "$(BUILD) $(YELLOW)Building Gnl...$(RESET)"
	@$(MAKE) -C $(GNL_DIR) all > $(NO_PRINT)

$(PRINTF):
	@echo "$(BUILD) $(YELLOW)Building Printf...$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR) all > $(NO_PRINT)

$(MLX42):
	@echo "$(BUILD) $(YELLOW)Building MLX42...$(RESET)"
	@cd $(MLX42_DIR)/.. && cmake -B build && cmake --build build -j4 && cd ..
	@$(MAKE) -C $(MLX42_DIR) all > $(NO_PRINT)

# Limpiar archivos intermedios
clean:
	@echo "$(CLEAN) $(RED)Removing object files...$(RESET)"
	@$(RM) $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(GNL_DIR)
	@$(MAKE) clean -C $(PRINTF_DIR)
	@echo "$(CROSS) $(RED)Cleaned!$(RESET)"

# Limpieza total
fclean: clean
	@echo "$(CLEAN) $(RED)Removing executable...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(GNL_DIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@echo "$(CROSS) $(RED)Full clean done!$(RESET)"

# Recompilar desde cero
re: fclean all

# Mensajes adicionales
.PHONY: all clean fclean re banner libmlx