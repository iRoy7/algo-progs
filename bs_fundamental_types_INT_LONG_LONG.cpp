/*
C++
- Char Size: 1 byte
- Integer Size: 4 bytes
- Long Size: 4 bytes
- Long Long: 8 bytes

INTEGER:
============================
INT_MAX: (1 << 31) - 1
INT_MIN: (1 << 31)
UINT: (1 << 62) -1
----------------------------

LONG LONG:
===========================
LONG_MAX: (1LL << 63) - 1
LONG_MIN: (1LL << 63)
ULONG: (1LL << 126) - 1
----------------------------
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	printf("- Char Size = %d byte\n", sizeof(char));
	printf("- Integer Size = %d bytes\n", sizeof(int));
	printf("- Long Size = %d bytes\n", sizeof(long));
	printf("- Long Long = %d bytes\n", sizeof(long long));
	printf("\n");
	// INTEGER
	printf("INTEGER:\n");
	printf("========================================\n");

	int a = 2147483647;
	unsigned int ua = 0xFFFFFFFFui32;
	// signed
	printf("Signed:%d\n", a);
	// unsigned : %u or %ud
	printf("Unsigned: %u\n", ua);

	// INT_MAX 2147483647
	printf("INT_MAX: (1 << 31)-1 = %d\n", (1 << 31) - 1);
	// INT_MIN -2147483648
	printf("INT_MIN: (1 << 31) = %d\n", (1 << 31));
	// unsigned
	printf("UINT: (1 << 62) - 1 = %u\n", (unsigned int)(1 << 62) - 1);

	printf("----------------------------------------\n\n");

	// LONG LONG
	printf("LONG LONG:\n");
	printf("========================================\n");
	long long x = 9223372036854775807;
	unsigned long long ux = 0xFFFFFFFFFFFFFFFFui64;
	// signed
	printf("Signed: %lld\n", x);
	// unsigned : %llu or %llud
	printf("Unsigned: %llu\n", ux);

	long long A = (1LL << 63);
	// LONG_MAX 9223372036854775807
	printf("LONG_MAX: (1LL << 63) - 1 = %lld\n", A - 1);
    // LONG_MIN -9223372036854775808
	printf("LONG_MIN: (1LL << 63) = %lld\n", A);
	// unsigned
	unsigned long long uA = (1LL << 126);
	printf("ULONG: (1LL << 126) - 1 = %llu\n", uA - 1);
	
	return 0;
}
