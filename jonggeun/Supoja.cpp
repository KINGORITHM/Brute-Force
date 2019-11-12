#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> score = { 0,0,0 };
	vector<int> case1 = { 1,2,3,4,5 };
	vector<int> case2 = { 2,1,2,3,2,4,2,5 };
	vector<int> case3 = { 3,3,1,1,2,2,4,4,5,5 };
	int max=0;

	for (int i = 0; i < answers.size(); i++)
	{
		if (case1[i % 5] == answers[i])
			score[0]++;

		if (case2[i % 8] == answers[i])
			score[1]++;

		if (case3[i % 10] == answers[i])
			score[2]++;
	}

	for (int i = 0; i < score.size(); i++)
	{
		if (score[i] > max)
			max = score[i];
	}

	for (int i = 0; i < score.size(); i++)
	{
		if (score[i] == max)
			answer.push_back(i+1);
	}

	return answer;
}