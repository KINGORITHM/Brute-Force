def solution(answers):
    answer = []
    people1 = [1, 2, 3, 4, 5]
    people2 = [2, 1, 2, 3, 2, 4, 2, 5]
    people3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    count = [0, 0, 0]

    for i in range(len(answers)):
        temp = answers[i]
        if (i < len(people1)) and (temp == people1[i]):
            count[0] += 1
        elif temp == people1[i % 5]:
            count[0] += 1
        if (i < len(people2)) and (temp == people2[i]):
            count[1] += 1
        elif temp == people2[i % 8]:
            count[1] += 1
        if (i < len(people3)) and (temp == people3[i]):
            count[2] += 1
        elif temp == people3[i % 10]:
            count[2] += 1

    max_score = 0
    for i in range(len(count)):
        if max_score < count[i]:
            answer.clear()
            answer.append(i + 1)
            max_score = count[i]
        elif max_score == count[i]:
            answer.append(i + 1)

    return answer


answers = [1, 2, 3, 4, 5]
result = solution(answers)
print(result)
