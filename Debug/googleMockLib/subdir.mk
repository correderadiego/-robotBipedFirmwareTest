################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../googleMockLib/gmock-gtest-all.cc 

CC_DEPS += \
./googleMockLib/gmock-gtest-all.d 

OBJS += \
./googleMockLib/gmock-gtest-all.o 


# Each subdirectory must supply rules for building sources it contributes
googleMockLib/%.o: ../googleMockLib/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


