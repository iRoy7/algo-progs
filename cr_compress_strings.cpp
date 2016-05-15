// Compress Strings:
// inputs: aabcccccaaa 
// outputs: a2b1c5a3
#include <stdio.h>
#define SZ_MEMORY 1024
char src[SZ_MEMORY];
char out[SZ_MEMORY];
static bool
compressed(const char *str) {
	size_t i, j, src_len, out_len;
	for (src_len = 0; str[src_len]; src_len++);
	//printf("D1: src_len = %d\n", src_len);
	if (src_len < 2) return false;

	int cnt = 1, out_idx = 0;
	for (i = 1; i < src_len; i++) {
		if (str[i - 1] == str[i])
			++cnt;
		else {
			out[out_idx++] = str[i - 1];
			char s[5];
			sprintf(s, "%d", cnt);
			size_t s_len;
			for (s_len = 0; s[s_len]; s_len++);
			for (j = 0; j < s_len; j++) {
				out[out_idx] = s[j];
				out_idx++;
			}
			cnt = 1;
		}
		for (out_len = 0; out[out_len]; out_len++);
		if (out_len >= src_len) 
			return false;
	}
	out[out_idx++] = str[src_len - 1];
	char ss[5];
	sprintf(ss, "%d", cnt);
	size_t ss_len;
	for (ss_len = 0; ss[ss_len]; ss_len++);
	for (j = 0; j < ss_len; j++) {
		out[out_idx] = ss[j];
		out_idx++;
	}
	for (out_len = 0; out[out_len]; out_len++);
	if (out_len >= src_len)
		return false;

	return true;
}
static void
clear_memory() {
	for (int i = 0; i < SZ_MEMORY; i++)
		src[i] = out[i] = 0;
}
int main() {
	int T, tc;
	freopen("compress_strings.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%s", src);
		printf("source: %s\n", src);
		if (compressed(src))
			printf("compressed: %s\n", out);
		else
			printf("not compressed: %s\n", src);
		clear_memory();
	}
	return 0;
}
