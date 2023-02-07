################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/HAL/Sev_Seg/Sev_Seg.c 

OBJS += \
./SRC/HAL/Sev_Seg/Sev_Seg.o 

C_DEPS += \
./SRC/HAL/Sev_Seg/Sev_Seg.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/HAL/Sev_Seg/%.o: ../SRC/HAL/Sev_Seg/%.c SRC/HAL/Sev_Seg/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


