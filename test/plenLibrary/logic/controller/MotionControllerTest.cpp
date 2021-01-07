/*
 * PlenControllerTest.cpp
 *
 *  Created on: 26 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_CONTROLLER_MOTIONCONTROLLERTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_CONTROLLER_MOTIONCONTROLLERTEST_CPP_

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "logic/bean/motion/Motion.h"
#include "logic/controller/MotionController.h"
#include "FrameControllerMock.h"
#include "HeaderControllerMock.h"

namespace {
	class MotionControllerTest : public ::testing::Test{
	protected:

		MotionController *motionController;
		FrameControllerMock frameControllerMock;
		HeaderControllerMock headerControllerMock;

		void SetUp(){
			motionController = new MotionController(
					&headerControllerMock,
					&frameControllerMock,
					NULL,
					NULL);
		}

		void TearDown() {
			delete motionController;
		}
	};

	TEST_F(MotionControllerTest, updateFrameExecutingPosition){
			Header* header = new Header();
			header->setLoopBeginFrame(0);
			header->setLoopEndFrame(3);
			Frame* frame[7] = {};
			Motion* motion = new Motion(header, frame);
			motion->setFrameExecutingPosition(0);

			motionController->updateLoopFrameExecutingPosition(motion);
			ASSERT_TRUE(1 == motion->getFrameExecutingPosition());
			delete motion;
	}

	TEST_F(MotionControllerTest, setHeader){
		File* file = new File();
		Header* header = new Header();
		header->setLoopBeginFrame(0);
		header->setLoopEndFrame(3);
		EXPECT_CALL(headerControllerMock, set(file, header)).Times(1);

		motionController->setHeader(file, header);
		delete header;
		delete file;
	}

	TEST_F(MotionControllerTest, setFrame){
		File* file = new File();
		Frame* frame = new Frame();
		EXPECT_CALL(frameControllerMock, set(file, frame)).Times(1);
		motionController->setFrame(file, frame);
		delete frame;
		delete file;
	}

	TEST_F(MotionControllerTest, executeMotionNullMotion){
		MotionController::MotionControllerErrors motionControllerError =
				motionController->executeMotion(nullptr, nullptr, 0, nullptr);
		ASSERT_EQ(motionControllerError, MotionController::NO_ERROR_NO_MOTION_TO_EXECUTE);
	}

	TEST_F(MotionControllerTest, executeMotionNullFile){
		Header* header = new Header();
		Frame* frame[7] = {};
		Motion* motion = new Motion(header, frame);

		MotionController::MotionControllerErrors motionControllerError =
				motionController->executeMotion(motion, nullptr, 0, nullptr);
		ASSERT_EQ(motionControllerError, MotionController::UNKNOWN_FILE_ERROR);
		delete motion;
	}
}

#endif /* TEST_PLENLIBRARY_LOGIC_CONTROLLER_MOTIONCONTROLLERTEST_CPP_ */
