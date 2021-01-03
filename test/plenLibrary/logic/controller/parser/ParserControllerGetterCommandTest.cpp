/*
 * ParserControllerGetterCommand.cpp
 *
 *  Created on: 24 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERCONTROLLERGETTERCOMMANDTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERCONTROLLERGETTERCOMMANDTEST_CPP_

#include "gtest/gtest.h"
#include "logic/bean/hardware/Buffer.h"
#include <logic/bean/commands/CommandInterface.h>
#include <logic/bean/commands/getterCommands/GetterCommand.h>
#include <logic/controller/parser/ParserControllerGetterCommand.h>

namespace {
	class ParserControllerGetterCommandTest : public ::testing::Test{
	protected:
		Buffer* buffer;
		CommandInterface* command = 0;
		ParserControllerGetterCommand* parserControllerGetterCommand =
				new ParserControllerGetterCommand();

		void populateBuffer(char message[]){
			for (int i = 0; i < (int)strlen(message); i++) {
				buffer->addChar(message[i]);
			}
		}

		void SetUp(){
			buffer = new Buffer();
		}

		void TearDown() {
			buffer->clearBuffer();
			delete buffer;
			delete parserControllerGetterCommand;
			delete command;
		}
	};

	TEST_F(ParserControllerGetterCommandTest, correctMatch){
		char message [] = "<JS\r";
		populateBuffer(message);
		ASSERT_TRUE(parserControllerGetterCommand->match(buffer));
	}

	TEST_F(ParserControllerGetterCommandTest, wrongMatch){
		char message [] = "$PO\r";
		populateBuffer(message);
		ASSERT_FALSE(parserControllerGetterCommand->match(buffer));
	}

	TEST_F(ParserControllerGetterCommandTest, dumpJointSettingsCommandType){
		char message [] = "<JS\r";
		populateBuffer(message);
		parserControllerGetterCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::GETTER_COMMAND);
	}

	TEST_F(ParserControllerGetterCommandTest, dumpJointSettingsSubCommandType){
		char message [] = "<JS\r";
		populateBuffer(message);
		parserControllerGetterCommand->parse(buffer, &command);
		ASSERT_EQ(((DumpJointSettingsCommand*)command)->getSubCommandType(),
				GetterCommand::DUMP_JOINT_SETTINGS);
	}

	TEST_F(ParserControllerGetterCommandTest, dumpAMotionCommandType){
		char message [] = "<MO00\r";
		populateBuffer(message);
		parserControllerGetterCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::GETTER_COMMAND);
	}

	TEST_F(ParserControllerGetterCommandTest, dumpAMotionSubCommandType){
		char message [] = "<MO00\r";
		populateBuffer(message);
		parserControllerGetterCommand->parse(buffer, &command);
		ASSERT_EQ(((DumpJointSettingsCommand*)command)->getSubCommandType(),
				GetterCommand::DUMP_MOTION);
	}

	TEST_F(ParserControllerGetterCommandTest, dumpAMotionWrongCommandLengthLess){
		char message [] = "<MO0\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerGetterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerGetterCommandTest, dumpAMotionWrongCommandLengthMore){
		char message [] = "<MO0052\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerGetterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerGetterCommandTest, dumpAMotionSlot){
		char message [] = "<MO00\r";
		populateBuffer(message);
		parserControllerGetterCommand->parse(buffer, &command);
		int slot = ((DumpMotionCommand*)command)->getPosition();
		ASSERT_EQ(slot, 0);
	}

	TEST_F(ParserControllerGetterCommandTest, dumpVersionInformationCommandType){
		char message [] = "<VI\r";
		populateBuffer(message);
		parserControllerGetterCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::GETTER_COMMAND);
	}

	TEST_F(ParserControllerGetterCommandTest, dumpVersionInformationSubCommandType){
		char message [] = "<VI\r";
		populateBuffer(message);
		parserControllerGetterCommand->parse(buffer, &command);
		ASSERT_EQ(((DumpVersionInformationCommand*)command)->getSubCommandType(),
				GetterCommand::DUMP_VERSION_INFORMATION);
	}

	TEST_F(ParserControllerGetterCommandTest, dumpNetworkInformationCommandType){
		char message [] = "<NI\r";
		populateBuffer(message);
		parserControllerGetterCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::GETTER_COMMAND);
	}

	TEST_F(ParserControllerGetterCommandTest, dumpNetworkInformationSubCommandType){
		char message [] = "<NI\r";
		populateBuffer(message);
		parserControllerGetterCommand->parse(buffer, &command);
		ASSERT_EQ(((DumpJointSettingsCommand*)command)->getSubCommandType(),
				GetterCommand::DUMP_NETWORK_INFORMATION);
	}
}

#endif /* TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERCONTROLLERGETTERCOMMANDTEST_CPP_ */
