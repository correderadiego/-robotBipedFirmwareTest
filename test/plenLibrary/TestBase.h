/*
 * TestBase.h
 *
 *  Created on: 4 ene. 2021
 *      Author: ziash
 */

#ifndef TEST_PLENLIBRARY_TESTBASE_H_
#define TEST_PLENLIBRARY_TESTBASE_H_

#include "gtest/gtest.h"
#include "logic/bean/hardware/Buffer.h"
#include <logic/bean/commands/CommandInterface.h>
#include "logic/controller/MotionController.h"


class TestBase : public ::testing::Test {
public:
	TestBase();
	virtual ~TestBase();

	void SetUp();
	void TearDown();

protected:
	CommandInterface* command 									= new CommandInterface();
	ExternalFileSystemController* externalFilesystemController 	= new ExternalFileSystemController();
	JointController* jointController 							= new JointController(nullptr, externalFilesystemController);
	HeaderController* headerController 							= new HeaderController(externalFilesystemController);
	FrameController* frameController 							= new FrameController(externalFilesystemController);
	MotionController* 				motionController 			= new MotionController(
			headerController, frameController, externalFilesystemController, jointController);
	Joint* joint[24] = {};
	Plen* plen;
	File* fileMotion 		= new File();
	File* fileConfiguration = new File();
	File* fileSystem 		= new File();

	void initJoint();
};

#endif /* TEST_PLENLIBRARY_TESTBASE_H_ */
