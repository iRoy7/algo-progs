#include <stdio.h>
#include <time.h>
#define PMAXIS 1000000
#define NMAXIS 10
#define NP 10
int not_primes[PMAXIS];
char Str[NMAXIS];
char subStr[NMAXIS];
inline void clear_memory();
inline bool check_SN(int drop_idx, int len)
{
	int h, i, j, k, l, m;
	// generate sub SN candidate after removing the number at drop index
	for (int idx = 0, h = 0; h < len; h++)
		if (h != drop_idx) subStr[idx] = Str[h], idx++;
	printf("sub str = %s\n", subStr);
	// first prime:
	char first[NP];
	int fp[NP];
	int f_idx = 0, fp_cnt = 0;
	for (i = 0; i < len - 3; i++, f_idx++) {
		int a;
		first[f_idx] = subStr[i];
		sscanf(first, "%d", &a);
		if (!not_primes[a]) {
			printf("1st prime: %d\n", a);
			fp[fp_cnt++] = i;
		}
	}
	if (fp_cnt < 1) return false;
	// second prime:
	char second[NP];
	int sp[NP];
	int sp_cnt = 0;
	for (j = 0; j < fp_cnt; j++) {
		for (m = 0; m < NP; m++) second[m] = 0;
		int s_idx = 0;
		if (subStr[fp[j] + 1] == '0') break;
		for (k = fp[j] + 1; k < len - 2; k++, s_idx++) {
			int b;
			second[s_idx] = subStr[k];
			sscanf(second, "%d", &b);
			if (!not_primes[b]) {
				printf("2nd prime: %d\n", b);
				sp[sp_cnt++] = k;
			}
		}
	}
	if (sp_cnt < 1) return false;
	// thrid prime:
	char third[NP+1];
	int tp[NP+1];
	int tp_cnt = 0;
	for (k = 0; k < sp_cnt; k++) {
		for (m = 0; m < NP; m++) third[m] = 0;
		int t_idx = 0;
		if (subStr[sp[k] + 1] == '0') break;
		for (l = sp[k] + 1; l < len; l++, t_idx++) 
			third[t_idx] = subStr[l];
		int c;
		sscanf(third, "%d", &c);
		if (!not_primes[c]) {
			printf("3rd prime: %d\n", c);
			return true;
		}
	}
	return false;
}
int main()
{
	int T, tc, i, j;
	setbuf(stdout, NULL);
	// generate not primes:
	clock_t start_p, end_p;
	start_p = clock();
	not_primes[0] = 1;
	not_primes[1] = 1;
	for (i = 2; i*i <= PMAXIS; i++) {
		if (!not_primes[i]) {
			for (j = i*i; j <= PMAXIS; j += i)
				not_primes[j] = 1;
		}
	}
	end_p = clock();
	printf("... speed: %f sec.\n", ((double)(end_p - start_p) / CLOCKS_PER_SEC));

	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		// inputs:
		scanf("%s", Str);
		int Str_len = 0;
		for (i = 0; Str[i]; i++) Str_len++;
		// solve:
		bool valid = false;
		for (j = 0; j < Str_len; j++) 
			if (valid = check_SN(j, Str_len))
				break;
		// outputs:
		printf("#%d ", tc);
		(valid) ? printf("1\n") : printf("0\n");
		// clear memory
		clear_memory();
	}
	return 0;
}
inline void clear_memory()
{
	for (int i = 0; i < NMAXIS; i++)
		Str[i] = subStr[i] = 0;
}
