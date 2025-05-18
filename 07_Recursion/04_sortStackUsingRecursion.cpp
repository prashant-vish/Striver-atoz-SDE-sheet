#include <bits/stdc++.h> 
using namespace std;

// time complexity 2*O(size)

// space complexity O(size);

void insertAtRightPosition(stack<int> & stack, int value){

	if(stack.empty()){
		stack.push(value);
		return ;
	}

	int topvalue=stack.top();

	if(topvalue<value){
		stack.push(value);
		return ;
	}
	stack.pop();
	insertAtRightPosition(stack, value);
	stack.push(topvalue);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return ;
	}
	int value=stack.top();
	stack.pop();
	sortStack(stack);

	insertAtRightPosition(stack,value);
	return  ;
}