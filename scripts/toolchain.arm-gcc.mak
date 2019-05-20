CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
LD = arm-none-eabi-gcc
GDB = arm-none-eabi-gdb
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

# Always generate debug information
SFLAGS += -ggdb3

ifeq ($(DEBUG),1)
LTO ?= 0
else
LTO ?= 1
endif

ifeq ($(LTO),1)
# Use link-time optimization if LTO=1
SFLAGS += -flto
else
# Otherwise, just get rid of unused symbols
SFLAGS += -fdata-sections -ffunction-sections
LDFLAGS += -Wl,--gc-sections
endif

SFLAGS += -mthumb -march=armv7e-m -mfloat-abi=hard -mcpu=cortex-m4 -mfpu=fpv4-sp-d16
LDFLAGS += $(SFLAGS) -lgcc -Wl,-T,$(LDSCRIPT)

# Work around command-line length limit with MSYS2
%.$(EXE):
	$(Q) echo $^ > $@.objs
	@echo "LD      $(@:$(BUILD_DIR)/%=%)"
	$(Q) $(LD) @$@.objs $(LDFLAGS) -o $@
	$(Q) rm $@.objs
