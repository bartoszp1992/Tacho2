################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/buttons.c \
../Src/interface.c \
../Src/main.c \
../Src/rtc.c \
../Src/sensing.c \
../Src/settings.c \
../Src/stm32g0xx_hal_msp.c \
../Src/stm32g0xx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32g0xx.c \
../Src/timers.c 

OBJS += \
./Src/buttons.o \
./Src/interface.o \
./Src/main.o \
./Src/rtc.o \
./Src/sensing.o \
./Src/settings.o \
./Src/stm32g0xx_hal_msp.o \
./Src/stm32g0xx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32g0xx.o \
./Src/timers.o 

C_DEPS += \
./Src/buttons.d \
./Src/interface.d \
./Src/main.d \
./Src/rtc.d \
./Src/sensing.d \
./Src/settings.d \
./Src/stm32g0xx_hal_msp.d \
./Src/stm32g0xx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32g0xx.d \
./Src/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32G071xx -c -I../Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/buttons.d ./Src/buttons.o ./Src/interface.d ./Src/interface.o ./Src/main.d ./Src/main.o ./Src/rtc.d ./Src/rtc.o ./Src/sensing.d ./Src/sensing.o ./Src/settings.d ./Src/settings.o ./Src/stm32g0xx_hal_msp.d ./Src/stm32g0xx_hal_msp.o ./Src/stm32g0xx_it.d ./Src/stm32g0xx_it.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o ./Src/system_stm32g0xx.d ./Src/system_stm32g0xx.o ./Src/timers.d ./Src/timers.o

.PHONY: clean-Src

