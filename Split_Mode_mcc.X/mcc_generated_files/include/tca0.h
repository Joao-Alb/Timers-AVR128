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


#ifndef TCA0_H_INCLUDED
#define TCA0_H_INCLUDED

#include "../utils/compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Initialize tca interface
 *
 * \return Initialization status.
 */
    

typedef void (*TCA0_cb_t)(void);    

int8_t TCA0_Initialize();
void TCA0_SetTimer1IsrCallback(TCA0_cb_t cb);
void TCA0_SetLCMP0IsrCallback(TCA0_cb_t cb);
void TCA0_SetLCMP1IsrCallback(TCA0_cb_t cb);
void TCA0_SetLCMP2IsrCallback(TCA0_cb_t cb);
void TCA0_SetTimer2IsrCallback(TCA0_cb_t cb);
void TCA0_EnableInterrupt(void);
void TCA0_DisableInterrupt(void);
uint8_t TCA0_ReadTimer1(void);
void TCA0_WriteTimer1(uint8_t timerVal);
uint8_t TCA0_ReadTimer2(void);
void TCA0_WriteTimer2(uint8_t timerVal);
void TCA0_ClearHUNFInterruptFlag(void);
bool TCA0_IsHUNFInterruptEnabled(void);
void TCA0_ClearLUNFInterruptFlag(void);
bool TCA0_IsLUNFInterruptEnabled(void);
void TCA0_ClearLCMP0InterruptFlag(void);
bool TCA0_IsLCMP0InterruptEnabled(void);
void TCA0_ClearLCMP1InterruptFlag(void);
bool TCA0_IsLCMP1InterruptEnabled(void);
void TCA0_ClearLCMP2InterruptFlag(void);
bool TCA0_IsLCMP2InterruptEnabled(void);
#ifdef __cplusplus
}
#endif

#endif /* TCA0_H_INCLUDED */