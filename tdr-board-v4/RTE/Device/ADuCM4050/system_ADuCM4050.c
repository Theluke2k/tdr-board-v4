/*!
 *****************************************************************************
 * @file:    system_ADuCM4050.c
 * @brief:   CMSIS Cortex-M4 Device Peripheral Access Layer Source File for
 *           ADuCM4050
 * @version  V3.10
 * @date     23. November 2012
 *-----------------------------------------------------------------------------
 *
 * @note     Modified January 11 2018 Analog Devices 

******************************************************************************/
/* Copyright (c) 2012 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.

   Portions Copyright (c) 2018 Analog Devices, Inc.
   ---------------------------------------------------------------------------*/

/*! \addtogroup SYS_Driver System Interfaces
 *  @{
 */

#include <stdint.h>
#include "system_ADuCM4050.h"
#include <adi_callback.h>
#include <adi_processor.h>
#include <rtos_map/adi_rtos_map.h>

#ifdef __ICCARM__
/*
* IAR MISRA C 2004 error suppressions.
*
* Pm073 (rule 14.7): a function should have a single point of exit.
* Pm143 (rule 14.7): a function should have a single point of exit at the end of the function.
*   Multiple returns are used for error handling.
*
* Pm140 (rule 11.3): a cast should not be performed between a pointer type and an integral type
*   The rule makes an exception for memory-mapped register accesses.
*/
#pragma diag_suppress=Pm073,Pm143,Pm140
#endif /* __ICCARM__ */

/*! \cond PRIVATE */

/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/

/* To enable the cache. Please note that linker description file need to
   have appropriate memory mapping.  */
/* #define ENABLE_CACHE */

#ifdef ADI_DEBUG
/*! Low frequency clock frequency, not needed unless its debug mode
    "lf_clk" coming out of LF mux */
uint32_t lfClock = 0u;
#endif

/*! "root_clk" output of HF mux */
uint32_t hfClock = 0u;

 /*! external GPIO clock */
uint32_t gpioClock = 0u;
extern void* __Vectors[];

/*----------------------------------------------------------------------------
  Security options
 *----------------------------------------------------------------------------*/

#if defined (__CC_ARM)
  __attribute__ ((at(0x00000180u)))
  __attribute__ ((weak))
#elif defined (__GNUC__)
  __attribute__ ((used,section(".security_options")))
  __attribute__ ((weak))
#elif defined (__ICCARM__)
  #pragma location=".security_options"
  __root
  __weak
#endif /* __ICCARM__ */
const ADI_ADUCM4X50_SECURITY_OPTIONS adi_aducm4x50_security_options
  = {
        { 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu },
        0xA79C3203u,
#if defined (__ICCARM__)
        0u,
#else
        253u,
#endif /* __ICCARM__ */
        0xFFFFFFFFu,
        0xFFFFFFFFu,
};

/*! \endcond  */


/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/

/*! System Clock Frequency (Core Clock) */
uint32_t SystemCoreClock = 0u;

/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/

