/** ###################################################################
 **     Filename    : PORTD_Init.c
 **     Processor   : MK64FN1M0LQ12
 **     Abstract    :
 **          This file implements the PORTD module initialization
 **          according to the Peripheral Initialization settings, and
 **          defines interrupt service routines prototypes.
 **
 **     Contents    :
 **         Int   - void PORTD_Init(void);
 **
 **     Copyright : 1997 - 2014 Freescale Semiconductor, Inc.
 **     All Rights Reserved.
 **
 **     Redistribution and use in source and binary forms, with or without modification,
 **     are permitted provided that the following conditions are met:
 **
 **     o Redistributions of source code must retain the above copyright notice, this list
 **       of conditions and the following disclaimer.
 **
 **     o Redistributions in binary form must reproduce the above copyright notice, this
 **       list of conditions and the following disclaimer in the documentation and/or
 **       other materials provided with the distribution.
 **
 **     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 **       contributors may be used to endorse or promote products derived from this
 **       software without specific prior written permission.
 **
 **     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 **     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 **     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 **     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 **     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 **     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 **     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 **     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 **     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 **     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **
 **     http: www.freescale.com
 **     mail: support@freescale.com
 ** ###################################################################*/

/*!
 * @file PORTD_Init.c
 * @brief This file implements the PORTD module initialization according to the
 *        Peripheral Initialization settings, and defines interrupt service
 *        routines prototypes.
 */


/* MODULE PORTD_Init. */

#include "PORTD_Init.h"
#include "MK64F12.h"
#include "Init_Config.h"

