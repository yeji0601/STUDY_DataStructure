#include <iostream>
using namespace std;

//�ܼ� �迭�� �̿��� ������ �⺻ �Լ� ���� �� ������ ���Ի���(push / pop)�׽�Ʈ
#define element int
const int MAX_SIZE = 10;
element Stack[MAX_SIZE]; //10���� ���� �迭 ����
int top = -1; //�ʱ�ȭ sp = -1

bool is_stack_empty() { //������ ������� Ȯ���ϴ� �Լ�
	/*if (top == -1) return true;
	else return false;*/
	return (top == -1); // ���ǽ��� ���̸� true ��ȯ �ƴ϶�� false ��ȯ
}

bool is_stack_full() { //������ á���� Ȯ���ϴ� �Լ�
	return (top == MAX_SIZE - 1);
}

void push(element data) {
	if (is_stack_full()) {
		cout << "ERROR: ������ ��� á���ϴ�" << endl;
		return;
	}
	else {
		//top++; Stack[top] = data;		
		Stack[++top] = data; // ���� �� top ����
	}
	
}

element pop() { // ���� ���� data return & top ����
	if (is_stack_empty()) {
		cout << "ERROR: ������ ������ϴ�" << endl;
		return -1;
	}
	else {
		//element x = Stack[top];top--;return x;
		
		return Stack[top--]; //�ٲ�� ���� �� return->top ����
		
	}

}

element peek() {
	if (is_stack_empty()) {
		cout << "ERROR: ������ ������ϴ�" << endl;
		exit;
	}
	else {
		return Stack[top];
	}
}

void print_stack() {
	cout << "���� (top�� ���� " <<top <<")" << endl;

	if (is_stack_empty()) {
		cout << "ERROR: ������ ������ϴ�" << endl;
		exit;
	}
	else {
		for (int i = top; i >= 0; i--)
			cout << Stack[i] << endl;
	}
	cout << endl;

}

void main() {
	push(10);
	push(20);
	push(30);
	pop();
	print_stack();

	push(70);
	pop();
	push(60);
	push(50);
	print_stack();
}