#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool SBcheck(vector<int> num1, vector<int> num2)
{
	int count_S = 0;
	int count_B = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (num1[j] == num2[0] % 10) // ���ڰ� ����
			{
				if (j == i) // ��ġ�� ����
					count_S++;
				else
					count_B++;
			}
		}
		num2[0] = num2[0] / 10;
	}

	if (count_S == num2[1] && count_B == num2[2]) // ��Ʈ����ũ, ���� ������ ����
		return true;
	else
		return false;
}

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	bool check = true;
	vector<int> number;

	for (int i = 123; i < 1000; i++)
	{
		number.clear();
		check = true;

		// ���� ����
		for (int j = i; j > 0;)
		{
			number.push_back(j % 10);
			j = j / 10;
		}
		
		// 0�� ����������
		if (number[0] == 0 || 
			number[1] == 0 || 
			number[2] == 0)
			continue;
		// ���� ���� �ٸ� ��
		if (number[0] == number[1] 
			|| number[1] == number[2]
			|| number[0] == number[2])
			continue;

		// reverse(number.begin(), number.end()); 
		
		for (int k = 0; k < baseball.size(); k++)
		{
			if(!SBcheck(number,baseball[k])) // �ϳ��� Ʋ���� 
			{
				check = false;
				break;
			}
		}

		if(check == true)
			answer++;
	}
	return answer;
}

int main()
{
	vector<vector<int>> baseball = { {123,1,1},{356,1,0} , {327,2,0}, {489,0,1} };
	int answer;
	answer = solution(baseball);
	cout << answer;
	return 0;
}