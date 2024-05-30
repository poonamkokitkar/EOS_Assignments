#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//	Q2. Create a thread to sort given array of "n" integers using bubble sort. Main thread should print the result after sorting is completed.
//			Hint: struct array { int *arr; int size; }
//			Pass struct address to thread function (via arg4 of pthread_create()).


typedef struct array{
	int arr[10];
	int size;
} arr_t ;
arr_t a;

void* bubble_sort(void *param){
int  i, j;  
arr_t *p1;
 p1 = (arr_t*)param;
      for (int i = 0; i < p1->size -1 ; i++)
      {
         for (int j = 0; j < p1->size - i - 1; j++)
         {
              if (p1->arr[j] > p1->arr[j+1]){
                 int temp = p1->arr[j];
                  p1->arr[j] = p1->arr[j+1];
                  p1->arr[j+1] = temp;
              }
          }
      }
      
	  printf("sorted array....\n");
		  for(i=0; i<10; i++){
			 printf("%d ",p1->arr[i]);	
		}
	printf("\n");
	return NULL;
}

//arr_t a;

int main() {
	int ret,i;
	a.size = 10;

	int arr1[10]={22,40,55,5,16,26,90,101,37,80};
	for (i =0; i<10; i++)
	{
		a.arr[i] = arr1[i];
	}

	pthread_t t1;

	ret = pthread_create(&t1, NULL, bubble_sort, &a);
	pthread_join(t1, NULL);
	printf("t1 array...\n");
	for(i=0; i<10; i++)
    		printf("%d ",a.arr[i]);
	printf("\n");
	printf("press enter to exit...\n");
	getchar();
	return 0;
}

