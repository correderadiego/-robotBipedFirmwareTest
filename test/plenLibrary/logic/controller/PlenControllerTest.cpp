/*
 * PlenControllerTest.cpp
 *
 *  Created on: 26 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_PLENCONTROLLERTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_PLENCONTROLLERTEST_CPP_

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <logic/bean/commands/CommandInterface.h>
#include <logic/bean/commands/controllerCommands/ApplyHomePositionCommand.h>
#include <logic/controller/process/ProcessController.h>
#include <logic/controller/parser/ParserController.h>
#include <logic/bean/commands/controllerCommands/ControllerCommand.h>
#include <logic/bean/commands/controllerCommands/ApplyNativeValueCommand.h>
#include <logic/controller/PlenController.h>

namespace {
	class PlenControllerTest : public ::testing::Test{
	protected:
		CommandInterface* command = 0;
		ExternalFileSystemController* externalFileSystemController = new ExternalFileSystemController();
		JointController* jointController =  new JointController(nullptr, externalFileSystemController);
		HeaderController* headerController = new HeaderController(externalFileSystemController);
		FrameController* frameController = new FrameController(externalFileSystemController);
		MotionController* motionController = new MotionController(headerController, frameController, externalFileSystemController, jointController);
		ProcessController* processController =
				new ProcessController(jointController, motionController);
		Joint* joint[24] = {};
		Plen* plen;

		Buffer* buffer;
		ParserController* parserController = new ParserController();

		void populateBuffer(char message[]){
			for (int i = 0; i < (int)strlen(message); i++) {
				buffer->addChar(message[i]);
			}
		}

		void SetUp(){
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
			buffer = new Buffer();
		}

		void TearDown() {
			buffer->clearBuffer();
			delete buffer;

			for (int i = 0; i <= 23; i++) {
				delete joint[i];
			}

			delete plen;
			delete parserController;
			delete processController;
			delete motionController;

			delete jointController;
			delete headerController;
			delete frameController;
			delete externalFileSystemController;
			// TODO
			//delete command;
		}
	};

	TEST_F(PlenControllerTest, correctMatch){
		char message [] = ">MI00010\r";
		populateBuffer(message);
		if(parserController->parse(buffer, &command) == ParserInterface::NO_ERROR){
			processController->process(plen, command);
		}
	}

	TEST_F(PlenControllerTest, setHeader){
			char message [] = ">MH00Test                1000103132002\r";
			populateBuffer(message);
			if(parserController->parse(buffer, &command) == ParserInterface::NO_ERROR){
				processController->process(plen, command);
			}
	}

	TEST_F(PlenControllerTest, moveJoint){
		Interpreter* interpreter 				= new Interpreter();
		LedController* ledController			= new LedController();
		EyeController* eyeController			= new EyeController(ledController);

		PlenController* plenController  = new PlenController(
				jointController,
				motionController,
				interpreter,
				eyeController,
				externalFileSystemController,
				parserController,
				processController);
		// todo
		//Joint *joint = new Joint(new PCA9685PwmPin(PIN_LEFT_KNEE_PITCH), HOME_POSITION_LEFT_KNEE_PITCH);
		Joint *joint = new Joint(nullptr, HOME_POSITION_LEFT_KNEE_PITCH);
		joint->setEnabled(true);
		joint->setAngle(400);
		plenController->jointController->moveJoint(joint);

		delete interpreter;
		delete ledController;
		delete eyeController;
		delete plenController;
		delete joint;
	}

}

#endif /* TEST_PLENLIBRARY_LOGIC_CONTROLLER_PLENCONTROLLERTEST_CPP_ */
