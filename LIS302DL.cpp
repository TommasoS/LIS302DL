/*
  DS1621.cpp - Arduino library for Maxim DS1621 Digital Thermometer
  this library is free software: you can redistribute it and/or modify
  it. 
  THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION WITHOUT ANY WARRANTIES
  
  Thermostat functions not yet implemented
 
  
*/

#include "LIS302DL.h"
#include <Wire.h>


LIS302DL::LIS302DL(short addr,long speed){
	TWBR=speed;
	Wire.begin();
	_addr=addr;
}
LIS302DL::LIS302DL(short addr){
	Wire.begin();
	_addr=addr;
}

uint8_t LIS302DL::readRegister(uint8_t reg){
  uint8_t r;
  Wire.beginTransmission(_addr);
  Wire.write(reg);  // register to read
  Wire.endTransmission();
  Wire.requestFrom(_addr,1); // read a byte
  r = Wire.read();
  return r;
}
void LIS302DL::writeRegister(uint8_t reg,uint8_t val)
{
  Wire.beginTransmission(_addr);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
  delay(10);
}
float LIS302DL::readX(){
  float x;
  char _x;
  _x=readRegister(_X);
  x=_x*0.018;
  return(x);
}
float LIS302DL::readY(){

  float y;
  char _y;
  _y=readRegister(_Y);
  y=_y*0.018;
  return(y);

}
float LIS302DL::readZ(){
  float z;
  char _z;
  _z=readRegister(_Z);
  z=_z*0.018;
  return(z);
}
void LIS302DL::xOn(){
	_ctrl_reg1_buff|=_X_ON;
	writeRegister(_CTRL_REG1,_ctrl_reg1_buff);
}
void LIS302DL::xOff(){
	_ctrl_reg1_buff &=_X_OFF;
	writeRegister(_CTRL_REG1,_ctrl_reg1_buff);
}
void LIS302DL::yOn(){
	_ctrl_reg1_buff|=_Y_ON;
	writeRegister(_CTRL_REG1,_ctrl_reg1_buff);
}
void LIS302DL::yOff(){
	_ctrl_reg1_buff &=_Y_OFF;
	writeRegister(_CTRL_REG1,_ctrl_reg1_buff);
}
void LIS302DL::zOn(){
	_ctrl_reg1_buff|=_Z_ON;
	writeRegister(_CTRL_REG1,_ctrl_reg1_buff);
}
void LIS302DL::zOff(){
	_ctrl_reg1_buff &=_Z_OFF;
	writeRegister(_CTRL_REG1,_ctrl_reg1_buff);
}
void LIS302DL::highSpeed(){
	_ctrl_reg1_buff|=_HIGH_SPEED;
	writeRegister(_CTRL_REG1,_ctrl_reg1_buff);
}
void LIS302DL::lowSpeed(){
	_ctrl_reg1_buff &=_LOW_SPEED;
	writeRegister(_CTRL_REG1,_ctrl_reg1_buff);
}
void LIS302DL::fullRange(){
	_ctrl_reg1_buff|=_FULL_RANGE;
	writeRegister(_CTRL_REG1,_ctrl_reg1_buff);
}
void LIS302DL::highSens(){
	_ctrl_reg1_buff &=_HIGH_SENS;
	writeRegister(_CTRL_REG1,_ctrl_reg1_buff);
}
void LIS302DL::turnOn(){
	_ctrl_reg1_buff|=_ON;
	writeRegister(_CTRL_REG1,_ctrl_reg1_buff);
}
void LIS302DL::turnOff(){
	_ctrl_reg1_buff &=_OFF;
	writeRegister(_CTRL_REG1,_ctrl_reg1_buff);
}