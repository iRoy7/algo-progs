/*
http://swlock.blogspot.kr/2016/05/blog-post.html
동전 거스름돈 구하기(전체탐색으로)
여기에서는 전체 탐색을 어떤 식으로 하는지에 대한 설명를 하도록 하겠습니다.

[질문] 아래 동전 종류가 있을때 최소의 거스름돈 갯수는 몇개일까?
동전 종류:1원,5원,10원,16원
거스름돈:20원

일반적으로 접근을 하자면 전체탐색은 부분집합,순열,조합 3가지중에 하나라고 생각하면 됩니다.

[순열]은
집합에서 순서가 다르게 끄집에 내는 경우, 
1,5,10,16 이란 집합에서 1,5,10,16, 과 5,1,10,16 ??? 이런식으로 순서를 바꿔서 꺼내는 가지수가 다른경우로 인식하기 때문에 해당문제와는 관계가 없습니다.

다음으로,
[조합]의 경우 순서에는 관계가 없으므로 4C2 라고 하면 4개중에 2개를 고르는 방법이 됩니다. 
4C1 이면 4개 중에 1개를 고르는 방법이고요, 최종 결과 20이 되려면 몇개를 골라야할지 모르기 때문에 조합 문제도 아닙니다.

마지막으로
남은 [부분집합]은 몇개를 골라서 집합을 만드는겁니다. 
1,5 고르고 1,10,16도 골라보고... 이게 20원이 되는지 보는 겁니다.

여기에도 문제는 있습니다.
동전 종류가 하나씩만 쓸 수 있으면 부분 집합 문제일 수 있는데 5,5,5,5,5 등으로 무한정으로 사용할 수 있기 때문입니다.
다시 문제로 돌아가서 1,1,1,1,1,1,5,5,5,5,5,5,10,10,10,10,10,16,16 이런식으로 많다고 문제를 바꿔 놓고 문제를 풀면 될 것입니다.
*/

#include <stdio.h>
#define INT_MAX 2147483647

int data[10] = { 16, 1, 10, 5 };
int sel[100];
int selCnt = 0;
int N = 4;
int P = 20;

/* No Prunning */
int pwrSet1(int depth, int starti, int sum)
{
	int i;

	if (sum > P) 
	{
		return 0;
	}
	if (sum == P)
	{
		for (i = 0; i < selCnt; i++)
		{
			printf("%d ", sel[i]);
		}
		printf("\n");
		return 0;
	}

	for (i = starti; i < N; i++)
	{
		sel[selCnt] = data[i];
		sum = sum + data[i];
		selCnt++;
		pwrSet1(depth + 1, i, sum);
		selCnt--;
		sum = sum - data[i];
	}

	return 0;
}

/* Prunning */
int minCnt = INT_MAX;
int pwrSet2(int depth, int starti, int sum)
{
	int i;
	
	if (sum > P || minCnt <= selCnt)
	{
		return 0;
	}

	if (sum == P)
	{
		for (i = 0; i < selCnt; i++)
		{
			printf("%d ", sel[i]);
		}
		printf("\n");
		minCnt = selCnt;
		return 0;
	}

	// Object Code here:
	for (i = starti; i < N; i++)
	{
		sel[selCnt] = data[i];
		sum = sum + data[i];
		selCnt++;
		pwrSet2(depth + 1, i, sum);
		selCnt--;
		sum = sum - data[i];
	}
		
	return 0;
}

int main()
{
	printf("pwrSet:(No Prunning)\n");
	pwrSet1(0, 0, 0);

	printf("\n");

	printf("pwrSet: Prunning\n");
	selCnt = 0;
	pwrSet2(0, 0, 0);
	return 0;
}
