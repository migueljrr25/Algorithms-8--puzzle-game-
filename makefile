CC = g++ -std=c++11 -Wextra
CFLAGS = -Wall
LDFLAGS =
OBJFILES = main.cpp Tile.cpp
TARGET = a.out

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
