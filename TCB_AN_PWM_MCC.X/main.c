/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include <xc.h>
#define F_CPU 32768UL //informa a frequência do clock utilizado
#define DEBOUNCE_TIME 25
#include <util/delay.h>
#include <stdio.h>


unsigned char button_state() { // Função que verifica se o botão está ou não ativado
   //Bitset(PORTC, 0x06);
   int a = PORTC.IN; //Faz com que a variável a seja igual ao estado lógico das portas C.
   a = a - 0b10000000; //verficiação se o botão está ou não ativado
    if (a < 0) {
    //if (PORTC.IN.PIN7 == 0){
        //if ((PORTC.IN == 0b00000011)||(PORTC.IN == 0b01000011)){
        _delay_ms(DEBOUNCE_TIME); //Processo de debouncing
        if (a < 0) {
        //if (PORTC.IN.PIN6 == 0){
            //if ((PORTC.IN == 0b00000011)||(PORTC.IN == 0b01000011)){
            //_delay_ms(DEBOUNCE_TIME); //Processo de debuncing
            return 1; //informar que o botão foi apertado

        }
    }
    return 0;
}

void duty_75(){
    
    TCB3.CCMP = 0xC0FF;
    
}

void duty_25(){
    
    TCB3.CCMP = 0x40FF;
    
}

void duty_50(){
    
    TCB3.CCMP = 0x80FF;
    
}

/*
    Main application
*/
int main(void)
{
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();
    PORTC.DIR = 0b01000000; //Pino PC6 como output e o pino PC7 como input
    PORTC.OUT &= 0x00;

    /* Replace with your application code */
    int i = 0;
    while (1){
        if (button_state()){
             i++;
            // _delay_ms(500);
             PORTC.OUTTGL = 0b01000000;
             if ( i == 3){
                 duty_25();
                 i = 0;
             }
             
             else if (i == 2){
                 duty_50();
             }
             
             else if (i == 1){
                 duty_75();
             }
             do {

            } while (button_state()); //Espera o botão parar de ser apertado
             
         }
    }
}
/**
    End of File
*/