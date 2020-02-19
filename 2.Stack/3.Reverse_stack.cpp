#include<iostream>
#include<stack>
using namespace std;


void place_at_bottom(stack<int> &s,int x){
	if(s.empty()){
		s.push(x);
		return;
	}
	int y = s.top();
	s.pop();
	place_at_bottom(s,x);
	s.push(y);
	return;
}
void reverse_stack(stack<int> &s){
	if(s.empty()){
		return;
	}
	int y = s.top();
	s.pop();
	reverse_stack(s);
	place_at_bottom(s,y);
	return;
}
int main(){
	stack<int> s;
	int data;
	for(int i=0;i<5;i++){
		cin>>data;
		s.push(data);
	}
	reverse_stack(s);
	for(int i=0;i<5;i++){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}