/*!
 * @brief   Update the clock
 * @details Updates the variable SystemCoreClock and must be called whenever
           the core clock is changed during program execution.
 *
 * @return none
 *
 */
 void SystemCoreClockUpdate(void)
{
    uint32_t val, nDivisor, nMulfactor, div2, mul2;

#ifdef ADI_DEBUG
    /* "lfclock" is only used during debug checks... */
    /* LF clock is always 32k, whether osc or xtal */
    lfClock = __LFCLK;  /* for beep, wdt and lcd */
    if (lfClock == 0u)
    {
      while (1) {}
    }
#endif
    /* Update Core Clock sources */
    /* update the HF clock */
    switch (pADI_CLKG0_CLK->CTL0 & BITM_CLKG_CLK_CTL0_CLKMUX ) {

        case HFMUX_INTERNAL_OSC_VAL:
            hfClock = __HFOSC;
            break;

        case HFMUX_EXTERNAL_XTAL_VAL:
            hfClock = __HFXTAL;
            break;

        case HFMUX_SYSTEM_SPLL_VAL:
            /* Calculate System PLL output frequency */
            if ((pADI_CLKG0_CLK->CTL0 & BITM_CLKG_CLK_CTL0_PLL_IPSEL) != 0u) {
                /* PLL input from HFXTAL */
                val = __HFXTAL;
            } else {
                /* PLL input from HFOSC */
                val = __HFOSC;
            }

            /* PLL NSEL multiplier */
            nMulfactor = (pADI_CLKG0_CLK->CTL3 & BITM_CLKG_CLK_CTL3_SPLLNSEL) >> BITP_CLKG_CLK_CTL3_SPLLNSEL;
            /* PLL MSEL divider */
            nDivisor = (pADI_CLKG0_CLK->CTL3 & BITM_CLKG_CLK_CTL3_SPLLMSEL) >> BITP_CLKG_CLK_CTL3_SPLLMSEL;

            /* PLL NSEL multiplier */
            mul2 = (pADI_CLKG0_CLK->CTL3 & BITM_CLKG_CLK_CTL3_SPLLMUL2) >> BITP_CLKG_CLK_CTL3_SPLLMUL2;
            /* PLL MSEL divider */
            div2 = (pADI_CLKG0_CLK->CTL3 & BITM_CLKG_CLK_CTL3_SPLLDIV2) >> BITP_CLKG_CLK_CTL3_SPLLDIV2;

            val = ((val << mul2) * nMulfactor / nDivisor) >> div2;

            hfClock = val;
            break;

        case HFMUX_GPIO_VAL:
            hfClock = gpioClock;
            break;

        default:
            return;
    } /* end switch */

    SystemCoreClock = hfClock;
 }

#ifdef __ARMCC_VERSION
/* We want a warning if semi-hosting libraries are used. */
#pragma import(__use_no_semihosting_swi)
#endif

#ifdef RELOCATE_IVT
/**
  A relocated IVT is requested.  Provision for IVT relocation
  to SRAM during startup.  This allows for dynamic interrupt
  vector patching required by RTOS.  Places the relocated IVT
  at the start of SRAM.  Note: the IVT placement is required
  to be next power-of-two of the vector table size.  So the
  IVT includes 72 programmable interrupts, 15 system exception
  vectors and the main stack pointer, therefore we need
  (72 + 15 + 1)*4 = 352 bytes, which rounds up to a 512 (0x200)
  address boundary (which address 0x20000000 satisfies).
*/
  
#define ADI_NUM_EXCEPTIONS        16
#define LENGTHOF_IVT              (NVIC_INTS + ADI_NUM_EXCEPTIONS)
#define RELOCATION_ADDRESS        (0x20000000)

/* Relocatable vector table is only supported in IAR */
#if defined (__ICCARM__)
/* reserve no-init aligned IVT space at top of RAM */
SECTION_PLACE(KEEP_VAR(__no_init uint32_t  __relocated_vector_table[LENGTHOF_IVT]), RELOCATION_ADDRESS);
#else
#warning "Relocated Interupt Vector Tables are not supported in this toolchain"
#endif
#endif
/*!
 * @brief  Sets up the microcontroller system.
 *         Initializes the System and updates the relocate vector table.
 * @return none
 *
 * @note This function is called by the start-up code and does not need to be
 *       called directly by applications
 */
