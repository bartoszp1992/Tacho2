################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Buttons/buttons.c 

OBJS += \
./Buttons/buttons.o 

C_DEPS += \
./Buttons/buttons.d 


# Each subdirectory must supply rules for building sources it contributes
Buttons/buttons.o: ../Buttons/buttons.c Buttons/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Buttons/buttons.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

