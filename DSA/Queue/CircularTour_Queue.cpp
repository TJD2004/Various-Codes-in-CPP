#include<iostream>
#include<queue>
using namespace std;

struct petrolpump {
    int petrol;
    int distance;
};

class Solution {
    public:
        int tour(petrolpump p[], int n) 
        {
            int deficit = 0;
            int balance = 0;
            int start = 0;

            for(int i = 0; i < n; i++) {
                balance += p[i].petrol - p[i].distance;
                if(balance < 0) {
                    deficit += balance;
                    start = i + 1;
                    balance = 0;
                }
            }

            if(deficit + balance >= 0) {
                return start;
            }
            else {
                return -1;
            }
        }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter the number of petrol pumps: ";
    cin >> n;

    petrolpump p[n];

    cout << "Enter the petrol and distance for each petrol pump: " << endl;
    for(int i = 0; i < n; i++) {
        cout << "Petrol in pump " << i+1 << ": ";
        cin >> p[i].petrol;
        cout << "Distance to next pump from pump " << i+1 << ": ";
        cin >> p[i].distance;
    }

    int start = sol.tour(p, n);

    if(start == -1) {
        cout << "It is not possible to complete the tour." << endl;
    } else {
        cout << "The tour can be started at pump " << start + 1 << "." << endl;
    }

    return 0;
}
