################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/commands/interpreterCommands/InterpreterCommand.cpp \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/commands/interpreterCommands/PopAFunctionCommand.cpp \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/commands/interpreterCommands/PushAFunctionCommand.cpp \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/commands/interpreterCommands/ResetInterpreterCommand.cpp 

OBJS += \
./plenLibrary/logic/bean/commands/interpreterCommands/InterpreterCommand.o \
./plenLibrary/logic/bean/commands/interpreterCommands/PopAFunctionCommand.o \
./plenLibrary/logic/bean/commands/interpreterCommands/PushAFunctionCommand.o \
./plenLibrary/logic/bean/commands/interpreterCommands/ResetInterpreterCommand.o 

CPP_DEPS += \
./plenLibrary/logic/bean/commands/interpreterCommands/InterpreterCommand.d \
./plenLibrary/logic/bean/commands/interpreterCommands/PopAFunctionCommand.d \
./plenLibrary/logic/bean/commands/interpreterCommands/PushAFunctionCommand.d \
./plenLibrary/logic/bean/commands/interpreterCommands/ResetInterpreterCommand.d 


# Each subdirectory must supply rules for building sources it contributes
plenLibrary/logic/bean/commands/interpreterCommands/InterpreterCommand.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/commands/interpreterCommands/InterpreterCommand.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

plenLibrary/logic/bean/commands/interpreterCommands/PopAFunctionCommand.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/commands/interpreterCommands/PopAFunctionCommand.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

plenLibrary/logic/bean/commands/interpreterCommands/PushAFunctionCommand.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/commands/interpreterCommands/PushAFunctionCommand.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

plenLibrary/logic/bean/commands/interpreterCommands/ResetInterpreterCommand.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/commands/interpreterCommands/ResetInterpreterCommand.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


