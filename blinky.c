#include <stdint.h>
#include "inc/tm4c123gh6pm.h"

//*********
// Practica 1
// Maria Monserrath Elias Sanchez   283222
// Alberto Gonzalez Moreno          290466
//! \addtogroup example_list
//! <h1>Blinky (blinky)</h1>
//*********
// Parpadeo el LED integrado. 
// En esta practica se hace un ejemplo sencillo de como habilitar el LED integrado 
// como salida y con comportamiento digital mediante registros. 
//*********

int main(void)
{
    volatile uint32_t contador;
    volatile uint32_t valor =  134850;

    // Habilitar el puerto GPIO asociado al LED integrado en el microcontrolador
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    // Hacer una lectura rÃ¡pida para realizar ciclos (delays) despuÃ©s de habilitar el perifÃ©rico
    contador = SYSCTL_RCGC2_R;

    // Habilitar el pin PF3 asociado al LED intergrado el puerto GPIO.
    // Se establece la direcciÃ³n como salida y la funciÃ³n como digital. 

    //Puerto F
    GPIO_PORTF_DIR_R = 0x08 ; // Configura el Port F como Salida en el pin
    GPIO_PORTF_DEN_R = 0x08 ; //Pin PF3

    // ciclo infinito
    while(1)
    {
        // Prender el LED.
        GPIO_PORTF_DATA_R |= 0x08 ; //Pin PF3

        // Se realiza un ciclo for para hacer un delay.
        for(contador = 0; contador < valor; contador++)
        {
        }

        // Apagar el LED.
        GPIO_PORTF_DATA_R &= ~(0x08);

        // Se realiza un ciclo for para hacer un delay.
        for(contador = 0; contador < valor; contador++)
        {
        }
    }
}