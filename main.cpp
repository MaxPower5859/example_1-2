#include "mbed.h"
#include "arm_book_lib.h"

/* 
En /home/studio/workspace/example-1.2-tp_02/mbed-os/mbed.h, se observa que 
se incluyen varias cabeceras y el codigo esta en C

En /home/studio/mbed-os/26606218ad9d1ee1c8781aa73774fd7ea3a7658e/mbed.h pasa 
exactamente lo mismo

La funcion de ambas es traer las librerias necesarias para poder programar

 */
int main()
{
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