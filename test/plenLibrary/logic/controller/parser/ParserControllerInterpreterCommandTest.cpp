/*
 * ParserControllerInterpreterCommand.cpp
 *
 *  Created on: 24 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERCONTROLLERINTERPRETERCOMMANDTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERCONTROLLERINTERPRETERCOMMANDTEST_CPP_

#include "gtest/gtest.h"
#include "logic/bean/hardware/Buffer.h"
#include <logic/bean/commands/CommandInterface.h>
#include <logic/bean/commands/interpreterCommands/InterpreterCommand.h>
#include <logic/controller/parser/ParserControllerInterpreterCommand.h>

namespace {
	class ParserControllerInterpreterCommandTest : public ::testing::Test{
	protected:
		Buffer* buffer;
		CommandInterface* command = 0;
		ParserControllerInterpreterCommand* parserControllerInterpreterCommand =
				new ParserControllerInterpreterCommand();

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
	    	delete parserControllerInterpreterCommand;
	    	delete command;
	    }
	};

	TEST_F(ParserControllerInterpreterCommandTest, correctMatch){
		char message [] = "#PO\r";
		populateBuffer(message);
		ASSERT_TRUE(parserControllerInterpreterCommand->match(buffer));
	}

	TEST_F(ParserControllerInterpreterCommandTest, wrongMatch){
		char message [] = "$PO\r";
		populateBuffer(message);
		ASSERT_FALSE(parserControllerInterpreterCommand->match(buffer));
	}

	TEST_F(ParserControllerInterpreterCommandTest, pushAFunctionCommandType){
		char message [] = "#PU0a03\r";
		populateBuffer(message);
		parserControllerInterpreterCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::INTERPRETER_COMMAND);
	}

	TEST_F(ParserControllerInterpreterCommandTest, pushAFunctionSubCommandType){
		char message [] = "#PU0a03\r";
		populateBuffer(message);
		parserControllerInterpreterCommand->parse(buffer, &command);
		ASSERT_EQ(((PushAFunctionCommand*)command)->getSubCommandType(),
				InterpreterCommand::PUSH_A_FUNCTION);
	}

	TEST_F(ParserControllerInterpreterCommandTest, pushAFunctionWrongCommandLengthLess){
		char message [] = "#PU0a0\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerInterpreterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerInterpreterCommandTest, pushAFunctionWrongCommandLengthMore){
		char message [] = "#PU0a053\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerInterpreterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerInterpreterCommandTest, pushAFunctionSlot){
		char message [] = "#PU0a03\r";
		populateBuffer(message);
		parserControllerInterpreterCommand->parse(buffer, &command);
		int slot = ((PushAFunctionCommand*)command)->getSlot();
		ASSERT_EQ(slot, 10);
	}

	TEST_F(ParserControllerInterpreterCommandTest, pushAFunctionLoopCount){
		char message [] = "#PU0a03\r";
		populateBuffer(message);
		parserControllerInterpreterCommand->parse(buffer, &command);
		int loopCount = ((PushAFunctionCommand*)command)->getLoopCount();
		ASSERT_EQ(loopCount, 3);
	}

	TEST_F(ParserControllerInterpreterCommandTest, popAFunctionCommandType){
		char message [] = "#PO\r";
		populateBuffer(message);
		parserControllerInterpreterCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::INTERPRETER_COMMAND);
	}

	TEST_F(ParserControllerInterpreterCommandTest, popAFunctionSubCommandType){
		char message [] = "#PO\r";
		populateBuffer(message);
		parserControllerInterpreterCommand->parse(buffer, &command);
		ASSERT_EQ(((PushAFunctionCommand*)command)->getSubCommandType(),
				InterpreterCommand::POP_A_FUNCTION);
	}

	TEST_F(ParserControllerInterpreterCommandTest, resetInterpreterCommandType){
		char message [] = "#RI\r";
		populateBuffer(message);
		parserControllerInterpreterCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::INTERPRETER_COMMAND);
	}

	TEST_F(ParserControllerInterpreterCommandTest, resetInterpreterSubCommandType){
		char message [] = "#RI\r";
		populateBuffer(message);
		parserControllerInterpreterCommand->parse(buffer, &command);
		ASSERT_EQ(((PushAFunctionCommand*)command)->getSubCommandType(),
				InterpreterCommand::RESET_INTERPRETER);
	}
}


#endif /* TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERCONTROLLERINTERPRETERCOMMANDTEST_CPP_ */
