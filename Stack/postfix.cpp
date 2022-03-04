#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
public:
	char mystack[MAX_SIZE];
	int top;

	Stack() { top = -1; }

	bool is_stack_empty() { //스택이 비었는지 확인하는 함수
	/*if (top == -1) return true;
	else return false;*/
		return (top == -1); // 조건식이 참이면 true 반환 아니라면 false 반환
	}

	bool is_stack_full() { //스택이 찼는지 확인하는 함수
		return (top == MAX_SIZE - 1);
	}

	void push(char data) {
		if (is_stack_full()) {
			cout << "ERROR: 스택이 모두 찼습니다" << endl;
			return;
		}
		else {
			//top++; Stack[top] = data;		
			mystack[++top] = data; // 연산 전 top 증가
		}

	}
	char pop() { // 가장 위의 data return & top 감소
		if (is_stack_empty()) {
			cout << "ERROR: 스택이 비었습니다" << endl;
			return -1;
		}
		else {
			//element x = Stack[top];top--;return x;

			return mystack[top--]; //바뀌기 전의 값 return->top 감소

		}

	}
	int peek() {
		if (is_stack_empty()) {
			cout << "ERROR: 스택이 비었습니다" << endl;
			exit;
		}
		else {
			return mystack[top];
		}
	}

	void print_stack() {
		cout << "스택 (top의 값은 " << top << ")" << endl;

		if (is_stack_empty()) {
			cout << "ERROR: 스택이 비었습니다" << endl;
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

	//후위표기로 바꾸고 결과 출력

	cout << "입력 수식" << expr << endl;
	cout << "후위 수식 = ";

	for (int i = 0; i < strlen(expr); i++) {
		if (expr[i] == '(') {//왼쪽 괄호면
			continue;
		}
		else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {//연산자면
			mystack.push(expr[i]);
		}
		else if (expr[i] == ')') {//오른쪽 괄호면
			cout << mystack.pop();
		}
		else {//피연산자면
			cout << expr[i];
		}
	}

	//stack에 남아있는 연산자 전부 출력
	if (mystack.is_stack_empty()) {
		cout << endl << endl;
	}
	else {
		cout << mystack.pop();
	}

}

void main() {

	char string[100];

	cout << "수식을 입력하세요 : " ;
	cin.getline(string, 100); //cin은 공백 앞까지만 받아들이기 때문에 getline이용

	postfix(string);
}