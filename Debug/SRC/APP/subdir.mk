################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/APP/main.c \
../SRC/APP/mainIraqi.c 

OBJS += \
./SRC/APP/main.o \
./SRC/APP/mainIraqi.o 

C_DEPS += \
./SRC/APP/main.d \
./SRC/APP/mainIraqi.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/APP/%.o: ../SRC/APP/%.c SRC/APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


