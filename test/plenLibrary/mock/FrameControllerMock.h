/*
 * FrameControllerMock.h
 *
 *  Created on: 16 ago. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_MOCK_FRAMECONTROLLERMOCK_H_
#define TEST_PLENLIBRARY_MOCK_FRAMECONTROLLERMOCK_H_

#include "gmock/gmock.h"

#include "logic/controller/FrameController.h"

class FrameControllerMock : public FrameController {
 public:
	// TODO set proper input
	FrameControllerMock() : FrameController(NULL) {}
  MOCK_METHOD(FrameControllerErrors, set, (File* fileMotion, Frame* frame), (override));
  MOCK_METHOD(FrameControllerErrors, get, (File* fileMotion, Frame* frame), (override));
  MOCK_METHOD(void, dumpFrame, (Frame* frame), (override));
  MOCK_METHOD(int, getPosition, (int frame, int framePosition), (override));
};

#endif /* TEST_PLENLIBRARY_MOCK_FRAMECONTROLLERMOCK_H_ */
