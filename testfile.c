#include <stdio.h>
#include <cpuid.h>
#include <stdint.h>

int
main(int argc, char **argv)
{
 uint32_t eax, ebx, ecx, edx;
 uint64_t var;
 __cpuid(0x4fffffff,eax , ebx, ecx, edx);

 var = (uint64_t)(((uint64_t)ebx << 32) | (uint64_t)ecx);
 printf("\nCPUID(0x4fffffff), exits=%d, cycles spent in exit=%ld \n\n", eax,var);

 return 0;
}
