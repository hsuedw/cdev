PWD := $(shell pwd)
KVERSION := $(shell uname -r)
KERNELDIR ?= /usr/src/linux-headers-$(KVERSION)/
 

MODULE_NAME = cdev

obj-m := $(MODULE_NAME).o
 

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
