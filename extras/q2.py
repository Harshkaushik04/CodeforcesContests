from copy import deepcopy
test_cases=int(input())
for i in range(test_cases):
    marbles_list = []
    not_taken_set = set()
    marbles_set = set()
    marbles_dict = {}
    alice_score = 0
    alice = []
    bob = []
    n=int(input())
    for j in range(n):
        # Input space-separated integers on a single line
        temp_list = list(map(int, input().split()))  # Convert space-separated input to list of integers

        # Process each element in the list
        for temp in temp_list:
            marbles_list.append(temp)  # Add the marble to the list
            if temp not in marbles_dict:
                marbles_dict[temp] = 1  # If it's not in the dictionary, set it to 1
            else:
                marbles_dict[temp] += 1  # If it already exists, increment the count

            not_taken_set.add(temp)  # Add the marble to the 'not_taken' set
            marbles_set.add(temp)  # Add the marble to the 'marbles' set
    game_over=False
    turn=0
    while not game_over:
        mini = 10000
        mini_element = list(marbles_dict.keys())[0]  # default
        if len(not_taken_set)!=0:
            for element in not_taken_set:
                if marbles_dict[element]<mini:
                    mini=marbles_dict[element]
                    mini_element=element
            if marbles_dict[mini_element]==1:
                if turn%2==0:
                    print("hi")
                    alice_score+=2
                    alice.append(mini_element)
                else:
                    bob.append(mini_element)
                marbles_set.remove(mini_element)
            else:
                if turn%2==0:
                    alice_score+=1
                    alice.append(mini_element)
                else:
                    bob.append(mini_element)
            marbles_dict[mini_element]-=1
            not_taken_set.remove(mini_element)
        else:
            mini = 10000
            mini_element = list(marbles_dict.keys())[0]  # default
            for element in marbles_dict.keys():
                if marbles_dict[element]<mini and marbles_dict[element]!=0:
                    mini = marbles_dict[element]
                    mini_element = element
            if (marbles_dict[mini_element]==1) and mini_element not in bob and turn%2==0:
                alice_score+=2
                alice.append(mini_element)
                marbles_set.remove(mini_element)
            elif turn%2==0:
                alice_score+=1
                alice.append(mini_element)
                if marbles_dict[mini_element] == 1:
                    marbles_set.remove(mini_element)
            else:
                bob.append(mini_element)
                if marbles_dict[mini_element] == 1:
                    marbles_set.remove(mini_element)
            marbles_dict[mini_element]-=1
        if len(marbles_set)==0:
            game_over=True
        turn+=1
    print(alice_score)