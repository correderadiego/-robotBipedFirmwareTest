/*
 * RunnableController.h
 *
 *  Created on: 17 abr. 2020
 *      Author: Diego
 */

#ifndef MOCKLIBRARY_HARDWARE_CONTROLLER_RUNNABLECONTROLLER_H_
#define MOCKLIBRARY_HARDWARE_CONTROLLER_RUNNABLECONTROLLER_H_

class RunnableController {
#define DEFAULT_EXECUTION_DELAY 1000
public:
	RunnableController();
	RunnableController(int executionDelayMilliSeconds);
	bool executeTask();
private:
	unsigned long currentMillis   = 0;
	unsigned long previousMillis  = 0;
	int executionDelayMilliSeconds = DEFAULT_EXECUTION_DELAY;
protected:
	void setExecutionDelayMilliSeconds(int executionDelayMilliSeconds);
};

#endif /* MOCKLIBRARY_HARDWARE_CONTROLLER_RUNNABLECONTROLLER_H_ */
