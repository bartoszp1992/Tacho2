################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Display/Fonts/font12.c \
../Src/Display/Fonts/font12CN.c \
../Src/Display/Fonts/font16.c \
../Src/Display/Fonts/font20.c \
../Src/Display/Fonts/font24.c \
../Src/Display/Fonts/font24CN.c \
../Src/Display/Fonts/font8.c 

OBJS += \
./Src/Display/Fonts/font12.o \
./Src/Display/Fonts/font12CN.o \
./Src/Display/Fonts/font16.o \
./Src/Display/Fonts/font20.o \
./Src/Display/Fonts/font24.o \
./Src/Display/Fonts/font24CN.o \
./Src/Display/Fonts/font8.o 

C_DEPS += \
./Src/Display/Fonts/font12.d \
./Src/Display/Fonts/font12CN.d \
./Src/Display/Fonts/font16.d \
./Src/Display/Fonts/font20.d \
./Src/Display/Fonts/font24.d \
./Src/Display/Fonts/font24CN.d \
./Src/Display/Fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Display/Fonts/%.o: ../Src/Display/Fonts/%.c Src/Display/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-Display-2f-Fonts

clean-Src-2f-Display-2f-Fonts:
	-$(RM) ./Src/Display/Fonts/font12.d ./Src/Display/Fonts/font12.o ./Src/Display/Fonts/font12CN.d ./Src/Display/Fonts/font12CN.o ./Src/Display/Fonts/font16.d ./Src/Display/Fonts/font16.o ./Src/Display/Fonts/font20.d ./Src/Display/Fonts/font20.o ./Src/Display/Fonts/font24.d ./Src/Display/Fonts/font24.o ./Src/Display/Fonts/font24CN.d ./Src/Display/Fonts/font24CN.o ./Src/Display/Fonts/font8.d ./Src/Display/Fonts/font8.o

.PHONY: clean-Src-2f-Display-2f-Fonts

