/*
 * 插入排序算法类似于玩扑克时抓牌的过程，玩家每拿到一张牌都要插入到手中已有的牌里，使之从小到大排好序。 
 *
 * 即理解数组第一个为已排好序的，从第二个开始，临时保存值，和前面已排序的逆序对比。
 * 如果比大小，移动该数组元素，比较下个，以此循环，直达遇到比它小的就停止。
 *
 * 所移动的最后一个坑即为该元素的位置。
 */
#include <stdio.h>

#define LEN 5
int a[LEN] = { 10, 5, 2, 4, 7 };

int main(int argc , char *argv[])
{
	int i, j, key;

	// 已第二个开始
	for (j = 1; j < LEN; ++j) {
		printf("%d, %d, %d, %d, %d\n",
		       a[0], a[1], a[2], a[3], a[4]);

		// 临时保存值
		key = a[j];

		// 已排序好的
		i = j - 1;

		// 逆序对比，大于该元素，移动位置，留出坑位
		while (i >= 0 && a[i] > key) {
			a[i+1] = a[i];
			--i;
		}

		// 插入该元素
		a[i+1] = key;
	}


	for(i=0; i < LEN; i++) {
		printf("%d ", a[i]);
	}

	printf("\n");
	return 0;
}
