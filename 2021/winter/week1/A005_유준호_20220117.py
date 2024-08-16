def solution(skill, skill_trees):
    answer = 0
    
    valid = [skill]
    for i in range(len(skill)):
        valid.append(skill[:i])

    for skill_tree in skill_trees:
        if ''.join([s for s in skill_tree if s in skill]) in valid:
            answer += 1
            
    return answer