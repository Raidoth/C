#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
int *rand_FNC(int n);
int main(void){
    rand_FNC(1000);



}
int *rand_FNC(int n){
    int arr[n];
    int tmp;
    int start = n;
    int iter=0;
    while(iter<n){
        struct timeb tmb;
        ftime(&tmb);
        int tm=tmb.time;
        Sleep(1);
        int tmm=tmb.millitm;
        int result = 1+(tm/tmm)%10;
        arr[iter]=result;
        printf("Number %d about value: %d\n",iter+1,result);
        iter++;
    }
}
