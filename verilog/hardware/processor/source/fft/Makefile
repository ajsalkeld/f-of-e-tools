TREEROOT	= ../../../../../
include $(TREEROOT)/tools/sunflower/conf/setup.conf

TARGET-ARCH	= riscv32-elf
TARGET		= riscv

PROGRAM		= fft-rc
PROGRAM-SF	= fft-rc-sf
INIT		= init
INIT-SF		= init-sf

OPTFLAGS	= -O0
CFLAGS		= -march=rv32imfd -mabi=ilp32d $(TARGET-ARCH-FLAGS) -Wall
ASFLAGS		= --march=rv32imfd --mabi=ilp32d
LDFLAGS		= -L$(TOOLSLIB)/$(TARGET) -Map $(PROGRAM).map -Tsail.ld
LDFLAGS-SF	= -Ttext $(LOADADDR-SF)  -L$(TOOLSLIB)/$(TARGET) -Map $(PROGRAM-SF).map
SREC2HEX	= srec2hex
LOADADDR-SF	= 0x08004000

OBJS		=\
		$(INIT).o\
		$(PROGRAM).o\

OBJS-SF		=\
		$(INIT-SF).o\
		$(PROGRAM).o\

all:	$(PROGRAM) $(PROGRAM).sr $(PROGRAM-SF) $(PROGRAM-SF).sr Makefile

$(INIT).o: $(INIT).S
	$(AS) $(ASFLAGS) $(INIT).S -o $(INIT).o

$(PROGRAM): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@ -lc -lm -lgcc 

$(PROGRAM).sr:$(PROGRAM)
	$(OBJCOPY) -O srec $(PROGRAM) $@

$(PROGRAM).o: $(PROGRAM).c Makefile
	$(CC) $(CFLAGS) $(OPTFLAGS) -c $(PROGRAM).c 


$(INIT-SF).o: $(INIT-SF).S
	$(CPP) $(INIT-SF).S > $(INIT-SF).i --specs=nosys.specs; $(AS) $(ASFLAGS) $(INIT-SF).i -o $(INIT-SF).o

$(PROGRAM-SF): $(OBJS-SF)
	$(LD) $(LDFLAGS-SF) $(OBJS-SF) -o $@ -lc -lm -lgcc -lgloss

$(PROGRAM-SF).sr:$(PROGRAM-SF)
	$(OBJCOPY) -O srec $(PROGRAM-SF) $@

install: all
	$(SREC2HEX) -b 4096 $(PROGRAM).sr
	cp program.hex ../../programs
	cp data.hex ../../programs

clean:
	$(RM) init.i *.o $(PROGRAM) $(PROGRAM).sr $(PROGRAM).map
	$(RM) init-sf.i *.o $(PROGRAM-SF) $(PROGRAM-SF).sr $(PROGRAM-SF).map
	$(RM) program.hex data.hex
