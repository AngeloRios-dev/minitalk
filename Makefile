# SETTINGS
CLIENT_NAME		= client
SERVER_NAME		= server
CLIENT_BONUS	= client_bonus
SERVER_BONUS	= server_bonus
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

# FOLDERS
SRC_DIR			= src
OBJ_DIR			= obj
LIBFT			= ./libft/libft.a

# SOURCES
CLIENT_SRC		= $(SRC_DIR)/client.c
SERVER_SRC		= $(SRC_DIR)/server.c
CLIENT_SRC_B	= $(SRC_DIR)/client_bonus.c
SERVER_SRC_B	= $(SRC_DIR)/server_bonus.c

# OBJECTS
CLIENT_OBJ		= $(CLIENT_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SERVER_OBJ		= $(SERVER_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CLIENT_OBJ_B	= $(CLIENT_SRC_B:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SERVER_OBJ_B	= $(SERVER_SRC_B:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

define LOADING_BAR_COMP
	@printf "\033[0;32mProgress: ["
	@for i in `seq 1 20`; do \
		printf "█"; \
		sleep 0.02; \
	done; \
	printf "] ✔️\033[0m\n\n"
endef

define CLEAN_MINITALK
    @printf "\033[0;31mCleaning Minitalk: ["
    @for i in `seq 1 20`; do \
        printf "█"; \
        sleep 0.02; \
    done; \
    printf "] ✔️\033[0m\n\n"
endef

all: $(LIBFT) $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT):
	@$(MAKE) -C libft --no-print-directory

$(CLIENT_NAME): $(CLIENT_OBJ)
	$(call LOADING_BAR_COMP)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ)
	$(call LOADING_BAR_COMP)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER_NAME)



bonus: $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(CLIENT_BONUS): $(CLIENT_OBJ_B)
	$(call LOADING_BAR_COMP)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ_B) $(LIBFT) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_OBJ_B)
	$(call LOADING_BAR_COMP)
	@$(CC) $(CFLAGS) $(SERVER_OBJ_B) $(LIBFT) -o $(SERVER_BONUS)




$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "⚙️  Compiling $<"
	@$(CC) $(CFLAGS) -I ./libft -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	$(call CLEAN_MINITALK)
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C libft clean --no-print-directory

fclean: clean
	@$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS) $(SERVER_BONUS)
	@$(MAKE) -C libft fclean --no-print-directory

re: fclean all

test: re
	@echo "📝 Checking Norminette..."
	@norminette -R CheckForbiddenSourceHeader -R CheckDefine $(CLIENT_SRC) $(SERVER_SRC)
	@echo "✅ Norminette check finished"

.PHONY: all clean fclean re test