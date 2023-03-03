/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   2.0.0
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


#include "../include/tca0.h"

void TCA0_DefaultTimer1IsrCallback(void);
void (*TCA0_Timer1_isr_cb)(void) = &TCA0_DefaultTimer1IsrCallback;
void TCA0_DefaultLCMP0IsrCallback(void);
void (*TCA0_LCMP0_isr_cb)(void) = &TCA0_DefaultLCMP0IsrCallback;
void TCA0_DefaultLCMP1IsrCallback(void);
void (*TCA0_LCMP1_isr_cb)(void) = &TCA0_DefaultLCMP1IsrCallback;
void TCA0_DefaultLCMP2IsrCallback(void);
void (*TCA0_LCMP2_isr_cb)(void) = &TCA0_DefaultLCMP2IsrCallback;
void TCA0_DefaultTimer2IsrCallback(void);
void (*TCA0_Timer2_isr_cb)(void) = &TCA0_DefaultTimer2IsrCallback;

void TCA0_DefaultTimer1IsrCallback(void)
{
	//Add your ISR code here
}

void TCA0_DefaultLCMP0IsrCallback(void)
{
	//Add your ISR code here
}

void TCA0_DefaultLCMP1IsrCallback(void)
{
	//Add your ISR code here
}

void TCA0_DefaultLCMP2IsrCallback(void)
{
	//Add your ISR code here
}
void TCA0_DefaultTimer2IsrCallback(void)
{
	//Add your ISR code here
}

void TCA0_SetTimer1IsrCallback(TCA0_cb_t cb)
{
	TCA0_Timer1_isr_cb = cb;
}

void TCA0_SetLCMP0IsrCallback(TCA0_cb_t cb)
{
	TCA0_LCMP0_isr_cb = cb;
}

void TCA0_SetLCMP1IsrCallback(TCA0_cb_t cb)
{
	TCA0_LCMP1_isr_cb = cb;
}

void TCA0_SetLCMP2IsrCallback(TCA0_cb_t cb)
{
	TCA0_LCMP2_isr_cb = cb;
}

void TCA0_SetTimer2IsrCallback(TCA0_cb_t cb)
{
	TCA0_Timer2_isr_cb = cb;
}

ISR(TCA0_HUNF_vect)
{
	if (TCA0_Timer1_isr_cb != NULL)
	(*TCA0_Timer1_isr_cb)();
	
	TCA0.SPLIT.INTFLAGS = TCA_SPLIT_HUNF_bm;
}

ISR(TCA0_LCMP0_vect)
{
	if (TCA0_LCMP0_isr_cb != NULL)
	(*TCA0_LCMP0_isr_cb)();
	
	TCA0.SPLIT.INTFLAGS = TCA_SPLIT_LCMP0_bm;
}

ISR(TCA0_LCMP1_vect)
{
	if (TCA0_LCMP1_isr_cb != NULL)
	(*TCA0_LCMP1_isr_cb)();
	
	TCA0.SPLIT.INTFLAGS = TCA_SPLIT_LCMP1_bm;
}

ISR(TCA0_LCMP2_vect)
{
	if (TCA0_LCMP2_isr_cb != NULL)
	(*TCA0_LCMP2_isr_cb)();
	
	TCA0.SPLIT.INTFLAGS = TCA_SPLIT_LCMP2_bm;
}
ISR(TCA0_LUNF_vect)
{
	if (TCA0_Timer2_isr_cb != NULL)
	(*TCA0_Timer2_isr_cb)();
	
	TCA0.SPLIT.INTFLAGS = TCA_SPLIT_LUNF_bm;
}

/**
 * \brief Initialize tca interface
 *
 * \return Initialization status.
 */
int8_t TCA0_Initialize()
{
    //SPLITM enabled; 
    TCA0.SPLIT.CTRLD = 0x01;

    //HCMP2EN enabled; HCMP1EN enabled; HCMP0EN enabled; LCMP2EN enabled; LCMP1EN enabled; LCMP0EN enabled; 
    TCA0.SPLIT.CTRLB = 0x77;

    //HCMP2OV enabled; HCMP1OV enabled; HCMP0OV enabled; LCMP2OV enabled; LCMP1OV enabled; LCMP0OV enabled; 
    TCA0.SPLIT.CTRLC = 0x77;

    //CMD NONE; CMDEN NONE; 
    TCA0.SPLIT.CTRLECLR = 0x00;

    //CMD NONE; CMDEN NONE; 
    TCA0.SPLIT.CTRLESET = 0x00;

    //DBGRUN enabled; 
    TCA0.SPLIT.DBGCTRL = 0x01;

    //High Compare
    TCA0.SPLIT.HCMP0 = 0x14;

    //High Compare
    TCA0.SPLIT.HCMP1 = 0x14;

    //High Compare
    TCA0.SPLIT.HCMP2 = 0x14;

    //High Count
    TCA0.SPLIT.HCNT = 0x00;

    //High Period
    TCA0.SPLIT.HPER = 0x3B;

    //LCMP2 enabled; LCMP1 enabled; LCMP0 enabled; HUNF enabled; LUNF enabled; 
    TCA0.SPLIT.INTCTRL = 0x73;

    //LCMP2 disabled; LCMP1 disabled; LCMP0 disabled; HUNF disabled; LUNF disabled; 
    TCA0.SPLIT.INTFLAGS = 0x00;

    //Low Compare
    TCA0.SPLIT.LCMP0 = 0x7F;

    //Low Compare
    TCA0.SPLIT.LCMP1 = 0xBF;

    //Low Compare
    TCA0.SPLIT.LCMP2 = 0x05;

    //Low Count
    TCA0.SPLIT.LCNT = 0x00;

    //Low Period
    TCA0.SPLIT.LPER = 0xFF;

    //RUNSTDBY disabled; CLKSEL DIV1024; ENABLE enabled; 
    TCA0.SPLIT.CTRLA = 0x0F;

    return 0;
}

