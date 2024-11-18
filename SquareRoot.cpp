#include<iostream>
using namespace std;

// int SquareRoot(int x) {

//     int i = 1;
//     while(i < x) {

//         int sqr = i*i;

//         if(sqr == x) {
//             return i;
//         } 
//         else{
//             i++;
//         }
//     }
// }


// int main() {

//     int x;
//     cin >> x;

//     cout << SquareRoot(x);
// }

 long long int sqrInteger(int n) {

        int s = 0;
        int e = n;
        long long int mid = s + (e-s)/2;

        int ans = -1;
        while(s<=e) {

            long long int square = mid * mid;

            if(square == n) {
                return mid;
            }
            if(square < n) {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s)/2;
        }
        return ans;
}

double morePrecision(int n, int precision, int tempSol){

    double factor = 1;
    double ans = tempSol;

    for(int i = 0; i < precision; i++){
        factor = factor / 10;

        for(double j = ans; j*j < n; j = j+factor){
            ans = j;
        }
    }
    return ans;
}


int main() {

    int x;
    cin >> x;

    // cout << BinarySearch(x);

    int tempSol = sqrInteger(x);
    cout << morePrecision(x, 3, tempSol);

    return 0;
}