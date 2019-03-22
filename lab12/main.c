#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int HashFunc(int key, int i){
    return key*(i+30)+13;
}
int main() {
    srand(time(NULL));
    int a[20], i, b[20];
    for(i=0;i<20;i++){
        a[i]=rand() % 20;
        printf(" key=%d",a[i]);
        b[i]=HashFunc(a[i],i);
    }
    printf("\n\n");
    for(i=0;i<20;i++){
        printf(" HashFunc(%d)=%d ",a[i], b[i]);}
    printf("\n\n");
    for(i=0;i<20;i++)
        if(b[i]%2==1)
            printf(" HashFuncWithoutEven(%d)=%d ",a[i], b[i]);
    return 0;
}
