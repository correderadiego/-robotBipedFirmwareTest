################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/motion/Frame.cpp \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/motion/Header.cpp \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/motion/Motion.cpp 

OBJS += \
./plenLibrary/logic/bean/motion/Frame.o \
./plenLibrary/logic/bean/motion/Header.o \
./plenLibrary/logic/bean/motion/Motion.o 

CPP_DEPS += \
./plenLibrary/logic/bean/motion/Frame.d \
./plenLibrary/logic/bean/motion/Header.d \
./plenLibrary/logic/bean/motion/Motion.d 


# Each subdirectory must supply rules for building sources it contributes
plenLibrary/logic/bean/motion/Frame.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/motion/Frame.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

plenLibrary/logic/bean/motion/Header.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/motion/Header.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

plenLibrary/logic/bean/motion/Motion.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/motion/Motion.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


