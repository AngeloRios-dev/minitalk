# SETTINGS
CLIENT_NAME	= client
SERVER_NAME	= server
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# FOLDERS
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes

# SOURCES
CLIENT_SRC	= $(SRC_DIR)/client.c $(SRC_DIR)/utils.c
SERVER_SRC	= $(SRC_DIR)/server.c $(SRC_DIR)/s_utils.c

# OBJECTS
CLIENT_OBJ	= $(CLIENT_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SERVER_OBJ	= $(SERVER_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ)
	@echo "🔨 Linking $(CLIENT_NAME)"
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT_NAME) -I $(INC_DIR)

$(SERVER_NAME): $(SERVER_OBJ)
	@echo "🔨 Linking $(SERVER_NAME)"
	@$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER_NAME) -I $(INC_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "⚙️  Compiling $<"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "🗑️  Deleting object files..."
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "🗑️  Deleting executables..."
	@$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

test: re
	@echo "📝 Checking Norminette..."
	@norminette -R CheckForbiddenSourceHeader -R CheckDefine $(CLIENT_SRC) $(SERVER_SRC) $(INC_DIR)/minitalk.h
	@echo "✅ Norminette check finished"

.PHONY: all clean fclean re test