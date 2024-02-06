# $@ = target file
# $< = first dependency
# $^ = all dependencies

GDB = /opt/homebrew/bin/i386-elf-gdb
QEMU = /opt/homebrew/bin/qemu-system-i386
CC = /opt/homebrew/bin/i686-elf-gcc
NASM = /opt/homebrew/bin/nasm

all: pre run

pre:
	mkdir -p bin

bin/kernel.o: src/kernel/kernel.c src/kernel/sys.c src/kernel/vga.c src/kernel/gdt.c
	${CC} -c -g -O0 $< -o $@ -std=gnu99 -ffreestanding -Wall -Wextra -nostdlib

# sys.o: sys.c sys.h
# 	i686-elf-gcc -c -g -O0 $< -o $@ -std=gnu99 -ffreestanding -Wall -Wextra -nostdlib

# vga.o: vga.c sys.h
# 	i686-elf-gcc -c -g -O0 $< -o $@ -std=gnu99 -ffreestanding -Wall -Wextra -nostdlib


bin/myos.bin: bin/boot.o bin/kernel.o src/kernel/linker.ld
	${CC} -T src/kernel/linker.ld -o bin/myos.bin -ffreestanding -O2 -nostdlib bin/boot.o bin/kernel.o -lgcc 
	

bin/boot.o: src/kernel/boot.s
	nasm -f elf32 src/kernel/boot.s -o bin/boot.o

run: bin/myos.bin
	${QEMU} -kernel bin/myos.bin

debug: bin/myos.bin 
	${QEMU} -s -S -kernel bin/myos.bin & 
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file bin/myos.bin"

clean:
	rm -rf bin
