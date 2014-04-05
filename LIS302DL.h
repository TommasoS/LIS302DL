/*
  LIS302DL.h - Arduino library for Maxim DS1621 Digital Thermometer
  this library is free software: you can redistribute it and/or modify
  it. 
  THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION WITHOUT ANY WARRANTIES
  
  Thermostat functions not yet implemented
  
*/



#ifndef LIS302DL_H
#define LIS302DL_H
#include "Arduino.h"

class LIS302DL{
	static const uint8_t _X = 0x29;
	static const uint8_t _Y = 0x2b;
	static const uint8_t _Z = 0x2d;
	static const uint8_t _CTRL_REG1=0x20;
	
	static const uint8_t _ON = 0x40;
	static const uint8_t _X_ON = 0x01;
	static const uint8_t _Y_ON = 0x02;
	static const uint8_t _Z_ON = 0x04;
	static const uint8_t _HIGH_SPEED= 0x80;
	static const uint8_t _FULL_RANGE= 0x20;//

	static const uint8_t _OFF = 0xBF;
	static const uint8_t _X_OFF = 0xFE;
	static const uint8_t _Y_OFF = 0xFD;
	static const uint8_t _Z_OFF = 0xFB;
	static const uint8_t _LOW_SPEED= 0x7F;
	static const uint8_t _HIGH_SENS= 0xDF;

	uint8_t _ctrl_reg1_buff;

	void writeRegister(uint8_t reg,uint8_t val);
	uint8_t readRegister(uint8_t reg);
	short _addr;
	
public:
	LIS302DL(short addr,long speed);//Object constructor (i2c slave address,i2c speed) 40000=400Khz
	LIS302DL(short addr);
	void zOn();//turn on z axes
	void zOff();//turn off z axes
	void yOn();//turn on y axes
	void yOff();//turn off y axes
	void xOn();//turn on x axes
	void xOff();//turn off x axes
	
	void turnOn();
	void turnOff();
	
	float readX();//read x axes
	float readY();//read y axes
	float readZ();//read z axes
	
	void highSpeed();//output data rate 400hz
	void lowSpeed();//output data rate 100hz
	void fullRange();//±9.2g range sensitivity 72 mg/digit
	void highSens();//±2.3g range sensitivity 18 mg/digit

};
#endif