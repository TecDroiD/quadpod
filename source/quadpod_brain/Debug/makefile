################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
quadpod_brain.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: quadpod_brain.elf secondary-outputs

# Tool invocations
quadpod_brain.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,quadpod_brain.map -mmcu=atmega168 -o "quadpod_brain.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

quadpod_brain.lss: quadpod_brain.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S quadpod_brain.elf  >"quadpod_brain.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: quadpod_brain.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega168 quadpod_brain.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) quadpod_brain.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
