#include <stdio.h>

int count = 0;
/*
* 确定m行n列是否可以安放皇后
*/
int isDanger(int m, int n, int (*chess)[8])
{
	int min;
	//对第m行进行判断
	for (int i = 0; i < 8; i++)
		if (chess[m][i] == 1)
			return 1;
	//对第n列进行判断
	for (int i = 0; i < 8; i++)
		if (chess[i][n] == 1)
			return 1;
	//左上角
	if (m >= n)min = n;
	else min = m;
	for (int i = min; i > 0; i--)
		if (chess[m - i][n - i] == 1)
			return 1;
	//右上角
	if (m >= 7- n)min =7 - n;
	else min = m;
	for (int i = min; i > 0; i--)
		if (chess[m - i][n + i] == 1)
			return 1;
	//右下角
	if (7 - m >= 7 - n)min = 7 - n;
	else min = 7 - m;
	for (int i = min; i > 0; i--)
		if (chess[m + i][n + i] == 1)
			return 1;
	//左下角
	if (7 - m >= n)min = n;
	else min = 7 - m;
	for (int i = min; i > 0; i--)
		if (chess[m + i][n - i] == 1)
			return 1;
	return 0;
}

/*
 * 从第m行开始,总共n列的棋盘,摆放皇后
 */
void eightQueen(int m, int n, int (*chess)[8])
{
	int chess1[8][8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			chess1[i][j] = chess[i][j];
	if (m == 8)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				printf("%d ", chess[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		count++;
	}
	else
		/*
		 *进行八次大循环,i代表列数,依次求出
		 *当0行0列有皇后时的所有情况,
		 *当0行1列有皇后时的所有情况,
		 *...
		 *当0行7列有皇后时的所有情况,
		 *chess保存的是0行第i列有皇后,第1行到第7行全为零,
		 *chess1保存的是当第0行第i列有皇后时所有情况中的一种,
		 *所有情况由递归求出.
		 */

		for (int i = 0; i < n; i++)	
		{
			if (!isDanger(m, i, chess))
			{
				for (int j = 0; j < 8; j++)
					chess1[m][j] = 0;
				chess1[m][i] = 1;
				eightQueen(m + 1, n, chess1);
			}
		}
}

int main()
{
	int chess[8][8] = {0};
	eightQueen(0, 8, chess);
	printf("总共有%d 方法\n", count);
	return 0;
}