void TCA0_WriteTimer2(uint8_t timerVal)
{
    TCA0.SPLIT.LCNT=timerVal;
}
	
uint8_t TCA0_ReadTimer2(void)
{
    uint8_t readVal;
	
    readVal = TCA0.SPLIT.LCNT;
    return readVal;
}

void TCA0_WriteTimer1(uint8_t timerVal)
{
    TCA0.SPLIT.HCNT=timerVal;
}

uint8_t TCA0_ReadTimer1(void)
{
    uint8_t readVal;

    readVal = TCA0.SPLIT.HCNT;
	

	return readVal;
}

void TCA0_EnableInterrupt(void)
{
	TCA0.SPLIT.INTCTRL = 1 << TCA_SPLIT_HUNF_bp /* High Underflow Interrupt Enable: enabled */
	| 1 << TCA_SPLIT_LCMP0_bp /* Low Compare 0 Interrupt Enable: enabled */
	| 1 << TCA_SPLIT_LCMP1_bp /* Low Compare 1 Interrupt Enable: enabled */
	| 1 << TCA_SPLIT_LCMP2_bp /* Low Compare 2 Interrupt Enable: enabled */
	| 1 << TCA_SPLIT_LUNF_bp; /* Low Underflow Interrupt Enable: enabled */
}

void TCA0_DisableInterrupt(void)
{
	TCA0.SPLIT.INTCTRL = 0 << TCA_SPLIT_HUNF_bp    /* High Underflow Interrupt Enable: disabled */
	| 0 << TCA_SPLIT_LCMP0_bp /* Low Compare 0 Interrupt Enable: disabled */
	| 0 << TCA_SPLIT_LCMP1_bp /* Low Compare 1 Interrupt Enable: disabled */
	| 0 << TCA_SPLIT_LCMP2_bp /* Low Compare 2 Interrupt Enable: disabled */
	| 0 << TCA_SPLIT_LUNF_bp; /* Low Underflow Interrupt Enable: disabled */
}

void TCA0_ClearHUNFInterruptFlag(void)
{
    TCA0.SPLIT.INTFLAGS &= ~TCA_SPLIT_HUNF_bm; /* High-Byte Underflow Interrupt: disabled */
}

bool TCA0_IsHUNFInterruptEnabled(void)
{
    return ((TCA0.SPLIT.INTFLAGS & TCA_SPLIT_HUNF_bm) > 0);
}

void TCA0_ClearLUNFInterruptFlag(void)
{
    TCA0.SPLIT.INTFLAGS &= ~TCA_SPLIT_LUNF_bm; /* Low-Byte Underflow Interrupt: disabled */
}

bool TCA0_IsLUNFInterruptEnabled(void)
{
    return ((TCA0.SPLIT.INTFLAGS & TCA_SPLIT_LUNF_bm) > 0);
}

void TCA0_ClearLCMP0InterruptFlag(void)
{
    TCA0.SPLIT.INTFLAGS &= ~TCA_SPLIT_LCMP0_bm; /* Low-Byte Compare Channel-0 Interrupt: disabled */
}

bool TCA0_IsLCMP0InterruptEnabled(void)
{
    return ((TCA0.SPLIT.INTFLAGS & TCA_SPLIT_LCMP0_bm) > 0);
}

void TCA0_ClearLCMP1InterruptFlag(void)
{
    TCA0.SPLIT.INTFLAGS &= ~TCA_SPLIT_LCMP1_bm; /* Low-Byte Compare Channel-1 Interrupt: disabled */
}

bool TCA0_IsLCMP1InterruptEnabled(void)
{
    return ((TCA0.SPLIT.INTFLAGS & TCA_SPLIT_LCMP1_bm) > 0);
}

void TCA0_ClearLCMP2InterruptFlag(void)
{
    TCA0.SPLIT.INTFLAGS &= ~TCA_SPLIT_LCMP2_bm; /* Low-Byte Compare Channel-2 Interrupt: disabled */
}

bool TCA0_IsLCMP2InterruptEnabled(void)
{
    return ((TCA0.SPLIT.INTFLAGS & TCA_SPLIT_LCMP2_bm) > 0);
}