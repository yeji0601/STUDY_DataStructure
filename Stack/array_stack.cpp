#include <iostream>
using namespace std;

//단순 배열을 이용한 스택의 기본 함수 구현 및 간단한 삽입삭제(push / pop)테스트
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
	cout << "스택 (top의 값은 " <<top <<")" << endl;

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