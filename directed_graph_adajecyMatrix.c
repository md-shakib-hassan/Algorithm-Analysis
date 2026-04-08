#include<stdio.h>

int main(){

    int mat[5][5];

    int node , edge,i,j,a,b;
    scanf("%d %d",&node,&edge);


    for(i=0; i<node; i++){
        for(j=0; j<node; j++){
            mat[i][j]=0;
        }
    }


    for(i=0; i<node; i++){
        for(j=0; j<node; j++){
            scanf("%d %d",&a,&b);

            mat[a][b]=1;
            
        }

    }

    for(i=0; i<node; i++){
        for(j=0; j<node; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");

    }


    return 0;
}