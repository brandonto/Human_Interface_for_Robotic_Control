//*****************************************************************************
//
// servo_driver_if.c
//
// High-Level servo driver for CC3200-LAUNCHXL
//
// Project: Human Interface for Robotic Control
//
// Created:
// December 20, 2015
//
// Modified:
// December 20, 2015
//
//*****************************************************************************

// Driverlib includes
#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_apps_rcm.h"
#include "hw_common_reg.h"
#include "interrupt.h"
#include "rom.h"
#include "rom_map.h"
#include "timer.h"
#include "utils.h"
#include "prcm.h"
#include "uart.h"

#include "servo_driver_if.h"

// Low-level Servo driver include
#include "servo_driver.h"

//****************************************************************************
//
// Initializes the Servo motors for operation
//
// \param none
//
// \return None.
//
//****************************************************************************
void InitServos()
{
    InitPWMModules();
}

//****************************************************************************
//
// Disables the Servo motors
//
// \param none
//
// \return None.
//
//****************************************************************************
void DisableServos()
{
    DeInitPWMModules();
}

//****************************************************************************
//
// Moves the servo motor by degrees on the finger specified
//
// \param usDegrees -> 0 to 180
// \param eFinger -> finger (ex: finger_thumb, finger_index, etc)
//
// \return None.
//
//****************************************************************************
void MoveServo(unsigned short usDegrees, enum enum_Finger_Type eFinger)
{
    unsigned short usMatchVal;
    unsigned char usPrescaleVal;

    Convert_Degrees_To_Match(usDegrees, &usMatchVal, &usPrescaleVal);

    switch(eFinger) {
        case finger_thumb:
            UpdatePWM_Match(TIMERA3_BASE, TIMER_A, usMatchVal, usPrescaleVal);
            break;
        case finger_index:
            UpdatePWM_Match(TIMERA2_BASE, TIMER_B, usMatchVal, usPrescaleVal);
            break;
        case finger_middle:
            UpdatePWM_Match(TIMERA3_BASE, TIMER_B, usMatchVal, usPrescaleVal);
            break;
        case finger_ring:
            // TODO map to appropriate pin
            break;
        case finger_pinky:
            // TODo map to appropriate pin
            break;
        default:
            UART_PRINT("[MoveServo] Invalid Finger input\n");
    }
}
