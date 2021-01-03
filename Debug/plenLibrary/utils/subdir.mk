################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/utils/Logger.cpp \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/utils/ParserUtils.cpp 

OBJS += \
./plenLibrary/utils/Logger.o \
./plenLibrary/utils/ParserUtils.o 

CPP_DEPS += \
./plenLibrary/utils/Logger.d \
./plenLibrary/utils/ParserUtils.d 


# Each subdirectory must supply rules for building sources it contributes
plenLibrary/utils/Logger.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/utils/Logger.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

plenLibrary/utils/ParserUtils.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/utils/ParserUtils.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


