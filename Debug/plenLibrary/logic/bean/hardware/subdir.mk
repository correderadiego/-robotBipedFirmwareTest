################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/hardware/Buffer.cpp \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/hardware/Eyes.cpp \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/hardware/Joint.cpp \
/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/hardware/Led.cpp 

OBJS += \
./plenLibrary/logic/bean/hardware/Buffer.o \
./plenLibrary/logic/bean/hardware/Eyes.o \
./plenLibrary/logic/bean/hardware/Joint.o \
./plenLibrary/logic/bean/hardware/Led.o 

CPP_DEPS += \
./plenLibrary/logic/bean/hardware/Buffer.d \
./plenLibrary/logic/bean/hardware/Eyes.d \
./plenLibrary/logic/bean/hardware/Joint.d \
./plenLibrary/logic/bean/hardware/Led.d 


# Each subdirectory must supply rules for building sources it contributes
plenLibrary/logic/bean/hardware/Buffer.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/hardware/Buffer.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

plenLibrary/logic/bean/hardware/Eyes.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/hardware/Eyes.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

plenLibrary/logic/bean/hardware/Joint.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/hardware/Joint.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

plenLibrary/logic/bean/hardware/Led.o: /home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary/logic/bean/hardware/Led.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/ziash/workspaceMiniPlen/MiniplenTest/googleMockLib" -I"/home/ziash/workspaceMiniPlen/MiniplenTest/mockLibrary" -I"/home/ziash/workspaceMiniPlen/MiniPlen/src/plenLibrary" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


