#include "mbed.h"
#include "arm_book_lib.h"

/* 
En /home/studio/workspace/example-1.2-tp_02/mbed-os/mbed.h, se observa que 
se incluyen varias cabeceras y el codigo esta en C

En /home/studio/mbed-os/26606218ad9d1ee1c8781aa73774fd7ea3a7658e/mbed.h pasa 
exactamente lo mismo

La funcion de ambas es traer las librerias necesarias para poder programar

 */

 /* Primero una explicacion de que es cada cosa:
 
 Objeto: Un objeto es una instancia de una clase. Representa una entidad que tiene propiedades y puede 
 realizar acciones. En C++, los objetos se crean a partir de clases y se utilizan para acceder a los 
 miembros de la clase.
 
 Mensaje: En C++, el término "mensaje" no se utiliza de la misma manera que en algunos otros lenguajes de 
 programación. En C++, se utiliza el concepto de "llamada a función" o "invocación de método" para 
 comunicarse con objetos y llamar a funciones miembro.

 Método: Un método es una función miembro de una clase que puede ser llamada en un objeto de esa clase. 
 Los métodos definen el comportamiento de un objeto y pueden acceder a sus datos internos.
 
 Clase: Una clase es una plantilla que define la estructura y el comportamiento de los objetos. Los objetos 
 se crean a partir de una clase, y la clase define sus atributos y métodos.

 Herencia: La herencia es un concepto de programación orientada a objetos que permite crear una nueva clase 
 basada en una clase existente. La nueva clase hereda los atributos y métodos de la clase base y puede agregar 
 o modificar su comportamiento.

 Polimorfismo: simplifica la programación al permitir que objetos de diferentes clases respondan de manera 
 específica a una llamada de función común, lo que facilita la escritura de código más genérico y reutilizable.

 Interfaz: En C++, una interfaz es una clase abstracta que define un conjunto de métodos virtuales que deben 
 ser implementados por cualquier clase derivada. Las interfaces se utilizan para lograr la abstracción y el 
 polimorfismo.

 Constructor: Un constructor es un método especial en una clase que se llama automáticamente cuando se crea un 
 objeto de esa clase. Se utiliza para inicializar los datos miembros del objeto.

 Sobrecarga: La sobrecarga se refiere a la capacidad de definir múltiples funciones con el mismo nombre pero con 
 diferentes parámetros. Esto permite que una función realice diferentes acciones según los argumentos que recibe.
  */
int main(){
    /* 
    Se crean objetos de la clase DigitalIn y DigitalOut llamados gasDetector, 
    overTempDetector, y alarmLed.

    Los objetos gasDetector y overTempDetector llaman al método mode() para configurar 
    su modo de funcionamiento como PullDown, se conectan a 5v.

    Los constructores estan dentro de las clases DigitalIn y DigitalOut
     */
   DigitalIn gasDetector(D2);

    /*
   Pusimos el break en la linea 16...
   Hicimos step into varias veces en la linea 16 para ver como se abren las bibliotecas
   DigitalIn.h - mbed_gpio.c - gpio_api.c - pinmap.c
   pin_device.h - stm32f4xx_II_gpio.h - cmsis_armclang.h
    */

    /* 
    En digitalin.h entro en una clase y luego va llamndo a otras funciones
    para ir definiendo esta clase y asi poder utilizar esta funcion de forma sencilla.
     */

   DigitalIn overTempDetector(D3);
   
   DigitalOut alarmLed(LED1);
   
   /* 
   Aca se configuran como PullDown por lo cual hayq ue conectarlos a 3V3
    */
   gasDetector.mode(PullDown);   

   overTempDetector.mode(PullDown);

/* 
Se puede ver que al poner el break en la linea 44 si el boton no estaba pulsado no va a cambiar
el estado ya que el codigo no se estaria ejecutando. Luego si vas corriendo de a una linea a la vez.
Tambien se puede observar que se sigue ejercutando infinitamente el while (true), seria un loop.

 */
   while (true) {
      
      if ( gasDetector || overTempDetector ) {
         alarmLed = ON;
      } else {
         alarmLed = OFF;
      }
   }
}