################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TP1.c \
../src/calculos.c \
../src/funciones.c \
../src/menu.c 

C_DEPS += \
./src/TP1.d \
./src/calculos.d \
./src/funciones.d \
./src/menu.d 

OBJS += \
./src/TP1.o \
./src/calculos.o \
./src/funciones.o \
./src/menu.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/TP1.d ./src/TP1.o ./src/calculos.d ./src/calculos.o ./src/funciones.d ./src/funciones.o ./src/menu.d ./src/menu.o

.PHONY: clean-src

