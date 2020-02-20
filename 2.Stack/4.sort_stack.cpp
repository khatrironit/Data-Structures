#include<iostream>
#include<stack>
using namespace std;

void place_sorted(stack<int> &s,int x){//places the int x at its right position.
	if(s.empty() || s.top() >= x){
		s.push(x);
		return;
	}
	int y = s.top();
	s.pop();
	place_sorted(s,x);
	s.push(y);
	return;
}
void sort_stack(stack<int> &s){
	if(s.empty()){
		return;
	}
	int y = s.top();
	s.pop();
	sort_stack(s);
	place_sorted(s,y);
	return;
}
int main(){
	stack<int> s;
	int data;
	for(int i=0;i<5;i++){
		cin>>data;
		s.push(data);
	}
	sort_stack(s);
	for(int i=0;i<5;i++){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}