section .data
    ; Retiro
    error_retiro_insuficiente db "Error: Saldo insuficiente para realizar el retiro", 0
    error_retiro_insuficiente_len equ $ - error_retiro_insuficiente
    error_retiro_mayor db "Error: No se puede retirar una cantidad mayor a 8000", 0
    error_retiro_maor_len equ $ - error_retiro_mayor
    error_retiro_menor db "Error: No se puede retirar una cantidad menor a 0", 0
    error_retiro_menor_len equ $ - error_retiro_menor
    retiro_exitoso db "Retiro realizado con exito", 0
section .text
global compare_strings; FUNCIÓN REALIZADA POR ROGER
global retirar_dinero; FUNCIÓN REALIZADA POR JORGE

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

; FUNCION DE RETIRAR - Jorge Omar Torres Sosa # 1270900
; Params: 
; rdi - Saldo Actual
; rsi - Cantidad a retirar

retirar_dinero:
    ; Si el retiro es mayor a 8000, retornar
    cmp rsi, 8000
    ja retiro_mayor
    ; Si el retiro es menor a 0, retornar
    cmp rsi, 0
    jl retiro_menor
    cmp rdi, rsi
    ; Si el saldo es menor a la cantidad a retirar, retornar
    jb retiro_insuficiente
    ; Si el saldo es mayor o igual a la cantidad a retirar, restar la cantidad a retirar al saldo
    sub rdi, rsi
    mov rax, rdi
    ret
retiro_insuficiente:
    mov rbx, rdi
    mov rdi, 1
    mov rax, 1
    mov rsi, error_retiro_insuficiente
    mov rdx, error_retiro_insuficiente_len
    syscall
    jmp retornar_mismo_saldo
retiro_mayor:
    mov rbx, rdi
    mov rdi, 1
    mov rax, 1
    mov rsi, error_retiro_mayor
    mov rdx, error_retiro_maor_len
    syscall
    jmp retornar_mismo_saldo
retiro_menor:
    mov rbx, rdi
    mov rdi, 1
    mov rax, 1
    mov rsi, error_retiro_menor
    mov rdx, error_retiro_menor_len
    syscall
    jmp retornar_mismo_saldo
retornar_mismo_saldo:
    mov rax, rbx
    ret