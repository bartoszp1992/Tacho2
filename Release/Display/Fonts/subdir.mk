################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Display/Fonts/font12.c \
../Display/Fonts/font12CN.c \
../Display/Fonts/font16.c \
../Display/Fonts/font20.c \
../Display/Fonts/font24.c \
../Display/Fonts/font24CN.c \
../Display/Fonts/font8.c 

OBJS += \
./Display/Fonts/font12.o \
./Display/Fonts/font12CN.o \
./Display/Fonts/font16.o \
./Display/Fonts/font20.o \
./Display/Fonts/font24.o \
./Display/Fonts/font24CN.o \
./Display/Fonts/font8.o 

C_DEPS += \
./Display/Fonts/font12.d \
./Display/Fonts/font12CN.d \
./Display/Fonts/font16.d \
./Display/Fonts/font20.d \
./Display/Fonts/font24.d \
./Display/Fonts/font24CN.d \
./Display/Fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
Display/Fonts/font12.o: ../Display/Fonts/font12.c Display/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Display/Fonts/font12.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Display/Fonts/font12CN.o: ../Display/Fonts/font12CN.c Display/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Display/Fonts/font12CN.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Display/Fonts/font16.o: ../Display/Fonts/font16.c Display/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Display/Fonts/font16.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Display/Fonts/font20.o: ../Display/Fonts/font20.c Display/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Display/Fonts/font20.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Display/Fonts/font24.o: ../Display/Fonts/font24.c Display/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Display/Fonts/font24.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Display/Fonts/font24CN.o: ../Display/Fonts/font24CN.c Display/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Display/Fonts/font24CN.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Display/Fonts/font8.o: ../Display/Fonts/font8.c Display/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Display/Fonts/font8.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

