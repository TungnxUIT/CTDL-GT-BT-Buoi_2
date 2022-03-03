#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int const MAX = 500000;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int ThuatToan1(int* a, int n)
{
	int res = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			sum = 0;
			for (int k = i; k <= j; k++)
			{
				sum += a[k];
			}
			res = max(res, sum);
		}
	}
	return res;
}

int ThuatToan2(int* a, int n)
{
	int res = INT_MIN;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += a[j];
			res = max(res, sum);
		}
	}
	return res;
}
int ThuatToan4(int* a, int n)
{
	int res = INT_MIN;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = max(sum + a[i], a[i]);
		if (sum > res)
			res = sum;
	}
	return res;
}


int ans4 = INT_MIN;
int ThuatToan3(int* a, int left, int right)
{
	int mid = left / 2 + right / 2;
	int sum = 0;
	int left_sum = INT_MIN;
	int right_sum = left_sum;
	if (left != right)
	{
		ThuatToan3(a, left, mid);
		ThuatToan3(a, mid + 1, right);
	}
	for (int i = mid; i >= left; i--)
	{
		sum += a[i];
		left_sum = max(left_sum, sum);
	}
	sum = 0;
	for (int i = mid + 1; i <= right; i++)
	{
		sum += a[i];
		right_sum = max(right_sum, sum);
	}
	if (left_sum == INT_MIN || right_sum == INT_MIN)
		return ans4;
	else
	{
		ans4 = max(ans4, left_sum + right_sum);
		return ans4;
	}
}

int main()
{
	clock_t start, end;
	double time_used;
	int test[] = { 10, 100, 1000, 5000, 10000, 100000, 200000, 300000, 400000, 500000 };
	int n = 0;
	int* a = new int[MAX];
	srand(time(NULL));
	while (n <= 9)
	{
		for (int i = 0; i < test[n]; i++)
			a[i] = rand() % 1000 - 499;

		cout << "Testcase " << test[n] << " phan tu\n";
		start = clock();
		cout << "Ket qua Thuat Toan 1 O(n^3) : " << ThuatToan1(a, test[n]) << endl;
		end = clock();
		cout << "Thoi gian chay thuat toan 1 : " << (double)(end - start) / CLOCKS_PER_SEC << endl; //thuat toan 1
		cout << endl;

		start = clock();
		cout << "Ket qua Thuat Toan 2 O(n^2) : " << ThuatToan2(a, test[n]) << endl;
		end = clock();
		cout << "Thoi gian chay thuat toan 2 : " << (double)(end - start) / CLOCKS_PER_SEC << endl; //thuat toan 2
		cout << endl;

		start = clock();
		cout << "Ket qua Thuat Toan 3 O(nlogn) : " << ThuatToan3(a, 0, test[n] - 1) << endl;
		end = clock();
		cout << "Thoi gian chay thuat toan 3 : " << (double)(end - start) / CLOCKS_PER_SEC << endl; // thuat toan 3
		cout << endl;

		start = clock();
		cout << "Ket qua Thuat Toan 4 O(n) : " << ThuatToan4(a, test[n]) << endl;
		end = clock();
		cout << "Thoi gian chay thuat toan 4 : " << (double)(end - start) / CLOCKS_PER_SEC << endl; // thuat toan 4
		cout << endl;
		cout << "///////////////////////////////////////////////////////" << endl;

		n++;
	}
	delete[] a;
	return 0;
}
