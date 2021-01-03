/*
 * SerialCommunication.cpp
 *
 *  Created on: 26 mar. 2020
 *      Author: Diego
 */

#include <hardware/bean/SerialCommunication.h>

SerialCommunication* SerialCommunication::serialCommunication = nullptr;

SerialCommunication::SerialCommunication() {}

SerialCommunication* SerialCommunication::getInstance(){
	if(serialCommunication == nullptr){
		serialCommunication = new SerialCommunication();
	}
	return serialCommunication;
}

void SerialCommunication::println(const char * string){}

void SerialCommunication::print(const char * string){}

void SerialCommunication::print(int message){}

void SerialCommunication::println(int number){}

bool SerialCommunication::available(){
	return false;
}

char SerialCommunication::read(){
	return '/0';
}

void SerialCommunication::flush(){}

SerialCommunication::~SerialCommunication() {}

