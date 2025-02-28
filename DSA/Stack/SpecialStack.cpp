#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

class SpecialStack {
    // Define the data members.
	stack<int> s;
    int mini = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else
        {
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }   
            else
            {
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty())
            return -1;
        
        return mini;
    }  
};

int main() {
    SpecialStack s;
    s.push(3);
    s.push(5);
    std::cout << "Minimum: " << s.getMin() << std::endl;
    s.push(2);
    s.push(1);
    std::cout << "Minimum: " << s.getMin() << std::endl;
    std::cout << "Popped: " << s.pop() << std::endl;
    std::cout << "Minimum: " << s.getMin() << std::endl;
    std::cout << "Popped: " << s.pop() << std::endl;
    std::cout << "Top: " << s.top() << std::endl;
    return 0;
}