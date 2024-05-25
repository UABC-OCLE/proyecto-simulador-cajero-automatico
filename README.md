## Proyecto de simulación de cajero automático
Bienvenid@ al repositorio donde se aloja el proyecto de simulación de cajero automático, en este apartado se reúne toda la información relacionada al proyecto, incluyendo desde su formato de ejecución hasta el objetivo de cada función.

### Descripción del proyecto
La interfaz de usuario (UI) presentada en este proyecto simula un cajero automático muy habitual en nuestras operaciones bancarias. Esta UI presenta funciones útiles y enfocadas a la consulta de información y operaciones en una misma cuenta o en cuentas externas. 

En cuanto al desarrollo del prpyecto, la principal característica del proyecto corresponde a la construcción de un programa híbrido usando dos famosos lenguajes de programación: C y Lenguaje Ensamblador (usando la ISA x86 en su modo de 64 bits). Mediante el uso de estos lenguajes se construyó una UI totalmente funcional y un sistema de validaciones encargado de verificar que el programa funcione correctamente.

### Método de ejecución y uso del programa
Este proyecto puede ser usado por desarrolladores, testers y usuarios en general. Para poder usar cómodamente este programa, siga los siguientes pasos.
1. Verifique que tenga acceso a este programa (ya sea mediante la terminal en GitHub o en su repositorio/computadora de forma local), para esto, se recomienda el siguiente comando en terminal: `pwd` para verificar la dirección en la que se encuentra actualmente. Si identifica la siguiente carpeta: **proyecto-simulador-cajero-automatico/** significa que usted puede empezar a trabajar.

2. Una vez verifique que puede acceder a los múltiples archivos en el repositorio, dirijase a la carpeta *src* mediante el siguiente comando: `cd src`

3. Para poder tener la versión más reciente del programa y descartar errores, se recomienda usar el comando `make release`.  Por consiguiente, use: `make clean`, una vez realizados estos dos pasos, puede ejecutar el programa mediante el siguiente comando: `./main_release.bin`

4. La terminal se limpiará automáticamente y podrá hacer uso del programa.

**Importante: El programa hace uso de ingreso de texto, por lo que debe de ser cuidadoso en sus ingresos de datos para evitar confusiones y/o respuestas que innesperadas.** Haga uso del siguiente archivo de texto para poder ingresar datos correctos: [Información de usuarios](https://drive.google.com/file/d/1226QPkL5M2XFGopv3rYX7ZssU-V_LnC3/view?usp=sharing "Información de usuarios")

### Funciones existentes en el proyecto
A continuación se enlistan las opciones de consulta y operaciones disponibles en el proyecto, así como de las validaciones que las mismas incluyen 
- Interfaz de usuario mediante terminal.
- Función de inicio de sesión.
	 - Autentificación de numero de cuenta y pin
- Función de depósito.
	- Validación de monto a depósitar
- Función de retiro.
	- Validación de monto a retirar
- Función de transferencia entre cuentas.
	- Validación de existencia de cuentas externas
	- Validación de monto a transferir
	
------------
##### Información sobre los desarrolladores
- Adrián Elí Ramírez Martínez - 2201328
- Rogelio Lara Duran - 1291647
- Jorge Omar Torres Sosa - 1270900
- Danicia Yeudiel Garcia Guerrero - 1291295
- Kevin Paul Pellegrín Vasquez - 2207262