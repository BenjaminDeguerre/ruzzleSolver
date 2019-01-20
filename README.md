# ruzzleSolver

This project was made during our first year of engineering school.

This is a solver for the game "ruzzle". The aim of the game is to make words from a grid, each letter used giving a certain amount of points. The solver outputs all the words that can be made from the grid, by descending order, from the maximum number of points to the minimum number of points.

It was carried out by a group of 5 students, namely:

    - Alexandre Duval
    - Benjamin Deguerre
    - Michel Cressant
    - Arthur Hamelin
    - Marthe Cuny

## How to use it

The program works in two steps, first the "intelligent" dictionary is created from a normal dictionary. The intelligent dictionary allows for a quick search of a word, the first creation of the dictionary takes a few seconds, but once serialized in a file, it can be re-instantiated very quickly and allow for quick search.

Then a string and the file containing the "intelligent" dictionary are given to the second program, which will find all the best solution for the grid provided.

```bash
# First compile the project (source + tests)
make

# Then create the intelligent dictionary
./bin/transcode dico-ref-ascii-sans-accent.txt dictionary.dat

# Finally run the solver on a string representing a grid
./bin/ruzzleSolver "T1LDR1  A1  S1WTE1LTN1  C3LTE1  U1  R1  I1  L2WDS1  O1WDP3  S1  " dictionary.dat
```

The string representing the grid can be cut down into 16 parts of 4 characters. The first one of each group of 4 is the character of the cell, the second represent the number of points the letter is worth, the third one either L or W tells if the bonus applies only to the letter or to the full word and finally the last one D or T (double or triple) tells if the points should be doubled or tripled.