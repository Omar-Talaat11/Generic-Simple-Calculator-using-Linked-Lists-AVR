################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Functions.c \
../gpio.c \
../keypad.c \
../lcd.c \
../linked_list.c \
../main.c 

OBJS += \
./Functions.o \
./gpio.o \
./keypad.o \
./lcd.o \
./linked_list.o \
./main.o 

C_DEPS += \
./Functions.d \
./gpio.d \
./keypad.d \
./lcd.d \
./linked_list.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


