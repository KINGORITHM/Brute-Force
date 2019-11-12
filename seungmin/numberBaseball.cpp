#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;

    for(int i = 102; i < 1000; i++){
        string num = to_string(i);
        int first = num[0], second = num[1], third = num[2];

        if(first == second || first == third || second == third)
            continue;
        if(first == '0' || second == '0' || third == '0')
            continue;
        int count = 0;
        for(int j = 0; j < baseball.size(); j++)
        {
            num = to_string(baseball[j][0]);
            int first_ = num[0], second_ = num[1], third_ = num[2];
            int strike = 0, ball = 0;

            if(first == first_){
                strike++;
            }
            else if(first == second_ || first == third_){
                ball++;
            }

            if(second == second_){
                strike++;
            }
            else if(second == first_ || second == third_){
                ball++;
            }

            if(third == third_){
                strike++;
            }
            else if(third == second_ || third == first_){
                ball++;
            }

            if(ball == baseball[j][2] && strike == baseball[j][1])
                count++;
            else    break;
        }


        if(count == baseball.size())
            answer++;
    }
    return answer;
}

int main(){

    vector <vector<int>> baseball = {{123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1}};

    cout << solution(baseball);
    return 0;
}
