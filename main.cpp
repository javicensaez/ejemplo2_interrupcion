/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 1 //Etiqueta con la constante del tiempo de espera entre iteración del while

DigitalOut led(D5); //Diodo led conectado en el pin D5
InterruptIn boton(D4); //Boton conectado en el pin D4, de tipo interrupcion



void botonSoltado(){
    led=!led; //Justo al soltar cambiamos el led
}

int main()
{
    printf("Hola mundo\n"); //Mensaje de comienzo de programa

    boton.fall(&botonSoltado); //Configuramos la funcion que queremos ejecutar justo al soltar el boton

    while (true) // Bucle para que se ejecute constantemente
    {
        thread_sleep_for(WAIT_TIME_MS); //Dentro del bucle no hacemos nada, funciona por interrupciones.
    }
}

