################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Display/e-Paper/EPD_1in54_V2.c 

OBJS += \
./Src/Display/e-Paper/EPD_1in54_V2.o 

C_DEPS += \
./Src/Display/e-Paper/EPD_1in54_V2.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Display/e-Paper/%.o: ../Src/Display/e-Paper/%.c Src/Display/e-Paper/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-Display-2f-e-2d-Paper

clean-Src-2f-Display-2f-e-2d-Paper:
	-$(RM) ./Src/Display/e-Paper/EPD_1in54_V2.d ./Src/Display/e-Paper/EPD_1in54_V2.o

.PHONY: clean-Src-2f-Display-2f-e-2d-Paper

