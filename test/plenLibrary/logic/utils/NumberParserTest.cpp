/*
 * NumberParserTest.cpp
 *
 *  Created on: 22 abr. 2020
 *      Author: Diego
 */

#ifndef TEST_PLENLIBRARY_LOGIC_UTILS_NUMBERPARSERTEST_CPP_
#define TEST_PLENLIBRARY_LOGIC_UTILS_NUMBERPARSERTEST_CPP_

#include <utils/ParserUtils.h>
#include "gtest/gtest.h"

namespace {
	class NumberParserTest : public ::testing::Test{
	protected:

		void SetUp(){}

	    void TearDown() {}
	};

	TEST_F(NumberParserTest, hexBytesToUintEqual){
		char* message = "0a38e";
		ASSERT_EQ(
				ParserUtils::hexBytesToUint(message,2),
				(unsigned int)10
				);
	}

	TEST_F(NumberParserTest, hexBytesToUintNotEqual){
		char* message = "0a38e";
		ASSERT_NE(
				ParserUtils::hexBytesToUint(message,2),
				(unsigned int)12
				);
	}


	TEST_F(NumberParserTest, hexbytes2intEqual){
		char* message = "0a38e";
				ASSERT_EQ(
						ParserUtils::hexbytes2int(message,2),
						(int)10
						);
	}

	TEST_F(NumberParserTest, hexbytes2intNotEqual){
		char* message = "0a38e";
				ASSERT_NE(
						ParserUtils::hexbytes2int(message,2),
						(int)12
						);
	}
}

#endif /* TEST_PLENLIBRARY_LOGIC_UTILS_NUMBERPARSERTEST_CPP_ */
