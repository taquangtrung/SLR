################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SPASS/alarm.c \
../SPASS/analyze.c \
../SPASS/approx.c \
../SPASS/clause.c \
../SPASS/clock.c \
../SPASS/closure.c \
../SPASS/cnf.c \
../SPASS/component.c \
../SPASS/condensing.c \
../SPASS/context.c \
../SPASS/defs.c \
../SPASS/dfgparser.c \
../SPASS/dfgscanner.c \
../SPASS/doc-proof.c \
../SPASS/eml.c \
../SPASS/flags.c \
../SPASS/foldfg.c \
../SPASS/graph.c \
../SPASS/hash.c \
../SPASS/hasharray.c \
../SPASS/iaparser.c \
../SPASS/iascanner.c \
../SPASS/kbo.c \
../SPASS/list.c \
../SPASS/memory.c \
../SPASS/misc.c \
../SPASS/options.c \
../SPASS/order.c \
../SPASS/partition.c \
../SPASS/proofcheck.c \
../SPASS/ras.c \
../SPASS/renaming.c \
../SPASS/resolution.c \
../SPASS/rpos.c \
../SPASS/rules-inf.c \
../SPASS/rules-red.c \
../SPASS/rules-sort.c \
../SPASS/rules-split.c \
../SPASS/rules-ur.c \
../SPASS/search.c \
../SPASS/sharing.c \
../SPASS/sort.c \
../SPASS/st.c \
../SPASS/stack.c \
../SPASS/strings.c \
../SPASS/subst.c \
../SPASS/subsumption.c \
../SPASS/symbol.c \
../SPASS/table.c \
../SPASS/tableau.c \
../SPASS/term.c \
../SPASS/terminator.c \
../SPASS/top.c \
../SPASS/unify.c \
../SPASS/vector.c 

OBJS += \
./SPASS/alarm.o \
./SPASS/analyze.o \
./SPASS/approx.o \
./SPASS/clause.o \
./SPASS/clock.o \
./SPASS/closure.o \
./SPASS/cnf.o \
./SPASS/component.o \
./SPASS/condensing.o \
./SPASS/context.o \
./SPASS/defs.o \
./SPASS/dfgparser.o \
./SPASS/dfgscanner.o \
./SPASS/doc-proof.o \
./SPASS/eml.o \
./SPASS/flags.o \
./SPASS/foldfg.o \
./SPASS/graph.o \
./SPASS/hash.o \
./SPASS/hasharray.o \
./SPASS/iaparser.o \
./SPASS/iascanner.o \
./SPASS/kbo.o \
./SPASS/list.o \
./SPASS/memory.o \
./SPASS/misc.o \
./SPASS/options.o \
./SPASS/order.o \
./SPASS/partition.o \
./SPASS/proofcheck.o \
./SPASS/ras.o \
./SPASS/renaming.o \
./SPASS/resolution.o \
./SPASS/rpos.o \
./SPASS/rules-inf.o \
./SPASS/rules-red.o \
./SPASS/rules-sort.o \
./SPASS/rules-split.o \
./SPASS/rules-ur.o \
./SPASS/search.o \
./SPASS/sharing.o \
./SPASS/sort.o \
./SPASS/st.o \
./SPASS/stack.o \
./SPASS/strings.o \
./SPASS/subst.o \
./SPASS/subsumption.o \
./SPASS/symbol.o \
./SPASS/table.o \
./SPASS/tableau.o \
./SPASS/term.o \
./SPASS/terminator.o \
./SPASS/top.o \
./SPASS/unify.o \
./SPASS/vector.o 

C_DEPS += \
./SPASS/alarm.d \
./SPASS/analyze.d \
./SPASS/approx.d \
./SPASS/clause.d \
./SPASS/clock.d \
./SPASS/closure.d \
./SPASS/cnf.d \
./SPASS/component.d \
./SPASS/condensing.d \
./SPASS/context.d \
./SPASS/defs.d \
./SPASS/dfgparser.d \
./SPASS/dfgscanner.d \
./SPASS/doc-proof.d \
./SPASS/eml.d \
./SPASS/flags.d \
./SPASS/foldfg.d \
./SPASS/graph.d \
./SPASS/hash.d \
./SPASS/hasharray.d \
./SPASS/iaparser.d \
./SPASS/iascanner.d \
./SPASS/kbo.d \
./SPASS/list.d \
./SPASS/memory.d \
./SPASS/misc.d \
./SPASS/options.d \
./SPASS/order.d \
./SPASS/partition.d \
./SPASS/proofcheck.d \
./SPASS/ras.d \
./SPASS/renaming.d \
./SPASS/resolution.d \
./SPASS/rpos.d \
./SPASS/rules-inf.d \
./SPASS/rules-red.d \
./SPASS/rules-sort.d \
./SPASS/rules-split.d \
./SPASS/rules-ur.d \
./SPASS/search.d \
./SPASS/sharing.d \
./SPASS/sort.d \
./SPASS/st.d \
./SPASS/stack.d \
./SPASS/strings.d \
./SPASS/subst.d \
./SPASS/subsumption.d \
./SPASS/symbol.d \
./SPASS/table.d \
./SPASS/tableau.d \
./SPASS/term.d \
./SPASS/terminator.d \
./SPASS/top.d \
./SPASS/unify.d \
./SPASS/vector.d 


# Each subdirectory must supply rules for building sources it contributes
SPASS/%.o: ../SPASS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


