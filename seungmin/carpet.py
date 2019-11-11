def solution(brown, red):
    answer = []
    carpet = brown + red

    for i in range(int(carpet/3)):
        y = i + 3
        if carpet % y == 0:
            x = carpet / y
            if x >= y and ((2 * x + 2 * (y - 2)) == brown) and ((y - 2) * (x - 2) == red):
                answer.append(int(x))
                answer.append(y)
                return answer

#brown = 10
#red = 2

#brown = 8
#red = 1

brown = 24
red = 24

result = solution(brown, red)
print(result)
