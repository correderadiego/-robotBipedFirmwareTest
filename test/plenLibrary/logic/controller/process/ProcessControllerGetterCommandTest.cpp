/*
 * ProcessControllerGetterTest.cpp
 *
 *  Created on: 26 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERGETTERCOMMANDTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERGETTERCOMMANDTEST_CPP_

#include "../TestBase.h"
#include <logic/controller/process/ProcessControllerGetterCommand.h>
#include <logic/bean/commands/getterCommands/DumpVersionInformationCommand.h>
#include <logic/bean/commands/getterCommands/DumpNetworkInformationCommand.h>

namespace {
	class ProcessControllerControllerGetterCommandTest : public ::TestBase{

	protected:
		ProcessControllerGetterCommand* processControllerGetterCommand;

		void SetUp(){
			TestBase::SetUp();
			processControllerGetterCommand =
										new ProcessControllerGetterCommand(jointController, motionController);
		}

		void TearDown() {
			TestBase::TearDown();
			delete processControllerGetterCommand;
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
		delete dumpJointSettingsCommand;
	}

	TEST_F(ProcessControllerControllerGetterCommandTest, dumpMotionCommand){
		DumpMotionCommand* dumpMotionCommand = new DumpMotionCommand();
		dumpMotionCommand->setPosition(1);
		ASSERT_EQ(processControllerGetterCommand->process(plen , (CommandInterface *)dumpMotionCommand),
						ProcessControllerInterface::NO_ERROR);
		delete dumpMotionCommand;
	}

	TEST_F(ProcessControllerControllerGetterCommandTest, dumpVersionInformationCommand){
		DumpVersionInformationCommand* dumpVersionInformationCommand = new DumpVersionInformationCommand();
		ASSERT_EQ(processControllerGetterCommand->process(plen , (CommandInterface *)dumpVersionInformationCommand),
						ProcessControllerInterface::NO_ERROR);
		delete dumpVersionInformationCommand;
	}

	TEST_F(ProcessControllerControllerGetterCommandTest, dumpNetworkInformationCommand){
		DumpNetworkInformationCommand* dumpNetworkInformationCommand = new DumpNetworkInformationCommand();
		ASSERT_EQ(processControllerGetterCommand->process(plen , (CommandInterface *)dumpNetworkInformationCommand),
						ProcessControllerInterface::NO_ERROR);
		delete dumpNetworkInformationCommand;
	}
}

#endif /* TEST_PLENLIBRARY_LOGIC_CONTROLLER_PROCESS_PROCESSCONTROLLERGETTERCOMMANDTEST_CPP_ */
