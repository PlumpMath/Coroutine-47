/* ###################################################################
**     Filename    : Events.c
**     Project     : Coroutine
**     Processor   : MK64FN1M0VLQ12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-12-26, 22:54, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMI - void Cpu_OnNMI(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "Init_Config.h"
#include "PDD_Includes.h"
#include "FRTOS1.h"
#include "croutine.h"
#include "portmacro.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "FreeRTOSConfig.h"

QueueHandle_t readerQueue;
QueueHandle_t schedulerQueue;


#ifdef __cplusplus
extern "C" {
#endif 



/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Cpu_OnNMI (module Events)
**
**     Component   :  Cpu [MK64FN1M0LQ12]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMI(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationStackOverflowHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         if enabled, this hook will be called in case of a stack
**         overflow.
**     Parameters  :
**         NAME            - DESCRIPTION
**         pxTask          - Task handle
**       * pcTaskName      - Pointer to task name
**     Returns     : Nothing
** ===================================================================
*/
void FRTOS1_vApplicationStackOverflowHook(xTaskHandle pxTask, char *pcTaskName)
{
  /* This will get called if a stack overflow is detected during the context
     switch.  Set configCHECK_FOR_STACK_OVERFLOWS to 2 to also check for stack
     problems within nested interrupts, but only do this for debug purposes as
     it will increase the context switch time. */
  (void)pxTask;
  (void)pcTaskName;
  taskDISABLE_INTERRUPTS();
  /* Write your code here ... */
  for(;;) {}
}

/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationTickHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, this hook will be called by the RTOS for every
**         tick increment.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void FRTOS1_vApplicationTickHook(void)
{
  /* Called for every RTOS tick. */
	vCoRoutineSchedule();
}

/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationIdleHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, this hook will be called when the RTOS is idle.
**         This might be a good place to go into low power mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void FRTOS1_vApplicationIdleHook(void)
{
  /* Called whenever the RTOS is idle (from the IDLE task).
     Here would be a good place to put the CPU into low power mode. */
  /* Write your code here ... */
	// FRTOS1_
	// FRTOS1_vCoRoutineSchedule(void);
}

/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationMallocFailedHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, the RTOS will call this hook in case memory
**         allocation failed.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void FRTOS1_vApplicationMallocFailedHook(void)
{
  /* Called if a call to pvPortMalloc() fails because there is insufficient
     free memory available in the FreeRTOS heap.  pvPortMalloc() is called
     internally by FreeRTOS API functions that create tasks, queues, software
     timers, and semaphores.  The size of the FreeRTOS heap is set by the
     configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h. */
  taskDISABLE_INTERRUPTS();
  /* Write your code here ... */
  for(;;) {}
}

/*
** ===================================================================
**     Event       :  SlowSchedulerTimer_OnInterrupt (module Events)
**
**     Component   :  SlowSchedulerTimer [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void SlowSchedulerTimer_OnInterrupt(void)
{
  /* Write your code here ... */
	 char cRxedChar;
	 portBASE_TYPE xCRWokenByPost = pdFALSE;

	// crQUEUE_SEND_FROM_ISR
	 crQUEUE_SEND_FROM_ISR( schedulerQueue, &cRxedChar, xCRWokenByPost );

 //crQUEUE_SEND_FROM_ISR( schedulerQueue, 0, 0 );
	// xQueueCRSendFromISR( schedulerQueue, 0, 0 );

	     // We loop around reading characters until there are none left in the UART.
	 //    while( UART_RX_REG_NOT_EMPTY() )
	 //    {
	         // Obtain the character from the UART.
	//         cRxedChar = UART_RX_REG;

	         // Post the character onto a queue.  xCRWokenByPost will be pdFALSE
	         // the first time around the loop.  If the post causes a co-routine
	         // to be woken (unblocked) then xCRWokenByPost will be set to pdTRUE.
	         // In this manner we can ensure that if more than one co-routine is
	         // blocked on the queue only one is woken by this ISR no matter how
	         // many characters are posted to the queue.

	   //  }
}

/*
** ===================================================================
**     Event       :  ThreadReaderTimer_OnInterrupt (module Events)
**
**     Component   :  ThreadReaderTimer [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ThreadReaderTimer_OnInterrupt(void) {
	char cCharToTx;
	portBASE_TYPE xCRWokenByPost = pdFALSE;

	//while (1) {
		// Are there any characters in the queue waiting to be sent?
		// xCRWokenByPost will automatically be set to pdTRUE if a co-routine
		// is woken by the post - ensuring that only a single co-routine is
		// woken no matter how many times we go around this loop.
	//	if (crQUEUE_RECEIVE_FROM_ISR(readerQueue, &cCharToTx, &xCRWokenByPost)) {
		// SEND_CHARACTER(cCharToTx);
	//	}
	//}

}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
