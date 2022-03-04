#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
public:
	char mystack[MAX_SIZE];
	int top;

	Stack() { top = -1; }

	bool is_stack_empty() { //������ ������� Ȯ���ϴ� �Լ�
	/*if (top == -1) return true;
	else return false;*/
		return (top == -1); // ���ǽ��� ���̸� true ��ȯ �ƴ϶�� false ��ȯ
	}

	bool is_stack_full() { //������ á���� Ȯ���ϴ� �Լ�
		return (top == MAX_SIZE - 1);
	}

	void push(char data) {
		if (is_stack_full()) {
			cout << "ERROR: ������ ��� á���ϴ�" << endl;
			return;
		}
		else {
			//top++; Stack[top] = data;		
			mystack[++top] = data; // ���� �� top ����
		}

	}
	char pop() { // ���� ���� data return & top ����
		if (is_stack_empty()) {
			cout << "ERROR: ������ ������ϴ�" << endl;
			return -1;
		}
		else {
			//element x = Stack[top];top--;return x;

			return mystack[top--]; //�ٲ�� ���� �� return->top ����

		}

	}
	int peek() {
		if (is_stack_empty()) {
			cout << "ERROR: ������ ������ϴ�" << endl;
			exit;
		}
		else {
			return mystack[top];
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
				cout << mystack[i] << endl;
		}
		cout << endl;

	}

};

void postfix(char expr[]) {
	Stack mystack;

	//����ǥ��� �ٲٰ� ��� ���

	cout << "�Է� ����" << expr << endl;
	cout << "���� ���� = ";

	for (int i = 0; i < strlen(expr); i++) {
		if (expr[i] == '(') {//���� ��ȣ��
			continue;
		}
		else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {//�����ڸ�
			mystack.push(expr[i]);
		}
		else if (expr[i] == ')') {//������ ��ȣ��
			cout << mystack.pop();
		}
		else {//�ǿ����ڸ�
			cout << expr[i];
		}
	}

	//stack�� �����ִ� ������ ���� ���
	if (mystack.is_stack_empty()) {
		cout << endl << endl;
	}
	else {
		cout << mystack.pop();
	}

}

void main() {

	char string[100];

	cout << "������ �Է��ϼ��� : " ;
	cin.getline(string, 100); //cin�� ���� �ձ����� �޾Ƶ��̱� ������ getline�̿�

	postfix(string);
}