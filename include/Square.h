#ifndef __SQUARE__
#define __SQUARE__

/**
 *	\typedef S_Square
 *	\brief Structure Square, contains a string and an integer (position in
 *the grid)
 */
typedef struct {
  char *value;
  int number;
} S_Square;

#define S_MEMORY_ERROR 1

/**
 *	\fn S_Square S_createSquare()
 *	\brief Create an empty square
 *
 *	\return S_Square*
 */
S_Square *S_createSquare();

/**
 *	\fn int S_isEmpty(S_Square square)
 *	\brief Tells if the square is empty.
 *
 *	Return 1 if empty, else 0.
 *	\param square, the S_Square
 *	\return int
 */
int S_isEmpty(S_Square square);

/**
 *	\fn char *S_getValue(S_Square)
 *	\brief Return the string of the square.
 *	\param square, the S_Square
 *	\return char*
 */
char *S_getValue(S_Square square);

/**
 *	\fn char S_getLetter(S_Square square)
 *	\brief Return the letter of the string (first value).
 *	\param square, the S_Square
 *	\return char
 */
char S_getLetter(S_Square square);

/**
 *	\fn int S_getPosition(S_Square square)
 *	\brief Return the position of the square in the grid.
 *	\param square, the S_Square
 *	\return int
 */
int S_getPosition(S_Square square);

/**
 *	\fn int S_getPointsNumber(S_Square square)
 *	\brief Return the value of the square (with out the bonuses).
 *	\param square, the S_Square
 *	\return int
 */
int S_getPointsNumber(S_Square square);

/**
 *	\fn char *S_getBonus(S_Square square)
 *	\brief Return the string with the bonuses (pos 2 and 3).
 *
 *  Malloc is used.
 *	\param square, the S_Square
 *	\return char*
 */
char *S_getBonus(S_Square square);

/**
 *	\fn S_Square S_defineSquare(S_Square *square, char *value, int squareNumber)
 *	\brief Fills the square with the provided values.
 *
 *	\param square, the S_Square
 *	\param *value, The string with the letter value and bonuses.
 *	\param squareNumber Square number.
 *	\return void
 */
void S_defineSquare(S_Square *square, char *value, int squareNumber);

/**
 *	\fn void* S_copy(void* square)
 *	\brief Copy a square
 *
 *	\param *square The square to copy.
 *	\return void*
 */
void *S_copy(void *square);

/**
 *	\fn void S_delete(void *square)
 *	\brief Function to delete the square.
 *
 *	\param *square The square to delete.
 *	\return void
 */
void S_delete(void *square);

/**
 *	\fn S_compare(void *square1, void *square2)
 *	\brief Function to compare two squares.
 *
 *	The squares are equal if they have the same position.
 *
 *	\param *square1 The first square.
 *	\param *square1 The second square.
 *	\return int -1 if position of square1 < position square2, 0 if ==, 1
 *else.
 */
int S_compare(void *square1, void *square2);
#endif
