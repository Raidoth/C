#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>
int *rand_FNC(int n);
int main(void){
    rand_FNC(1000);



}
int *rand_FNC(int n){
    int a = 0;//1
    int b = 0;//2
    int c = 0;//3
    int d = 0;//4
    int e = 0;//5
    int f = 0;//6
    int g = 0;//7
    int h = 0;//8
    int i = 0;//9
    int j = 0;//10
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


int rlt = 0;




    while(rlt<start){

        //printf("Number %d equal: %d\n",rlt+1,arr[rlt]);
        rlt++;
    }



}
