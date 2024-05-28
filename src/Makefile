# Variables
ASM_SOURCE = functions.asm
C_SOURCE = main.c
OBJ_FILES = main.o functions.o

EXEC_RELEASE = SystemAtm.exe

release: $(OBJ_FILES) # Cración del sistema ejecutable
	gcc -o $(EXEC_RELEASE) $(OBJ_FILES) -no-pie

main.o: $(C_SOURCE) # Creación del archivo objeto de la función de 
	gcc -c $(C_SOURCE)

functions.o: $(ASM_SOURCE) # Creación del archivo objeto de las funciones de ASM
	nasm -f elf64 -o functions.o $(ASM_SOURCE)

clean:
	rm -f $(OBJ_FILES) $(OBJ_FILES) $(EXEC_DEBUG)