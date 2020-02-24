#include <iostream>
#include<vector>
using namespace std;
class heap{
        vector<int>v;
        bool minheap;
        bool compare(int a ,int b){
            if(minheap){
                return a > b;
            }else{
                //maxheap
                return a < b;
            }
        }
        void heapify(int i){
            //assume minindex is current index;
            int minindex = i;
            int left = 2*i;
            int right = 2*i + 1;
            if(left < v.size() && compare(v[minindex],v[left])){
                minindex = left;
            }
            if(right < v.size() && compare(v[minindex],v[right])){
                minindex = right;
            }
            if(minindex != i){
                swap(v[i],v[minindex]);
                heapify(minindex);
            }
            return;
        }
    public:
        heap(bool type = true){
            minheap = type;
            v.push_back(-1);
        }
        void push(int data){
            v.push_back(data);
            int index = v.size() - 1;
            int parent = index/2;
            while(index > 1 && compare(v[parent],v[index])){
                swap(v[parent],v[index]);
                index = parent;
                parent = parent/2;
            }
            return;
        }
        bool isEmpty(){
            return v.size() == 1;
        }
        int top(){
            if(isEmpty())
            return -1;
            return v[1];
        }
        void remove(){
            int index = v.size() - 1;
            v[1] = v[index];
            v.pop_back();
            heapify(1);
            return;
        }
        void print(){
            for(int i = 1 ; i < v.size() ; i++){
                cout<<v[i]<<endl;
            }
        }
};

int main() {
    //priority_queue<int>q  =>maxheap
    //priority_queue<int , vector<int> , greater<int>>q   =>minheap
    heap h(false);
    h.push(17);
    h.push(15);
    h.push(14);
    h.push(11);
    h.push(10);
    h.push(8);
    h.push(7);
    h.push(5);
    h.push(1);
    //h.remove();
    h.print();

    return 0;
}
