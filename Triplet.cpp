#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int arr[100] = {10 ,5, 5, 5, 2};
    int K = 12;
	for(int i = 0; i<n-1; i++){

		for(int j = i+1; j<n-1; j++){

			for(int k = j+1; k<n-1; k++){
				if(arr[i] + arr[j] + arr[k] == K){
					cout << arr[i]<<" "<<arr[j]<<" "<<arr[k];
				}
				else{
					i++;
					j++;
					k++;
				}
			}
		}
	}
}