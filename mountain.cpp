/* mountain is set of adjacent integers that strictly increases and then strictly decreases after reaching the peak

Also, amountain requires at least 3 numbers to form.*/

//eg. [5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4]

//code
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int peak(vector<int> arr) {
    int n = arr.size();
    int highest_peak = 0, counter=0, peak_length=0;

    for(int i=0; i<n; i++) {
        
        if((arr[i] > arr[i+1]) && (arr[i] > arr[i-1])) {
            highest_peak = arr[i];
            counter++;
        }
        
        //backward loop for back slope of the mountain
        int j = i-1;
        while((j>0) && (arr[j] < arr[j+1])) {
            counter++;
            j--;
        }

        //forward loop for forward slope of the mountain
        //eg. [5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4]
        int k =i+1;
        while ((arr[k] < arr[k - 1]) && (k < n-1)) {
            counter++;
            k++;
        }

        //checking for mountain and its highest peak
        if((counter > 2) && (counter > peak_length)) {
            peak_length = counter;
        }
        counter = 0;
    }
    return peak_length;
}


int main(){
    vector<int> arr;
    int n;
    cout << "No. of elements:";
    cin >> n;

    cout<<"enter the values of array:"<< endl;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int peak_length = peak(arr);
    cout<<"highest peak length = "<< peak_length << endl;
    
    return 0;
}



/* A small trick for such problem is to follow the following steps:
    a) identity the peaks
    b) move backward and then forward to find the length of the mountain*/