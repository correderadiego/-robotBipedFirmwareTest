################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/plenLibrary/logic/controller/parser/ParserControllerControllerCommandTest.cpp \
../test/plenLibrary/logic/controller/parser/ParserControllerGetterCommandTest.cpp \
../test/plenLibrary/logic/controller/parser/ParserControllerInterpreterCommandTest.cpp \
../test/plenLibrary/logic/controller/parser/ParserControllerSetterCommandTest.cpp \
../test/plenLibrary/logic/controller/parser/ParserControllerTest.cpp 

OBJS += \
./test/plenLibrary/logic/controller/parser/ParserControllerControllerCommandTest.o \
./test/plenLibrary/logic/controller/parser/ParserControllerGetterCommandTest.o \
./test/plenLibrary/logic/controller/parser/ParserControllerInterpreterCommandTest.o \
./test/plenLibrary/logic/controller/parser/ParserControllerSetterCommandTest.o \
./test/plenLibrary/logic/controller/parser/ParserControllerTest.o 

CPP_DEPS += \
./test/plenLibrary/logic/controller/parser/ParserControllerControllerCommandTest.d \
./test/plenLibrary/logic/controller/parser/ParserControllerGetterCommandTest.d \
./test/plenLibrary/logic/controller/parser/ParserControllerInterpreterCommandTest.d \
./test/plenLibrary/logic/controller/parser/ParserControllerSetterCommandTest.d \
./test/plenLibrary/logic/controller/parser/ParserControllerTest.d 


# Each subdirectory must supply rules for building sources it contributes
test/plenLibrary/logic/controller/parser/%.o: ../test/plenLibrary/logic/controller/parser/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/test/plenLibrary/mock" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