void SystemInit (void)
{
    uint32_t IntStatus;

#if defined(ADI_FLCC_ENABLE_BUS_ERR) && (ADI_FLCC_ENABLE_BUS_ERR != 0)
    /* Bus error on CRC error */
    *pREG_FLCC0_IEN |= ENUM_FLCC_IEN_BUS_ERR_ERR;
#endif

    /* On reset, there is no SRAM retention.  Any retention has to be explicitly
     * set here. */
    adi_system_EnableRetention(ADI_SRAM_BANK_1 | 
                               ADI_SRAM_BANK_3 |
                               ADI_SRAM_BANK_4 |
                               ADI_SRAM_BANK_5 |
                               ADI_SRAM_BANK_6 |     
                               ADI_SRAM_BANK_7 , true);
     

    
/* To enable the instruction cache.  */    
#ifdef  ENABLE_CACHE
    adi_system_EnableCache(true);
#endif

#if defined(ADI_SRAM_PARITY_ENABLE) && (ADI_SRAM_PARITY_ENABLE != 0)
    /* Enable SRAM parity */
    pADI_PMG0_TST->SRAM_CTL |= (BITM_PMG_TST_SRAM_CTL_PENBNK0 |
                                BITM_PMG_TST_SRAM_CTL_PENBNK1 |
                                BITM_PMG_TST_SRAM_CTL_PENBNK2 |
                                BITM_PMG_TST_SRAM_CTL_PENBNK3 |
                                BITM_PMG_TST_SRAM_CTL_PENBNK4 |
                                BITM_PMG_TST_SRAM_CTL_PENBNK5 |
                                BITM_PMG_TST_SRAM_CTL_PENBNK6 |
                                BITM_PMG_TST_SRAM_CTL_PENBNK7);
#endif

    /* Switch the Interrupt Vector Table Offset Register
     * (VTOR) to point to the relocated IVT in SRAM.
     */

    /* Because SystemInit must not use global variables, the following
     * interrupt disabling code should not be replaced with critical region
     * code which uses global variables.
     */
    IntStatus = __get_PRIMASK();
    __disable_irq();
#ifdef RELOCATE_IVT
    /* Copy the IVT (avoid use of memcpy here so it does not become locked into flash). */
    size_t i;
    for (i = 0u; i < LENGTHOF_IVT; i++)
    {
        __relocated_vector_table[i] = (uint32_t )__Vectors[i];
    }
    SCB->VTOR = (uint32_t) &__relocated_vector_table;
#else
   /* Set the vector table address  */
    SCB->VTOR = (uint32_t) &__Vectors;
#endif /* RELOCATE_IVT */
   
    /* Set all three (USGFAULTENA, BUSFAULTENA, and MEMFAULTENA) fault enable bits
     * in the System Control Block, System Handler Control and State Register
     * otherwise these faults are handled as hard faults.
     */
    SCB->SHCSR = SCB_SHCSR_USGFAULTENA_Msk |
                 SCB_SHCSR_BUSFAULTENA_Msk |
                 SCB_SHCSR_MEMFAULTENA_Msk ;

#ifdef DEBUG
    /* Trap divide by zero and generate a fault in debug builds. */
    SCB->CCR |= SCB_CCR_DIV_0_TRP_Msk;
#endif

#if (__FPU_PRESENT == 1u) && (__FPU_USED == 1u)
    /* the FPU is disabled by default so enable FPU (NEON and VFP)
     * set the System Control Block, Coprocessor Access Control Register bits:
     * CP10 = grant CP10 coprocessor privileges and user mode access (full access)
     * CP11 = grant CP11 coprocessor privileged and user mode access (full access)
     * (CP10 and CP11 MUST be the same or "BEHAVIOR IS UNPREDICTABLE")
     */
    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 for Full Access */
#endif

    /* Flush instruction and data pipelines to insure assertion of new settings. */
    __ISB();
    __DSB();

    __set_PRIMASK(IntStatus);

#ifdef ADI_MAX_IRQ_PRIORITY
    adi_system_SetGlobalIrqPriority();
#endif
}


/*!
 * @brief  Enables or disables the cache.
 * @param  bEnable Specify whether to enable/disable cache.
 *                 - true : Enable cache.
 *                 - false: Disable cache.
 * @return none
 */
void adi_system_EnableCache(bool bEnable)
{
    pADI_FLCC0_CACHE->KEY = CACHE_CONTROLLER_KEY;
    if( bEnable == true )
    {
        pADI_FLCC0_CACHE->SETUP |= BITM_FLCC_CACHE_SETUP_ICEN;
    }
    else
    {
        pADI_FLCC0_CACHE->SETUP &= ~BITM_FLCC_CACHE_SETUP_ICEN;
    }
}


/*!
 * @brief  This enables/disable SRAM retention during the hibernation.
 * @param eBank:   Specify which SRAM banks.  Multiple banks can be set
 /                 using a logical OR of the banks. 
 * @param bEnable Enable/disable the  retention for specified SRAM bank.
 *               -  true : Enable retention during hibernation.
 *               -  false: Disable retention during hibernation.
 * @return   ADI_SYS_SUCCESS Configured successfully.
 * @return   ADI_SYS_FAILURE Invalid bank, or banks, specified.  Any incorrect
 *                           or invalid bank options will result in failure and
 *                           no changes will have been applied.
 * @note The appropriate linker file needs to support the configuration. 
 *       BANK  0 is always retained.
 *       BANKS 1 can be retained individually.
 *       BANK  2 is never retained.
 *       BANKS 3 and 4 can only be mutually retained.
 *       BANKS 5 can be retained individually.
 *       BANKS 6 and 7 can only be mutually retained.
 */
