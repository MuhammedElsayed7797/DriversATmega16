################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EEPROM_24C512/EEPROM_24C512.c 

OBJS += \
./EEPROM_24C512/EEPROM_24C512.o 

C_DEPS += \
./EEPROM_24C512/EEPROM_24C512.d 


# Each subdirectory must supply rules for building sources it contributes
EEPROM_24C512/%.o: ../EEPROM_24C512/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


