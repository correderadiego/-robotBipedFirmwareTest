################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/MainTest.cpp 

OBJS += \
./test/MainTest.o 

CPP_DEPS += \
./test/MainTest.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/test/plenLibrary/mock" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


