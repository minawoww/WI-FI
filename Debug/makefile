################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Module_1.lss \

FLASH_IMAGE += \
Module_1.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Module_1.elf secondary-outputs

# Tool invocations
Module_1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Module_1.map -L"C:\Workspace2\Module_1\Lib" -XlinkerC:\Workspace2\Module_1\Lib -mmcu=atmega32 -o "Module_1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Module_1.lss: Module_1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Module_1.elf  >"Module_1.lss"
	@echo 'Finished building: $@'
	@echo ' '

Module_1.hex: Module_1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Module_1.elf  "Module_1.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Module_1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Module_1.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Module_1.elf
	@echo 'Invoking: AVRDude'
	E:\programs\Embedded software prog\IMT_SDK_Win_32\IMT_SDK_Win_32\WinAVR\bin\avrdude -pm32 -cusbasp -Uflash:w:Module_1.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Module_1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
