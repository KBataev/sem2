#include <stdio.h>

void ShellSort(int *mass, int n)
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp > mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}

int main(int argc, const char * argv[]) {
    const int N = 10, K = 5;
    int arr[N] = {1,1,2,2,3,3,4,4,5,5};
    int arr_rep[K];
    int i, j, k = 0;
    printf("Short array: ");
    for(i = 0; i < N; ++i){
        for(j = i + 1; j < N; ++j){
            if(arr[i] == arr[j]){
                arr_rep[k++] = arr[j];
                arr[i] = 0;
            }
        }
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Break Elements: ");
    for(i = 0; i < K; ++i)
        printf("%d ", arr_rep[i]);
    printf("\n");
    ShellSort(arr, N);
    printf("Sort Array: ");
    for(i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    k = 0;
    for(i = N - 1; i > 0; --i){
        if(arr[i] == 0)
            arr[i] = arr_rep[k++];
    }
    printf("End array: ");
    for(i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
