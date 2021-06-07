#include <iostream>
using namespace std;

typedef struct Linknode {
    struct Linknode* next;
    int data;
}*liStack;

//必须加引用，因为要改变.
//void initLiStack(listack &lst)
//引用就是传入的stack与lst同时使用一个地址，stack就是lst的别名。
liStack initLiStack() {
    liStack lst = (liStack)malloc(sizeof(Linknode));
    if (lst == NULL) {
        exit(-1);
    }
    lst->next = NULL;
    return lst;
}

bool isEmpty(liStack lst) {
    if (lst->next == NULL) {
        return true;
    }
    return false;
}

//栈的插入采用头插法，因为要先进后出。
void push(liStack lst, int x) {
    liStack list;
    list = (liStack)malloc(sizeof(Linknode));
    if (list == NULL) {
        exit(-1);
    }
    list->next = NULL;

    //
    list->data = x;
    list->next = lst->next;
    lst->next = list;
}

bool pop(liStack lst, int &x) {
    liStack temp;
    if (isEmpty(lst)) {
        return false;
    }
    temp = lst->next;
    x = temp->data;
    lst->next = temp->next;
    free(temp);
    return true;
}

void display(liStack lst) {
    if (lst->next == NULL) {
        exit(-1);
    }
    liStack temp;
    temp = lst->next;
    while (temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}



int main()
{
    liStack stack =NULL;
    int temp = 0;
    //不用引用的情况，
    stack = initLiStack();
    //使用引用的情况；
    //initLiStack(stack);

    if (isEmpty(stack)) {
        push(stack, 1);
        push(stack, 2);
        push(stack, 3);
        push(stack, 4);
        push(stack, 5);
    }
    cout << "-------------Initialization------------" << endl;

    display(stack);
    pop(stack, temp);
    cout << "--------------Pop Number-----------" << endl;
    cout << temp << endl;
    cout << "-------------Pop------------" << endl;
    display(stack);
}
