#include <bits/stcd++.h>
using namespace std;
#include<queue>

struct stack{
    private:
        queue<int> q1;
        queue<int> q2;
    public:
        bool isempty(){
            return (q1.empty() && q2.empty());
        }
        int siz(){
            if(q1.empty())
                return q2.size();
            return q1.size();
        }
        void push(int data){
            if(isempty()){
                q1.push(data);
                return;
            }
            if(q1.empty()){
                q1.push(data);
                while(!q2.empty()){
                    q1.push(q2.front());
                    q2.pop();
                }
            }else{
                q2.push(data);
                while(!q1.empty()){
                    q2.push(q1.front());
                    q1.pop();
                }
            }
        }
        void pop(){
            if(!isempty()){
                if(q1.empty()){
                    q2.pop();
                }
                else{
                    q1.pop();
                }
            }
        }
        int top(){
            if(!isempty()){
                if(q1.empty()){
                    return q2.front();
                }
                return q1.front();
            }
            return -1;
        }
};
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.top()<<endl;
    for(int i=0;i<5;i++){
        cout<<s.top();
        s.pop();
    }
    return 0;
}
