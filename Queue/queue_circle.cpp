#include <iostream>
using namespace std;

//배열을 이용한 원형큐 구현
#define element int
const int MAX_SIZE = 6;


class CQUEUE {
public:
	element CQueue[MAX_SIZE]; //큐배열 선언
	int front, rear; //초기화 

	CQUEUE() {
		front = rear = -1;
	}

	bool is_queue_empty() { //큐가 비었는지 확인하는 함수
	
		return (front == rear); 
	}

	bool is_queue_full() { //큐가 찼는지 확인하는 함수
		if (front == (rear + 1) % MAX_SIZE)
			return true;
		else return false;
	}

	void enQueue(element data) {
		if (is_queue_full()) {
			cout << "ERROR: 큐가 모두 찼습니다" << endl;
			return;
		}
		else {
			rear = (rear + 1) % MAX_SIZE;
			CQueue[rear] = data;
		}

	}

	element deQueue() {
		if (is_queue_empty()) {

			cout << "ERROR: 큐가 비었습니다" << endl;
			return -1;
		}
		else {
			front = (front + 1) % MAX_SIZE;
			return CQueue[front];
		}
	}

	element peek() {
		if (is_queue_empty()) {
			cout << "ERROR: 큐가 비었습니다" << endl;
			exit;
		}
		else {
			return CQueue[front + 1];
		}
	}

	void print_queue() {
		if (front <= rear) {
			for (int i = front + 1; i <= rear; i++)
				cout << CQueue[i] << " ";
		}
		else {
			for (int i = front + 1; i < MAX_SIZE; i++)
				// front부터 마지막 원소까지 출력
				cout << CQueue[i] << " ";
			for (int i = 0; i <= rear; i++)
				//rear까지 출력
				cout << CQueue[i] << " ";
		}
		cout << endl;
	}
};


	void main() {
		CQUEUE myQueue;

		myQueue.enQueue(20);
		myQueue.enQueue(30);
		myQueue.enQueue(40);
		myQueue.enQueue(50);
		myQueue.enQueue(60);
		myQueue.deQueue();
		myQueue.enQueue(40);

		myQueue.print_queue();

		myQueue.deQueue();
		myQueue.deQueue();
		myQueue.enQueue(50);
		myQueue.enQueue(70);
		
		myQueue.print_queue();
	}