#include <iostream>
#include<stack>
using namespace std;
class queue{
    stack<int>s1;
    stack<int>s2;
public:
    bool empty(){
        return s1.empty();
    }
    int siz(){
            return s1.size();
        }
    void push(int data){
        if(s1.empty()){
            s1.push(data);
            return;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(data);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return;
        }
    void pop(){
        if(!s1.empty())
            s1.pop();
    }
    int top(){
        if(!s1.empty())
            return s1.top();
    }
};
int main() {
    queue q;
    cout<<q.empty()<<endl;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<endl<<q.siz()<<endl;
    q.push(4);
    cout<<q.siz()<<endl;
    int size = q.siz();
    for(int i=1 ; i <=size ; i++){
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}
