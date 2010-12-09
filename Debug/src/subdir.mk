################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CityGMLObject.cpp \
../src/DisplayMode.cpp \
../src/InfoQualitative.cpp \
../src/Information.cpp \
../src/ParsedObject.cpp \
../src/main.cpp 

OBJS += \
./src/CityGMLObject.o \
./src/DisplayMode.o \
./src/InfoQualitative.o \
./src/Information.o \
./src/ParsedObject.o \
./src/main.o 

CPP_DEPS += \
./src/CityGMLObject.d \
./src/DisplayMode.d \
./src/InfoQualitative.d \
./src/Information.d \
./src/ParsedObject.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DUSE_DARWIN_CARBON_IMPLEMENTATION -I/Users/Flo/Dev/OpenSceneGraph-2.9.9/include -I/Users/Flo/Dev/OpenSceneGraph-2.9.9/lib -I/usr/lib -I/usr/include -I/usr/X11 -I/usr/X11/lib -I/usr/local/lib -I/Users/Flo/Dev/OpenSceneGraph-2.9.9/include/osgViewer/api/Carbon -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


