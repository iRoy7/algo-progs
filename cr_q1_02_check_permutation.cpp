#include <stdio.h>
char pairs[2][128];
int letters[128];
int n;
inline void clear_mem();
inline bool permutation(char *s, char *t)
{
	int i, j, len1, len2;
	
	for (len1 = 0; s[len1]; len1++);
	for (len2 = 0; t[len2]; len2++);
	if (len1 != len2) return false;

	for (i = 0; i < len1; i++) {
		int c = s[i] - 'a';
		letters[c]++;
	}
	for (j = 0; j < len2; j++) {
		int c = t[j] - 'a';
		letters[c]--;
		if (letters[c] < 0)
			return false;
	}
	return true;
}
int main()
{
	freopen("check_permutation.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &n);
	while (n--) {
		scanf("%s %s", &pairs[0], &pairs[1]);
		bool anagram = permutation(pairs[0], pairs[1]);
		printf("%s, %s: %d\n", pairs[0], pairs[1], anagram);
		clear_mem();
	}
}
inline void clear_mem()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 128; j++)
			pairs[i][j] = 0;
	for (int k = 0; k < 128; k++)
		letters[k] = 0;
}
