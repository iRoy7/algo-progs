#include <stdio.h>
#define MAXIS 512
char str[MAXIS+1];
bool char_set[128];
int n;
inline void clear_mem();
inline bool is_uniq_chars(char *str, int len)
{
	if (len > 128) return false;
	for (int i = 0; i < len; i++) {
		int val = str[i];
		if (char_set[val])
			return false;
		char_set[val] = true;
	}
	return true;
}
int main()
{
	int i, len;
	freopen("words.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &n);
	while (n--) {
		scanf("%s", str);
		printf("%s is unique?(0:false, 1:true): ", str);
		for (len = 0; str[len]; len++);
		printf("length = %d\n", len);
		printf("%d\n", is_uniq_chars(str, len));
		clear_mem();
	}
}
inline void clear_mem()
{
	for (int i = 0; i < MAXIS + 1; i++)
		str[i] = 0;
	for (int j = 0; j < 128; j++)
		char_set[j] = false;
}
