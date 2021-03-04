msb.s : msb
	objdump -dSl msb >msb.s

gdb : msb
	gdb -ex "set disassemble-next-line on" -ex "break main" -ex "run" --args ./msb 14

test : msb
	./msb 14
	
msb : msb.c
	gcc -O0 -g -m32 -Wall -std=c11 -o msb msb.c
	
clean :
	-rm msb msb.s
