################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/plenLibrary/logic/bean/hardware/BufferTest.cpp \
../test/plenLibrary/logic/bean/hardware/JointTest.cpp 

OBJS += \
./test/plenLibrary/logic/bean/hardware/BufferTest.o \
./test/plenLibrary/logic/bean/hardware/JointTest.o 

CPP_DEPS += \
./test/plenLibrary/logic/bean/hardware/BufferTest.d \
./test/plenLibrary/logic/bean/hardware/JointTest.d 


# Each subdirectory must supply rules for building sources it contributes
test/plenLibrary/logic/bean/hardware/BufferTest.o: ../test/plenLibrary/logic/bean/hardware/BufferTest.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"test/plenLibrary/logic/bean/hardware/BufferTest.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

test/plenLibrary/logic/bean/hardware/%.o: ../test/plenLibrary/logic/bean/hardware/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