#ifdef __cplusplus
extern "C" {
#endif

void PORTD_Init(void) {

  /* Register 'PORTD_PCR0' initialization */
  #if PORTD_PCR0_MASK_1
    #if PORTD_PCR0_MASK_1 == 0xFFFFFFFF
  PORTD_PCR0 = PORTD_PCR0_VALUE_1;
    #elif PORTD_PCR0_MASK_1 == PORTD_PCR0_VALUE_1
  PORTD_PCR0 |= PORTD_PCR0_VALUE_1;
    #elif PORTD_PCR0_VALUE_1 == 0
  PORTD_PCR0 &= ~PORTD_PCR0_MASK_1;
    #else
  PORTD_PCR0 = (PORTD_PCR0 & (~PORTD_PCR0_MASK_1)) | PORTD_PCR0_VALUE_1;
    #endif
  #elif defined(PORTD_PCR0_VALUE_1)
  PORTD_PCR0 = PORTD_PCR0_VALUE_1;
  #endif

  /* Register 'PORTD_PCR1' initialization */
  #if PORTD_PCR1_MASK_1
    #if PORTD_PCR1_MASK_1 == 0xFFFFFFFF
  PORTD_PCR1 = PORTD_PCR1_VALUE_1;
    #elif PORTD_PCR1_MASK_1 == PORTD_PCR1_VALUE_1
  PORTD_PCR1 |= PORTD_PCR1_VALUE_1;
    #elif PORTD_PCR1_VALUE_1 == 0
  PORTD_PCR1 &= ~PORTD_PCR1_MASK_1;
    #else
  PORTD_PCR1 = (PORTD_PCR1 & (~PORTD_PCR1_MASK_1)) | PORTD_PCR1_VALUE_1;
    #endif
  #elif defined(PORTD_PCR1_VALUE_1)
  PORTD_PCR1 = PORTD_PCR1_VALUE_1;
  #endif

  /* Register 'PORTD_PCR2' initialization */
  #if PORTD_PCR2_MASK_1
    #if PORTD_PCR2_MASK_1 == 0xFFFFFFFF
  PORTD_PCR2 = PORTD_PCR2_VALUE_1;
    #elif PORTD_PCR2_MASK_1 == PORTD_PCR2_VALUE_1
  PORTD_PCR2 |= PORTD_PCR2_VALUE_1;
    #elif PORTD_PCR2_VALUE_1 == 0
  PORTD_PCR2 &= ~PORTD_PCR2_MASK_1;
    #else
  PORTD_PCR2 = (PORTD_PCR2 & (~PORTD_PCR2_MASK_1)) | PORTD_PCR2_VALUE_1;
    #endif
  #elif defined(PORTD_PCR2_VALUE_1)
  PORTD_PCR2 = PORTD_PCR2_VALUE_1;
  #endif

  /* Register 'PORTD_PCR3' initialization */
  #if PORTD_PCR3_MASK_1
    #if PORTD_PCR3_MASK_1 == 0xFFFFFFFF
  PORTD_PCR3 = PORTD_PCR3_VALUE_1;
    #elif PORTD_PCR3_MASK_1 == PORTD_PCR3_VALUE_1
  PORTD_PCR3 |= PORTD_PCR3_VALUE_1;
    #elif PORTD_PCR3_VALUE_1 == 0
  PORTD_PCR3 &= ~PORTD_PCR3_MASK_1;
    #else
  PORTD_PCR3 = (PORTD_PCR3 & (~PORTD_PCR3_MASK_1)) | PORTD_PCR3_VALUE_1;
    #endif
  #elif defined(PORTD_PCR3_VALUE_1)
  PORTD_PCR3 = PORTD_PCR3_VALUE_1;
  #endif

  /* Register 'PORTD_PCR4' initialization */
  #if PORTD_PCR4_MASK_1
    #if PORTD_PCR4_MASK_1 == 0xFFFFFFFF
  PORTD_PCR4 = PORTD_PCR4_VALUE_1;
    #elif PORTD_PCR4_MASK_1 == PORTD_PCR4_VALUE_1
  PORTD_PCR4 |= PORTD_PCR4_VALUE_1;
    #elif PORTD_PCR4_VALUE_1 == 0
  PORTD_PCR4 &= ~PORTD_PCR4_MASK_1;
    #else
  PORTD_PCR4 = (PORTD_PCR4 & (~PORTD_PCR4_MASK_1)) | PORTD_PCR4_VALUE_1;
    #endif
  #elif defined(PORTD_PCR4_VALUE_1)
  PORTD_PCR4 = PORTD_PCR4_VALUE_1;
  #endif

  /* Register 'PORTD_PCR5' initialization */
  #if PORTD_PCR5_MASK_1
    #if PORTD_PCR5_MASK_1 == 0xFFFFFFFF
  PORTD_PCR5 = PORTD_PCR5_VALUE_1;
    #elif PORTD_PCR5_MASK_1 == PORTD_PCR5_VALUE_1
  PORTD_PCR5 |= PORTD_PCR5_VALUE_1;
    #elif PORTD_PCR5_VALUE_1 == 0
  PORTD_PCR5 &= ~PORTD_PCR5_MASK_1;
    #else
  PORTD_PCR5 = (PORTD_PCR5 & (~PORTD_PCR5_MASK_1)) | PORTD_PCR5_VALUE_1;
    #endif
  #elif defined(PORTD_PCR5_VALUE_1)
  PORTD_PCR5 = PORTD_PCR5_VALUE_1;
  #endif

  /* Register 'PORTD_PCR6' initialization */
  #if PORTD_PCR6_MASK_1
    #if PORTD_PCR6_MASK_1 == 0xFFFFFFFF
  PORTD_PCR6 = PORTD_PCR6_VALUE_1;
    #elif PORTD_PCR6_MASK_1 == PORTD_PCR6_VALUE_1
  PORTD_PCR6 |= PORTD_PCR6_VALUE_1;
    #elif PORTD_PCR6_VALUE_1 == 0
  PORTD_PCR6 &= ~PORTD_PCR6_MASK_1;
    #else
  PORTD_PCR6 = (PORTD_PCR6 & (~PORTD_PCR6_MASK_1)) | PORTD_PCR6_VALUE_1;
    #endif
  #elif defined(PORTD_PCR6_VALUE_1)
  PORTD_PCR6 = PORTD_PCR6_VALUE_1;
  #endif

  /* Register 'PORTD_PCR7' initialization */
  #if PORTD_PCR7_MASK_1
    #if PORTD_PCR7_MASK_1 == 0xFFFFFFFF
  PORTD_PCR7 = PORTD_PCR7_VALUE_1;
    #elif PORTD_PCR7_MASK_1 == PORTD_PCR7_VALUE_1
  PORTD_PCR7 |= PORTD_PCR7_VALUE_1;
    #elif PORTD_PCR7_VALUE_1 == 0
  PORTD_PCR7 &= ~PORTD_PCR7_MASK_1;
    #else
  PORTD_PCR7 = (PORTD_PCR7 & (~PORTD_PCR7_MASK_1)) | PORTD_PCR7_VALUE_1;
    #endif
  #elif defined(PORTD_PCR7_VALUE_1)
  PORTD_PCR7 = PORTD_PCR7_VALUE_1;
  #endif

  /* Register 'PORTD_PCR8' initialization */
  #if PORTD_PCR8_MASK_1
    #if PORTD_PCR8_MASK_1 == 0xFFFFFFFF
  PORTD_PCR8 = PORTD_PCR8_VALUE_1;
    #elif PORTD_PCR8_MASK_1 == PORTD_PCR8_VALUE_1
  PORTD_PCR8 |= PORTD_PCR8_VALUE_1;
    #elif PORTD_PCR8_VALUE_1 == 0
  PORTD_PCR8 &= ~PORTD_PCR8_MASK_1;
    #else
  PORTD_PCR8 = (PORTD_PCR8 & (~PORTD_PCR8_MASK_1)) | PORTD_PCR8_VALUE_1;
    #endif
  #elif defined(PORTD_PCR8_VALUE_1)
  PORTD_PCR8 = PORTD_PCR8_VALUE_1;
  #endif

  /* Register 'PORTD_PCR9' initialization */
  #if PORTD_PCR9_MASK_1
    #if PORTD_PCR9_MASK_1 == 0xFFFFFFFF
  PORTD_PCR9 = PORTD_PCR9_VALUE_1;
    #elif PORTD_PCR9_MASK_1 == PORTD_PCR9_VALUE_1
  PORTD_PCR9 |= PORTD_PCR9_VALUE_1;
    #elif PORTD_PCR9_VALUE_1 == 0
  PORTD_PCR9 &= ~PORTD_PCR9_MASK_1;
    #else
  PORTD_PCR9 = (PORTD_PCR9 & (~PORTD_PCR9_MASK_1)) | PORTD_PCR9_VALUE_1;
    #endif
  #elif defined(PORTD_PCR9_VALUE_1)
  PORTD_PCR9 = PORTD_PCR9_VALUE_1;
  #endif

  /* Register 'PORTD_PCR10' initialization */
  #if PORTD_PCR10_MASK_1
    #if PORTD_PCR10_MASK_1 == 0xFFFFFFFF
  PORTD_PCR10 = PORTD_PCR10_VALUE_1;
    #elif PORTD_PCR10_MASK_1 == PORTD_PCR10_VALUE_1
  PORTD_PCR10 |= PORTD_PCR10_VALUE_1;
    #elif PORTD_PCR10_VALUE_1 == 0
  PORTD_PCR10 &= ~PORTD_PCR10_MASK_1;
    #else
  PORTD_PCR10 = (PORTD_PCR10 & (~PORTD_PCR10_MASK_1)) | PORTD_PCR10_VALUE_1;
    #endif
  #elif defined(PORTD_PCR10_VALUE_1)
  PORTD_PCR10 = PORTD_PCR10_VALUE_1;
  #endif

  /* Register 'PORTD_PCR11' initialization */
  #if PORTD_PCR11_MASK_1
    #if PORTD_PCR11_MASK_1 == 0xFFFFFFFF
  PORTD_PCR11 = PORTD_PCR11_VALUE_1;
    #elif PORTD_PCR11_MASK_1 == PORTD_PCR11_VALUE_1
  PORTD_PCR11 |= PORTD_PCR11_VALUE_1;
    #elif PORTD_PCR11_VALUE_1 == 0
  PORTD_PCR11 &= ~PORTD_PCR11_MASK_1;
    #else
  PORTD_PCR11 = (PORTD_PCR11 & (~PORTD_PCR11_MASK_1)) | PORTD_PCR11_VALUE_1;
    #endif
  #elif defined(PORTD_PCR11_VALUE_1)
  PORTD_PCR11 = PORTD_PCR11_VALUE_1;
  #endif

  /* Register 'PORTD_PCR12' initialization */
  #if PORTD_PCR12_MASK_1
    #if PORTD_PCR12_MASK_1 == 0xFFFFFFFF
  PORTD_PCR12 = PORTD_PCR12_VALUE_1;
    #elif PORTD_PCR12_MASK_1 == PORTD_PCR12_VALUE_1
  PORTD_PCR12 |= PORTD_PCR12_VALUE_1;
    #elif PORTD_PCR12_VALUE_1 == 0
  PORTD_PCR12 &= ~PORTD_PCR12_MASK_1;
    #else
  PORTD_PCR12 = (PORTD_PCR12 & (~PORTD_PCR12_MASK_1)) | PORTD_PCR12_VALUE_1;
    #endif
  #elif defined(PORTD_PCR12_VALUE_1)
  PORTD_PCR12 = PORTD_PCR12_VALUE_1;
  #endif

  /* Register 'PORTD_PCR13' initialization */
  #if PORTD_PCR13_MASK_1
    #if PORTD_PCR13_MASK_1 == 0xFFFFFFFF
  PORTD_PCR13 = PORTD_PCR13_VALUE_1;
    #elif PORTD_PCR13_MASK_1 == PORTD_PCR13_VALUE_1
  PORTD_PCR13 |= PORTD_PCR13_VALUE_1;
    #elif PORTD_PCR13_VALUE_1 == 0
  PORTD_PCR13 &= ~PORTD_PCR13_MASK_1;
    #else
  PORTD_PCR13 = (PORTD_PCR13 & (~PORTD_PCR13_MASK_1)) | PORTD_PCR13_VALUE_1;
    #endif
  #elif defined(PORTD_PCR13_VALUE_1)
  PORTD_PCR13 = PORTD_PCR13_VALUE_1;
  #endif

  /* Register 'PORTD_PCR14' initialization */
  #if PORTD_PCR14_MASK_1
    #if PORTD_PCR14_MASK_1 == 0xFFFFFFFF
  PORTD_PCR14 = PORTD_PCR14_VALUE_1;
    #elif PORTD_PCR14_MASK_1 == PORTD_PCR14_VALUE_1
  PORTD_PCR14 |= PORTD_PCR14_VALUE_1;
    #elif PORTD_PCR14_VALUE_1 == 0
  PORTD_PCR14 &= ~PORTD_PCR14_MASK_1;
    #else
  PORTD_PCR14 = (PORTD_PCR14 & (~PORTD_PCR14_MASK_1)) | PORTD_PCR14_VALUE_1;
    #endif
  #elif defined(PORTD_PCR14_VALUE_1)
  PORTD_PCR14 = PORTD_PCR14_VALUE_1;
  #endif

  /* Register 'PORTD_PCR15' initialization */
  #if PORTD_PCR15_MASK_1
    #if PORTD_PCR15_MASK_1 == 0xFFFFFFFF
  PORTD_PCR15 = PORTD_PCR15_VALUE_1;
    #elif PORTD_PCR15_MASK_1 == PORTD_PCR15_VALUE_1
  PORTD_PCR15 |= PORTD_PCR15_VALUE_1;
    #elif PORTD_PCR15_VALUE_1 == 0
  PORTD_PCR15 &= ~PORTD_PCR15_MASK_1;
    #else
  PORTD_PCR15 = (PORTD_PCR15 & (~PORTD_PCR15_MASK_1)) | PORTD_PCR15_VALUE_1;
    #endif
  #elif defined(PORTD_PCR15_VALUE_1)
  PORTD_PCR15 = PORTD_PCR15_VALUE_1;
  #endif

  /* Register 'PORTD_DFWR' initialization */
  #ifdef PORTD_DFWR_VALUE
  PORTD_DFWR = PORTD_DFWR_VALUE;
  #endif

  /* Register 'PORTD_DFCR' initialization */
  #ifdef PORTD_DFCR_VALUE
  PORTD_DFCR = PORTD_DFCR_VALUE;
  #endif

  /* Register 'PORTD_DFER' initialization */
  #if PORTD_DFER_MASK
    #if PORTD_DFER_MASK == 0xFFFFFFFF
  PORTD_DFER = PORTD_DFER_VALUE;
    #elif PORTD_DFER_MASK == PORTD_DFER_VALUE
  PORTD_DFER |= PORTD_DFER_VALUE;
    #elif PORTD_DFER_VALUE == 0
  PORTD_DFER &= ~PORTD_DFER_MASK;
    #else
  PORTD_DFER = (PORTD_DFER & (~PORTD_DFER_MASK)) | PORTD_DFER_VALUE;
    #endif
  #elif defined(PORTD_DFER_VALUE)
  PORTD_DFER = PORTD_DFER_VALUE;
  #endif

  /* Register 'PORTD_PCR0' initialization */
  #if PORTD_PCR0_MASK_2
    #if PORTD_PCR0_MASK_2 == 0xFFFFFFFF
  PORTD_PCR0 = PORTD_PCR0_VALUE_2;
    #elif PORTD_PCR0_MASK_2 == PORTD_PCR0_VALUE_2
  PORTD_PCR0 |= PORTD_PCR0_VALUE_2;
    #elif PORTD_PCR0_VALUE_2 == 0
  PORTD_PCR0 &= ~PORTD_PCR0_MASK_2;
    #else
  PORTD_PCR0 = (PORTD_PCR0 & (~PORTD_PCR0_MASK_2)) | PORTD_PCR0_VALUE_2;
    #endif
  #elif defined(PORTD_PCR0_VALUE_2)
  PORTD_PCR0 = PORTD_PCR0_VALUE_2;
  #endif

  /* Register 'PORTD_PCR1' initialization */
  #if PORTD_PCR1_MASK_2
    #if PORTD_PCR1_MASK_2 == 0xFFFFFFFF
  PORTD_PCR1 = PORTD_PCR1_VALUE_2;
    #elif PORTD_PCR1_MASK_2 == PORTD_PCR1_VALUE_2
  PORTD_PCR1 |= PORTD_PCR1_VALUE_2;
    #elif PORTD_PCR1_VALUE_2 == 0
  PORTD_PCR1 &= ~PORTD_PCR1_MASK_2;
    #else
  PORTD_PCR1 = (PORTD_PCR1 & (~PORTD_PCR1_MASK_2)) | PORTD_PCR1_VALUE_2;
    #endif
  #elif defined(PORTD_PCR1_VALUE_2)
  PORTD_PCR1 = PORTD_PCR1_VALUE_2;
  #endif

  /* Register 'PORTD_PCR2' initialization */
  #if PORTD_PCR2_MASK_2
    #if PORTD_PCR2_MASK_2 == 0xFFFFFFFF
  PORTD_PCR2 = PORTD_PCR2_VALUE_2;
    #elif PORTD_PCR2_MASK_2 == PORTD_PCR2_VALUE_2
  PORTD_PCR2 |= PORTD_PCR2_VALUE_2;
    #elif PORTD_PCR2_VALUE_2 == 0
  PORTD_PCR2 &= ~PORTD_PCR2_MASK_2;
    #else
  PORTD_PCR2 = (PORTD_PCR2 & (~PORTD_PCR2_MASK_2)) | PORTD_PCR2_VALUE_2;
    #endif
  #elif defined(PORTD_PCR2_VALUE_2)
  PORTD_PCR2 = PORTD_PCR2_VALUE_2;
  #endif

  /* Register 'PORTD_PCR3' initialization */
  #if PORTD_PCR3_MASK_2
    #if PORTD_PCR3_MASK_2 == 0xFFFFFFFF
  PORTD_PCR3 = PORTD_PCR3_VALUE_2;
    #elif PORTD_PCR3_MASK_2 == PORTD_PCR3_VALUE_2
  PORTD_PCR3 |= PORTD_PCR3_VALUE_2;
    #elif PORTD_PCR3_VALUE_2 == 0
  PORTD_PCR3 &= ~PORTD_PCR3_MASK_2;
    #else
  PORTD_PCR3 = (PORTD_PCR3 & (~PORTD_PCR3_MASK_2)) | PORTD_PCR3_VALUE_2;
    #endif
  #elif defined(PORTD_PCR3_VALUE_2)
  PORTD_PCR3 = PORTD_PCR3_VALUE_2;
  #endif

  /* Register 'PORTD_PCR4' initialization */
  #if PORTD_PCR4_MASK_2
    #if PORTD_PCR4_MASK_2 == 0xFFFFFFFF
  PORTD_PCR4 = PORTD_PCR4_VALUE_2;
    #elif PORTD_PCR4_MASK_2 == PORTD_PCR4_VALUE_2
  PORTD_PCR4 |= PORTD_PCR4_VALUE_2;
    #elif PORTD_PCR4_VALUE_2 == 0
  PORTD_PCR4 &= ~PORTD_PCR4_MASK_2;
    #else
  PORTD_PCR4 = (PORTD_PCR4 & (~PORTD_PCR4_MASK_2)) | PORTD_PCR4_VALUE_2;
    #endif
  #elif defined(PORTD_PCR4_VALUE_2)
  PORTD_PCR4 = PORTD_PCR4_VALUE_2;
  #endif

  /* Register 'PORTD_PCR5' initialization */
  #if PORTD_PCR5_MASK_2
    #if PORTD_PCR5_MASK_2 == 0xFFFFFFFF
  PORTD_PCR5 = PORTD_PCR5_VALUE_2;
    #elif PORTD_PCR5_MASK_2 == PORTD_PCR5_VALUE_2
  PORTD_PCR5 |= PORTD_PCR5_VALUE_2;
    #elif PORTD_PCR5_VALUE_2 == 0
  PORTD_PCR5 &= ~PORTD_PCR5_MASK_2;
    #else
  PORTD_PCR5 = (PORTD_PCR5 & (~PORTD_PCR5_MASK_2)) | PORTD_PCR5_VALUE_2;
    #endif
  #elif defined(PORTD_PCR5_VALUE_2)
  PORTD_PCR5 = PORTD_PCR5_VALUE_2;
  #endif

  /* Register 'PORTD_PCR6' initialization */
  #if PORTD_PCR6_MASK_2
    #if PORTD_PCR6_MASK_2 == 0xFFFFFFFF
  PORTD_PCR6 = PORTD_PCR6_VALUE_2;
    #elif PORTD_PCR6_MASK_2 == PORTD_PCR6_VALUE_2
  PORTD_PCR6 |= PORTD_PCR6_VALUE_2;
    #elif PORTD_PCR6_VALUE_2 == 0
  PORTD_PCR6 &= ~PORTD_PCR6_MASK_2;
    #else
  PORTD_PCR6 = (PORTD_PCR6 & (~PORTD_PCR6_MASK_2)) | PORTD_PCR6_VALUE_2;
    #endif
  #elif defined(PORTD_PCR6_VALUE_2)
  PORTD_PCR6 = PORTD_PCR6_VALUE_2;
  #endif

  /* Register 'PORTD_PCR7' initialization */
  #if PORTD_PCR7_MASK_2
    #if PORTD_PCR7_MASK_2 == 0xFFFFFFFF
  PORTD_PCR7 = PORTD_PCR7_VALUE_2;
    #elif PORTD_PCR7_MASK_2 == PORTD_PCR7_VALUE_2
  PORTD_PCR7 |= PORTD_PCR7_VALUE_2;
    #elif PORTD_PCR7_VALUE_2 == 0
  PORTD_PCR7 &= ~PORTD_PCR7_MASK_2;
    #else
  PORTD_PCR7 = (PORTD_PCR7 & (~PORTD_PCR7_MASK_2)) | PORTD_PCR7_VALUE_2;
    #endif
  #elif defined(PORTD_PCR7_VALUE_2)
  PORTD_PCR7 = PORTD_PCR7_VALUE_2;
  #endif

  /* Register 'PORTD_PCR8' initialization */
  #if PORTD_PCR8_MASK_2
    #if PORTD_PCR8_MASK_2 == 0xFFFFFFFF
  PORTD_PCR8 = PORTD_PCR8_VALUE_2;
    #elif PORTD_PCR8_MASK_2 == PORTD_PCR8_VALUE_2
  PORTD_PCR8 |= PORTD_PCR8_VALUE_2;
    #elif PORTD_PCR8_VALUE_2 == 0
  PORTD_PCR8 &= ~PORTD_PCR8_MASK_2;
    #else
  PORTD_PCR8 = (PORTD_PCR8 & (~PORTD_PCR8_MASK_2)) | PORTD_PCR8_VALUE_2;
    #endif
  #elif defined(PORTD_PCR8_VALUE_2)
  PORTD_PCR8 = PORTD_PCR8_VALUE_2;
  #endif

  /* Register 'PORTD_PCR9' initialization */
  #if PORTD_PCR9_MASK_2
    #if PORTD_PCR9_MASK_2 == 0xFFFFFFFF
  PORTD_PCR9 = PORTD_PCR9_VALUE_2;
    #elif PORTD_PCR9_MASK_2 == PORTD_PCR9_VALUE_2
  PORTD_PCR9 |= PORTD_PCR9_VALUE_2;
    #elif PORTD_PCR9_VALUE_2 == 0
  PORTD_PCR9 &= ~PORTD_PCR9_MASK_2;
    #else
  PORTD_PCR9 = (PORTD_PCR9 & (~PORTD_PCR9_MASK_2)) | PORTD_PCR9_VALUE_2;
    #endif
  #elif defined(PORTD_PCR9_VALUE_2)
  PORTD_PCR9 = PORTD_PCR9_VALUE_2;
  #endif

  /* Register 'PORTD_PCR10' initialization */
  #if PORTD_PCR10_MASK_2
    #if PORTD_PCR10_MASK_2 == 0xFFFFFFFF
  PORTD_PCR10 = PORTD_PCR10_VALUE_2;
    #elif PORTD_PCR10_MASK_2 == PORTD_PCR10_VALUE_2
  PORTD_PCR10 |= PORTD_PCR10_VALUE_2;
    #elif PORTD_PCR10_VALUE_2 == 0
  PORTD_PCR10 &= ~PORTD_PCR10_MASK_2;
    #else
  PORTD_PCR10 = (PORTD_PCR10 & (~PORTD_PCR10_MASK_2)) | PORTD_PCR10_VALUE_2;
    #endif
  #elif defined(PORTD_PCR10_VALUE_2)
  PORTD_PCR10 = PORTD_PCR10_VALUE_2;
  #endif

  /* Register 'PORTD_PCR11' initialization */
  #if PORTD_PCR11_MASK_2
    #if PORTD_PCR11_MASK_2 == 0xFFFFFFFF
  PORTD_PCR11 = PORTD_PCR11_VALUE_2;
    #elif PORTD_PCR11_MASK_2 == PORTD_PCR11_VALUE_2
  PORTD_PCR11 |= PORTD_PCR11_VALUE_2;
    #elif PORTD_PCR11_VALUE_2 == 0
  PORTD_PCR11 &= ~PORTD_PCR11_MASK_2;
    #else
  PORTD_PCR11 = (PORTD_PCR11 & (~PORTD_PCR11_MASK_2)) | PORTD_PCR11_VALUE_2;
    #endif
  #elif defined(PORTD_PCR11_VALUE_2)
  PORTD_PCR11 = PORTD_PCR11_VALUE_2;
  #endif

  /* Register 'PORTD_PCR12' initialization */
  #if PORTD_PCR12_MASK_2
    #if PORTD_PCR12_MASK_2 == 0xFFFFFFFF
  PORTD_PCR12 = PORTD_PCR12_VALUE_2;
    #elif PORTD_PCR12_MASK_2 == PORTD_PCR12_VALUE_2
  PORTD_PCR12 |= PORTD_PCR12_VALUE_2;
    #elif PORTD_PCR12_VALUE_2 == 0
  PORTD_PCR12 &= ~PORTD_PCR12_MASK_2;
    #else
  PORTD_PCR12 = (PORTD_PCR12 & (~PORTD_PCR12_MASK_2)) | PORTD_PCR12_VALUE_2;
    #endif
  #elif defined(PORTD_PCR12_VALUE_2)
  PORTD_PCR12 = PORTD_PCR12_VALUE_2;
  #endif

  /* Register 'PORTD_PCR13' initialization */
  #if PORTD_PCR13_MASK_2
    #if PORTD_PCR13_MASK_2 == 0xFFFFFFFF
  PORTD_PCR13 = PORTD_PCR13_VALUE_2;
    #elif PORTD_PCR13_MASK_2 == PORTD_PCR13_VALUE_2
  PORTD_PCR13 |= PORTD_PCR13_VALUE_2;
    #elif PORTD_PCR13_VALUE_2 == 0
  PORTD_PCR13 &= ~PORTD_PCR13_MASK_2;
    #else
  PORTD_PCR13 = (PORTD_PCR13 & (~PORTD_PCR13_MASK_2)) | PORTD_PCR13_VALUE_2;
    #endif
  #elif defined(PORTD_PCR13_VALUE_2)
  PORTD_PCR13 = PORTD_PCR13_VALUE_2;
  #endif

  /* Register 'PORTD_PCR14' initialization */
  #if PORTD_PCR14_MASK_2
    #if PORTD_PCR14_MASK_2 == 0xFFFFFFFF
  PORTD_PCR14 = PORTD_PCR14_VALUE_2;
    #elif PORTD_PCR14_MASK_2 == PORTD_PCR14_VALUE_2
  PORTD_PCR14 |= PORTD_PCR14_VALUE_2;
    #elif PORTD_PCR14_VALUE_2 == 0
  PORTD_PCR14 &= ~PORTD_PCR14_MASK_2;
    #else
  PORTD_PCR14 = (PORTD_PCR14 & (~PORTD_PCR14_MASK_2)) | PORTD_PCR14_VALUE_2;
    #endif
  #elif defined(PORTD_PCR14_VALUE_2)
  PORTD_PCR14 = PORTD_PCR14_VALUE_2;
  #endif

  /* Register 'PORTD_PCR15' initialization */
  #if PORTD_PCR15_MASK_2
    #if PORTD_PCR15_MASK_2 == 0xFFFFFFFF
  PORTD_PCR15 = PORTD_PCR15_VALUE_2;
    #elif PORTD_PCR15_MASK_2 == PORTD_PCR15_VALUE_2
  PORTD_PCR15 |= PORTD_PCR15_VALUE_2;
    #elif PORTD_PCR15_VALUE_2 == 0
  PORTD_PCR15 &= ~PORTD_PCR15_MASK_2;
    #else
  PORTD_PCR15 = (PORTD_PCR15 & (~PORTD_PCR15_MASK_2)) | PORTD_PCR15_VALUE_2;
    #endif
  #elif defined(PORTD_PCR15_VALUE_2)
  PORTD_PCR15 = PORTD_PCR15_VALUE_2;
  #endif
}

#ifdef __cplusplus
}
#endif

/* END PORTD_Init. */

/** ###################################################################
 **
 **     This file is a part of Processor Expert static initialization
 **     library for Freescale microcontrollers.
 **
 ** ################################################################### */
