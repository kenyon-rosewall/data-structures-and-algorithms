CC      = gcc
CFLAGS  = -Wall -g -I../
RM      = rm -fr
BUILD_DIR = build

BIN			= $(BUILD_DIR)/main
OBJ			= $(BUILD_DIR)/main.o $(BUILD_DIR)/btree.o

all: $(BIN) vis

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

vis:
	$(BUILD_DIR)/main dot | dot -Tpdf > $(BUILD_DIR)/vis.pdf

clean:
	$(RM) $(BIN) $(OBJ) $(BUILD_DIR)/vis.pdf
