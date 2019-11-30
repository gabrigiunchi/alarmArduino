#ifndef __EVENTS_CODE__
#define __EVENTS_CODE__

/*************** EVENTI INTERNI **********************/

#define BUTTON_PRESSED_EVENT  1
#define SERIAL_EVENT          2  // Messaggio ricevuto sulla seriale
#define TIMER_EVENT           3 
#define PIR_DETECTION_EVENT   4


/**************** EVENTI ESTERNI ******************/

#define TURN_SYSTEM_ON  32   // Comando di attivazione del sistema
#define TURN_SYSTEM_OFF 33   // Comando di disattivazione del sistema
#define TURN_ALARM_OFF  34   // Comando di disattivazione dell'allarme
#define STATE_REQUEST   35   // Richiesta dello stato attuale del sistema
#define STATE_RESPONSE  36   // Risposta contenente lo stato del sistema
#define ID_REQUEST      37   // Richiesta dell'id attuale del sistema
#define ID_RESPONSE     38   // Risposta contenente l'id del sistema

/***************** STATI DEL SISTEMA ********************/
#define CALIBRATING_STATE   48
#define STATE_ON            49
#define STATE_OFF           50
#define ALARM_STATE         51

#endif
