################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/commands/CommandInterface.cpp 

OBJS += \
./plenLibrary/logic/bean/commands/CommandInterface.o 

CPP_DEPS += \
./plenLibrary/logic/bean/commands/CommandInterface.d 


# Each subdirectory must supply rules for building sources it contributes
plenLibrary/logic/bean/commands/CommandInterface.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/commands/CommandInterface.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


