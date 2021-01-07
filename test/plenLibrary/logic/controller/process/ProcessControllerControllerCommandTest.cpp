/*
 * ProcessControllerControllerCommandTest.h
 *
 *  Created on: 25 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMANDTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMANDTEST_CPP_

#include "../TestBase.h"
#include <logic/controller/process/ProcessControllerControllerCommand.h>
#include <logic/bean/commands/controllerCommands/ApplyHomePositionCommand.h>
#include <logic/controller/process/ProcessControllerInterface.h>

namespace {
	class ProcessControllerControllerCommandTest : public ::TestBase{
		protected:

		ProcessControllerControllerCommand* processControllerControllerCommand;

		void SetUp(){
			TestBase::SetUp();
			processControllerControllerCommand =
									new ProcessControllerControllerCommand(jointController, motionController);
		}

		void TearDown(){
			TestBase::TearDown();
			delete processControllerControllerCommand;
		}
	};

	TEST_F(ProcessControllerControllerCommandTest, correctMatch){
		command->setCommandType(CommandInterface::CONTROLLER_COMMAND);
		ASSERT_TRUE(processControllerControllerCommand->match(command));
	}

	TEST_F(ProcessControllerControllerCommandTest, wrongMatch){
		ASSERT_FALSE(processControllerControllerCommand->match(command));
	}

	TEST_F(ProcessControllerControllerCommandTest, applyNativeValueCommand){
		ApplyNativeValueCommand* applyNativeValueCommand = new ApplyNativeValueCommand();
		applyNativeValueCommand->setDeviceId(10);
		applyNativeValueCommand->setValue(200);
		ProcessControllerInterface::CommandControllerErrors commandControllerError
			= processControllerControllerCommand->process(this->plen , (CommandInterface *)applyNativeValueCommand);
		ASSERT_EQ(this->plen->getJointVector()[10]->getAngle(),200);
		ASSERT_EQ(commandControllerError, ProcessControllerInterface::NO_ERROR);
		delete applyNativeValueCommand;
	}

	TEST_F(ProcessControllerControllerCommandTest, ApplyDiffValueCommand){
		ApplyDiffValueCommand* applyDiffValueCommand = new ApplyDiffValueCommand();
		applyDiffValueCommand->setDeviceId(15);
		applyDiffValueCommand->setValue(205);
		ProcessControllerInterface::CommandControllerErrors commandControllerError
					= processControllerControllerCommand->process(plen , (CommandInterface *)applyDiffValueCommand);
		ASSERT_EQ(plen->getJointVector()[15]->getAngle(), 205 + plen->getJointVector()[15]->getAngleHome());
		ASSERT_EQ(commandControllerError, ProcessControllerInterface::NO_ERROR);
		delete applyDiffValueCommand;
	}

	TEST_F(ProcessControllerControllerCommandTest, PlayAMotionCommand){
		PlayAMotionCommand* playAMotionCommand = new PlayAMotionCommand();
		ProcessControllerInterface::CommandControllerErrors commandControllerError
					= processControllerControllerCommand->process(plen , (CommandInterface *)playAMotionCommand);
		ASSERT_EQ(commandControllerError, ProcessControllerInterface::NO_ERROR);
		delete playAMotionCommand;
	}

	TEST_F(ProcessControllerControllerCommandTest, StopAMotionCommand){
		StopAMotionCommand* stopAMotionCommand = new StopAMotionCommand();
		ProcessControllerInterface::CommandControllerErrors commandControllerError
					= processControllerControllerCommand->process(plen , (CommandInterface *)stopAMotionCommand);
		ASSERT_EQ(commandControllerError, ProcessControllerInterface::NO_ERROR);
		delete stopAMotionCommand;
	}

	TEST_F(ProcessControllerControllerCommandTest, ApplyHomePositionCommand){
		ApplyHomePositionCommand* applyHomePositionCommand = new ApplyHomePositionCommand();
		ProcessControllerInterface::CommandControllerErrors commandControllerError
		 	 	 	 = processControllerControllerCommand->process(plen , (CommandInterface *)applyHomePositionCommand);
		for (int i = 0; i < plen->getJointSize(); i++) {
			ASSERT_EQ(plen->getJointVector()[i]->getAngle(), plen->getJointVector()[i]->getAngleHome());
		}
		ASSERT_EQ(commandControllerError, ProcessControllerInterface::NO_ERROR);
		delete applyHomePositionCommand;
	}
}

#endif /* TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMANDTEST_CPP_ */
