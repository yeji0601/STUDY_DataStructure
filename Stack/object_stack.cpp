#include <iostream>
using namespace std;

//��ü ���� ������� ������ �⺻ �Լ� ���� �� ������ ���Ի��� �ڵ�
#define element int
const int MAX_SIZE = 10;

class Stack {
public :
	element MyStack[MAX_SIZE]; 
	int top;
	Stack() {
		top = -1; //�ʱ�ȭ sp = -1
	}

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
			MyStack[++top] = data; // ���� �� top ����
		}

	}

	element pop() { // ���� ���� data return & top ����
		if (is_stack_empty()) {
			cout << "ERROR: ������ ������ϴ�" << endl;
			return -1;
		}
		else {
			//element x = Stack[top];top--;return x;

			return MyStack[top--]; //�ٲ�� ���� �� return->top ����

		}

	}

	element peek() {
		if (is_stack_empty()) {
			cout << "ERROR: ������ ������ϴ�" << endl;
			exit;
		}
		else {
			return MyStack[top];
		}
	}

	void print_stack() {
		cout << "���� (top�� ���� " << top << ")" << endl;

		if (is_stack_empty()) {
			cout << "ERROR: ������ ������ϴ�" << endl;
			exit;
		}
		else {
			for (int i = top; i >= 0; i--)
				cout << MyStack[i] << endl;
		}
		cout << endl;

	}


};


void main() {

	Stack OStack;

	OStack.push(10);
	OStack.push(20);
	OStack.push(30);
	OStack.pop();
	OStack.print_stack();

	OStack.push(70);
	OStack.pop();
	OStack.push(60);
	OStack.push(50);
	OStack.print_stack();
}