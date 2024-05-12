// Librerías de C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Funciones de ensamblador
extern int lenstr(char *str);

int main(void)
{
    /// Settings de información de usuarios
    char *names[5] = {"Adrián\0", "Danicia\0", "Pellegrín\0", "Roger\0", "Jorge\0"};
    char *numcuenta[5] = {"003412\0", "132441\0", "13415\0", "492453\0", "314514\0"};
    char *pins[5] = {"0034\0", "1323\0", "1341\0", "4924\0", "3145\0"};
    int saldos[5] = {3400, 1300, 1800, 4000, 3000};

    /// Menu variables
    int MenuUserOn = 1;
    int menu_input, user_input;

    /// User variables
    //char user_name, user_na,
    int number_account, saldoEnCuenta; // Pruebas

    while(1)
    {
        printf("----------------------- MENU -----------------------\n\n");
        printf("Ingrese el numero con la funcion que desea realizar\n");
        printf("(1) Iniciar operacion\n");
        printf("(2) Cancelar operacion\n= ");
        scanf("%d", &menu_input);

        switch(menu_input)
        {
            case 1:
                MenuUserOn = 1;
                saldoEnCuenta = 2000; // Esto se debe de reemplezar por el saldo en la cuenta del usuario
                system("clear");

                printf("Ingrese su numero de cuenta.\n= ");
                scanf("%d",&number_account);

                while(number_account != 1) // En un futuro se debe validar que el fgets es igual a una de las cuentas del usuario
                {
                    system("clear");
                    printf("Opcion invalida, ingrese un nombre de usuario valido.\n= ");
                    scanf("%d",&number_account);
                }

                while(MenuUserOn == 1)
                {
                    // Pasó el filtro de seguridad de acceso
                    system("clear");
                    printf("----------------------- MENU DE USUARIO -----------------------\n\n");
                    printf("Clave de usuario: %d\n", number_account);
                    printf("Saldo disponible: %d\n\n", saldoEnCuenta);
                    printf("Ingrese el numero de la opcion que desee consultar\n");
                    printf("(1) Depositar\n(2) Retirar\n(3) Transferir\n(4) Cerrar sesion\n= ");
                    scanf("%d", &user_input);

                    switch(user_input)
                    {
                        case 1:
                            sleep(1);
                            system("clear");
                            printf("----------------------- DEPOSITAR -----------------------\n\n");
                            // Futura implementación: Si el saldo es mayor o igual a 10,000. NO DEBE DEPOSITAR
                            sleep(1);
                            break;

                        case 2:
                            sleep(1);
                            system("clear");
                            printf("----------------------- RETIRAR -----------------------\n\n");
                            // Futura implementación: Si el saldo es menor o igual a 100. NO DEBE RETIRAR
                            sleep(1);
                            break;

                        case 3:
                            sleep(1);
                            system("clear");
                            printf("----------------------- TRANSFERIR -----------------------\n\n");
                            // Futura implementación: Si el No de cuenta de otro usuario, NO DEBE TRANSFERIR
                            sleep(1);
                            break;

                        case 4:
                            sleep(1);
                            system("clear");
                            sleep(1);
                            printf("----------------------- Sesión cerrada exitosamente -----------------------\n\n");
                            sleep(1);
                            system("clear");
                            MenuUserOn = 0; // Cerrando el menu de consultas en la cuenta
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
                printf("----------------------- SESION CERRADA EXITOSAMENTE -----------------------\n");
                sleep(1);
                return 0;

            default:
                system("clear");
                printf("Opcion no reconocida.\n\n");
            }
    }
}
