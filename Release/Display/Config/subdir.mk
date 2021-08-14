################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Display/Config/DEV_Config.c 

OBJS += \
./Display/Config/DEV_Config.o 

C_DEPS += \
./Display/Config/DEV_Config.d 


# Each subdirectory must supply rules for building sources it contributes
Display/Config/DEV_Config.o: ../Display/Config/DEV_Config.c Display/Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Display/Config/DEV_Config.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

