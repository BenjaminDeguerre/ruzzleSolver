#ifndef __SOLUTION__
#define __SOLUTION__

/**
 *	\typedef So_Solution
 *	\brief Structure for a solution, the word and the associated value.
 */
typedef struct {
  char *word;
  int value;
} So_Solution;

#define S_MEMORY_ERROR 1

/**
 *	\fn So_Solution* S_createSolution(char *word, int value)
 *	\brief Create a new solution.
 *	\param *word The word associated to the solution.
 *  \param value The value in points of the solution.
 *	\return So_Solution*
 */
So_Solution *So_createSolution(char *word, int value);

/**
 *	\fn char* S_getString(So_Solution solution)
 *	\brief Getter for the solution word.
 *	\param solution The So_Solution to get the word from.
 *	\return char*
 */
char *So_getString(So_Solution solution);

/**
 *	\fn int W_getValue(So_Solution solution)
 *	\brief Get the value of a solution.
 *	\param solution The So_Solution to get the value from.
 *	\return int
 */
int So_getValue(So_Solution solution);

/**
 *	\fn void* S_copy(So_Solution *solution)
 *	\brief Cop a solution
 *	\param *solution The solution to copy.
 *	\return void*
 */
void *So_copy(void *solution);

/**
 *	\fn void S_delete(So_Solution *solution)
 *	\brief Delete a solution.
 *	\param *solution The So_Solution to delete.
 *	\return void
 */
void So_delete(void *solution);

/**
 *	\fn int S_compare(So_Solution *solution1, So_Solution *solution2)
 *	\brief Compare two solution by the value.
 *	\param *solution1 The first So_Solution to compare.
 *	\param *solution2 The second So_Solution to compare.
 *	\return int -1 for solution1 < solution2, 0 for solution1 == solution2
 *else 1
 */
int So_compare(void *solution1, void *solution2);

#endif
