################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../DIO_conf.c \
../MOTOR_Confg.c \
../Motor.c \
../main.c \
../uart_driver.c 

OBJS += \
./DIO.o \
./DIO_conf.o \
./MOTOR_Confg.o \
./Motor.o \
./main.o \
./uart_driver.o 

C_DEPS += \
./DIO.d \
./DIO_conf.d \
./MOTOR_Confg.d \
./Motor.d \
./main.d \
./uart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


