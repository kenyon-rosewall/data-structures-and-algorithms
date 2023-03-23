CC      = gcc
CFLAGS  = -Wall -g -I../
RM      = rm -fr
BUILD_DIR = build

BIN			= $(BUILD_DIR)/main
OBJ			= $(BUILD_DIR)/main.o $(BUILD_DIR)/single_linked_list.o $(BUILD_DIR)/double_linked_list.o

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(BIN) $(OBJ)
