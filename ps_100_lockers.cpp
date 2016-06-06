#include <stdio.h>

int main()
{
#if 1
	bool is_opened[100] = { false };

	// do the 100 passes
	for (int pass = 0; pass < 100; ++pass)
		for (int door = pass; door < 100; door += pass + 1)
			is_opened[door] = !is_opened[door];

	// outputs the result
	for (int door = 0; door < 100; ++door)
		printf("door#%d %s\n", door + 1, (is_opened[door]) ? "is open." : "is closed.");
#endif

	// optimized
	for (int i = 1; (i*i) <= 100; i++)
		printf("Door %d is open!\n", (i*i));

	return 0;
}
