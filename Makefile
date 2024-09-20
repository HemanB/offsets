CC = gcc
FLAGS = -g

all: offsets

offsets: offsets_student.c offsets.c
	$(CC) $(FLAGS) -o $@ offsets_student.c offsets.c

clean:
	rm -f offsets