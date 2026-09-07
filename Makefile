# Compilador e flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Diretórios
SRC_DIR = src
OBJ_DIR = $(SRC_DIR)
BIN = main

# Arquivos fonte e objetos
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/treinador/treinador.c $(SRC_DIR)/pokemon/pokemon.c $(SRC_DIR)/centroDePesquisa/centroDePesquisa.c $(SRC_DIR)/pokelista/pokelista.c $(SRC_DIR)/coordenada/coordenada.c
OBJS = $(SRCS:.c=.o)

# Regra padrão
all: $(BIN)

# Linkagem final
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

# Compilação dos .c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Executar com arquivo de teste
run: $(BIN)
	./$(BIN) testes/teste1.txt

# Limpar arquivos compilados
clean:
	del /s /q *.o 2>nul