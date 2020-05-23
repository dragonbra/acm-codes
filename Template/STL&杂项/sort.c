#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 2e5 + 10;

void sort(int a[], int n) {
    for (int j = 1; j < n; j++) {
        int key = a[j];
        int i = j - 1; 
        while (i >= 0 && key < a[i]) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

void bubbleSort(int array[], int n)
{
    for(int i=0; i<n;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(array[j-1]>array[j]) //如果遇到比array[j]大的元素，就交换
            {
                // swap(array[j-1],array[j]); //最终array[j]前面的数字都比array[j]小
                int t = array[j-1];
                array[j-1] = array[j];
                array[j] = t;
            }
        }   
    }
}


void selectSort(int array[], int n){
    int i,index,j,temp;
    for(i=1; i<n; i++)//执行第i遍扫描操作
    {
        index = i;
        for(j=i+1; j<n; j++)//比较无序序列中的记录
        {
            if(array[index] > array[j])//记录序列中最小值的位置
            {
                index = j;
            }
        }
        if(index != i)//如果无序序列中第一个记录不是最小值，则进行交换
        {
            temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }
}

int BinarySearch(int array[], int len, int value) // 数组，长度，待查询值
{
	if (array == NULL || len <= 0)
		return -1;
 
	int low = 0;
	int high = len - 1;
	while (low <= high) // 二分的过程
	{
		int mid = low + (high - low) / 2;
		if (array[mid] == value)
			return mid+1; // 找到值后直接返回坐标
		else if (array[mid] > value)
			high = mid - 1;
		else
			low = mid + 1;
	}
 
	return -1; // 没找到值 所以返回-1
}

int main() {
    freopen("result.txt","w",stdout);

    int n = 10;
    int insert_array[11] = {1,4,2,8,5,7,9,3,6,10};
    int bubble_array[11] = {1,4,2,8,5,7,9,3,6,10};
    int select_array[11] = {1,4,2,8,5,7,9,3,6,10};
    
    printf("原始数据为:");
    for (int i=0; i<10; i++) {
        printf("%d ", insert_array[i]);
    } printf("\n");

    printf("---------------------------\n");

    srand(time(NULL));
    
    insertSort(insert_array, n);
    printf("插入排序完成，进行二分查找检验\n");
    for (int i=0; i<10; i++) {
        printf("%d ", insert_array[i]);
    } printf("\n");
    for (int i=0; i<3; i++) {
        int x = rand()%10 + 1;
        printf("本次随机查找的数据为：%d\n", x);
        printf("查询结果(第几个)：%d\n", BinarySearch(insert_array, n, x));
    }

    printf("---------------------------\n");

    bubbleSort(bubble_array, n);
    printf("冒泡排序完成，进行二分查找检验\n");
    for (int i=0; i<10; i++) {
        printf("%d ", bubble_array[i]);
    } printf("\n");
    for (int i=0; i<3; i++) {
        int x = rand()%10 + 1;
        printf("本次随机查找的数据为：%d\n", x);
        printf("查询结果(第几个)：%d\n", BinarySearch(bubble_array, n, x));
    }

    printf("---------------------------\n");

    selectSort(select_array, n);
    printf("选择排序完成，进行二分查找检验\n");
    for (int i=0; i<10; i++) {
        printf("%d ", select_array[i]);
    } printf("\n");
    for (int i=0; i<3; i++) {
        int x = rand()%10 + 1;
        printf("本次随机查找的数据为：%d\n", x);
        printf("查询结果(第几个)：%d\n", BinarySearch(select_array, n, x));
    }

    return 0;
}