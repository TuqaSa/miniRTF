NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -march=native -I. -I./MLX42/include -Ilibft/header -Isrc/parsing -Isrc/shapes -Isrc/matrix -Isrc/color -Isrc/canvas -Isrc/rendering -Isrc/utils
LDFLAGS = -Llibft -lft
MLX_PATH = ./MLX42/build
MLX_LIB = $(MLX_PATH)/libmlx42.a
MLX_FLAGS = -ldl -lglfw -pthread -lm
RM = rm -f

SRCS =	main.c 									\
		src/rendering/ray.c						\
		src/rendering/light.c 					\
		src/rendering/world.c					\
		src/rendering/camera.c					\
		src/rendering/shadow.c					\
		src/rendering/precompute.c				\
		src/canvas/canvas_init.c 				\
		src/canvas/canvas_pixel.c 				\
		src/canvas/canvas_utils.c 				\
		src/canvas/canvas_destroy.c 			\
		src/utils/info.c						\
		src/utils/hooks.c						\
		src/utils/std_utils.c					\
		src/color/color.c						\
		src/color/pattern.c 					\
		src/color/color_operations.c			\
		src/matrix/info.c						\
		src/matrix/math.c						\
		src/matrix/tuple.c						\
		src/matrix/shearing.c					\
		src/matrix/sub_matrix.c					\
		src/matrix/view_matrix.c				\
		src/matrix/matrix_utils.c				\
		src/matrix/minor_matrix.c				\
		src/matrix/matrix_cofactor.c			\
		src/matrix/transformations.c			\
		src/matrix/matrix_invertion.c			\
		src/matrix/matrix_comparison.c			\
		src/matrix/matrix_operations.c			\
		src/matrix/matrix_determinant.c			\
		src/matrix/tuple_ops_immutable.c		\
		src/matrix/matrix_initialization.c		\
		src/matrix/matrix_multiplication.c		\
		src/shapes/cone.c						\
		src/shapes/info.c						\
		src/shapes/plane.c						\
		src/shapes/shape.c						\
		src/shapes/normal.c 					\
		src/shapes/sphere.c						\
		src/shapes/cylinder.c					\
		src/shapes/hyperboloid.c				\
		src/shapes/cone_rendering.c				\
		src/shapes/cylinder_rendering.c 		\
		src/parsing/ft_atof.c					\
		src/parsing/parsing.c					\
		src/parsing/fill_ids.c					\
		src/parsing/fill_info.c					\
		src/parsing/identifiers.c				\
		src/parsing/parsing_rgb.c				\
		src/parsing/cone_parsing.c				\
		src/parsing/bonus_parsing.c				\
		src/parsing/file_validity.c 			\
		src/parsing/light_parsing.c				\
		src/parsing/parsing_utils.c				\
		src/parsing/plane_parsing.c				\
		src/parsing/parsing_utils2.c			\
		src/parsing/camera_parsing.c			\
		src/parsing/sphere_parsing.c			\
		src/parsing/cylinder_parsing.c			\
		src/parsing/hyperboloid_parsing.c		\
		src/parsing/parsing_datatypes.c			\
		src/intersection/intersections.c 		\
		src/intersection/intersections_sort.c	\
		src/intersection/intersect_shapes.c		\
		src/intersection/intersect_cylinder_cone.c	\
		src/intersection/intersect_hyperboloid.c	\
		src/intersection/intersection_utils.c	\
		src/intersection/world_intersection.c	


OBJS = $(SRCS:%.c=build/%.o)

all: MLX42 $(NAME)

MLX42:
	@echo "Building MLX42..."
	@cmake ./MLX42 -B $(MLX_PATH) && make -C $(MLX_PATH) -j4

libft:
	$(MAKE) -C libft

# Link with MLX42
$(NAME): $(OBJS) | libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) $(MLX_LIB) $(MLX_FLAGS)
	@echo "miniRT is built"

build/%.o: %.c minirt.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@rm -rf build
	@$(MAKE) -C libft fclean || true

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C libft fclean || true
	@$(RM) $(MLX_LIB)
	@rm -rf $(MLX_PATH)

re: fclean all

run:
	@./$(NAME)

.PHONY: all clean fclean re run libft MLX42
