/*
 * ProcessControllerSetterCommandTest.cpp
 *
 *  Created on: 27 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PROCESSCONTROLLERSETTERCOMMANDTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PROCESSCONTROLLERSETTERCOMMANDTEST_CPP_

#include <logic/controller/process/ProcessControllerSetterCommand.h>
#include <logic/bean/commands/setterCommands/ResetJointSettingsCommand.h>
#include "../TestBase.h"

namespace {

	class ProcessControllerControllerSetterCommandTest : public ::TestBase{

	protected:
		ProcessControllerSetterCommand* processControllerSetterCommand;

		void SetUp(){
			TestBase::SetUp();
			processControllerSetterCommand =
							new ProcessControllerSetterCommand(jointController, motionController);
		}

		void TearDown(){
			TestBase::TearDown();
			delete processControllerSetterCommand;
		}
	};

	TEST_F(ProcessControllerControllerSetterCommandTest, correctMatch){
		command->setCommandType(CommandInterface::SETTER_COMMAND);
		ASSERT_TRUE(processControllerSetterCommand->match(command));
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, wrongMatch){
		ASSERT_FALSE(processControllerSetterCommand->match(command));
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, setMotionHeaderCommand){
		SetMotionHeaderCommand* setMotionHeaderCommand = new SetMotionHeaderCommand();
		ASSERT_EQ(processControllerSetterCommand->process(plen , (CommandInterface *)setMotionHeaderCommand),
				ProcessControllerInterface::NO_ERROR);
		delete setMotionHeaderCommand;
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, setMotionFrameCommand){
		SetMotionFrameCommand* setMotionFrameCommand = new SetMotionFrameCommand();
		ASSERT_EQ(processControllerSetterCommand->process(plen , (CommandInterface *)setMotionFrameCommand),
				ProcessControllerInterface::NO_ERROR);
		delete setMotionFrameCommand;
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, resetJointSettingsCommand){
		ResetJointSettingsCommand* resetJointSettingsCommand = new ResetJointSettingsCommand();
		ASSERT_EQ(processControllerSetterCommand->process(plen , (CommandInterface *)resetJointSettingsCommand),
						ProcessControllerInterface::NO_ERROR);
		delete resetJointSettingsCommand;
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, setHomeValueCommand){
		SetAngleHomeValueCommand* setHomeValueCommand = new SetAngleHomeValueCommand();
		setHomeValueCommand->setDeviceId(10);
		setHomeValueCommand->setValue(100);
		ProcessControllerInterface::CommandControllerErrors commandControllerError
				= processControllerSetterCommand->process(plen , (CommandInterface *)setHomeValueCommand);
		ASSERT_EQ(plen->getJointVector()[10]->getAngleHome(),100);
		ASSERT_EQ(commandControllerError, ProcessControllerInterface::NO_ERROR);
		delete setHomeValueCommand;
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, setMaxValueCommand){
		SetAngleMaxValueCommand* setMaxValueCommand = new SetAngleMaxValueCommand();
		setMaxValueCommand->setDeviceId(10);
		setMaxValueCommand->setValue(100);
		ProcessControllerInterface::CommandControllerErrors commandControllerError
				= processControllerSetterCommand->process(plen , (CommandInterface *)setMaxValueCommand);
		ASSERT_EQ(plen->getJointVector()[10]->getAngleMax(),100);
		ASSERT_EQ(commandControllerError, ProcessControllerInterface::NO_ERROR);
		delete setMaxValueCommand;
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, setMinValueCommand){
		SetMinValueCommand* setMinValueCommand = new SetMinValueCommand();
		setMinValueCommand->setDeviceId(10);
		setMinValueCommand->setValue(100);
		ProcessControllerInterface::CommandControllerErrors commandControllerError
				= processControllerSetterCommand->process(plen , (CommandInterface *)setMinValueCommand);
		ASSERT_EQ(plen->getJointVector()[10]->getAngleMin(),100);
		ASSERT_EQ(commandControllerError, ProcessControllerInterface::NO_ERROR);
		delete setMinValueCommand;
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, resetJointCommandMaxValue){
		for (int i = 0; i < plen->getJointSize(); i++) {
			ASSERT_EQ(plen->getJointVector()[i]->getAngleMax(),ANGLE_MAX);
		}
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, resetJointCommandMinValue){
		for (int i = 0; i < plen->getJointSize(); i++) {
			ASSERT_EQ(plen->getJointVector()[i]->getAngleMin(),ANGLE_MIN);
		}
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, resetJointCommandHomeValue){
		for (int i = 0; i < plen->getJointSize(); i++) {
			ASSERT_EQ(plen->getJointVector()[i]->getAngleHome(),
				plen->getJointVector()[i]->getDefaultAngleHome());
		}
	}
}

#endif /* TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PROCESSCONTROLLERSETTERCOMMANDTEST_CPP_ */
