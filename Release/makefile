################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Timer1/subdir.mk
-include TWI/subdir.mk
-include MCU/subdir.mk
-include ExtInterrupt/subdir.mk
-include EEPROM_24C512/subdir.mk
-include EEPROM/subdir.mk
-include Dio/subdir.mk
-include Application/subdir.mk
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
ATmega16.lss \

FLASH_IMAGE += \
ATmega16.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: ATmega16.elf secondary-outputs

# Tool invocations
ATmega16.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ATmega16.map -mmcu=atmega16 -o "ATmega16.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ATmega16.lss: ATmega16.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ATmega16.elf  >"ATmega16.lss"
	@echo 'Finished building: $@'
	@echo ' '

ATmega16.hex: ATmega16.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ATmega16.elf  "ATmega16.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ATmega16.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 ATmega16.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: ATmega16.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm16 -cusbasp -u -Uflash:w:ATmega16.hex:a -Ulfuse:w:0x6f:m -Uhfuse:w:0xcf:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ATmega16.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
