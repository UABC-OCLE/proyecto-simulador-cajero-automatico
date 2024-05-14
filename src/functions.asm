section .text
global compare_strings; FUNCIÓN REALIZADA POR ROGER

; FUNCIONES DE VALIDACIÓN
; Estas validaciones tiene como objetivo comprobar que la operación que se está por ejecutar pueda ser realmente ejecutada

compare_strings:
    xor rax, rax        ; Inicializar rax a 0

loop:
    mov al, byte [rdi]  ; Cargar el byte de la primera cadena
    cmp al, byte [rsi]  ; Comparar con el byte de la segunda cadena
    jne end             ; Si son diferentes, salir del bucle
    test al, al         ; Comprobar si hemos llegado al final de la cadena (byte nulo)
    jz equal            ; Si sí, las cadenas son iguales
    inc rdi             ; Avanzar al siguiente byte de la primera cadena
    inc rsi             ; Avanzar al siguiente byte de la segunda cadena
    jmp loop            ; Repetir el bucle

equal:
    mov rax, 1
    ret

end:
    xor rax, rax
    ret