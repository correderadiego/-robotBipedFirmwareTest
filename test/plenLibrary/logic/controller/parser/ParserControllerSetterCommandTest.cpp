/*
 * ParserControllerSetterCommand.cpp
 *
 *  Created on: 24 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERCONTROLLERSETTERCOMMANDTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERCONTROLLERSETTERCOMMANDTEST_CPP_

#include "gtest/gtest.h"
#include "logic/bean/hardware/Buffer.h"
#include <logic/bean/commands/CommandInterface.h>
#include <logic/controller/parser/ParserControllerSetterCommand.h>
#include <logic/bean/commands/setterCommands/SetterCommand.h>
#include <logic/bean/commands/controllerCommands/ApplyNativeValueCommand.h>

namespace {
	class ParserControllerSetterCommandTest : public ::testing::Test{
	protected:
		Buffer* buffer;
		CommandInterface* command = 0;
		ParserControllerSetterCommand* parserControllerSetterCommand =
				new ParserControllerSetterCommand();

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
	    	delete parserControllerSetterCommand;
	    }

	    std::string convertVecToChar(std::vector<unsigned char>& source){
	        return std::string(source.begin(), source.end());
	    }
	};



	TEST_F(ParserControllerSetterCommandTest, correctMatch){
		char message [] = ">JS\r";
		populateBuffer(message);
		ASSERT_TRUE(parserControllerSetterCommand->match(buffer));
	}

	TEST_F(ParserControllerSetterCommandTest, wrongMatch){
		char message [] = "#JS\r";
		populateBuffer(message);
		ASSERT_FALSE(parserControllerSetterCommand->match(buffer));
	}

	TEST_F(ParserControllerSetterCommandTest, resetJointSettingsCommandType){
		char message [] = ">JS\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::SETTER_COMMAND);
	}

	TEST_F(ParserControllerSetterCommandTest, resetJointSettingsSubCommandType){
		char message [] = ">JS\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		ASSERT_EQ(((ResetJointSettingsCommand*)command)->getSubCommandType(),
				SetterCommand::RESET_JOINT_SETTINGS);
	}

	TEST_F(ParserControllerSetterCommandTest, setHomeValueCommandType){
		char message [] = ">HO00064\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::SETTER_COMMAND);
	}

	TEST_F(ParserControllerSetterCommandTest, setHomeValueSubCommandType){
		char message [] = ">HO00064\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		ASSERT_EQ(((SetAngleHomeValueCommand*)command)->getSubCommandType(),
				SetterCommand::SET_ANGLE_HOME_VALUE);
	}

	TEST_F(ParserControllerSetterCommandTest, setHomeValueWrongCommandLengthLess){
		char message [] = ">HO0004\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerSetterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerSetterCommandTest, setHomeValueWrongCommandLengthMore){
		char message [] = ">HO0005564\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerSetterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerSetterCommandTest, setHomeValueDeviceId){
		char message [] = "<HO00064\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int deviceId =((SetAngleHomeValueCommand*)command)->getDeviceId();
		ASSERT_EQ(deviceId, 0);
	}

	TEST_F(ParserControllerSetterCommandTest, setHomeValueValue){
		char message [] = "<HO00064\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int deviceId = ((SetAngleHomeValueCommand*)command)->getValue();
		ASSERT_EQ(deviceId, 100);
	}


	TEST_F(ParserControllerSetterCommandTest, setMaxValueCommandType){
		char message [] = ">MA00001\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::SETTER_COMMAND);
	}

	TEST_F(ParserControllerSetterCommandTest, setMaxValueSubCommandType){
		char message [] = ">MA00064\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		ASSERT_EQ(((SetAngleMaxValueCommand*)command)->getSubCommandType(),
				SetterCommand::SET_ANGLE_MAX_VALUE);
	}

	TEST_F(ParserControllerSetterCommandTest, setMaxValueWrongCommandLengthLess){
		char message [] = ">MA0004\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerSetterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerSetterCommandTest, setMaxValueWrongCommandLengthMore){
		char message [] = ">MA0005564\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerSetterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerSetterCommandTest, setMaxValueDeviceId){
		char message [] = ">MA00064\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int deviceId = ((SetAngleMaxValueCommand*)command)->getDeviceId();
		ASSERT_EQ(deviceId, 0);
	}

	TEST_F(ParserControllerSetterCommandTest, setMaxValueValue){
		char message [] = ">MA00064\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int value = ((SetAngleMaxValueCommand*)command)->getValue();
		ASSERT_EQ(value, 100);
	}

	TEST_F(ParserControllerSetterCommandTest, setMinValueCommandType){
		char message [] = ">MI00001\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::SETTER_COMMAND);
	}

	TEST_F(ParserControllerSetterCommandTest, setMinValueSubCommandType){
		char message [] = ">MI00001\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		ASSERT_EQ(((SetMinValueCommand*)command)->getSubCommandType(),
				SetterCommand::SET_ANGLE_MIN_VALUE);
	}

	TEST_F(ParserControllerSetterCommandTest, setMinValueWrongCommandLengthLess){
		char message [] = ">MI0004\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerSetterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerSetterCommandTest, setMinValueWrongCommandLengthMore){
		char message [] = ">MI0005564\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerSetterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerSetterCommandTest, setMinValueDeviceId){
		char message [] = "<MI00001\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int deviceId = ((SetMinValueCommand*)command)->getDeviceId();
		ASSERT_EQ(deviceId, 0);
	}

	TEST_F(ParserControllerSetterCommandTest, setMinValueValue){
		char message [] = ">MI00001\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int value = ((SetMinValueCommand*)command)->getValue();
		ASSERT_EQ(value, 1);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionFrameCommandType){
		char message [] = ">MF000000640000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::SETTER_COMMAND);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionFrameSubCommandType){
		char message [] = ">MF000000640000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		ASSERT_EQ(((SetAngleHomeValueCommand*)command)->getSubCommandType(),
				SetterCommand::SET_MOTION_FRAME);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionFrameWrongCommandLengthLess){
		char message [] = ">MF000000640000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff00ffff0000ffff0000ffff0000ffff0000ffff\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerSetterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionFrameWrongCommandLengthMore){
		char message [] = ">MF000000640000ffff0000ffff0000ffffffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerSetterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionFrameSlotValue){
		char message [] = ">MF010000640000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int slotValue = ((SetMotionFrameCommand*)command)->getMotionFrame()->getHeaderPosition();
		ASSERT_EQ(slotValue, 1);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionFrameFrameIdValue){
		char message [] = ">MF010500640000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int frameIndex = ((SetMotionFrameCommand*)command)->getMotionFrame()->getFramePosition();
		ASSERT_EQ(frameIndex, 5);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionFrameTransitionTimeValue){
		char message [] = ">MF010500640000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int transitionTime = ((SetMotionFrameCommand*)command)->getMotionFrame()->getTransitionTime();
		ASSERT_EQ(transitionTime, 100);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionFrameValue){
		char message [] = ">MF010500640000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff0000ffff\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int* jointAngle = ((SetMotionFrameCommand*)command)->getMotionFrame()->getJointAngle();
		for(int i = 0; i < NUMBER_OF_JOINTS/2; i=i+2){
			ASSERT_EQ(jointAngle[i], 0);
			ASSERT_EQ(jointAngle[i+1], -1);
		}
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderCommandType){
		char message [] = ">MH01Test                1000103132002\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		ASSERT_EQ(command->getCommandType(), CommandInterface::SETTER_COMMAND);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderSubCommandType){
		char message [] = ">MH00Test                1000103132002\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		ASSERT_EQ(((SetAngleHomeValueCommand*)command)->getSubCommandType(),
				SetterCommand::SET_MOTION_HEADER);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderWrongCommandLengthLess){
		char message [] = ">MH00Test                100010313200\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerSetterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderWrongCommandLengthMore){
		char message [] = ">MH00Test                10001031320025555\r";
		populateBuffer(message);
		ASSERT_EQ(parserControllerSetterCommand->parse(buffer, &command),
				ParserInterface::WRONG_LENGHT_COMMAND_ERROR);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderSlotValue){
		char message [] = ">MH01Test                1000103132002\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int positionValue = ((SetMotionHeaderCommand*)command)->getMotionHeader()->getPosition();
		ASSERT_EQ(positionValue, 1);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderNameValue){
		char message [] = ">MH01Test                1000103132002\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		char* motionName = ((SetMotionHeaderCommand*)command)->getMotionHeader()->getMotionName();
		ASSERT_STREQ( motionName, "Test                ");
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderUseLoopValue){
		char message [] = ">MH01Test                1000103132002\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		bool useLoop = ((SetMotionHeaderCommand*)command)->getMotionHeader()->useLoop();
		ASSERT_TRUE(useLoop);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderLoopBeginValue){
		char message [] = ">MH01Test                1"
				"01"
				"01"
				"03"
				"132002\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int loopBegin = ((SetMotionHeaderCommand*)command)->getMotionHeader()->getLoopBeginFrame();
		ASSERT_EQ(loopBegin, 1);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderLoopEndValue){
		char message [] = ">MH01Test                1010103132002\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int loopEnd = ((SetMotionHeaderCommand*)command)->getMotionHeader()->getLoopEndFrame();
		ASSERT_EQ(loopEnd, 1);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderLoopCountValue){
		char message [] = ">MH01Test                1010103132002\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int loopCount = ((SetMotionHeaderCommand*)command)->getMotionHeader()->getLoopCount();
		ASSERT_EQ(loopCount, 3);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderUseJumpValue){
		char message [] = ">MH01Test                1"
				"01"
				"01"
				"03"
				"1"
				"32"
				"0"
				"02\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		bool useJump = ((SetMotionHeaderCommand*)command)->getMotionHeader()->useJump();
		ASSERT_TRUE(useJump);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderJumpSlotValue){
		char message [] = ">MH01Test                1"
						"01"
						"01"
						"03"
						"1"
						"32"
						"002\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int jumpSlot = ((SetMotionHeaderCommand*)command)->getMotionHeader()->getJumpPosition();
		ASSERT_EQ(jumpSlot, 50);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderUseExtraValue){
		char message [] = ">MH01Test                1"
					"01"
					"01"
					"03"
					"1"
					"32"
					"1"
					"02\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		bool useExtra = ((SetMotionHeaderCommand*)command)->getMotionHeader()->useExtra();
		ASSERT_TRUE(useExtra);
	}

	TEST_F(ParserControllerSetterCommandTest, setMotionHeaderFrameLengthValue){
		char message [] = ">MH01Test                1"
						"01"
						"01"
						"03"
						"1"
						"32"
						"1"
						"02\r";
		populateBuffer(message);
		parserControllerSetterCommand->parse(buffer, &command);
		int frameLength = ((SetMotionHeaderCommand*)command)->getMotionHeader()->getMotionFrameLength();
		ASSERT_EQ(frameLength, 2);
	}
}

#endif /* TEST_PLENLIBRARY_LOGIC_CONTROLLER_PARSER_PARSERCONTROLLERSETTERCOMMANDTEST_CPP_ */
