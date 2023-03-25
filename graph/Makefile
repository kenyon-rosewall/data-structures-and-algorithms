CC      = gcc
CFLAGS  = -Wall -g -I../
RM      = rm -fr
BUILD_DIR = build

BIN			= $(BUILD_DIR)/main
OBJ			= $(BUILD_DIR)/main.o $(BUILD_DIR)/single_linked_list.o $(BUILD_DIR)/graph.o

all: $(BIN) vis

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/graph.o: graph.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD_DIR)/single_linked_list.o: ../list/single_linked_list.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

vis:
	$(BUILD_DIR)/main dot | dot -Tpdf > $(BUILD_DIR)/vis.pdf

clean:
	$(RM) $(BIN) $(OBJ) $(BUILD_DIR)/vis.pdf
