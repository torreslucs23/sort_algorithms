#include <bits/stdc++.h>

using namespace std;

void merge(int *array, int start, int center, int end){
    //temp array for swap elements
    int tempArray[end+1];
    int i;

    //adding elements in a temp array
    for( i =start; i<=center; i++){
        tempArray[i] = array[i];
    }

    i = center+1;
    for (int w = end; w>center;w--){
        tempArray[i] = array[w];
        i++;
    }
    
    //making the merge
    int c = start;
    while (start<=end){
        if(tempArray[start] <= tempArray[end]){
            array[c] = tempArray[start];
            c++;
            start++;
        }
        else{
            array[c] = tempArray[end];
            c++;
            end--;
        }
    }
}


//recursion function to divide the array
void solve(int *array, int start, int end){
    if(start < end){
        int center = (start+end)/2;
        solve(array, start, center);
        solve(array, center+1, end);
        merge(array, start, center, end);

    }
}

//function that called in the main
void mergeSort(int *array, int n){
    solve(array, 0, n-1);
}



int main(int argc, char const *argv[])
{
    int array[5] = {10,23,1,5,2};

    mergeSort(array,5);

    for(int i =0 ;i<5; i++){
        cout << array[i] << "\n";
    }
    return 0;
}
