/*
 * BufferTest.cpp
 *
 *  Created on: 19 abr. 2020
 *      Author: Diego
 */

#include "gtest/gtest.h"
#include <string.h>
#include "logic/bean/hardware/Joint.h"

namespace {
	class JointTest : public::testing::Test {
	protected:
	};

	TEST_F(JointTest, moveJoint){
		Joint *joint = new Joint(nullptr, HOME_POSITION_LEFT_KNEE_PITCH);
		joint->setEnabled(true);
		joint->setAngle(400);
		delete joint;
	}
}
