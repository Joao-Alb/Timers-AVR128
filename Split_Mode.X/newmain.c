/*
 * File:   newmain.c
 * Author: BEV
 *
 * Created on 7 de Outubro de 2021, 13:42
 */


#include <xc.h>
#define F_CPU 32768UL //informa a frequência do clock utilizado

void setup_timer(){
    
    PORTMUX.TCAROUTEA = PORTMUX_TCA0_PORTA_gc; //seleciona a porta A como saída
    TCA0.SPLIT.CTRLD = TCA_SPLIT_SPLITM_bm; //habilitando o split mode
    TCA0.SPLIT.CTRLB = TCA_SPLIT_HCMP0EN_bm | TCA_SPLIT_LCMP0EN_bm; //habilitando comparadores de high e low byte
    TCA0.SPLIT.LPER = 0xFF; //definindo frequencia de pwm1 como 1hz
    TCA0.SPLIT.HPER = 0xFF;//definindo frequencia de pwm2 como 0,5 hz
    TCA0.SPLIT.LCMP0 = 0x7F;//definindo valor de duty cycle como 50% 
    TCA0.SPLIT.HCMP0 = 0xBD;//definindo valor de duty cycle como 75%
    TCA0.SPLIT.CTRLA = 0x0F;//escolhendo valor de prescaler e iniciando contação
    
}

void TCA0_hardReset(){
    
    TCA0.SINGLE.CTRLA &= TCA_SINGLE_ENABLE_bm;
    
    TCA0.SINGLE.CTRLESET = TCA_SINGLE_CMD_RESET_gc;
}

void port_setup(){
    
    _PROTECTED_WRITE(CLKCTRL.MCLKCTRLA, CLKCTRL_CLKSEL_OSC32K_gc);//escolhendo frequencia de clock
    while (CLKCTRL.MCLKSTATUS & CLKCTRL_SOSC_bm){
 ;
}
    PORTA.DIR |= 0xFF;
    
}


void main(void) {
    
    TCA0_hardReset();
    
    port_setup();
    
    setup_timer();
            
    
    while(1){
        ;
    }
    
    return;
}
