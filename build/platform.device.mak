TOOLCHAIN ?= arm-gcc
USE_LIBA = 1
EXE = elf
EPSILON_BOOT_PROMPT = none

EPSILON_DEVICE_BENCH ?= 1
SFLAGS += -DEPSILON_DEVICE_BENCH=$(EPSILON_DEVICE_BENCH)

python/port/port.o: CXXFLAGS += -DMP_PORT_USE_STACK_SYMBOLS=1
