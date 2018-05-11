CC=msp430-gcc
#CC=msp430-elf-gcc

SIZER=msp430-size
DEVICE=msp430g2553
DEVICE=msp430f2012
FILE=main

ifeq ($(CC),msp430-elf-gcc)
	CFLAGS=-Os -Wall -g -mmcu=$(DEVICE) -I /home/chetan/ti/gcc/include -L /home/chetan/ti/gcc/include -Wl,-Map="$(FILE).map"
else
	CFLAGS=-Os -Wall -g -mmcu=$(DEVICE) -Wl,-Map="$(FILE).map",--cref
endif


#OBJS=main.o nokia_lcd.o
OBJS=main.o


all: $(OBJS)
	$(CC) $(CFLAGS) -o $(FILE).elf $(OBJS)
	$(SIZER) $(FILE).elf

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr $(FILE).elf $(FILE).map $(OBJS)
