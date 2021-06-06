#include <iostream>
using namespace std;


typedef struct DoubleLinkedList {
	DoubleLinkedList* next,*pre;
	int data;
}node, * pnode;

pnode initList();
void display(pnode);

int main() {
	pnode temp = NULL;
	temp = initList();
	display(temp);
}


pnode initList() {
	pnode head = (pnode)malloc(sizeof(node));
	if (head == NULL) {
		cout << "Error generating head node" << endl;
		exit(-1);
	}
	pnode temp = head;


	for (int i = 0; i < 5; i++) {
		pnode body = (pnode)malloc(sizeof(node));
		if (NULL == body) {
			cout << "Error generating body node" << endl;
			exit(-1);
		}
		body->pre = NULL;
		body->next = NULL;
		body->data = i;

		temp->next = body;
		body->pre = temp;
		temp = body;
	}
	return head;
}

void display(pnode head) {
	if (head == NULL) {
		cout << "Error displaying list" << endl;
		exit(-1);
	}
	pnode list = head;
	while (list->next != NULL) {
		list = list->next;
		cout << list->data<<endl;
	}
}

/*
增删改查与单链表并无多少差异，需要注意的是：
	以插入为例子：
	新建结点Newbody;(默认temp的位置为插入结点的前一个位置)
	Newbody->next = temp->next;
	temp->next->pre = Newbody;
	Newbody->pre = temp;
	temp->next = Newbody;//最后才修改，防止操作失误导致temp丢失后面的结点。
*/


