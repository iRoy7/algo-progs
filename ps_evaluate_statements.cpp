/*
input:
6
x + 384 = 887
x +30 =200
x+30=200
x+ 5 = 2
x + 10 =20
x  +  12  = 3
========================
output:
503
170
170
-3
10
-9
*/

#include <stdio.h>
#define SZ_STR 128

char str[SZ_STR];
char a_str[10];
char b_str[10];

static void
clear_buf() {
	int i;

	for (i = 0; i < SZ_STR; i++)
		str[i] = 0;
	for (i = 0; i < 10; i++) {
		a_str[i] = b_str[i] = 0;
	}
}

static int
find_value() {
	bool p_flag = false;
	bool e_flag = false;
	int a = 0, b = 0;
	int a_cnt = 0, b_cnt = 0;
	size_t i;

	for (i = 0; str[i]; i++) {
		if (str[i] == '+') 
			p_flag = true;

		if (p_flag && !e_flag) {
			if (str[i] != '+' && str[i] != ' ' && str[i] != '=') {
				a_str[a_cnt++] = str[i];
			}
		}

		if (!e_flag && str[i] == '=') {
			p_flag = false, e_flag = true;
			sscanf(a_str, "%d", &a);
		}

		if (!p_flag && e_flag) {
			if (str[i] != '=' && str[i] != ' ') {
				b_str[b_cnt++] = str[i];
			}
		}
	}

	sscanf(b_str, "%d", &b);

	return (b - a);
}

int main() {
	freopen("statements.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, x;
	scanf("%d", &T);
	
	while (T--) {
		scanf(" %[^\n]\n", str);

		x = 0;
		x = find_value();
		printf("%d\n", x);
		
		clear_buf();
	}

	return 0;
}