ADI_SYS_RESULT adi_system_EnableRetention(ADI_SRAM_BANK eBank, bool bEnable)
{
    uint32_t retainBits = 0u;
    
#ifdef ADI_DEBUG
    if((0u != (eBank & ADI_SRAM_BANK_0)) || 
       (0u != (eBank & ADI_SRAM_BANK_2))) {
        /* Banks 0 and 2 are not selectable */
        return ADI_SYS_FAILURE;
    }
    
    /* Are banks 3 or 4 selected? */
    if(0u != (eBank & (ADI_SRAM_BANK_3 | ADI_SRAM_BANK_4))) {
       /* If so, the only valid option is for both to be retained. */
       if((eBank & (ADI_SRAM_BANK_3 | ADI_SRAM_BANK_4)) != (ADI_SRAM_BANK_3 | ADI_SRAM_BANK_4)) {
           return ADI_SYS_FAILURE;
       }
    }

    /* Are banks 6 or 7 selected? */
    if(0u != (eBank & (ADI_SRAM_BANK_6 | ADI_SRAM_BANK_7))) {
       /* If so, the only valid option is for both to be retained */
       if((eBank & (ADI_SRAM_BANK_6 | ADI_SRAM_BANK_7)) != (ADI_SRAM_BANK_6 | ADI_SRAM_BANK_7)) {
           return ADI_SYS_FAILURE;
       }
    }
#endif
    if((eBank & ADI_SRAM_BANK_1) != 0u) {
        retainBits |= BITM_PMG_SRAMRET_RET1;
    }
    if((eBank & (ADI_SRAM_BANK_3 | ADI_SRAM_BANK_4)) != 0u) {
        retainBits |= BITM_PMG_SRAMRET_RET2;
    }
    if((eBank & ADI_SRAM_BANK_5) != 0u) {
        retainBits |= BITM_PMG_SRAMRET_RET3;
    }
    if((eBank & (ADI_SRAM_BANK_6 | ADI_SRAM_BANK_7)) != 0u) {
        retainBits |= BITM_PMG_SRAMRET_RET4;
    }
       
    /* Unlock the SRAMRET register using the PWRKEY.
     * If there is any chance that this sequence can be interrupted then it
     * should be protected by disabling interrupts.   A write to any other 
     * register on the APB bus before writing to PMG_SRAMRET will return the 
     * protection to the lock state. */
    pADI_PMG0->PWRKEY = PWRKEY_VALUE_KEY;
    if(bEnable) {
        pADI_PMG0->SRAMRET |= retainBits;
    }
    else {
        pADI_PMG0->SRAMRET &= ~(retainBits);
    }

    return ADI_SYS_SUCCESS;
}


/*!
 * @brief  This function sets the priority for all IRQ interrupts to the value 
 *         defined by ADI_MAX_IRQ_PRIORITY (if defined).
 *
 * @details  At reset the hardware default priority 0, which is the highest. For 
 *         any applications that use BASEPRI to mask interrupts, such as any
 *         application using FreeRTOS, then any interrupts using default priority
 *         will never be masked.  Defining ADI_MAX_IRQ_PRIORITY to a value
 *         will enable this function call at startup and set all IRQ interrupts
 *         to that priority value. 
 * @return none
 *
 */
void adi_system_SetGlobalIrqPriority(void)
{
#ifdef ADI_MAX_IRQ_PRIORITY
  uint32_t prio = (uint32_t)ADI_MAX_IRQ_PRIORITY;
#else
  uint32_t prio = (uint32_t)0u;
#endif
   
  /* NVIC supports up to 240 interrupt sources, but this part does not
   * use the full range. */ 
  for(uint8_t irq = 0u; irq < NVIC_INTS; irq++) {
      NVIC_SetPriority((IRQn_Type)irq, prio);
  }
}

/*@}*/
