#include <iostream>
using namespace std;

// 괄호 검사 프로그램 (단순 배열을 이용한 스택 수정)
#define element int

const int MAX_SIZE = 10;
element Stack[MAX_SIZE]; //10개의 스택 배열 선언
int top = -1; //초기화 sp = -1

bool is_stack_empty() { //스택이 비었는지 확인하는 함수
	/*if (top == -1) return true;
	else return false;*/
	return (top == -1); // 조건식이 참이면 true 반환 아니라면 false 반환
}

bool is_stack_full() { //스택이 찼는지 확인하는 함수
	return (top == MAX_SIZE - 1);
}

void push(element data) {
	if (is_stack_full()) {
		cout << "ERROR: 스택이 모두 찼습니다" << endl;
		return;
	}
	else {
		//top++; Stack[top] = data;		
		Stack[++top] = data; // 연산 전 top 증가
	}

}

element pop() { // 가장 위의 data return & top 감소
	if (is_stack_empty()) {
		cout << "ERROR: 스택이 비었습니다" << endl;
		return -1;
	}
	else {
		//element x = Stack[top];top--;return x;

		return Stack[top--]; //바뀌기 전의 값 return->top 감소

	}

}

element peek() {
	if (is_stack_empty()) {
		cout << "ERROR: 스택이 비었습니다" << endl;
		exit;
	}
	else {
		return Stack[top];
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
			cout << Stack[i] << endl;
	}
	cout << endl;

}

bool check_matching(char sentence[]) {

	int len = strlen(sentence);

	for (int i = 0; i < len; i++) {
		//여는 괄호
		if (sentence[i] == '(' || sentence[i] == '[' || sentence[i] == '{' || sentence[i] == '<'){
			push(sentence[i]);
		}
		//닫는 괄호
		else if (sentence[i] == ')') {
			if (is_stack_empty()) return false; //스택이 비었다면 끝내기
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
	if (is_stack_empty()) return true; // 스택이 비었으면 true
	else return false;
}

void main() {

	char string[100];

	cout << "수식을 입력하세요" << endl;
	cin.getline(string, 100); //cin은 공백 앞까지만 받아들이기 때문에 getline이용

	if (check_matching(string) == true) cout << string <<  " ===> 괄호 OK" << endl;
	else cout << string << " ===> 괄호 ERROR" << endl;

}