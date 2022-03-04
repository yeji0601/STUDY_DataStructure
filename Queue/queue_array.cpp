#include <iostream>
using namespace std;

//큐의 기본 함수 구현
#define element int
const int MAX_SIZE = 100;


class QUEUE {
public:
	element Queue[MAX_SIZE]; //100개의 큐배열 선언
	int front, rear; //초기화 

	QUEUE() {
		front = rear = -1;
	}

	bool is_queue_empty() { //큐가 비었는지 확인하는 함수
	//front와 rear가 같으면 큐가 빈 것
		return (front == rear); // 조건식이 참이면 true 반환 아니라면 false 반환
	}

	bool is_queue_full() { //큐가 찼는지 확인하는 함수
		return (rear == MAX_SIZE);
	}

	void enQueue(element data) {
		if (is_queue_full()) {
			cout << "ERROR: 큐가 모두 찼습니다" << endl;
			return;
		}
		else {
			Queue[++rear] = data; // rear++; Queue[rear] = data;
		}

	}

	element deQueue() {
		if (is_queue_empty()) {

			cout << "ERROR: 큐가 비었습니다" << endl;
			return -1;
		}
		else {
			return Queue[front + 1]; //front는 가장 앞 원소 / 삭제한 원소의 앞을 가리킴->front 증가 후 return
		}
	}

	element peek() {
		if (is_queue_empty()) {
			cout << "ERROR: 큐가 비었습니다" << endl;
			exit;
		}
		else {
			return Queue[front + 1];//++front로 front값 바꾸면 제대로 된 결과 나오지 않음
		}
	}

	void print_queue() {
		cout << "큐 : ( front = " << front << ", rear = " << rear << " )" << endl;

		if (is_queue_empty()) {
			cout << "ERROR: 큐가 비었습니다" << endl;
			exit;
		}
		else {
			for (int i = front + 1; i <= rear; i++)
				cout << Queue[i] << " ";
		}
		cout << endl;
	}
};


void main() {
	QUEUE myQueue; 

	myQueue.enQueue(20);
	myQueue.enQueue(30);
	myQueue.enQueue(40);
	myQueue.deQueue();
	myQueue.print_queue();

	myQueue.enQueue(50);
	myQueue.enQueue(70);
	myQueue.deQueue();
	myQueue.enQueue(60);
	myQueue.enQueue(40);
	myQueue.print_queue();
}