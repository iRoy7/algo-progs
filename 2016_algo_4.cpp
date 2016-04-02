#include <stdio.h>
#define MAXIS 1000
int n, m, cnt;
int a[MAXIS*MAXIS+1000];
inline void memory_clear() {
  cnt = 0;
  for (int i = 0; i < (MAXIS*MAXIS)+1000; i++)
    a[i] = 0;
}
int main() {
  int i, j;
  setbuf(stdout, NULL);
  scanf("%d %d", &n, &m);
  memory_clear();
  for (i = 1; i <= n*m; i+=4)
    a[i]++, a[i+1]++;
  for (i = 1; i <= n*m; i++)
    if (a[i]) cnt++;
  printf("%d\n", cnt);
}
