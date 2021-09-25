#include <stdio.h>
#include <stdlib.h>

void merge(int low, int mid, int high);
void mergeSort(int low, int high);
void printArr(int a[], int n);
void copyArray(int start, int end);

#define number 100000
static int mergeArr1[number];
static int mergeArr2[number];

void mergeSort(int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high)/2;
        mergeSort(low, mid);
        mergeSort(mid+1, high);
        merge(low, mid, high);
	}
}

void merge(int low, int mid, int high) {

    int i = low;
    int j = mid+1;
    int k = low;

    while (i<=mid && j<=high) {
        if(mergeArr2[i] < mergeArr2[j]) {
           mergeArr1[k++] = mergeArr2[i++];
        } else if(mergeArr2[i] >= mergeArr2[j]) {
           mergeArr1[k++] = mergeArr2[j++];
        }
    }

 

    // ���� ���� ������ mergedArr���� ����

    if(i>=mid) {
        while(j<=high) {
           mergeArr1[k++] = mergeArr2[j++];
        }
    }

    if(j>=high) {
        while(i<=mid) {
           mergeArr1[k++] = mergeArr2[i++];
        }
    }
    copyArray(low, high);
}

 

// �迭 ��� �Լ� 

void printArr(int a[], int n) {
     int i;
     for (i=0; i<n; i++) {
        printf("%d ", a[i]);
     }
     printf("\n");
}

 

void copyArray(int start, int end) {
    int i;
    for (i=start; i<=end; i++) {
        mergeArr2[i] = mergeArr1[i];
    }
}

 

int main(int argc, char *argv[]) {

	int i,n;
	 
    printf("��� ���ڷ� �����Ͻðڽ��ϱ�?\n");
    scanf("%d",&n);

    for(i = 0 ; i < n ; i++)
	mergeArr2[i]=rand()%1000;
  
    printf("������ �迭 : ");
    printArr(mergeArr2,n);

    mergeSort(0, n-1);

	printf("������ �迭 : ");
    printArr(mergeArr2,n); 

    system("PAUSE");

    return 0;

}