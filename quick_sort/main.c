//
//  main.c
//  quick_sort
//
//  Created by 方舟 on 15/5/3.
//  Copyright (c) 2015年 方舟. All rights reserved.
//

#include <stdio.h>
int qsort_key(int *ar,int a,int b);
void swap(int *a,int *b);
void q_sort(int *ar,int a,int b);
int main(void)
{
    int ar[] = {5,4,9,2,1};
    q_sort(ar,0,4);
    for(int i = 0; i < 5;i++)
        printf("%d\t",ar[i]);
    return 0;
}
int qsort_key(int *ar,int a,int b)
{
    int i = a - 1;
    int j;
    for(j = a; j < b; j++)
    {
        if(ar[j] <= ar[b])
        {
            i++;
            swap(&ar[i],&ar[j]);
        }
    }
    swap(&ar[i+1],&ar[b]);
    return i+1;
}
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void q_sort(int *ar,int a,int b)
{
    if(b > a){
        int c = qsort_key(ar, a, b);
        q_sort(ar,a,c-1);
        q_sort(ar,c+1,b);
    }
}