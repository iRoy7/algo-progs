// Interesting digits from TOPCODER
// constraints:
// base: 3 <= base <= 30
// max digits: 3
// 21 * 2 = 42
// 4+2 % 2 = 0

#include <stdio.h>

int main()
{
	int T, base, n;
	int k1, k2, k3;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	while (T--) 
	{
		scanf("%d", &base);
#if 0 // approach 1
		for (n = 2; n < base; n++)
		{
			bool ok = true;
			for (k1 = 0; k1 < base; k1++)
			{
				for (k2 = 0; k2 < base; k2++)
				{
					for (k3 = 0; k3 < base; k3++)
					{
						if ((k1 + k2*base + k3*base*base) % n == 0
							&& (k1 + k2 + k3) % n != 0)
						{
							ok = false;
							break;
						}
					}
					if (!ok) break;
				}
				if (!ok) break;
			}
			if (ok) 
			{
				printf("%d ", n);
			}
		}
		printf("\n");
#else
		for (n = 2; n < base; n++)
			if ((base - 1) % n == 0)
				printf("%d ", n);
		printf("\n");
#endif
	}

	return 0;
}
