// wasi_stubs.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
// Stub for proc_exit, which exits the program with a specific code
void w2c_wasi__snapshot__preview1_proc_exit(int32_t code) {
    clock_t end;
    end = clock();
    printf("end: %ld\n", end);
    printf("proc_exit called!\n");
    exit(0);  // Exit with the provided code
}

// Stub for fd_write, which typically writes to a file descriptor
int32_t w2c_wasi__snapshot__preview1_fd_write(
    int32_t fd,           // File descriptor
    const void *iovs,     // Pointer to the data to write
    int32_t iovs_len,     // Length of data
    int32_t *nwritten     // Number of bytes written
) {
    printf("fd_write called\n");
    *nwritten = iovs_len;  // Pretend all bytes were written
    return 0;              // Return 0 to indicate success
}
