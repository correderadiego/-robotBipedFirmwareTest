/*
 * RunnableController.cpp
 *
 *  Created on: 17 abr. 2020
 *      Author: Diego
 */

#include <hardware/controller/RunnableController.h>

RunnableController::RunnableController() {
	// TODO Auto-generated constructor stub
}

bool RunnableController::executeTask(){
	return true;
}

void RunnableController::setExecutionDelayMilliSeconds(int executionDelayMilliSeconds){
	this->executionDelayMilliSeconds = executionDelayMilliSeconds;
}
