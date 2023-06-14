#include <stdio.h>
#include "copy.h"

int copy_save(copy_t *u) {
    FILE *file = fopen("copy.db", "ab");  // Open the file in binary write mode

    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    fwrite(u, sizeof(copy_t), 1, file);  // Write the user structure to the file

    fclose(file);  // Close the file

    return 1;
}