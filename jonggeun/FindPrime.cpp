#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

vector<bool> prime_check;

bool desc(int a,int b)
{
	return a > b;
}

void era(int max) 
{
	for (int i = 2; i < sqrt(max); i++) //�����佺�׳׽��� ü 
	{
		if (prime_check[i] == false)
			continue;

		for (int j = i * 2; j <= max; j += i)
			prime_check[j] = false;
	}
}

int numberCheck(int num,vector<int> number_check) // ���� �� �ִ� ������ Ȯ��
{
	while (num > 0)
	{
		if (number_check[num % 10] == 0)
		{
			return false;
		}
		else
			number_check[num % 10] --;

		num = num / 10;
	}

	return true;
}

int primeCheck(int max,vector<int> number_check) // �Ҽ����� Ȯ��
{
	int answer = 0;

	for (int i = 2; i <= max; i++)
	{
		if (numberCheck(i, number_check) == false) // ���� �� �ִ� ������ Ȯ��
			continue;

		if (prime_check[i] == true)
			answer++;
	}

	return answer;
}

int solution(string numbers) {

	int answer = 0;

	vector<int> number_check;
	vector<char> piece;
	string tmp = "";
	int max;

	number_check.assign(10, 0);
	for (int i = 0; i < numbers.size(); i++) // ���ڿ� ����
	{
		piece.push_back(numbers[i]);
		number_check[numbers[i] - 48] ++;
	}
	sort(piece.begin(), piece.end(),desc); // �������� ����

	for (int i = 0; i < piece.size(); i++) // �ٽ� ���ڿ���
		tmp += piece[i];

	max = stoi(tmp);
	prime_check.assign(max+1,true);

	
	era(max); // �����佺�׳׽��� ü
	answer = primeCheck(max,number_check); // ����� �ִ� ������, �Ҽ����� Ȯ��

	return answer;
}

int main()
{
	string numbers = "17";
	cout << solution(numbers);
	return 0;
}