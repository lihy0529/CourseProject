#include <stdio.h>
#include <stdlib.h>

#include "vulnerable.h"

#include <time.h>
struct w2c_host {
  wasm_rt_memory_t memory;
  char* input;
};

/* Accessor to access the memory member of the host */
wasm_rt_memory_t* w2c_host_mem(struct w2c_host* instance) {
  return &instance->memory;
}

int main(int argc, char** argv) {
  /* Initialize the Wasm runtime. */
  // freopen("./memtrace/wasm2c_2.txt", "w", stdout);
  wasm_rt_init();

  /* Declare an instance of the `vulnerable` module. */
  w2c_vulnerable vul;
  
  struct w2c_host host;
  
  wasm_rt_allocate_memory(&host.memory, 1, 1000, false);
  /* Construct the module instance. */
  wasm2c_vulnerable_instantiate(&vul, &host);


  w2c_vulnerable_0x5Fstart(&vul);

  /* Free the fac module. */
  wasm2c_vulnerable_free(&vul);

  /* Free the Wasm runtime state. */
  wasm_rt_free();

  return 0;
}
