#include <iostream>
using namespace std;

//학생수 수정 시 SIZE변수의 값을 수정
const int SIZE = 10; 
// 과목수 수정 시 변수값 수정
const int COU = 3;
// 학급수 수정 시 변수값 수정
const int CLA = 3; 
// 학생 성적 임의로 부여
int score[CLA][COU][SIZE] = { 40, 80, 50, 70, 80, 90, 10, 82, 35, 40,20, 60, 50, 70, 40, 90, 50, 82, 35,40, 20, 60, 50, 70, 80, 90, 100, 82, 35,40, 20, 60, 50, 70, 80, 90, 100, 82, 35,40, 20, 60, 70, 70, 80, 90, 100, 82, 35,40, 20, 60, 50, 70, 80, 90, 100, 82, 35,40, 20, 60, 50, 70, 80, 90, 100, 82, 35,40, 20, 60, 50, 70, 100, 90, 100, 82, 35,40, 20, 60, 50, 70, 80, 77, 100, 82, 35,40 };

int main() {
	
	//해당 학년의 과목별 평균
	double course_grade[3];		
	for (int course = 0; course < COU; course++) //과목에 따른 각반의 평균값
	{
		int sum = 0;//다음 반의 합계 계산을 위해 sum을 0으로 리셋
		for (int cl = 0; cl < CLA; cl++)//각 반의 개별 과목 점수를 더하기
		{
			for (int i = 0; i < SIZE; i++) {
				sum += score[cl][course][i];
			}
		}
		course_grade[course] = (double)sum / (SIZE*3); //배열에 저장된 각 과목별 합계를 전체 학생 수로 나누기
	}

	//각 반별 과목별 평균
	double course_byclass[3][3];
	for (int cl = 0; cl < CLA; cl++) //각 반의 과목 평균값
	{		
		for (int course = 0; course < COU; course++)//각 반의 개별 과목 점수를 더하기
		{
			int sum = 0;//다음 과목의 합계 계산을 위해 sum을 0으로 리셋
			for (int i = 0; i < SIZE; i++) {
				sum += score[cl][course][i];
			}
			course_byclass[cl][course] = (double)sum / SIZE;
		}
	}

	//해당 학년의 과목별 평균 출력
	for (int i = 0; i < 3; i++)
		cout << i+1 << "번 과목 평균 : " << course_grade[i] << endl;

	cout << endl;

	//각 반별 과목별 평균 출력
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << i + 1 << "반의 " << j + 1 << "번 평균 : " << course_byclass[i][j] << endl;
			cout << endl;
	}
}