#include <stdio.h>
#include <stdlib.h>
#define N 8
void set2zero(int board[N][N]);
void printBoard(int board[N][N]);
int fillBoard_r(int board[N][N],int n);
void colorBoard(int board[N][N],int i,int j, int q);
int main()
{
    int board[N][N];
    set2zero(board);
    if(fillBoard_r(board,0)){
        printf("You found the right place for each Queen!\n");
        printBoard(board);
    }else{
        printf("No solution is found!");
    }

    return 0;
}
void set2zero(int board[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            board[i][j]=0;
        }
    }
    return;
}

int fillBoard_r(int board[N][N],int n){
    int i,j;
    if(n==N){
        return 1;
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(board[i][j]==0){
                colorBoard(board,i,j,+1);
                if(fillBoard_r(board,n+1)){
                    return 1;
                }
                colorBoard(board,i,j,-1);
            }
        }
    }

    return 0;
}
void colorBoard(int board[N][N],int i,int j, int q){
    int r,c;

    for(c=0;c<N;c++){
        board[i][c]+=q;
    }
    for(r=0;r<N;r++){
        board[r][j]+=q;
    }
    for(r=i,c=j;r<N && c<N;r++,c++){
        board[r][c]+=q;
    }
    for(r=i,c=j;r>=0 && c<N;r--,c++){
        board[r][c]+=q;
    }
    for(r=i,c=j;r>=0 && c>=0;r--,c--){
        board[r][c]+=q;
    }
    for(r=i,c=j;r<N && c>=N;r++,c--){
        board[r][c]+=q;
    }
    return ;
}
void printBoard(int board[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(board[i][j]==5){//here i get diffrent results with diffrent numbers,neither is the correct one
                printf("Q");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
    return;

}
