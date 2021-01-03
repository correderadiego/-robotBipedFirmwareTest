/*
 * ParserTest.cpp
 *
 *  Created on: 20 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERTEST_CPP_

#include "gtest/gtest.h"
#include "logic/bean/hardware/Buffer.h"
#include <logic/bean/commands/CommandInterface.h>
#include <logic/controller/parser/ParserController.h>

namespace {
	class ParserControllerTest : public ::testing::Test{
	protected:
		Buffer* buffer;
		CommandInterface* command = 0;
		ParserController* parserController = new ParserController();

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
	      delete parserController;
	    }
	};

	TEST_F(ParserControllerTest, wrongLengthCommandError){
		char message [] = "$a\r";
		populateBuffer(message);
		ASSERT_EQ(parserController->parse(buffer, &command), ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerTest, unknownCommandError){
		char message [] = "$an\r";
		populateBuffer(message);
		ASSERT_EQ(parserController->parse(buffer, &command), ParserInterface::UNKNOWN_COMMAND_ERROR);
	}

	TEST_F(ParserControllerTest, controllerCommand){
		char message [] = "$AN0a3e8\r";
		populateBuffer(message);
		parserController->parse(buffer, &command);
		ASSERT_EQ((command)->getCommandType(), CommandInterface::CONTROLLER_COMMAND);
	}

	TEST_F(ParserControllerTest, interpreterCommand){
		char message [] = "#RI\r";
		populateBuffer(message);
		parserController->parse(buffer, &command);
		ASSERT_EQ((command)->getCommandType(), CommandInterface::INTERPRETER_COMMAND);
	}

	TEST_F(ParserControllerTest, setterCommand){
		char message [] = ">JS\r";
		populateBuffer(message);
		parserController->parse(buffer, &command);
		ASSERT_EQ((command)->getCommandType(), CommandInterface::SETTER_COMMAND);
	}

	TEST_F(ParserControllerTest, getterCommand){
		char message [] = "<VI\r";
		populateBuffer(message);
		parserController->parse(buffer, &command);
		ASSERT_EQ((command)->getCommandType(), CommandInterface::GETTER_COMMAND);
	}
}

#endif /* TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERTEST_CPP_ */
