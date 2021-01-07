/*
 * TestBase.cpp
 *
 *  Created on: 4 ene. 2021
 *      Author: ziash
 */

#include "TestBase.h"

TestBase::TestBase() {}

TestBase::~TestBase() {}

void TestBase::initJoint(){
	joint[0] =	new Joint(nullptr,	HOME_POSITION_LEFT_SHOULDER_PITCH, Joint::counterClockWise);
	joint[1] =	new Joint(nullptr,	HOME_POSITION_LEFT_THIGH_YAW);
	joint[2] =  new Joint(nullptr,	HOME_POSITION_LEFT_SHOULDER_ROLL);
	joint[3] =	new Joint(nullptr,	HOME_POSITION_LEFT_ELBOW_ROLL);
	joint[4] =	new Joint(nullptr,	HOME_POSITION_LEFT_THIGH_ROLL);
	joint[5] =	new Joint(nullptr,	HOME_POSITION_LEFT_THIGH_PITCH);
	joint[6] =	new Joint(nullptr,	HOME_POSITION_LEFT_KNEE_PITCH);
	joint[7] =	new Joint(nullptr,	HOME_POSITION_LEFT_FOOT_PITCH);
	joint[8] =	new Joint(nullptr,	HOME_POSITION_LEFT_FOOT_ROLL);
	joint[9] =	new Joint();
	joint[10] =	new Joint();
	joint[11] =	new Joint();
	joint[12] =	new Joint(nullptr,  HOME_POSITION_RIGHT_SHOULDER_PITCH, Joint::counterClockWise);
	joint[13] =	new Joint(nullptr, 	HOME_POSITION_RIGHT_THIGH_YAW);
	joint[14] =	new Joint(nullptr,  HOME_POSITION_RIGHT_SHOULDER_ROLL);
	joint[15] =	new Joint(nullptr, 	HOME_POSITION_RIGHT_ELBOW_ROLL);
	joint[16] =	new Joint(nullptr,  HOME_POSITION_RIGHT_THIGH_ROLL);
	joint[17] =	new Joint(nullptr, 	HOME_POSITION_RIGHT_THIGH_PITCH);
	joint[18] =	new Joint(nullptr, 	HOME_POSITION_RIGHT_KNEE_PITCH);
	joint[19] =	new Joint(nullptr, 	HOME_POSITION_RIGHT_FOOT_PITCH);
	joint[20] =	new Joint(nullptr,  HOME_POSITION_RIGHT_FOOT_ROLL);
	joint[21] =	new Joint();
	joint[22] =	new Joint();
	joint[23] =	new Joint();
}

void TestBase::SetUp(){
	command->setCommandType(CommandInterface::UNKNOWN_COMMAND_TYPE);
	initJoint();

	plen = new Plen(
					joint,
					24,
					nullptr,
					nullptr,
					nullptr,
					fileMotion,
					fileConfiguration,
					fileSystem
				);
}

void TestBase::TearDown() {
	delete plen;

	for (int i = 0; i <= 23; i++) {
		delete joint[i];
	}

	delete command;
	delete motionController;

	delete jointController;
	delete headerController;
	delete frameController;

	delete externalFilesystemController;

	delete fileMotion;
	delete fileConfiguration;
	delete fileSystem;
}


