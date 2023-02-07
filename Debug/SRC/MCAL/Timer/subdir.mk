################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/MCAL/Timer/timer.c 

OBJS += \
./SRC/MCAL/Timer/timer.o 

C_DEPS += \
./SRC/MCAL/Timer/timer.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/MCAL/Timer/%.o: ../SRC/MCAL/Timer/%.c SRC/MCAL/Timer/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


