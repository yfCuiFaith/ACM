#include<cstdio>
#include<algorithm>
using namespace std;

struct arc
{
	int e,w;
};

int record[10000];
int N(0), M(0), K(0);

int cmp(const void *a, const void *b)
{
	arc *x = (arc*)a, *y = (arc*)b;
	if(x->e != y->e)
		return y->e - x->e;
	return y->w - x->w;
}

int lowbit(int x)
{
	return x & (-x);
}

int get_sum(int n)
{
	int sum = 0;
	while(n > 0)
	{
		sum += record[n];
		n -= lowbit(n);
	}
	return sum;
}

void update(int n)
{
	while(n <= M)
	{
		record[n] += 1;
		n += lowbit(n);
	}
}

int main()
{
	int T(0);
	long long res(0);
	arc shw[1000010];
	
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		scanf("%d %d %d", &N, &M, &K);
		for(int j = 0; j < K; j++)
			scanf("%d %d", &shw[j].e, &shw[j].w);
		qsort(shw, K, sizeof(arc), cmp);
		
		for(int j = 1; j <= M; j++)
			record[j] = 0;
		
		res = 0;
		for(int j = 0; j < K; j++)
		{
			res += get_sum(shw[j].w - 1);
			update(shw[j].w);
		}
		
		printf("Test case %d: %I64d\n", i, res);
	}
	return 0;
}

