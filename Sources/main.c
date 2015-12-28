/* ###################################################################
**     Filename    : main.c
**     Project     : Coroutine
**     Processor   : MK64FN1M0VLQ12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-12-26, 22:54, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
#include "FRTOS1.h"
#include "croutine.h"
#include "UTIL1.h"
#include "SlowSchedulerTimer.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "ThreadReaderTimer.h"
#include "TimerIntLdd2.h"
#include "TU2.h"
#include "croutine.h"
#include "portmacro.h"
#include "FreeRTOS.h"

extern QueueHandle_t schedulerQueue;
extern QueueHandle_t messageQueue;

/* User includes (#include below this line is not maintained by Processor Expert) */
static void messageQueueSenderRoutine(CoRoutineHandle_t xHandle,
		unsigned portBASE_TYPE uxIndex) {

	// Variables in co-routines must be declared static if they must maintain value across a blocking call.
	static portBASE_TYPE xNumberToPost = 0;
	static portBASE_TYPE xResult;

	// Co-routines must begin with a call to crSTART().
	crSTART( xHandle );

	for (;;) {
		// This assumes the queue has already been created.
		crQUEUE_SEND(xHandle, messageQueue, &xNumberToPost, (TickType_t ) 0U,
				&xResult);

		if (xResult != pdPASS) {
			// The message was not posted!
		}

		// Increment the number to be posted onto the queue.
		xNumberToPost++;

		// Delay for 100 ticks.
		crDELAY(xHandle, 100);
	}

	// Co-routines must end with a call to crEND().
	crEND();
}

static void messageQueueReceiveRoutine(CoRoutineHandle_t xHandle,
	unsigned portBASE_TYPE uxIndex) {
// Variables in co-routines must be declared static if they must maintain value across a blocking call.
	static portBASE_TYPE xResult;
	static unsigned portBASE_TYPE uxLEDToFlash;

// All co-routines must start with a call to crSTART().
	crSTART( xHandle )
	;

	for (;;) {
	// Wait for data to become available on the queue.
		crQUEUE_RECEIVE(xHandle, messageQueue, &uxLEDToFlash, portMAX_DELAY,
			&xResult);

		if (xResult == pdPASS) {
		// We received the LED to flash - flash it!
		// vParTestToggleLED( uxLEDToFlash );
		}
	}

	crEND();
}

// A co-routine that blocks on a queue waiting for characters to be received.
static void schedulerQueueReceiveRoutine(CoRoutineHandle_t xHandle,
		unsigned portBASE_TYPE uxIndex) {
	static char cRxedChar;
	static portBASE_TYPE xResult;
	static unsigned portBASE_TYPE uxLEDToFlash;

	crSTART( xHandle );

	for (;;) {
		crQUEUE_RECEIVE(xHandle, schedulerQueue, &uxLEDToFlash, portMAX_DELAY, &xResult);

		// Was a character received?
		if (xResult == pdPASS) {
			// Process the character here.
		}
	}

	crEND();
}

static void schedulerQueueSendRoutine( xCoRoutineHandle xHandle, unsigned portBASE_TYPE uxIndex) {
    // cChar holds its value while this co-routine is blocked and must therefore
	// be declared static.
	static char cCharToTx = 'a';
	static portBASE_TYPE xResult;

	crSTART( xHandle );

	for (;;) {
	// Send the next character to the queue.
		crQUEUE_SEND(xHandle, schedulerQueue, &cCharToTx, (TickType_t ) 0U, &xResult);

		if (xResult == pdPASS) {
		// The character was successfully posted to the queue.
		} else {
		// Could not post the character to the queue.
		}

		// ENABLE_RX_INTERRUPT();

		cCharToTx++;
		if (cCharToTx > 'x') {
			cCharToTx = 'a';
		}

		crDELAY(xHandle, (TickType_t ) 100);
	}

         // All co-routines must end with a call to crEND().
	crEND();
}

static void emptyRunnerRoutine(CoRoutineHandle_t xHandle, unsigned portBASE_TYPE uxIndex) {
 // Variables in co-routines must be declared static if they must maintain value across a blocking call.
 // This may not be necessary for const variables.
 // We are to delay for 200ms.
	static const TickType_t xDelayTime = 200 / portTICK_RATE_MS;

	crSTART( xHandle );

	for (;;) {
	 // Delay for 200ms.
		crDELAY(xHandle, xDelayTime);

	 // Do something here.
	}

	// Must end every co-routine with a call to crEND();
	crEND();
}

static void anotherEmptyRunnerRoutine(CoRoutineHandle_t xHandle, unsigned portBASE_TYPE uxIndex) {

 // Variables in co-routines must be declared static if they must maintain value across a blocking call.
	static long ulAVariable;

 // Must start every co-routine with a call to crSTART();
	crSTART( xHandle );

	for (;;) {
		// Co-routine functionality goes here.
	}

	// Must end every co-routine with a call to crEND();
	crEND();
}

static void andAnotherEmptyRunnerRoutine(CoRoutineHandle_t xHandle, UBaseType_t uxIndex) {

	static const char cLedToFlash[2] = { 5, 6 };
	static const TickType_t uxFlashRates[2] = { 200, 400 };

	crSTART( xHandle );

	for (;;) {

	//   vParTestToggleLED( cLedToFlash[ uxIndex ] );
		crDELAY(xHandle, uxFlashRates[uxIndex]);
	}

	crEND();
}

// Think this gets called on
/// FRTOS1_vApplicationIdleHook();
void FRTOS1_vApplicationIdleHook( void )
 {
	FRTOS1_vCoRoutineSchedule( void );
 }

void FRTOS1_vApplicationStackOverflowHook() {

}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  /* Write your code here */


  // In this case the index is not used and is passed
  // in as 0.
  FRTOS1_xCoRoutineCreate( messageQueueSenderRoutine, 0, 0 );
  FRTOS1_xCoRoutineCreate( messageQueueReceiveRoutine, 0, 1);
  FRTOS1_xCoRoutineCreate( schedulerQueueReceiveRoutine, 0, 2);
  FRTOS1_xCoRoutineCreate( schedulerQueueSendRoutine, 0, 3 );
  FRTOS1_xCoRoutineCreate( emptyRunnerRoutine, 0, 4 );
  FRTOS1_xCoRoutineCreate( anotherEmptyRunnerRoutine, 0, 6);
  FRTOS1_xCoRoutineCreate( andAnotherEmptyRunnerRoutine, 0, 7);


  FRTOS1_vTaskStartScheduler();




  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
