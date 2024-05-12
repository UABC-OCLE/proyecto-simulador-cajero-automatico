# Variables
ASM_SOURCE = functions.asm
C_SOURCE = main.c
OBJ_FILES = main.o functions.o

EXEC_RELEASE = main_release.bin
EXEC_DEBUG = main_debug.bin

release: $(OBJ_FILES)
	gcc -o $(EXEC_RELEASE) $(OBJ_FILES)

debug: $(OBJ_FILES)
	gcc -g -o $(EXEC_DEBUG) $(OBJ_FILES)

main.o: $(C_SOURCE)
	gcc -c $(C_SOURCE)

functions.o: $(ASM_SOURCE)
	nasm -f elf64 -o functions.o $(ASM_SOURCE)

clean:
	rm -f $(OBJ_FILES) $(OBJ_FILES) $(EXEC_DEBUG)