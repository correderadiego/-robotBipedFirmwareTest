/*
 * ExternalFsController.cpp
 *
 *  Created on: 17 mar. 2020
 *      Author: Diego
 */

#include <hardware/controller/ExternalFileSystemController.h>

/*
 * ExternalFsController.cpp
 *
 *  Created on: 17 mar. 2020
 *      Author: Diego
 */

#include <hardware/controller/ExternalFileSystemController.h>

ExternalFileSystemController::ExternalFileSystemController() {}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::initExternalFileSystemController(){
	return NO_ERROR;
}

void ExternalFileSystemController::createAndResetFile(
								File* file,
								const char* filePath,
								int fileSize,
								unsigned char* buf,
								int bufferSize){
}

void ExternalFileSystemController::createFile(
								File* file,
								const char* filePath,
								int fileSize,
								unsigned char* buf,
								int bufferSize){

}

void ExternalFileSystemController::initFile(File* file){
}

void ExternalFileSystemController::writeMinAngle(Plen* plen, Joint* joint){
}

void ExternalFileSystemController::writeMaxAngle(File* fileConfiguration, Joint* joint){
}

void ExternalFileSystemController::writeHomeAngle(File* fileConfiguration, Joint* joint){
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::readAccesPointNamePassword(
	File* fileConfiguration, char* apName, char* password){
	return NO_ERROR;
}

bool ExternalFileSystemController::isFileInitiated(Plen* plen, File* file){
	return false;
}

void ExternalFileSystemController::initFileConfiguration(Plen* plen){
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::read(
								unsigned int startAddress,
								unsigned int size,
								unsigned char data[],
								int* sizeRead,
								File* file
							){

	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::write(
								unsigned int startAddress,
								unsigned int size,
								const unsigned char data[],
								unsigned int* sizeWrite,
								File* file
							){

	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::readByte(
											unsigned int startAddress,
											unsigned char* data,
											File* file
										){
	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::writeByte(
											unsigned int startAddress,
											unsigned char data,
											unsigned int sizeWrite,
											File* file
										){

	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::readSlot(
									unsigned int  slot,
									unsigned char data[],
									unsigned char readSize,
									File* file
								){
	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors ExternalFileSystemController::writeSlot(
									unsigned int  slot,
									const unsigned char data[],
									unsigned char writeSize,
									File* file
								){

	return NO_ERROR;
}
