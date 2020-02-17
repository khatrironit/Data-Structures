#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node(int data){
        this->data=data;
        next= NULL;
    }
};
struct stack{
    private:
        node* head;
        int size;
    public:
        stack(){
            head=NULL;
            size=0;
        }
        bool isempty(){
            return head==NULL;
        }
        int siz(){
            return size;
        }
        void push(int data){
            node* temp=new node(data);
            temp->next=head;
            head=temp;
            size++;
        }
        void pop(){
            if(!isempty()){
                node* temp=head;
                head=head->next;
                delete temp;
                size--;
            }
        }
        int top()
        {
            if(!head){
                return -1;
            }
            return head->data;
        }

};
int main(){
	stack s;

	return 0;
}