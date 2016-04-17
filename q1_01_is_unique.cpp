// Assumes only letters a through z.
#include <stdio.h>
#define MAXIS 512
char str[MAXIS + 1];
int n, len;
inline void clear_mem();
inline bool is_uniq_chars(char *str, int len)
{
	if (len > 26) return false; // only 26 characters
	int checker = 0;
	for (int i = 0; i < len; i++) {
		int val = str[i] - 'a';
		// check의 val bit가 켜져있는지?
		if ((checker & (1ull << val)) > 0) return false;
		// 원소추가: bit turn on
		checker |= (1ull << val);
	}
	return true;
}
int main()
{
	freopen("words.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &n);
	while (n--) {
		scanf("%s", str);
		for (len = 0; str[len]; len++);
		printf("%d\n", is_uniq_chars(str, len));
		clear_mem();
	}
}
inline void clear_mem()
{
	for (int i = 0; i < MAXIS + 1; i++)
		str[i] = 0;
}
