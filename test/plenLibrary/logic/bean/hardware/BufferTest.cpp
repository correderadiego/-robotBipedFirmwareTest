/*
 * BufferTest.cpp
 *
 *  Created on: 19 abr. 2020
 *      Author: Diego
 */

#include "gtest/gtest.h"
#include <string.h>
#include "logic/bean/hardware/Buffer.h"

namespace {
	class BufferTest : public ::testing::Test {
	protected:
		Buffer* buffer;

		void populateBuffer(char message[]){
			buffer = new Buffer();
			for (int i = 0; i < (int)strlen(message); i++) {
				buffer->addChar(message[i]);
			}
		}

	    void TearDown() {
	      buffer->clearBuffer();
	      delete buffer;
	    }
	};

	TEST_F(BufferTest, messageLength){
		char message [] = "$an0a3e258sdaa";
		populateBuffer(message);
		ASSERT_EQ(buffer->getLenght(), (int)strlen(message));
	}

	TEST_F(BufferTest, clearBufferLenght){
		char message [] = "$an0a3e258sdaa\r";
		populateBuffer(message);
		buffer->clearBuffer();
		ASSERT_EQ(buffer->getLenght(),0);
	}

	TEST_F(BufferTest, clearBufferCommandComplete){
		char message [] = "$an0a3e258sdaa\r";
		populateBuffer(message);
		buffer->clearBuffer();
		ASSERT_FALSE(buffer->isCommandComplete());
	}

	TEST_F(BufferTest, clearBufferData){
		char message [] = "$an0a3e258sdaa\r";
		populateBuffer(message);
		buffer->clearBuffer();
		ASSERT_STREQ(buffer->getData(), "");
	}

	TEST_F(BufferTest, addCharData){
		buffer = new Buffer();
		buffer->addChar('a');
		ASSERT_STREQ(buffer->getData(), "a");
	}

	TEST_F(BufferTest, addCharCommandComplete){
		buffer = new Buffer();
		buffer->addChar('a');
		ASSERT_FALSE(buffer->isCommandComplete());
	}

	TEST_F(BufferTest, addCharNoError){
		buffer = new Buffer();
		ASSERT_EQ(buffer->addChar('a'), Buffer::NO_ERROR);
	}

	TEST_F(BufferTest, addCharBufferFullError){
		buffer = new Buffer();
		for (int i = 0; i < BUFFER_SIZE - 1; i++) {
			buffer->addChar('a');
		}
		ASSERT_EQ(buffer->addChar('a'), Buffer::BUFFER_FULL_ERROR);
	}

	TEST_F(BufferTest, commandNotcomplete){
		char message [] = "$an0a3e258sdaa";
		populateBuffer(message);
		ASSERT_FALSE(buffer->isCommandComplete());
	}

	TEST_F(BufferTest, commandComplete){
		char message [] = "$an0a3e258sd\r";
		populateBuffer(message);
		ASSERT_TRUE(buffer->isCommandComplete());
	}

	TEST_F(BufferTest, commandCompleteAditionalCharacters){
		char message [] = "$an0a3\re258sd";
		populateBuffer(message);
		ASSERT_TRUE(buffer->isCommandComplete());
	}

	TEST_F(BufferTest, messageLengthAditionalCharacters){
		char message [] = "$an0a3\re258sd";
		populateBuffer(message);
		ASSERT_EQ(buffer->getLenght(), (int)strlen(message) - 1);
	}
}
