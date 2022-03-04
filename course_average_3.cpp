#include <iostream>
using namespace std;

//�л��� ���� �� SIZE������ ���� ����
const int SIZE = 10; 
// ����� ���� �� ������ ����
const int COU = 3;
// �б޼� ���� �� ������ ����
const int CLA = 3; 
// �л� ���� ���Ƿ� �ο�
int score[CLA][COU][SIZE] = { 40, 80, 50, 70, 80, 90, 10, 82, 35, 40,20, 60, 50, 70, 40, 90, 50, 82, 35,40, 20, 60, 50, 70, 80, 90, 100, 82, 35,40, 20, 60, 50, 70, 80, 90, 100, 82, 35,40, 20, 60, 70, 70, 80, 90, 100, 82, 35,40, 20, 60, 50, 70, 80, 90, 100, 82, 35,40, 20, 60, 50, 70, 80, 90, 100, 82, 35,40, 20, 60, 50, 70, 100, 90, 100, 82, 35,40, 20, 60, 50, 70, 80, 77, 100, 82, 35,40 };

int main() {
	
	//�ش� �г��� ���� ���
	double course_grade[3];		
	for (int course = 0; course < COU; course++) //���� ���� ������ ��հ�
	{
		int sum = 0;//���� ���� �հ� ����� ���� sum�� 0���� ����
		for (int cl = 0; cl < CLA; cl++)//�� ���� ���� ���� ������ ���ϱ�
		{
			for (int i = 0; i < SIZE; i++) {
				sum += score[cl][course][i];
			}
		}
		course_grade[course] = (double)sum / (SIZE*3); //�迭�� ����� �� ���� �հ踦 ��ü �л� ���� ������
	}

	//�� �ݺ� ���� ���
	double course_byclass[3][3];
	for (int cl = 0; cl < CLA; cl++) //�� ���� ���� ��հ�
	{		
		for (int course = 0; course < COU; course++)//�� ���� ���� ���� ������ ���ϱ�
		{
			int sum = 0;//���� ������ �հ� ����� ���� sum�� 0���� ����
			for (int i = 0; i < SIZE; i++) {
				sum += score[cl][course][i];
			}
			course_byclass[cl][course] = (double)sum / SIZE;
		}
	}

	//�ش� �г��� ���� ��� ���
	for (int i = 0; i < 3; i++)
		cout << i+1 << "�� ���� ��� : " << course_grade[i] << endl;

	cout << endl;

	//�� �ݺ� ���� ��� ���
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << i + 1 << "���� " << j + 1 << "�� ��� : " << course_byclass[i][j] << endl;
			cout << endl;
	}
}