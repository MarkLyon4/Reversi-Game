################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/New\ Reversi.cpp \
../src/ReversiGame.cpp 

OBJS += \
./src/New\ Reversi.o \
./src/ReversiGame.o 

CPP_DEPS += \
./src/New\ Reversi.d \
./src/ReversiGame.d 


# Each subdirectory must supply rules for building sources it contributes
src/New\ Reversi.o: ../src/New\ Reversi.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/New Reversi.d" -MT"src/New\ Reversi.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


