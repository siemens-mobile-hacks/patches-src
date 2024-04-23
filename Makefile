CFLAGS = -I "../sdk/dietlibc/include" -I "../sdk/swilib/include/"

define gcc
	arm-none-eabi-gcc -mcpu=arm926ej-s -std=gnu99 -Os -mthumb-interwork -msoft-float -mlittle-endian -c $(CFLAGS) $(1) patch.c -o patch.o
endef

define ld
	arm-none-eabi-ld -zmax-page-size=1 patch.o -o patch.elf -T $(1).ld
endef

define obj
	arm-none-eabi-objcopy -O binary patch.elf patch.bin
	cat patch.bin | xxd -ps -c 200
endef

e71_45:
	$(call gcc,-DNEWSGOLD -DELKA -DE71_45)
	$(call ld,E71_45)
	$(call obj)

clean:
	rm -f patch.o patch.elf patch.bin
