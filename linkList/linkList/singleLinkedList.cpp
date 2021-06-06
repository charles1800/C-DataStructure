#include<iostream>

using namespace std;

typedef struct singleLinkedList {
	singleLinkedList* next;
	int data;
}node,*pnode;
//ͷ�巨
pnode linkHeadInsert();
void display(singleLinkedList*);
//β�巨
node* initLinkedList();
void change(pnode, int, int);
bool deleteNode(pnode, int);
bool insertNode(pnode, int, int);

int main() {

	pnode temp = NULL;
	cout << "--------------------------Initialization------------------------------------------" << endl;
	temp = linkHeadInsert();
	display(temp);
	cout << "--------------------------Change------------------------------------------" << endl;
	change(temp, 10, 3);
	display(temp);
	cout << "--------------------------Delete------------------------------------------" << endl;
	//temp = initLinkedList();
	//display(temp);
	if (deleteNode(temp, 3)) {
		display(temp);
	}
	cout << "--------------------------Insert------------------------------------------" << endl;
	if (insertNode(temp, 3,5)) {
		display(temp);
	}
}


pnode linkHeadInsert() {
	
	 pnode head = (pnode)malloc(sizeof(node));
	//һ��Ҫע��ÿһ��malloc��Ҫ�ж��Ƿ�Ϊ�գ�������exit��-1����
	//��������C6011����
	if (head == NULL) {
		cout << "Error generating head node" << endl;
		exit(-1);
	}
	pnode plist = head;
	//plist->next = NULL;
	
	for (int i = 0; i < 5; i++) {
		pnode body =(singleLinkedList*)malloc(sizeof(singleLinkedList));
		if (NULL == body) {
			cout << "Error generating body node" << endl;
			exit(-1);
		}

		body->data = i;
		plist->next = body;
		body->next = NULL;
		plist = body;
	}
	return head;
}

node *initLinkedList() {
	 node * head = (singleLinkedList*)malloc(sizeof(singleLinkedList));
	if (head == NULL) {
		cout << "Error generating head node" << endl;
		exit(-1);
	}
	node* temp = head;
	temp->next = NULL;
	for (int i = 0; i < 5; i++) {
		singleLinkedList* body = (singleLinkedList*)malloc(sizeof(singleLinkedList));
		if (NULL == body) {
			cout << "Error generating body node" << endl;
			exit(-1);
		}
		temp->next = body;
		body->data = i;
		temp = body;
	}
	temp->next = NULL;
	return head;
}

void change(pnode head,int number,int address) {
	if (head == NULL) {
		cout << "Error displaying list" << endl;
		exit(-1);
	}
	pnode temp = head;

	for (int i = 0; i < address; i++) {
		temp = temp->next;
		if (i+1 == address) {
			temp->data = number;
		}
	}
}
bool deleteNode(pnode head, int address) {
	if (head == NULL) {
		cout << "Error displaying list" << endl;
		exit(-1);
	}
	pnode temp = head;
	int i = 1;

	//��λ��ɾ������ǰһ��λ�á�
	for (i; i < address; i++) {
		temp = temp->next;
	}

	if(temp->next==NULL){
		exit(-1);
	}
	pnode targetNode = temp->next;
	temp->next = targetNode->next;
	free(targetNode);

	return true;
}

bool insertNode(pnode head, int address, int number) {
	if (head == NULL) {
		cout << "Error displaying list" << endl;
		exit(-1);
	}
	pnode temp = head;
	//���뵽��ǰ���ĺ��棬Ҳ���ǣ���address3������²��������ʾ��4��λ�á�
	//for(int i = 0;i<address;i++)
	//���뵽��ǰ���ĵ�λ��
	for (int i =1 ; i < address; i++) {
		pnode insertnode = (pnode)malloc(sizeof(node));
		if (insertnode == NULL) {
			cout << "Error displaying list" << endl;
			exit(-1);
		}
		temp = temp->next;
		if (i == address-1) {
			//��ʱtemp->address ��λ����address-1
			insertnode->next = temp->next;
			temp->next = insertnode;
			insertnode->data = number;
		}
	}
	return true;
}

void display(singleLinkedList *head) {
	if (head == NULL) {
		cout << "Error displaying list" << endl;
		exit(-1);
	}
	node* list = head;
	while (list->next != NULL) {
		list = list->next;
		cout << list->data<<endl;
	}
}

