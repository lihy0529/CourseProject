# # Use implicit rules for compiling C files.
# NOTE: you need to set the environment variable `WASM2C` to the path of the wasm2c binary.

CFLAGS=-I~/workspace/course_project/wabt/wasm2c -pthread -Wno-int-to-pointer-cast
LDLIBS=-lm -pthread -L~/workspace/course_project/wabt/wasm2c

all: vulnerable

clean:
	rm -rf vulnerable vulnerable.wasm vulnerable.c *.o

vulnerable: main.o vulnerable.o ~/workspace/course_project/wabt/wasm2c/wasm-rt-impl.o ~/workspace/course_project/wabt/wasm2c/wasm-rt-mem-impl.o wasi_stubs.c

vulnerable.wasm: vulnerable.wat ~/workspace/course_project/wabt/bin/wat2wasm
	~/workspace/course_project/wabt/bin/wat2wasm $< -o $@

vulnerable.c: vulnerable.wasm ~/workspace/course_project/wabt/bin/wasm2c
	~/workspace/course_project/wabt/bin/wasm2c $< -o $@ --disable-simd

.PHONY: all clean