SRC = $(wildcard src/*.c)
OBJ = $(SRC:%.c=%.o)

bin = advcalc

$(bin): $(OBJ)
	gcc $^ -o $@

%.o: %.c
	gcc -o $@ -c $<

clean: $(OBJ)
	rm $^
	rm $(bin)

run: $(bin)
	./$(bin)