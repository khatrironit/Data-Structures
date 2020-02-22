#include<iostream>
#include<queue>
using namespace std;

void reverse_queue(queue<int> &q){
	if(q.empty()){
		return;
	}
	int y = q.front();
	q.pop();
	reverse_queue(q);
	q.push(y);
	return;
}
int main(){
	queue<int> q;
	int data;
	for(int i = 0 ; i < 5 ; i++){
		cin>>data;
		q.push(data);
	}
	reverse_queue(q);
	for(int i = 0 ; i < 5 ; i++){
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}