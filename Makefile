# SETTINGS
CLIENT_NAME	= client
SERVER_NAME	= server
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Iincludes -I$(INC_DIR)/libft
RM			= rm -f

# FOLDERS
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes
LIBFT_DIR   = includes/libft
LIBFT       = $(LIBFT_DIR)/libft.a

# SOURCES
CLIENT_SRC	= $(SRC_DIR)/client.c
SERVER_SRC	= $(SRC_DIR)/server.c

# OBJECTS
CLIENT_OBJ	= $(CLIENT_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SERVER_OBJ	= $(SERVER_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME): $(LIBFT) $(CLIENT_OBJ)
	@echo "🔨 Linking $(CLIENT_NAME)"
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L$(LIBFT_DIR) -lft -o $(CLIENT_NAME)

$(SERVER_NAME): $(LIBFT) $(SERVER_OBJ)
	@echo "🔨 Linking $(SERVER_NAME)"
	@$(CC) $(CFLAGS) $(SERVER_OBJ) -L$(LIBFT_DIR) -lft -o $(SERVER_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "⚙️  Compiling $<"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "🗑️  Deleting object files..."
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "🗑️  Deleting executables..."
	@$(RM) $(CLIENT_NAME) $(SERVER_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

test: re
	@echo "📝 Checking Norminette..."
	@norminette -R CheckForbiddenSourceHeader -R CheckDefine $(CLIENT_SRC) $(SERVER_SRC) $(INC_DIR)/minitalk.h
	@echo "✅ Norminette check finished"

.PHONY: all clean fclean re test