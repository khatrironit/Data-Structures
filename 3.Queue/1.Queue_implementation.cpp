#include <iostream>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
struct queue{
    private:
        T* arr;
        int front;
        int rear;
        int max_size;
        int curr_size;
    public:
        queue(int size){
            max_size=size;
            arr = new T[size];
            curr_size = 0;
            front = 0;
            rear = max_size-1;
         }
         bool isfull(){
             return curr_size == max_size;
         }
         bool isempty(){
             return curr_size == 0;
         }
         void enqueue(T data){
            if(!isfull()){
                rear=(rear+1)%max_size;
                arr[rear] = data;
                curr_size++;
                return;
            }
            cout<<"queue is full";
            return;
         }
         void dequeue(){
             if(!isempty()){
                 front = (front+1)%max_size;
                 curr_size--;
                 return;
             }
             cout<<"queue is empty";
             return;
         }
         T top(){
             if(!isempty()){
                 return arr[front];
             }
             return -1;
         }

};
int main(){
	queue<int>q;

	return 0;
}
