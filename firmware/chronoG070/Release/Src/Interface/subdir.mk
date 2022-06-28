################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Interface/interface.c 

OBJS += \
./Src/Interface/interface.o 

C_DEPS += \
./Src/Interface/interface.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Interface/%.o: ../Src/Interface/%.c Src/Interface/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-Interface

clean-Src-2f-Interface:
	-$(RM) ./Src/Interface/interface.d ./Src/Interface/interface.o

.PHONY: clean-Src-2f-Interface

