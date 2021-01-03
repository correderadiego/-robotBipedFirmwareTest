/*
 * ProcessControllerSetterCommandTest.cpp
 *
 *  Created on: 27 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PROCESSCONTROLLERSETTERCOMMANDTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PROCESSCONTROLLERSETTERCOMMANDTEST_CPP_
#include "gtest/gtest.h"
#include "logic/bean/hardware/Buffer.h"
#include <logic/bean/commands/CommandInterface.h>
#include <logic/controller/process/ProcessControllerSetterCommand.h>
#include <logic/bean/commands/setterCommands/SetMotionFrameCommand.h>
#include <logic/bean/commands/setterCommands/SetMotionHeaderCommand.h>
#include <logic/bean/commands/setterCommands/ResetJointSettingsCommand.h>
#include "logic/controller/MotionController.h"
#include "Configuration.h"

namespace {

	class ProcessControllerControllerSetterCommandTest : public ::testing::Test{

	protected:
		CommandInterface* command = new CommandInterface();
		ExternalFileSystemController* externalFileSystemController = new ExternalFileSystemController();
		JointController* jointController = new JointController(nullptr, externalFileSystemController);
		HeaderController* headerController = new HeaderController(externalFileSystemController);
		FrameController* frameController = new FrameController(externalFileSystemController);
		MotionController* motionController = new MotionController(headerController, frameController, externalFileSystemController, jointController);
		ProcessControllerSetterCommand* processControllerSetterCommand =
				new ProcessControllerSetterCommand(jointController, motionController);
		Joint* joint[24] = {};
		Plen* plen;

		void initJoint(){
			joint[0] =	new Joint(nullptr,	HOME_POSITION_LEFT_SHOULDER_PITCH, Joint::counterClockWise);
			joint[1] =	new Joint(nullptr,	HOME_POSITION_LEFT_THIGH_YAW);
			joint[2] =  new Joint(nullptr,	HOME_POSITION_LEFT_SHOULDER_ROLL);
			joint[3] =	new Joint(nullptr,	HOME_POSITION_LEFT_ELBOW_ROLL);
			joint[4] =	new Joint(nullptr,	HOME_POSITION_LEFT_THIGH_ROLL);
			joint[5] =	new Joint(nullptr,	HOME_POSITION_LEFT_THIGH_PITCH);
			joint[6] =	new Joint(nullptr,	HOME_POSITION_LEFT_KNEE_PITCH);
			joint[7] =	new Joint(nullptr,	HOME_POSITION_LEFT_FOOT_PITCH);
			joint[8] =	new Joint(nullptr,	HOME_POSITION_LEFT_FOOT_ROLL);
			joint[9] =	new Joint();
			joint[10] =	new Joint();
			joint[11] =	new Joint();
			joint[12] =	new Joint(nullptr,  HOME_POSITION_RIGHT_SHOULDER_PITCH, Joint::counterClockWise);
			joint[13] =	new Joint(nullptr, 	HOME_POSITION_RIGHT_THIGH_YAW);
			joint[14] =	new Joint(nullptr,  HOME_POSITION_RIGHT_SHOULDER_ROLL);
			joint[15] =	new Joint(nullptr, 	HOME_POSITION_RIGHT_ELBOW_ROLL);
			joint[16] =	new Joint(nullptr,  HOME_POSITION_RIGHT_THIGH_ROLL);
			joint[17] =	new Joint(nullptr, 	HOME_POSITION_RIGHT_THIGH_PITCH);
			joint[18] =	new Joint(nullptr, 	HOME_POSITION_RIGHT_KNEE_PITCH);
			joint[19] =	new Joint(nullptr, 	HOME_POSITION_RIGHT_FOOT_PITCH);
			joint[20] =	new Joint(nullptr,  HOME_POSITION_RIGHT_FOOT_ROLL);
			joint[21] =	new Joint();
			joint[22] =	new Joint();
			joint[23] =	new Joint();
		}

		void SetUp(){
			command->setCommandType(CommandInterface::UNKNOWN_COMMAND_TYPE);
			initJoint();

			plen = new Plen(
							joint,
							24,
							nullptr,
							nullptr,
							nullptr,
							nullptr,
							nullptr,
							nullptr
						);
		}

		void TearDown() {
			delete plen;

			for (int i = 0; i <= 23; i++) {
				delete joint[i];
			}

			delete command;
			delete externalFileSystemController;
			delete jointController;
			delete headerController;
			delete frameController;

			delete processControllerSetterCommand;
			delete motionController;
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
	}


	TEST_F(ProcessControllerControllerSetterCommandTest, setMotionFrameCommand){
		SetMotionFrameCommand* setMotionFrameCommand = new SetMotionFrameCommand();
		ASSERT_EQ(processControllerSetterCommand->process(plen , (CommandInterface *)setMotionFrameCommand),
				ProcessControllerInterface::NO_ERROR);
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, resetJointSettingsCommand){
		ResetJointSettingsCommand* resetJointSettingsCommand = new ResetJointSettingsCommand();
				ASSERT_EQ(processControllerSetterCommand->process(plen , (CommandInterface *)resetJointSettingsCommand),
						ProcessControllerInterface::NO_ERROR);
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, setHomeValueCommand){
		SetAngleHomeValueCommand* setHomeValueCommand = new SetAngleHomeValueCommand();
		setHomeValueCommand->setDeviceId(10);
		setHomeValueCommand->setValue(100);
		processControllerSetterCommand->process(plen , (CommandInterface *)setHomeValueCommand);
				ASSERT_EQ(plen->getJointVector()[10]->getAngleHome(),100);
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, setMaxValueCommand){
		SetAngleMaxValueCommand* setMaxValueCommand = new SetAngleMaxValueCommand();
		setMaxValueCommand->setDeviceId(10);
		setMaxValueCommand->setValue(100);
		processControllerSetterCommand->process(plen , (CommandInterface *)setMaxValueCommand);
				ASSERT_EQ(plen->getJointVector()[10]->getAngleMax(),100);
	}

	TEST_F(ProcessControllerControllerSetterCommandTest, setMinValueCommand){
		SetMinValueCommand* setMinValueCommand = new SetMinValueCommand();
		setMinValueCommand->setDeviceId(10);
		setMinValueCommand->setValue(100);
		processControllerSetterCommand->process(plen , (CommandInterface *)setMinValueCommand);
				ASSERT_EQ(plen->getJointVector()[10]->getAngleMin(),100);
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
