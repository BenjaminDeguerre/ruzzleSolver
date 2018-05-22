/** \file Solution.h
 *	\brief Definition of a solution. The solver prints a list of solutions.
 *	\version 1.0
 *	\date 22/05/2018
 */
#ifndef __SOLUTION__
#define __SOLUTION__

/**
 *	\typedef S_Solution
 *	\brief Structure for a solution, the word and the associated value.
 */
typedef struct
{
    char *word;
    int value;
} S_Solution;

#define S_MEMORY_ERROR 1

/**
 *	\fn S_Solution* S_createSolution(char *word, int value)
 *	\brief Create a new solution.
 *	\param *word The word associated to the solution.
 *  \param value The value in points of the solution.
 *	\return S_Solution*
 */
S_Solution *S_createSolution(char *word, int value);

/**
 *	\fn char* S_getString(S_Solution solution)
 *	\brief Getter for the solution word.
 *	\param solution The S_Solution to get the word from.
 *	\return char*
 */
char *S_getString(S_Solution solution);

/**
 *	\fn int W_getValue(S_Solution solution)
 *	\brief Get the value of a solution.
 *	\param solution The S_Solution to get the value from.
 *	\return int
 */
int S_getValue(S_Solution solution);

/**
 *	\fn void* S_copy(S_Solution *solution)
 *	\brief Cop a solution
 *	\param *solution The solution to copy.
 *	\return void*
 */
void *S_copy(void *solution);

/**
 *	\fn void S_delete(S_Solution *solution)
 *	\brief Delete a solution.
 *	\param *solution The S_Solution to delete.
 *	\return void
 */
void S_delete(void *solution);

/**
 *	\fn int S_compare(S_Solution *solution1, S_Solution *solution2)
 *	\brief Compare two solution by the value.
 *	\param *solution1 The first S_Solution to compare.
 *	\param *solution2 The second S_Solution to compare.
 *	\return int
 */
int S_compare(void *solution1, void *solution2);

#endif
