################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/binary_tree_v1.cpp \
../src/same_tree.cpp 

OBJS += \
./src/binary_tree_v1.o \
./src/same_tree.o 

CPP_DEPS += \
./src/binary_tree_v1.d \
./src/same_tree.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++11 -D__GXX_EXPERIMENTAL_CXX0X__ -I"C:\Users\Rich\Documents\OneDrive\FACA\code\misc\Cpp" -I"C:\Users\Rich\Documents\OneDrive\FACA\code\misc\Cpp\header" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

