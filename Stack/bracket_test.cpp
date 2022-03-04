#include <iostream>
using namespace std;

// ��ȣ �˻� ���α׷� (�ܼ� �迭�� �̿��� ���� ����)
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
	cout << "���� (top�� ���� " << top << ")" << endl;

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

bool check_matching(char sentence[]) {

	int len = strlen(sentence);

	for (int i = 0; i < len; i++) {
		//���� ��ȣ
		if (sentence[i] == '(' || sentence[i] == '[' || sentence[i] == '{' || sentence[i] == '<'){
			push(sentence[i]);
		}
		//�ݴ� ��ȣ
		else if (sentence[i] == ')') {
			if (is_stack_empty()) return false; //������ ����ٸ� ������
			char left = pop();
			if (left == '(') continue;
			else return false;
		}else if (sentence[i] == ']') {
			if (is_stack_empty()) return false;
			char left = pop();
			if (left == '[') continue;
			else return false;
		}else if (sentence[i] == '}') {
			if (is_stack_empty()) return false;
			char left = pop();
			if (left == '{') continue;
			else return false;
		}else if (sentence[i] == '>') {
			if (is_stack_empty()) return false;
			char left = pop();
			if (left == '<') continue;
			else return false;
		}
	}
	if (is_stack_empty()) return true; // ������ ������� true
	else return false;
}

void main() {

	char string[100];

	cout << "������ �Է��ϼ���" << endl;
	cin.getline(string, 100); //cin�� ���� �ձ����� �޾Ƶ��̱� ������ getline�̿�

	if (check_matching(string) == true) cout << string <<  " ===> ��ȣ OK" << endl;
	else cout << string << " ===> ��ȣ ERROR" << endl;

}