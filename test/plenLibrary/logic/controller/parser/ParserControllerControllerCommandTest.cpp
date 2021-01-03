/*
 * ParserControllerControllerCommandTest.h
 *
 *  Created on: 22 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMANDTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMANDTEST_CPP_

#include "gtest/gtest.h"
#include "logic/bean/hardware/Buffer.h"
#include <logic/bean/commands/CommandInterface.h>
#include <logic/controller/parser/ParserControllerControllerCommand.h>
#include <logic/bean/commands/controllerCommands/ControllerCommand.h>
#include <logic/bean/commands/controllerCommands/ApplyNativeValueCommand.h>

namespace {
	class ParserControllerControllerCommandTest : public ::testing::Test{
	protected:
		Buffer* buffer;
		CommandInterface* command = 0;
		ParserControllerControllerCommand* parserControllerControllerCommand =
				new ParserControllerControllerCommand();

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
	    	delete command;
	    	delete parserControllerControllerCommand;
	    }
	};

	TEST_F(ParserControllerControllerCommandTest, correctMatch){
		char message [] = "$AN\r";
		populateBuffer(message);
		ASSERT_TRUE(parserControllerControllerCommand->match(buffer));
	}

	TEST_F(ParserControllerControllerCommandTest, wrongMatch){
		char message [] = "<AN\r";
		populateBuffer(message);
		ASSERT_FALSE(parserControllerControllerCommand->match(buffer));
	}

	TEST_F(ParserControllerControllerCommandTest, applyNativeValueCommandType){
		char message [] = "$AN0a3e8\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::CONTROLLER_COMMAND);
	}

	TEST_F(ParserControllerControllerCommandTest, applyNativeValueSubCommandType){
		char message [] = "$AN0a3e8\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		ASSERT_EQ(((ApplyNativeValueCommand*)command)->getSubCommandType(),
				ControllerCommand::APPY_NATIVE_VALUE);
	}

	TEST_F(ParserControllerControllerCommandTest, applyNativeValueWrongCommandLengthLess){
		char message [] = "$AN0a3e\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerControllerCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerControllerCommandTest, applyNativeValueWrongCommandLengthMore){
		char message [] = "$AN0a3e333\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerControllerCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerControllerCommandTest, applyNativeValueDeviceId){
		char message [] = "$AN0a3e8\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		int deviceIdInt = ((ApplyNativeValueCommand*)command)->getDeviceId();
		ASSERT_EQ(deviceIdInt, 10);
	}

	TEST_F(ParserControllerControllerCommandTest, applyNativeValueValue){
		char message [] = "$AN0a3e8\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		int value = ((ApplyNativeValueCommand*)command)->getValue();
		ASSERT_EQ(value, 1000);
	}

	TEST_F(ParserControllerControllerCommandTest, applyDiffValueCommandType){
		char message [] = "$AD0a3e8\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::CONTROLLER_COMMAND);
	}

	TEST_F(ParserControllerControllerCommandTest, applyDiffValueSubCommandType){
		char message [] = "$AD0a3e8\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		ASSERT_EQ(((ApplyDiffValueCommand *)command)->getSubCommandType(),
				ControllerCommand::APPLY_DIFF_VALUE);
	}

	TEST_F(ParserControllerControllerCommandTest, applyDiffValueWrongCommandLengthLess){
		char message [] = "$AD0a3e\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerControllerCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerControllerCommandTest, applyDiffValueWrongCommandLengthMore){
		char message [] = "$AD0a3e333\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerControllerCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerControllerCommandTest, applyDiffValueDeviceId){
		char message [] = "$AD0a3e8\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		int deviceIdInt = ((ApplyDiffValueCommand*)command)->getDeviceId();
		ASSERT_EQ(deviceIdInt, 10);
	}

	TEST_F(ParserControllerControllerCommandTest, applyDiffValueValue){
		char message [] = "$AN0a3e8\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		int value = ((ApplyDiffValueCommand*)command)->getValue();
		ASSERT_EQ(value, 1000);
	}

	TEST_F(ParserControllerControllerCommandTest, playAMotionCommandType){
		char message [] = "$PM04\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::CONTROLLER_COMMAND);
	}

	TEST_F(ParserControllerControllerCommandTest, playAMotionSubCommandType){
		char message [] = "$PM04\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		ASSERT_EQ(((PlayAMotionCommand *)command)->getSubCommandType(),
				ControllerCommand::PLAY_A_MOTION);
	}

	TEST_F(ParserControllerControllerCommandTest, playAMotionWrongCommandLengthLess){
		char message [] = "$PM0\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerControllerCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerControllerCommandTest, playAMotionWrongCommandLengthMore){
		char message [] = "$PM04555\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerControllerCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerControllerCommandTest, playAMotionSlot){
		char message [] = "$PM04\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		int slot = ((PlayAMotionCommand*)command)->getPosition();
		ASSERT_EQ(slot, 4);
	}

	TEST_F(ParserControllerControllerCommandTest, stopAMotionCommandType){
		char message [] = "$SM\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::CONTROLLER_COMMAND);
	}

	TEST_F(ParserControllerControllerCommandTest, stopAMotionSubCommandType){
		char message [] = "$SM\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		ASSERT_EQ(((PlayAMotionCommand *)command)->getSubCommandType(),
				ControllerCommand::STOP_A_MOTION);
	}

	TEST_F(ParserControllerControllerCommandTest, stopAMotionWrongCommandLengthMore){
		char message [] = "$SM04\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerControllerCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerControllerCommandTest, applyHomeCommandType){
		char message [] = "$HP\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::CONTROLLER_COMMAND);
	}

	TEST_F(ParserControllerControllerCommandTest, applyHomenSubCommandType){
		char message [] = "$HP\r";
		populateBuffer(message);
		parserControllerControllerCommand->parse(buffer, &command);
		ASSERT_EQ(((PlayAMotionCommand *)command)->getSubCommandType(),
				ControllerCommand::APPLY_HOME_POSITION);
	}

	TEST_F(ParserControllerControllerCommandTest, applyHomeWrongCommandLengthMore){
		char message [] = "$HP04\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerControllerCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}
}

#endif /* TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMANDTEST_CPP_ */
