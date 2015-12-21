.PHONY: all clean

TARGET=demo
SRC=main.c object.c object1.c object2.c
OBJ=main.o object.o object1.o object2.o

#Run
all: $(TARGET)
	./$(TARGET)

#Link
$(TARGET): $(OBJ)
	gcc -o $@ $^

#Compile
%.o: %.c
	gcc -c $< -o $@ -I.

clean:
	rm -rf $(OBJ) $(TARGET)
