
// Librerías de C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Funciones de ensamblador
//extern int lenstr(char *str);
extern int compare_strings(char *str1, char *str2);
extern int retirar_dinero(int saldo, int retiro);

int main(void)
{
    system("clear");
    
    /// Settings de información de usuarios
    char *names[5] = {"Adrián\0", "Danicia\0", "Pellegrín\0", "Roger\0", "Jorge\0"};
    char *numcuenta[5] = {"003412\0", "132441\0", "13415\0", "492453\0", "314514\0"};
    char *pins[5] = {"0034\0", "1323\0", "1341\0", "4924\0", "3145\0"};
    int saldos[5] = {10000, 1300, 1800, 4000, 3000};

    /// Menu variables
    int MenuUserOn, menu_input, user_input, cuenta_encontrada;
    char input_account[20];
    char input_pin[20];

    // Información del usuario
    char *nombre_encontrado, *menu_num_cuenta;
    int saldoEnCuenta;
    int cantidadRetirar;
    int user_identifier;

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
                    printf("Ingrese su número de cuenta:\n= ");
                    fgets(input_account, sizeof(input_account), stdin);
                    input_account[strcspn(input_account, "\n")] = '\0';

                    printf("Ingrese su PIN:\n= ");
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
                            menu_num_cuenta = numcuenta[i];
                            nombre_encontrado = names[i];
                            saldoEnCuenta = saldos [i];
                            user_identifier = i;
                            break;
                        }
                    }

                    if (!cuenta_encontrada)
                    {
                        MenuUserOn = 0;
                        system("clear");
                        printf("Número de cuenta no válido. Inténtelo de nuevo.\n");
                    }
                }

                while(MenuUserOn == 1)
                {   // Pasó el filtro de seguridad de acceso
                    system("clear");
                    printf("----------------------- MENU DE USUARIO -----------------------\n\n");

                    // Muestra de la información
                    printf("¡Bienvenid@, %s!\nNumero de cuenta: %s\n", nombre_encontrado, menu_num_cuenta);
                    printf("Saldo disponible: %d\n\n", saldoEnCuenta);

                    // Ingreso del usuario
                    printf("Ingrese el numero de la opcion que desee consultar\n");
                    printf("(1) Depositar\n(2) Retirar\n(3) Transferir\n(4) Cerrar sesion\n= ");
                    scanf("%d", &user_input);

                    switch(user_input)
                    {
                        case 1:
                            sleep(1);
                            system("clear");
                            printf("----------------------- DEPOSITAR -----------------------\n\n");
                            sleep(1);
                            break;

                        case 2:
                            sleep(1);
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
                            sleep(1);
                            system("clear");
                            printf("----------------------- TRANSFERIR -----------------------\n\n");
                            sleep(1);
                            break;

                        case 4:
                            /// SETEEN SUS VARIABLES DE VALIDACIÓN A 0 POR SI LAS DUDAS

                            MenuUserOn = 0; // Cerrando el menu de consultas en la cuenta
                            cuenta_encontrada = 0; // Seteando a 0 la validación de ASM
                            user_identifier = 0;

                            sleep(1);
                            system("clear");
                            sleep(1);
                            printf("----------------------- Sesión cerrada exitosamente -----------------------\n\n");
                            sleep(1);
                            system("clear");
                            break;

                        default:
                            printf("Opcion invalida.\n\n");
                            break;
                    }
                }
                break;

            case 2:
                sleep(1);
                system("clear");
                sleep(1);
                printf("\n\n----------------------- SESION CERRADA EXITOSAMENTE -----------------------\n\n\n");
                return 0;

            default:
                system("clear");
                printf("Opcion no reconocida.\n\n");
        }
    }
}