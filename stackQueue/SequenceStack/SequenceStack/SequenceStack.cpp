#include <iostream>
using namespace std;
#define MAX_SIZE 5
//非常基础简单的顺序栈
typedef struct sqStack {
	int data[MAX_SIZE];
	int top;
}sqs;

void initStack(sqStack &S) {
	//当top为-1的时候栈为空。
	S.top = -1;
}
bool emptyStack(sqStack S) {
	if (S.top == -1) {
		return true;
	}
	else {
		return false;
	}
}
bool push(sqs& s, int x) {
	if (s.top == MAX_SIZE - 1) {
		cout << "Stack is full!" << endl;
		return false;
	}
	s.data[++s.top] = x;
	return true;
}
//获取最顶栈的数据存储在x中。
bool pop(sqs& s, int x) {
	if (s.top == -1) {
		return false;
	}
	x = s.data[s.top--];
	return true;
}
bool getTop(sqs& s, int x) {
	if (s.top == -1) {
		return false;
	}
	x = s.data[s.top];
	return true;
}

int main()
{
  cout << "Hello World!\n";
}
