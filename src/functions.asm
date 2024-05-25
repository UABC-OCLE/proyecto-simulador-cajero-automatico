section .data
    ; Mensajes para las funciones de retiro
    cantidad_invalida db "Error: Verifique que la cantidad a retirar sea correcta.",10
    cantidad_invalida_len equ $ - cantidad_invalida

    error_retiro_insuficiente db "Error: Saldo insuficiente para realizar el retiro",10
    error_retiro_insuficiente_len equ $ - error_retiro_insuficiente
    
    retiro_exitoso db "Retiro realizado con exito",10
    retiro_exitoso_len equ $ - retiro_exitoso

    ; Mensajes para las funciones de depósito
    deposito_exitoso db "Depósito realizado con éxito",10
    deposito_exitoso_len equ $ - deposito_exitoso

    deposito_incorrecto db "Error: La cantidad que ingresó no es válida.",10
    deposito_incorrecto_len equ $ - deposito_incorrecto

section .text
global compare_strings; FUNCIÓN REALIZADA POR ROGELIO
global retirar_dinero; FUNCIÓN REALIZADA POR JORGE
global depositar_dinero; FUNCIÓN REALIZADA POR DANICIA
global comparar_saldos; FUNCIÓN REALIZADA POR PELLEGRÍN

; FUNCION DE ACCESO - Rogelio Lara Duran # 1291647
; Params: 
; rdi - Cadena de chars ingresada por el usuario
; rsi - Cadena de char en el buffer actual (dada por i en C)

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
    cmp rsi, 0 ; Si el retiro es menor a 0, retornar
    jle cantidad_incorrecta

    cmp rsi, 8000 ; Si el retiro es mayor a 8000, retornar
    jg cantidad_incorrecta
    
    cmp rdi, rsi ; Si el saldo es menor a la cantidad a retirar, retornar
    jl retiro_insuficiente
    
    ; Si el saldo es mayor o igual a la cantidad a retirar, restar la cantidad a retirar al saldo
    sub rdi, rsi
    mov rbx, rdi ; rbx sirve como un registro auxiliar para guardar el nuevo saldo
    
    mov rbx, rdi
    mov rdi, 1
    mov rax, 1
    mov rsi, retiro_exitoso
    mov rdx, retiro_exitoso_len
    syscall

    mov rax, rbx
    ret

cantidad_incorrecta:
    mov rbx, rdi
    mov rdi, 1
    mov rax, 1
    mov rsi, cantidad_invalida
    mov rdx, cantidad_invalida_len
    syscall
    mov rax, rbx
    ret

retiro_insuficiente:
    mov rbx, rdi
    mov rdi, 1
    mov rax, 1
    mov rsi, error_retiro_insuficiente
    mov rdx, error_retiro_insuficiente_len
    syscall
    jmp retornar_mismo_saldo

retornar_mismo_saldo:
    mov rax, rbx
    ret

; FUNCION DE DEPOSITAR - Danicia Yeudiel Garcia Guerrero # 1291295
; Params: 
; rdi - Saldo Actual
; rsi - Monto depósito

depositar_dinero:
    cmp rsi, 10000
    jge deposito_invalido

    ;Si llega a quí es que es válido
    add rdi, rsi
    mov rbx, rdi

    mov rdi, 1
    mov rax, 1
    mov rsi, deposito_exitoso
    mov rdx, deposito_exitoso_len
    syscall

    mov rax, rbx
    ret

deposito_invalido:
    mov rbx, rdi
    mov rdi, 1
    mov rax, 1
    mov rsi, deposito_incorrecto
    mov rdx, deposito_incorrecto_len
    syscall

    mov rax, rbx; Retornar el mismo saldo
    ret

; FUNCION DE TRANSFERENCIA - Kevin Paul Pellegrín Vasquez # 2207262
; Params: 
; rdi - (Monto a transferir)
; rsi - (Saldo en cuenta)

comparar_saldos:
    xor rax, rax ; Limpiando rax por si las dudas

    cmp rdi, 0 ; si es menor a 0 (negativo), error
    jl .error

    cmp rdi, 10000 ; si es mayor a 10000, error
    jg .error

    cmp rdi, rsi ; si el monto a transferir es mayor al saldo, error
    jg .error

    mov rax, 0 ; 0 es exitoso
    ret

.error:
    mov rax, 1 ; 1 es error
    ret