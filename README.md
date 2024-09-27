# Wordladder-Game
A wordladder game that runs for eight rounds. A project for CS246 - Object Oriented Software Development

A word ladder has a starting word and an ending word. The player’s goal is to find a chain of words that link the two, where each word differs from the previous by exactly one character. The shorter the chain, the better! For example a chain to go from “cold” to “warm” would be:
1. “cold”
2. “cord”
3. “card”
4. “ward”
5. “warm”
This chain is of length 3 i.e. it took 3 words to go from “cold” to “warm”.
Your program should take three command line arguments: the starting word, the ending word, and a
filename for the words file (a file that contains a list of words valid to use in the game).
The lengths of both the starting and ending words must be greater than 0 and equal to each other. The
starting word and the ending word must not be the same. Since these are strings, they are case-sensitive
i.e. “Cat” is not the same as “cat”.

There is a limit of 8 steps between the starting word and ending word (excluding both the starting and
ending word). If, after entering 8 words, the player cannot validly enter the ending word, the player loses,
and you should display You lose and end the game.
