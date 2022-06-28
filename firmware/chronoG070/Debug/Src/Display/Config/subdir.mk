################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Display/Config/DEV_Config.c 

OBJS += \
./Src/Display/Config/DEV_Config.o 

C_DEPS += \
./Src/Display/Config/DEV_Config.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Display/Config/%.o: ../Src/Display/Config/%.c Src/Display/Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-Display-2f-Config

clean-Src-2f-Display-2f-Config:
	-$(RM) ./Src/Display/Config/DEV_Config.d ./Src/Display/Config/DEV_Config.o

.PHONY: clean-Src-2f-Display-2f-Config

