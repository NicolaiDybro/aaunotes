#include <stdio.h>

int main() {
    __asm__ (
        "mov $1, %rax\n"
        "mov $0, %rdi\n"
        "syscall\n"
    );
    return 0;
}
