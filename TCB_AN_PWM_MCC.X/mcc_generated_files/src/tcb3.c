/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
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


#include "../include/tcb3.h"
pwm_irq_cb_t TCB3_pwm_cb= NULL;
ISR(TCB3_INT_vect)
{
    static volatile uint8_t callback_count = 0;

    // Clear the interrupt flag
    TCB3.INTFLAGS = TCB_CAPT_bm;

    // callback function - called every 0 passes
    if ((++callback_count >= TCB3_PWM_INTERRUPT_CB_RATE) && (TCB3_PWM_INTERRUPT_CB_RATE != 0)) {
        if (TCB3_pwm_cb!= NULL) {
                TCB3_pwm_cb();
        }
    }
}

/**
 * \brief Initialize tcb interface
 *
 * \return Initialization status.
 */
int8_t TCB3_Initialize()
{
    //Compare or Capture
    TCB3.CCMP = 0x7F7F;

    //Count
    TCB3.CNT = 0x00;

    //ASYNC disabled; CCMPINIT disabled; CCMPEN enabled; CNTMODE PWM8; 
    TCB3.CTRLB = 0x17;

    //DBGRUN disabled; 
    TCB3.DBGCTRL = 0x00;

    //FILTER disabled; EDGE disabled; CAPTEI disabled; 
    TCB3.EVCTRL = 0x00;

    //OVF disabled; CAPT enabled; 
    TCB3.INTCTRL = 0x01;

    //OVF disabled; CAPT disabled; 
    TCB3.INTFLAGS = 0x00;

    //Temporary Value
    TCB3.TEMP = 0x00;

    //RUNSTDBY disabled; CASCADE disabled; SYNCUPD disabled; CLKSEL DIV2; ENABLE enabled; 
    TCB3.CTRLA = 0x03;

    return 0;
}

void TCB3_WriteTimer(uint16_t timerVal)
{
    TCB3.CNT=timerVal;
}

uint16_t TCB3_ReadTimer(void)
{
    uint16_t readVal;

    readVal = TCB3.CNT;

    return readVal;
}

void TCB3_EnableCaptInterrupt(void)
{
    TCB3.INTCTRL |= TCB_CAPT_bm; /* Capture or Timeout: enabled */
}

void TCB3_EnableOvfInterrupt(void)
{
	TCB3.INTCTRL |= TCB_OVF_bm; /* Overflow Interrupt: enabled */
}

void TCB3_DisableCaptInterrupt(void)
{
    TCB3.INTCTRL &= ~TCB_CAPT_bm; /* Capture or Timeout: disabled */
}

void TCB3_DisableOvfInterrupt(void)
{
	TCB3.INTCTRL &= ~TCB_OVF_bm; /* Overflow Interrupt: disabled */

}

inline void TCB3_ClearCaptInterruptFlag(void)
{
    TCB3.INTFLAGS |= TCB_CAPT_bm;

}

inline void TCB3_ClearOvfInterruptFlag(void)
{
    TCB3.INTFLAGS |= TCB_OVF_bm;

}

inline bool TCB3_IsCaptInterruptEnabled(void)
{
    return ((TCB3.INTCTRL & TCB_CAPT_bm) > 0);
}

inline bool TCB3_IsOvfInterruptEnabled(void)
{
    return ((TCB3.INTCTRL & TCB_OVF_bm) > 0);
}

/* 8-bit PWM API's */       
void TCB3_PWM_Enable(void)
{
    TCB3.CTRLA |= TCB_ENABLE_bm;
}

void TCB3_PWM_Disable(void)
{
    TCB3.CTRLA &= ~TCB_ENABLE_bm;
}

void TCB3_load_counter(TCB3_pwm_register_t counter_value)
{
    TCB3.CNT = counter_value;
}

void TCB3_load_top(TCB3_pwm_register_t top_value)
{
    TCB3.CCMPL = top_value;
}

void TCB3_load_duty_cycle(TCB3_pwm_register_t duty_value)
{
    TCB3.CTRLA &= ~TCB_ENABLE_bm;
    TCB3.CCMPH = duty_value;
    TCB3.CNT   = 0;
    TCB3.CTRLA |= TCB_ENABLE_bm;
}

void TCB3_register_callback(pwm_irq_cb_t function)
{
    TCB3_pwm_cb= function;
}

