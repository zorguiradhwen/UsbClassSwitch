/*
 * UsbClassSwitch.c
 *
 *  Created on: 1 avr. 2021
 *      Author: radhwen.zorgui
 */

#ifndef USBCLASSSWITCH_C_
#define USBCLASSSWITCH_C_


#include "UsbClassSwitch.h"
#include "usb_device.h"

UsbClassSwitch_Handler UsbClassSwitch_handler = {
		.CONFIGURATION_STRING = "STMDUCKY Config" ,
		.INTERFACE_STRING = "STMDUCKY Interface",
		.PID = 22352,
		.class = USB_HID_CLASS
};

extern USBD_HandleTypeDef hUsbDeviceFS;



_Bool UsbClassSwitch_updateClass()
{
	USBD_DeInit(&hUsbDeviceFS);
	HAL_Delay(500);
	MX_USB_DEVICE_Init();
	HAL_Delay(500);

	return 1u;

}


_Bool UsbClassSwitch_setClass(UsbClassSwitch_Class class)
{
	UsbClassSwitch_handler.class = class;
	UsbClassSwitch_updateClass();
	return 1u;

}




#endif /* USBCLASSSWITCH_C_ */
