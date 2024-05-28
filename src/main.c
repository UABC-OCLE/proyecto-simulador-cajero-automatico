/// APLICACIÓN EXCLUSIVAMENTE ENFOCADA PARA LA DEPENDENCIA LINUX X86 - 64 BITS
// Es importante tener instalada la distribución de Linux: Ubuntu 22.04 en adelante.

// Librerías de C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Funciones de ensamblador
extern int compare_strings(char *str1, char *str2); // Función hecha por Roger
extern int retirar_dinero(int saldo, int retiro);  // Función hecha por Jorge
extern int depositar_dinero(int saldo_actual, int monto_deposito); // Función hecha por Danicia
extern int comparar_saldos(int transferencia, int saldo); // Función hecha por Pellegón

int main(void)
{
    system("clear");

    /// Settings de información de usuarios
    char *names[5] = {"Adrián\0", "Danicia\0", "Pellegrín\0", "Roger\0", "Jorge\0"};
    char *numcuenta[5] = {"003412\0", "132441\0", "134153\0", "492453\0", "314514\0"};
    char *pins[5] = {"0034\0", "1323\0", "1341\0", "4924\0", "3145\0"};
    int saldos[5] = {10000, 1300, 1800, 4000, 3000};

    // Variables de consulta y muestra de información
    char *username, *numberAccount;
    int saldoEnCuenta;

    // Inputs del usuario
    char input_account[18], input_pin[18], input_extern_account[18];
    int transferAmount, cantidadRetirar;

    /// Variables de funcionamiento 
    int MenuUserOn, menu_input, user_input, cuenta_encontrada;
    int user_identifier, user_identifier_transfer;

    /* DESARROLLO DEL PROGRAMA */
    while(1)
    {
        printf("----------------------- MENU -----------------------\n\n");
        printf("Ingrese el numero con la funcion que desea realizar\n");
        printf("(1) Iniciar operacion\n(2) Cancelar operacion\n= ");
        scanf("%d", &menu_input);
        while(getchar() != '\n');

        switch(menu_input)
        {
            case 1:
                // Conservar estas lineas para inicializar los valores
                MenuUserOn = 0;
                cuenta_encontrada = 0;
                system("clear");

                while (!cuenta_encontrada)
                {
                    printf("Ingrese su número de cuenta\n= ");
                    fgets(input_account, sizeof(input_account), stdin);
                    input_account[strcspn(input_account, "\n")] = '\0';

                    printf("\nIngrese su PIN\n= ");
                    fgets(input_pin, sizeof(input_pin), stdin);
                    input_pin[strcspn(input_pin, "\n")] = '\0';

                    // Comparar el número de cuenta ingresado con los números de cuenta almacenados
                    for (int i = 0; i < 5; i++)
                    {
                        //Funcion en ensamblador
                        if(compare_strings(input_account, numcuenta[i]) && compare_strings(input_pin, pins[i]))
                        {
                            cuenta_encontrada = 1;
                            MenuUserOn = 1; // Si llega aquí significa que si puede entrar a la interfaz

                            //IMPORTANTE PARA QUE FUNCIONE BIEN LA IMPRESION EN EL MENU
                            numberAccount = numcuenta[i];
                            username = names[i];
                            saldoEnCuenta = saldos[i];
                            user_identifier = i;
                            break;
                        }
                    }

                    if (!cuenta_encontrada)
                    {
                        MenuUserOn = 0;
                        sleep(0.5);
                        printf("Numero de cuenta o contraseña inválidos. Inténtelo de nuevo.\n");
                        sleep(1);
                        system("clear");
                        sleep(0.8);
                    }
                }

                while(MenuUserOn == 1)
                {   // Pasó el filtro de seguridad para validar el acceso
                    system("clear");
                    printf("----------------------- MENU DE USUARIO -----------------------\n\n");

                    // Muestra de la información
                    printf("¡Bienvenid@, %s!\nNumero de cuenta: %s\n", username, numberAccount);
                    printf("Saldo disponible: %d\n\n", saldoEnCuenta);

                    // Ingreso del usuario
                    printf("Ingrese el numero de la opcion que desee consultar\n");
                    printf("(1) Depositar\n(2) Retirar\n(3) Transferir\n(4) Cerrar sesion\n= ");
                    scanf("%d", &user_input);
                    while(getchar() != '\n');

                    switch(user_input)
                    {
                        case 1:
                            sleep(0.8);
                            system("clear");
                            printf("----------------------- DEPOSITAR -----------------------\n\n");

                            int monto_deposito;
                            printf("Ingrese el monto a depositar: ");
                            scanf("%d", &monto_deposito);
                            while(getchar() != '\n');

                            saldoEnCuenta = depositar_dinero(saldoEnCuenta, monto_deposito); // Llamado de la función

                            if(saldoEnCuenta != saldos[user_identifier]) // Si el saldo "actualizado" != al saldo en la base de datos hay que reemplazarlo
                            {
                                saldos[user_identifier] = saldoEnCuenta; // Actualizando el saldo del usuario en la sesión actual
                            }

                            sleep(1);
                            break;

                        case 2:
                            sleep(0.8);
                            system("clear");
                            printf("----------------------- RETIRAR -----------------------\n\n");

                            printf("Ingrese la cantidad que desea retirar: ");
                            scanf("%d", &cantidadRetirar);
                            while(getchar() != '\n');

                            saldoEnCuenta = retirar_dinero(saldoEnCuenta, cantidadRetirar); // Obteniendo el nuevo saldo
                            saldos[user_identifier] = saldoEnCuenta; // Actualizando el valor del retiro en el arreglo saldos

                            sleep(1);
                            break;

                        case 3:
                            cuenta_encontrada = 0;
                            user_identifier_transfer = 0;

                            sleep(0.8);
                            system("clear");
                            printf("----------------------- TRANSFERIR -----------------------\n\n");

                            printf("Ingrese el numero de cuenta a la que quiere transferir: ");
                            fflush(stdin);
                            fgets(input_extern_account, sizeof(input_extern_account), stdin);
                            input_extern_account[strcspn(input_extern_account, "\n")] = '\0';

                            if(!compare_strings(input_extern_account, numberAccount)) // Evaluando que el ususario no se quiera enviar dinero a si mismo
                            {
                                for(int i = 0; i < 5; i++)
                                {
                                    if(compare_strings(input_extern_account, numcuenta[i])) // Comparando que el input del usuario councida con algun número de cuenta
                                        {
                                            cuenta_encontrada = 1;
                                            user_identifier_transfer = i; // Brindando el índice del usuario identificado
                                            break;
                                        }
                                }

                                if (cuenta_encontrada)
                                {
                                    sleep(0.5);
                                    system("clear");
                                    sleep(0.5);
                                    printf("¡Cuenta encontrada!\nIngrese la cantidad a transferir: ");
                                    scanf("%d", &transferAmount);
                                    while(getchar() != '\n');

                                    if(comparar_saldos(transferAmount, saldos[user_identifier]))
                                    {
                                        sleep(0.5);
                                        printf("No se puede transferir ese monto desde esta cuenta.\n");
                                        sleep(1);
                                        system("clear");
                                        sleep(0.5);
                                    }
                                    else
                                    {
                                        system("clear");
                                        sleep(0.5);
                                        printf("Transferencia a la cuenta %s exitosa.\n", input_extern_account);
                                        sleep(1.5);
                                        system("clear");
                                        sleep(0.5);

                                        saldoEnCuenta = saldoEnCuenta - transferAmount; // Actualizando el saldo en la interfaz
                                        saldos[user_identifier] = saldos[user_identifier] - transferAmount; // Actualizando el saldo del usuario actual en el arreglo
                                        saldos[user_identifier_transfer] = saldos[user_identifier_transfer] + transferAmount; // Actualizando el saldo del usuario externo en el arreglo
                                    }
                                }
                                else
                                {
                                    sleep(0.5);
                                    printf("Numero de cuenta no identificado. Inténtelo de nuevo.\n");
                                    sleep(1);
                                    system("clear");
                                }
                            }
                            else
                            {
                                sleep(0.5);
                                printf("No puede enviar dinero a su misma cuenta, intentelo de nuevo.\n");
                                sleep(1);
                                system("clear");
                            }

                            sleep(1);
                            break;

                        case 4:
                            /// Reinicio de variables para evitar incongruencias
                            MenuUserOn = 0; // Cerrando el menu de consultas en la cuenta
                            cuenta_encontrada = 0; // Seteando a 0 la validación de ASM
                            user_identifier = 0; // Identificador a 0
                            user_identifier_transfer = 0; // Identificador a 0

                            sleep(0.8);
                            system("clear");
                            sleep(1);
                            printf("----------------------- Sesión cerrada exitosamente -----------------------\n");
                            sleep(1);
                            system("clear");
                            break;

                        default:
                            sleep(0.5);
                            printf("Opcion no reconocida.\n\n");
                            sleep(1);
                            system("clear");
                            sleep(0.5);
                            break;
                    }
                }
                break;

            case 2:
                system("clear");
                printf("\n\n----------------------- APLICACIÓN CERRADA EXITOSAMENTE -----------------------\n\n\n");
                return 0;

            default:
                sleep(0.5);
                printf("Opcion no reconocida.\n\n");
                sleep(1);
                system("clear");
                sleep(0.5);
                break;
        }
    }
}