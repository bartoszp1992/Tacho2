################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Display/DEV_Config.c \
../Src/Display/EPD_1in54_V2.c \
../Src/Display/GUI_Paint.c 

OBJS += \
./Src/Display/DEV_Config.o \
./Src/Display/EPD_1in54_V2.o \
./Src/Display/GUI_Paint.o 

C_DEPS += \
./Src/Display/DEV_Config.d \
./Src/Display/EPD_1in54_V2.d \
./Src/Display/GUI_Paint.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Display/%.o: ../Src/Display/%.c Src/Display/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -DUSE_FULL_LL_DRIVER -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-Display

clean-Src-2f-Display:
	-$(RM) ./Src/Display/DEV_Config.d ./Src/Display/DEV_Config.o ./Src/Display/EPD_1in54_V2.d ./Src/Display/EPD_1in54_V2.o ./Src/Display/GUI_Paint.d ./Src/Display/GUI_Paint.o

.PHONY: clean-Src-2f-Display

