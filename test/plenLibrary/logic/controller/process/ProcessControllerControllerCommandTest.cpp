/*
 * ProcessControllerControllerCommandTest.h
 *
 *  Created on: 25 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMANDTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMANDTEST_CPP_

#include "gtest/gtest.h"
#include "logic/bean/hardware/Buffer.h"
#include <logic/bean/commands/CommandInterface.h>
#include <logic/controller/process/ProcessControllerControllerCommand.h>
#include <logic/bean/commands/controllerCommands/ControllerCommand.h>
#include <logic/bean/commands/controllerCommands/ApplyNativeValueCommand.h>
#include <logic/bean/commands/controllerCommands/ApplyHomePositionCommand.h>

namespace {
	class ProcessControllerControllerCommandTest : public ::testing::Test{
	protected:
		CommandInterface* command = new CommandInterface();
		ExternalFileSystemController* externalFileSystemController = new ExternalFileSystemController();
		JointController* jointController = new JointController(nullptr, externalFileSystemController);
		HeaderController* headerController = new HeaderController(externalFileSystemController);
		FrameController* frameController = new FrameController(externalFileSystemController);
		MotionController* motionController = new MotionController(
				headerController,
				frameController,
				externalFileSystemController,
				jointController);
		ProcessControllerControllerCommand* processControllerControllerCommand =
				new ProcessControllerControllerCommand(jointController, motionController);
		Joint* joint[24] = {};
		Plen* plen;
		void SetUp(){
			command->setCommandType(CommandInterface::UNKNOWN_COMMAND_TYPE);
			for (int i = 0; i <= 23; i++) {
				joint[i] = new Joint();
			}

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
			delete command;
			delete externalFileSystemController;
			delete jointController;
			delete headerController;
			delete frameController;
			delete motionController;
			delete processControllerControllerCommand;
			for (int i = 0; i <= 23; i++) {
				delete joint[i];
			}
			delete plen;
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
		processControllerControllerCommand->process(plen , (CommandInterface *)applyNativeValueCommand);
		ASSERT_EQ(plen->getJointVector()[10]->getAngle(),200);
	}

	TEST_F(ProcessControllerControllerCommandTest, ApplyDiffValueCommand){
		ApplyDiffValueCommand* applyDiffValueCommand = new ApplyDiffValueCommand();
		applyDiffValueCommand->setDeviceId(15);
		applyDiffValueCommand->setValue(205);
		processControllerControllerCommand->process(plen , (CommandInterface *)applyDiffValueCommand);
		ASSERT_EQ(plen->getJointVector()[15]->getAngle(), 205 + plen->getJointVector()[15]->getAngleHome());
	}

	TEST_F(ProcessControllerControllerCommandTest, PlayAMotionCommand){
		PlayAMotionCommand* playAMotionCommand = new PlayAMotionCommand();
		processControllerControllerCommand->process(plen , (CommandInterface *)playAMotionCommand);
	}

	TEST_F(ProcessControllerControllerCommandTest, StopAMotionCommand){
		StopAMotionCommand* stopAMotionCommand = new StopAMotionCommand();
		processControllerControllerCommand->process(plen , (CommandInterface *)stopAMotionCommand);
	}

	TEST_F(ProcessControllerControllerCommandTest, ApplyHomePositionCommand){
		ApplyHomePositionCommand* applyHomePositionCommand = new ApplyHomePositionCommand();
		processControllerControllerCommand->process(plen , (CommandInterface *)applyHomePositionCommand);
		for (int i = 0; i < plen->getJointSize(); i++) {
			ASSERT_EQ(plen->getJointVector()[i]->getAngle(), plen->getJointVector()[i]->getAngleHome());
		}
		delete applyHomePositionCommand;
	}
}

#endif /* TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMANDTEST_CPP_ */
