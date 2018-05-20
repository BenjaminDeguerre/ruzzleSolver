/* Alexandre DUVAL - 06/12/14 */
/* Alexandre DUVAL - 31/12/14 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "transcode.h"

int main(int argc, char **argv) {
  if (argc == 3) {
    transcode(argv[1], argv[2]);
  } else {
    printf("usage : transcode <dictionary-ref..> <dictionary intelligent>\n");
  }

  return EXIT_SUCCESS;
}