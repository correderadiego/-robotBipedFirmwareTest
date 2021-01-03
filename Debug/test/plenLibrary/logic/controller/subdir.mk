################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/plenLibrary/logic/controller/MotionControllerTest.cpp \
../test/plenLibrary/logic/controller/PlenControllerTest.cpp 

OBJS += \
./test/plenLibrary/logic/controller/MotionControllerTest.o \
./test/plenLibrary/logic/controller/PlenControllerTest.o 

CPP_DEPS += \
./test/plenLibrary/logic/controller/MotionControllerTest.d \
./test/plenLibrary/logic/controller/PlenControllerTest.d 


# Each subdirectory must supply rules for building sources it contributes
test/plenLibrary/logic/controller/%.o: ../test/plenLibrary/logic/controller/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/test/plenLibrary/mock" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


