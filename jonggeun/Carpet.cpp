#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;

	int side_sum = (brown - 4) / 2;

	for (int i = 1; i <= side_sum; i++)
	{
		if ((side_sum - i)*i == red)
		{
			answer.push_back(side_sum - i + 2);
			answer.push_back(i + 2);
			break;
		}
	}

	return answer;
}