#ifndef TEST_PLENLIBRARY_MOCK_HEADERCONTROLLERMOCK_H_
#define TEST_PLENLIBRARY_MOCK_HEADERCONTROLLERMOCK_H_

#include "gmock/gmock.h"
#include "logic/controller/HeaderController.h"

class HeaderControllerMock : public HeaderController {
 public:
	HeaderControllerMock() : HeaderController(NULL) {};
  MOCK_METHOD(HeaderControllerErrors, set, (File* fileMotion, Header* header), (override));
  MOCK_METHOD(HeaderControllerErrors, get, (File* fileMotion, Header* header), (override));
  MOCK_METHOD(void, dumpHeader, (Header* header), (override));
};

#endif /* TEST_PLENLIBRARY_MOCK_HEADERCONTROLLERMOCK_H_ */
