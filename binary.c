#include<stdio.h>
int main(){
    
    int arr[100];
    printf("\nEnter array number:");
    int n;
    scanf("%d",&n);
    printf("Enter array element: ");

    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("\nEnter target: ");
    int target;
    scanf("%d",&target);

    int left =0, right=n-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(target==arr[mid]){
            printf("found in %d",mid);
            return 0;
        }else if(arr[mid]<target){
            left = mid+1;
        }else if (arr[mid]>target){
            right = mid-1;
        }
    }


        // printf("Printed array.");

        // for(int i=0; i<n; i++){
        //     printf("%d",arr[i]);
        // }
    return 0;
}