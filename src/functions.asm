section .text

global lenstr; función para calcular la longitud de un string
global valid_depositar, valid_retirar; Funciones de validación
global op_depositar, op_retirar; Funciones de operación

lenstr:
    xor rcx, rcx; contador principal
    xor rax, rax; registro a retornar

    loop:  
        mov al, byte [rdi + rcx]; extrayendo el char del argumento rdi
        cmp al, 0 ; Comparando con el salto de linea

        je end
        inc rcx; rcx = rcx + 1
        jne loop

        end:
            mov rax, rcx
            ret ; retornando la cantidad de rax 

; FUNCIONES DE VALIDACIÓN
; Estas validaciones tiene como objetivo comprobar que la operación que se está por ejecutar pueda ser realmente ejecutada

valid_depositar:
    xor rax, rax; Limpiando el valor de rax para evitar conflictos

    cmp rdi, 10000; Comparando rdi con 10000
    je vd_NonPossible; si saldo (rdi) == 10000 -> NO SE PUEDE DEPOSITAR
    jl vd_PositiveReturn; si saldo (rdi) < 10000 -> SE PUEDE DEPOSITAR

    vd_NonPossible:
        mov rax, 1; NO ES POSIBLE DEPOSITAR
        ret
    
    vd_PositiveReturn:
        mov rax, 0; SI ES POSIBLE DEPOSITAR
        ret

valid_retirar: 
    xor rax, rax; Limpiando el valor de rax para evitar conflictos

    cmp rdi, 100; Comparando rdi con 100
    je vr_NonPossible; si saldo (rdi) == 100 -> NO SE PUEDE RETIRAR
    jg vr_PositiveReturn; si saldo (rdi) > 100 -> SE PUEDE RETIRAR

    vr_NonPossible:
        mov rax, 1; NO ES POSIBLE RETIRAR
        ret
    
    vr_PositiveReturn:
        mov rax, 0; SI ES POSIBLE RETIRAR
        ret

; FUNCIONES DE OPERACIÓN

op_depositar:
    add rdi, rsi; saldo = saldo + depósito
    cmp rdi, 10000
    jg od_NonPossible; if saldo (rdi) > 10000 = NO SE PUEDE DEPOSITAR
    jle od_PositiveReturn; if saldo (rdi) <= 10000

    od_NonPossible:
        mov rax, 0
        ret
    
    od_PositiveReturn:
        mov rax, 1
        ret

op_retirar:
    sub rdi, rsi; saldo = saldo - depósito
    cmp rdi, 100

    jge or_PositiveReturn; if saldo (rdi) >= 100 -> SE PUEDE RETIRAR
    jl or_NonPossible; if saldo (rdi) < 100 -> NO SE PUEDE RETIRAR

    or_NonPossible:
        mov rax, 0
        ret
    
    or_PositiveReturn:
        mov rax, 1
        ret