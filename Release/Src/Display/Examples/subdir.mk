################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Display/Examples/EPD_1in54_V2_test.c \
../Src/Display/Examples/ImageData.c 

OBJS += \
./Src/Display/Examples/EPD_1in54_V2_test.o \
./Src/Display/Examples/ImageData.o 

C_DEPS += \
./Src/Display/Examples/EPD_1in54_V2_test.d \
./Src/Display/Examples/ImageData.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Display/Examples/EPD_1in54_V2_test.o: ../Src/Display/Examples/EPD_1in54_V2_test.c Src/Display/Examples/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Display/Examples/EPD_1in54_V2_test.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/Display/Examples/ImageData.o: ../Src/Display/Examples/ImageData.c Src/Display/Examples/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Display/Examples/ImageData.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

