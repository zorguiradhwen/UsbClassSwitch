/*
 * UsbClassSwitch.h
 *
 *  Created on: 1 avr. 2021
 *      Author: radhwen.zorgui
 */

#ifndef USBCLASSSWITCH_H_
#define USBCLASSSWITCH_H_

#include "main.h"

#include "stdbool.h"

typedef enum SupportedClasses_e
{
	USB_MSC_CLASS,
	USB_HID_CLASS
}UsbClassSwitch_Class;

typedef struct UsbClassSwitch_Handler_s
{
	uint16_t PID;
	char CONFIGURATION_STRING[20];
	char INTERFACE_STRING[20];
	UsbClassSwitch_Class class;
}UsbClassSwitch_Handler;

extern UsbClassSwitch_Handler UsbClassSwitch_handler;

_Bool UsbClassSwitch_setClass(UsbClassSwitch_Class class);

_Bool UsbClassSwitch_updateClass();

#endif /* USBCLASSSWITCH_H_ */
