/*
 * 归并排序
 *
 * 采取分而治之（Divide-and-Conquer）的策略
 *
 * Divide: 把长度为n的输入序列分成两个长度为n/2的子序列。
 * Conquer: 对这两个子序列分别采用归并排序。
 * Combine: 将两个排序好的子序列合并成一个最终的排序序列。
 *
 *
 */
#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

void merge(int start, int mid, int end)
{
	int n1 = mid - start + 1;
	int n2 = end - mid;
	int left[n1], right[n2];
	int i, j, k;

	for (i = 0; i < n1; i++) /* left holds a[start..mid] */
		left[i] = a[start+i];
	for (j = 0; j < n2; ++j) /* right holds a[mid+1..end] */
		right[j] = a[mid+1+j];

	i = j = 0;
	for (k = start; i < n1 && j < n2; ++k) {
		if (left[i] < right[j]) {
			a[k] = left[i];
			++i;
		} else {
			a[k] = right[j];
			++j;
		}
	}

	if (i < n1) 		/* left[] is not exhausted */
		for (; i < n1; i++) {
			a[k] = left[i];
			++k;
		}
	if (j < n2)		/* right[] is not exhausted */
		for (; j < n2; ++j) {
			a[k] = right[j];
			++k;
		}
}

void sort(int start, int end)
{
	int mid;

	if (start < end) {

		// 分
		mid = (start + end) / 2;
		printf("sort (%d-%d, %d-%d) %d %d %d %d %d %d %d %d\n", 
		       start, mid, mid+1, end, 
		       a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);

		// 左边的子序列：递归分治
		sort(start, mid);
		// 右边的子序列：递归分治
		sort(mid + 1, end);

		// 治
		merge(start, mid, end);

		printf("merge (%d-%d, %d-%d) to %d %d %d %d %d %d %d %d\n", 
		       start, mid, mid+1, end, 
		       a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
	}
}

int main(int argc , char * argv[])
{
	sort(0, LEN-1);
	return 0;
}
