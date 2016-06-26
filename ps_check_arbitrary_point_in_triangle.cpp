/*
point A, B, C:
triangle extent
 /\ ABC = 1/2 * | x1 * (y2-y3) + x2 * (y3-y1) + x3 * (y1-y2) |

A = total triangle extent
arbitrary point (x, y)

A1 = sub triangle extent with (x, y)
A2 = sub triangle extent with (x, y)
A3 = sub triangle extent with (x, y)

If A - (A1+A2+A3) == 0,
 the point (x, y) lies in triangle.

*/

#include <stdio.h>

inline float
ABS(float a) { return (a > 0.0) ? a : (-a); }

inline float
tri_extent(int x1, int y1, int x2, int y2, int x3, int y3)
{
	// area formula of triangles via 3 points
	return ABS(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;
}

int main()
{
	setbuf(stdout, NULL);

	int T, tc, x1, x2, x3, y1, y2, y3, x, y;
	scanf("%d", &T);

	for (tc = 1; tc <= T; tc++)
	{
		float A, A1, A2, A3;

		scanf("%d%d %d%d %d%d", &x1, &y1, &x2, &y2, &x3, &y3);
		scanf("%d%d", &x, &y);

		A = tri_extent(x1, y1, x2, y2, x3, y3);
		A1 = tri_extent(x1, y1, x2, y2, x, y);
		A2 = tri_extent(x1, y1, x, y, x3, y3);
		A3 = tri_extent(x, y, x2, y2, x3, y3);

		if ((A - (A1 + A2 + A3)) == 0.0)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
