################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/DAC/DAC_cfg.c \
../src/HAL/DAC/DAC_prg.c 

OBJS += \
./src/HAL/DAC/DAC_cfg.o \
./src/HAL/DAC/DAC_prg.o 

C_DEPS += \
./src/HAL/DAC/DAC_cfg.d \
./src/HAL/DAC/DAC_prg.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/DAC/%.o: ../src/HAL/DAC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g -DNDEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


