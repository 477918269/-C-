#include <stdio.h>

int a[100], n, temp;

void QuickSort(int h, int t)
{
	if (h >= t) return;
	int mid = (h + t) / 2, i = h, j = t, x;
	x = a[mid];
	while (1)
	{
		while (a[i]<x) i++;
		while (a[j]>x) j--;
		if (i >= j) break;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	a[mid] = a[j];
	a[j] = x;
	QuickSort(h, j - 1);
	QuickSort(j + 1, t);
	return;
}

int main()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i<n; i++) scanf("%d", &a[i]);
	QuickSort(0, n - 1);
	for (i = 0; i<n; i++) printf("%d ", a[i]);

	return(0);
}