################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Settings/settings.c 

OBJS += \
./Src/Settings/settings.o 

C_DEPS += \
./Src/Settings/settings.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Settings/settings.o: ../Src/Settings/settings.c Src/Settings/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Settings/settings.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

