def solution(s):
    answer = []
    save = []
    
    for i in s:
        if i in save:
            save_rev = list(reversed(save))
            answer.append(save_rev.index(i) + 1)
            save.append(i)
        else:
            save.append(i)
            answer.append(-1)
    return answer
