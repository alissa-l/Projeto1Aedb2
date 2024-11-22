TARGET=projeto1A
GCC=gcc
GCCFLAGS=-Wall
SRC=src
OBJ=obj
BUILD=build
HEADER_FILES=$(wildcard src/*.h)
SOURCE_FILES=$(wildcard src/*.c)
OBJECTS=$(patsubst %.c, $(OBJ)/%.o, $(SOURCE_FILES))

all:
	make mkdir
	make $(TARGET)
	rm -f $(OBJ)/$(SRC)/*.o
	echo "\n\nExecutando...\n\n"
	./$(BUILD)/$(TARGET)

mkdir:
	mkdir -p $(OBJ) $(BUILD) $(OBJ)/$(SRC)

$(TARGET): $(OBJECTS)
	$(GCC) ${GCCFLAGS} -o $(BUILD)/$(TARGET) $(OBJECTS)

$(OBJ)/%.o: %.c $(HEADER_FILES)
	$(GCC) ${GCCFLAGS} -c -o $@ $<

clean:
	rm -f $(OBJ)/$(SRC)/*.o $(BUILD)/$(TARGET)