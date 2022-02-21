OBJ_DIR = bin
SRC_DIR = src
OBJS = $(addprefix ${OBJ_DIR}/, main.o) # Add other .o files here 
EXE = ${OBJ_DIR}/main

# Build executable
${EXE}: ${OBJS}
	gcc $^ -o $@

# Create .o file from all .c files in root dir
${OBJ_DIR}/%.o: %.c
	gcc -c $< -I src -g -o $@

# Create .o file from all .c files in src/
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	gcc -c $< -I src -g -o $@

# Additional Dependencies 
#${OBJ_DIR}/otherFile.o: ${SRC_DIR}/otherFile.h