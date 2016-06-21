// waterbottle erbottlewat

#include <stdio.h>
#define MAXIS 256

char src[MAXIS + 1];
char tar[MAXIS + 1];
char concatSrc[2 * MAXIS + 1];

static void 
clearMemory()
{
	for (int i = 0; i < MAXIS + 1; i++)
		src[i] = tar[i] = 0;
	for (int j = 0; j < 2 * MAXIS + 1; j++)
		concatSrc[j] = 0;
}

static int 
search2(const char *src, const char *tar, int src_len, int tar_len)
{
	int flag;
	int i, j;
	for (i = 0; i <= src_len - tar_len; i++) {
		for (j = i; j < i + tar_len; j++) {
			flag = 1;
			if (src[j] != tar[j - i]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	return flag;
}

static bool
isRotation(const char *src, const char *tar)
{
	int i, j;
	size_t len1, len2, len3;
	for (len1 = 0; src[len1]; len1++);
	for (len2 = 0; tar[len2]; len2++);

	if (len1 == 0 || len1 != len2)
		return false;
	// make src doubled
	int concatStr_idx = 0;
	for (i = 0; i < 2; i++)
		for (j = 0; j < len1; j++)
			concatSrc[concatStr_idx++] = src[j];
	for (len3 = 0; concatSrc[len3]; len3++);

	int loc;
	loc = search2(concatSrc, tar, len3, len2);
	if (loc == 1) return true;
	else return false;
}

int main()
{
	freopen("check_rotation_strings.txt", "r", stdin);
	setbuf(stdout, NULL);
	
	int T;
	scanf("%d", &T);
	
	while (T--) {
		// inputs:
		scanf("%s %s", src, tar);
		printf("Inputs: %s %s\n", src, tar);
		// solve&outputs:
		if (isRotation(src, tar))
			printf("Yes! %s is rotation of %s.\n", tar, src);
		else
			printf("No! %s is not rotation of %s.\n", tar, src);
		// clear memory
		clearMemory();
	}
	
	return 0;
}
