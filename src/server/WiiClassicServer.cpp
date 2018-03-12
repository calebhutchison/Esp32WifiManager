/*
 * WiiClassicServer.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: hephaestus
 */

#include "WiiClassicServer.h"

void WiiClassicServerEvent::event(float * buffer) {
	//Serial.print("\r\nClassic read");
	//classic->readData();
	//classic->printInputs();

	int8_t * charBuff = (int8_t *)buffer;
	charBuff[0]=controllerIndex;
	charBuff[1]=classic->getJoyXLeft()<<2;
	charBuff[2]=classic->getJoyYLeft()<<2;
	charBuff[3]=classic->getJoyXRight()<<3;
	charBuff[4]=classic->getJoyYRight()<<3;
	charBuff[5]=classic->getTriggerLeft();
	charBuff[6]=classic->getTriggerRight();

	charBuff[7]=classic->getPadRight();
	charBuff[8]=classic->getPadDown();
	charBuff[9]=classic->getPadUp();
	charBuff[10]=classic->getPadLeft();
	charBuff[11]=classic->getButtonX();
	charBuff[12]=classic->getButtonY();
	charBuff[13]=classic->getButtonA();
	charBuff[14]=classic->getButtonB();

	charBuff[15]=classic->getButtonMinus();
	charBuff[16]=classic->getButtonHome();
	charBuff[17]=classic->getButtonPlus();

	charBuff[18]=classic->getButtonZLeft();
	charBuff[19]=classic->getButtonZRight();
	//Serial.print("...Done");
}
