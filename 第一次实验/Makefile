CC = gcc
CFLAGS = -Wall -Wextra

SRC_DIR = src
BIN_DIR = bin

SOURCES = $(wildcard $(SRC_DIR)/*.c)
TARGETS = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SOURCES))

.PHONY: all clean

all: $(TARGETS)

$(BIN_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(BIN_DIR)

run-hanoi-recursive: $(BIN_DIR)/hanoi_recursive
	@$(BIN_DIR)/hanoi_recursive

run-hanoi-iterative: $(BIN_DIR)/hanoi_iterative
	@$(BIN_DIR)/hanoi_iterative

run-combination: $(BIN_DIR)/combination
	@$(BIN_DIR)/combination
