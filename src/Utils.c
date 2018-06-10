/* Michel CRESSANT - 11/12/2014 */
/* Benjamin Deguerre - 17/12/2014 */

/* #define NDEBUG 
   decommenter pour annuler les tests
   de precondition
*/

/* partie privee */

/* partie publique */

#include "subString.h"
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

char *subString(char *string, int begin, int end)
{
    char *res = malloc(sizeof(char) * (end - begin + 2));
    res[end - begin + 1] = '\0';
    int i;

    assert(end >= begin);
    assert(end <= strlen(string));
    assert(begin >= 0);

    if (res == NULL)
    {
        errno = 1;
        exit(errno);
    }

    for (i = begin; i <= end; i++)
    {
        res[i - begin] = string[i];
    }

    return res;
}
/* Alexandre DUVAL - 17/12/2014 */
/* Alexandre DUVAL - 31/12/2014 */

#include <stdlib.h>

#include "readFile.h"

D_Dictionary readFile(FILE *file)
{
    D_Dictionary dictionary = D_createDictionary();
    char *string = (char *)malloc(100 * sizeof(char));

    while (fscanf(file, "%s", string) == 1)
    {
        if (strcmp(string, "Internet") != 0)
        {
            if (strcmp(string, "Länder") == 0)
            {
                string = "Lander";
            }

            W_Word *word = W_createWord(string);
            D_add(word, &dictionary);
            W_delete((void *)word);
        }
    }

    free(string);

    return dictionary;
}
/* Alexandre DUVAL - 17/12/2014 */
/* Alexandre DUVAL - 17/12/2014 */

#include "openFile.h"

FILE *openFile(char *fileName, char *mode)
{
    FILE *file;

    file = fopen(fileName, mode);

    if (file == NULL)
    {
        fprintf(stderr, "\tERREUR : impossible d'open %s, verifiez l'existence du file et ses droits.\n\t (openFile.c)\n", fileName);
        exit(1);
    }

    return file;
}