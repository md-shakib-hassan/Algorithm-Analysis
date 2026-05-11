#include<stdio.h>
int main(){

    int arr[100];
    printf("Enter array number: ");
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("enter target: ");
    int target;
    scanf("%d",&target);

    for(int i=0; i<n; i++){
        if(arr[i]==target){
            printf("taeget found at %d",i);
            return 0;
        }
    }
    printf("not found.");


    return 0;
}


