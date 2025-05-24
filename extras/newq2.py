from copy import deepcopy
def alice_score(n, colors):
    # Dictionary to store frequency of each color
    color_counts = {}

    # Count the frequency of each color
    for color in colors:
        if color in color_counts:
            color_counts[color] += 1
        else:
            color_counts[color] = 1

    # Alice's score
    alice_score = 0
    alice_taken = {color: 0 for color in color_counts}  # Track how many marbles Alice has taken from each color
    total_marbles = len(colors)

    # Sort colors by frequency (ascending order of frequency)
    sorted_colors = sorted(color_counts.items(), key=lambda x: x[1])

    # Turn simulation: 0 for Alice, 1 for Bob
    turn = 0
    remaining_counts = dict(color_counts)  # Copy of the color_counts dictionary

    while sum(remaining_counts.values()) > 0:
        # Find the color with the smallest remaining marbles
        remaining_colors = [color for color, count in remaining_counts.items() if count > 0]
        remaining_colors.sort(key=lambda x: remaining_counts[x])  # Sort colors by remaining count

        if not remaining_colors:
            break

        # Select the color with the least remaining marbles
        selected_color = remaining_colors[0]

        if turn == 0:  # Alice's turn
            alice_taken[selected_color] += 1
            remaining_counts[selected_color] -= 1

            # If Alice has taken all marbles of a color
            if remaining_counts[selected_color] == 0 and alice_taken[selected_color]==color_counts[selected_color]:
                alice_score += 1  # Alice gets an extra point for completing this color
            alice_score += 1  # Alice gets 1 point for taking at least one marble from this color

        else:  # Bob's turn
            remaining_counts[selected_color] -= 1

        # Alternate turns
        turn = 1 - turn

    return alice_score


# Input reading and execution
t = int(input())  # Number of test cases
for _ in range(t):
    n = int(input())  # Number of marbles
    colors = list(map(int, input().split()))  # List of colors
    print(alice_score(n, colors))
