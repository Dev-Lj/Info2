main: main.o
	gcc main.o -o main.exe -L src/lib -l glfw3 -l gdi32 -l opengl32

main.o: main.c
	gcc -c main.c -I src/include -g