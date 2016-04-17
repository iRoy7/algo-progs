#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_N 1000000
unsigned char sieve[(MAX_N + 7) / 8];
inline bool isPrime(int k) {
	return sieve[k >> 3] & (1 << (k & 7));
}
inline void setComposite(int k) {
	sieve[k >> 3] &= ~(1 << (k & 7));
}
int main()
{
	int i, j, k;
	memset(sieve, 255, sizeof(sieve));
	// generate not primes:
	clock_t start_p, end_p;
	start_p = clock();
	setComposite(0);
	setComposite(1);
	for (i = 2; i*i <= MAX_N; i++) {
		if (isPrime(i))
			for (j = i*i; j <= MAX_N; j += i)
				setComposite(j);
	}
	end_p = clock();
	printf("... speed: %f sec.\n", ((double)(end_p - start_p) / CLOCKS_PER_SEC));
#if 0
	for (k = 0; k <= MAX_N; k++)
		if (isPrime(k))
			printf("%d\n", k);
#endif
	return 0;
}
