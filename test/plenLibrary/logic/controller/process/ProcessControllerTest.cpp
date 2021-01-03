/*
 * ProcessControllerTest.cpp
 *
 *  Created on: 25 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERTEST_CPP_

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <logic/bean/commands/CommandInterface.h>
#include <logic/bean/commands/controllerCommands/ApplyHomePositionCommand.h>
#include <logic/controller/process/ProcessController.h>

namespace {

	class ProcessControllerTest : public ::testing::Test{
	protected:
		void SetUp(){}

	    void TearDown() {}
	};
}

#endif /* TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERTEST_CPP_ */
