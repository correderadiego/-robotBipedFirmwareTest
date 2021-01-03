################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include test/plenLibrary/logic/utils/subdir.mk
-include test/plenLibrary/logic/controller/process/subdir.mk
-include test/plenLibrary/logic/controller/parser/subdir.mk
-include test/plenLibrary/logic/controller/subdir.mk
-include test/plenLibrary/logic/bean/hardware/subdir.mk
-include test/subdir.mk
-include plenLibrary/utils/subdir.mk
-include plenLibrary/logic/controller/process/subdir.mk
-include plenLibrary/logic/controller/parser/subdir.mk
-include plenLibrary/logic/controller/subdir.mk
-include plenLibrary/logic/bean/motion/subdir.mk
-include plenLibrary/logic/bean/hardware/subdir.mk
-include plenLibrary/logic/bean/commands/setterCommands/subdir.mk
-include plenLibrary/logic/bean/commands/interpreterCommands/subdir.mk
-include plenLibrary/logic/bean/commands/getterCommands/subdir.mk
-include plenLibrary/logic/bean/commands/controllerCommands/subdir.mk
-include plenLibrary/logic/bean/commands/subdir.mk
-include plenLibrary/logic/bean/subdir.mk
-include mockLibrary/hardware/controller/subdir.mk
-include mockLibrary/hardware/bean/subdir.mk
-include googleMockLib/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: MiniplenTest

# Tool invocations
MiniplenTest: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++  -o "MiniplenTest" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(INO_DEPS)$(PDE_DEPS)$(C_DEPS)$(CPP_DEPS) MiniplenTest
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
