#include <iostream>
#include <random>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

int * calcSum(int ** arr, int rows, int cols){
    int temp;
    int * sum = (int *) malloc (cols * sizeof(int));
    for(int i = 0; i < cols; i ++){
        sum[i] = 0;
    }
    int carry = 0;
    for(int i = 0; i < rows; i ++){
        for(int j = cols -1; j >= 0; j--){
            if((arr[i][j] + carry + sum[j]) == 0 ){
                carry = 0;
                sum[j] = 0;
            }else if((arr[i][j] + carry + sum[j]) == 1){
                carry = 0;
                sum[j] = 1;
            }else if((arr[i][j] + carry + sum[j]) == 2){
                carry = 1;
                sum[j] = 0;
            }else if((arr[i][j] + carry + sum[j]) == 3){
                carry = 1;
                sum[j] = 1;
            }
        }
        temp = cols -1;
        while(carry != 0 && temp > 0){
            if(carry + sum[temp] == 1){
                carry = 0;
                sum[temp] = 1;
            }else if(carry + sum[temp] == 2){
                carry = 1;
                sum[temp] = 0;
            }
            --temp;
        }
    }
    return sum;
}

int main(){
    srand(time(NULL));
    int block_cols, block_rows, n, row, col;
    cout << "Welcome to CheckSum!!!\n";
    cout << "Enter the size of the block: ";
    cin >> block_cols;
    cout << "Enter the number of blocks: ";
    cin >> block_rows;
    int ** arr = (int **) malloc ((block_rows + 1) * sizeof(int *));
    for(int i = 0; i < block_rows + 1; i ++){
        arr[i] = (int *) malloc ((block_cols + 1) * sizeof(int));
    }
    int * sum = (int *) malloc (block_cols * sizeof(int));
    int * checkSum = (int *) malloc (block_cols * sizeof(int));
    for(int i = 0; i < block_rows; i ++){
        for(int j = 0; j < block_cols; j ++)
            arr[i][j] = rand()%2;
    }
    for(int i = 0; i < block_rows; i ++){
        for(int j = 0; j < block_cols; j ++)
            cout << arr[i][j] << " ";
            cout << endl;
    }
    cout << "****************************************************************************\n";
    sum = calcSum(arr, block_rows, block_cols);

    cout << "The sum is : ";
    for(int i = 0; i < block_cols; i ++){
        cout << sum[i];
    }cout << endl;
    cout << "Enter the number of bits you wanna change: ";
    cin >> n;
    for(int i = 0; i < n; i ++){
        cout << "Enter the row and column of the bit you wanna manipulate\n";
        cin >> row >> col;
        if(row > 0 && col > 0 &&row <= block_cols && col <= block_rows){
            if(arr[row-1][col-1] == 1){
                arr[row-1][col-1] = 0;
            }else{
                arr[row-1][col-1] = 1;
            }
        }else{
            cout << "Please choose the correct row and column\n";
        }
    }
    checkSum = calcSum(arr, block_rows, block_cols);
    cout << "The checkSum is : ";
    for(int i = 0; i < block_cols; i ++){
        cout << checkSum[i];
    }cout << endl;
    for(int i = 0; i < block_cols; i ++){
        if(sum[i] != checkSum[i]){
            cout << "Message is currupted\n";
            return 0;
        }
    }
    cout << "Message is fine\n";
    return 0;
}