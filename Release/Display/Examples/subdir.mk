################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Display/Examples/EPD_1in54_V2_test.c \
../Display/Examples/ImageData.c 

OBJS += \
./Display/Examples/EPD_1in54_V2_test.o \
./Display/Examples/ImageData.o 

C_DEPS += \
./Display/Examples/EPD_1in54_V2_test.d \
./Display/Examples/ImageData.d 


# Each subdirectory must supply rules for building sources it contributes
Display/Examples/EPD_1in54_V2_test.o: ../Display/Examples/EPD_1in54_V2_test.c Display/Examples/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Display/Examples/EPD_1in54_V2_test.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Display/Examples/ImageData.o: ../Display/Examples/ImageData.c Display/Examples/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Display/Examples/ImageData.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

