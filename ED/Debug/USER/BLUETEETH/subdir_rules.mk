################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
USER/BLUETEETH/%.o: ../USER/BLUETEETH/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/d1550/workspace_v12/ED/ED" -I"C:/Users/d1550/workspace_v12/ED/ED/USER/DELAY" -I"C:/Users/d1550/workspace_v12/ED/ED/USER/KEYBOARD" -I"C:/Users/d1550/workspace_v12/ED/ED/USER/PID" -I"C:/Users/d1550/workspace_v12/ED/ED/USER/OPENMV" -I"C:/Users/d1550/workspace_v12/ED/ED/USER/PRINT" -I"C:/Users/d1550/workspace_v12/ED/ED/USER/SONIC" -I"C:/Users/d1550/workspace_v12/ED/ED/USER/BLUETEETH" -I"C:/Users/d1550/workspace_v12/ED/ED/USER/MOTOR" -I"C:/Users/d1550/workspace_v12/ED/ED/Debug" -I"C:/ti/mspm0_sdk_2_00_00_03/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_00_00_03/source" -gdwarf-3 -MMD -MP -MF"USER/BLUETEETH/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


