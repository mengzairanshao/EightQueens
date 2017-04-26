#include <stdio.h>

int count = 0;
/*
* ȷ��m��n���Ƿ���԰��Żʺ�
*/
int isDanger(int m, int n, int (*chess)[8])
{
	int min;
	//�Ե�m�н����ж�
	for (int i = 0; i < 8; i++)
		if (chess[m][i] == 1)
			return 1;
	//�Ե�n�н����ж�
	for (int i = 0; i < 8; i++)
		if (chess[i][n] == 1)
			return 1;
	//���Ͻ�
	if (m >= n)min = n;
	else min = m;
	for (int i = min; i > 0; i--)
		if (chess[m - i][n - i] == 1)
			return 1;
	//���Ͻ�
	if (m >= 7- n)min =7 - n;
	else min = m;
	for (int i = min; i > 0; i--)
		if (chess[m - i][n + i] == 1)
			return 1;
	//���½�
	if (7 - m >= 7 - n)min = 7 - n;
	else min = 7 - m;
	for (int i = min; i > 0; i--)
		if (chess[m + i][n + i] == 1)
			return 1;
	//���½�
	if (7 - m >= n)min = n;
	else min = 7 - m;
	for (int i = min; i > 0; i--)
		if (chess[m + i][n - i] == 1)
			return 1;
	return 0;
}

/*
 * �ӵ�m�п�ʼ,�ܹ�n�е�����,�ڷŻʺ�
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
		 *���а˴δ�ѭ��,i��������,�������
		 *��0��0���лʺ�ʱ���������,
		 *��0��1���лʺ�ʱ���������,
		 *...
		 *��0��7���лʺ�ʱ���������,
		 *chess�������0�е�i���лʺ�,��1�е���7��ȫΪ��,
		 *chess1������ǵ���0�е�i���лʺ�ʱ��������е�һ��,
		 *��������ɵݹ����.
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
	printf("�ܹ���%d ����\n", count);
	return 0;
}
