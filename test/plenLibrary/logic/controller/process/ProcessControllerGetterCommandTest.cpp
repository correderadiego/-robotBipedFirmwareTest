/*
 * ProcessControllerGetterTest.cpp
 *
 *  Created on: 26 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERGETTERCOMMANDTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERGETTERCOMMANDTEST_CPP_

#include "gtest/gtest.h"
#include "logic/bean/hardware/Buffer.h"
#include "logic/controller/MotionController.h"
#include "logic/controller/JointController.h"
#include <logic/bean/commands/CommandInterface.h>
#include <logic/controller/process/ProcessControllerGetterCommand.h>
#include <logic/bean/commands/getterCommands/DumpJointSettingsCommand.h>
#include <logic/bean/commands/getterCommands/DumpMotionCommand.h>
#include <logic/bean/commands/getterCommands/DumpVersionInformationCommand.h>
#include <logic/bean/commands/getterCommands/DumpNetworkInformationCommand.h>

namespace {
	class ProcessControllerControllerGetterCommandTest : public ::testing::Test{

	protected:
		CommandInterface* command = new CommandInterface();
		ExternalFileSystemController* 	externalFilesystemController 	= new ExternalFileSystemController();
		JointController* 				jointController 				= new JointController(nullptr, externalFilesystemController);
		HeaderController* headerController = new HeaderController(externalFilesystemController);
		FrameController* frameController = new FrameController(externalFilesystemController);
		MotionController* 				motionController 				= new MotionController(headerController, frameController, externalFilesystemController, jointController);
		ProcessControllerGetterCommand* processControllerGetterCommand =
				new ProcessControllerGetterCommand(jointController, motionController);
		Joint* joint[24] = {};
		Plen* plen;
		File* fileMotion = new File();
		File* fileConfiguration = new File();
		File* fileSystem = new File();

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
							fileMotion,
							fileConfiguration,
							fileSystem
						);
		}

		void TearDown() {
			delete plen;

			for (int i = 0; i <= 23; i++) {
				delete joint[i];
			}

			delete command;
			delete processControllerGetterCommand;
			delete motionController;

			delete jointController;
			delete headerController;
			delete frameController;

			delete externalFilesystemController;

			delete fileMotion;
			delete fileConfiguration;
			delete fileSystem;
		}
	};

	TEST_F(ProcessControllerControllerGetterCommandTest, correctMatch){
		command->setCommandType(CommandInterface::GETTER_COMMAND);
		ASSERT_TRUE(processControllerGetterCommand->match(command));
	}

	TEST_F(ProcessControllerControllerGetterCommandTest, wrongMatch){
		ASSERT_FALSE(processControllerGetterCommand->match(command));
	}

	TEST_F(ProcessControllerControllerGetterCommandTest, dumpJointSettingsCommand){
		DumpJointSettingsCommand* dumpJointSettingsCommand = new DumpJointSettingsCommand();
		ASSERT_EQ(processControllerGetterCommand->process(plen , (CommandInterface *)dumpJointSettingsCommand),
				ProcessControllerInterface::NO_ERROR);
	}

	TEST_F(ProcessControllerControllerGetterCommandTest, dumpMotionCommand){
		DumpMotionCommand* dumpMotionCommand = new DumpMotionCommand();
		dumpMotionCommand->setPosition(1);
				ASSERT_EQ(processControllerGetterCommand->process(plen , (CommandInterface *)dumpMotionCommand),
						ProcessControllerInterface::NO_ERROR);
	}

	TEST_F(ProcessControllerControllerGetterCommandTest, dumpVersionInformationCommand){
		DumpVersionInformationCommand* dumpVersionInformationCommand = new DumpVersionInformationCommand();
				ASSERT_EQ(processControllerGetterCommand->process(plen , (CommandInterface *)dumpVersionInformationCommand),
						ProcessControllerInterface::NO_ERROR);
	}

	TEST_F(ProcessControllerControllerGetterCommandTest, dumpNetworkInformationCommand){
		DumpNetworkInformationCommand* dumpNetworkInformationCommand = new DumpNetworkInformationCommand();
				ASSERT_EQ(processControllerGetterCommand->process(plen , (CommandInterface *)dumpNetworkInformationCommand),
						ProcessControllerInterface::NO_ERROR);
	}
}

#endif /* TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERGETTERCOMMANDTEST_CPP_ */
