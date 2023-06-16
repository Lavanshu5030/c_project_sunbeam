#ifndef ISSUERECORD_H
#define ISSUERECORD_H

#include <time.h>

typedef struct issuerecord {
    int id;             // Issue record ID
    int copy_id;        // Copy ID
    int user_id;        // User ID
    char issue_date[20];    // Issue date (string format or use a time_t variable)
    char due_date[20];      // Due date (string format or use a time_t variable)
    char return_date[20];   // Return date (string format or use a time_t variable)
    float fine_amount;  // Fine amount (if any)
}issuerecord_t;


#endif // ISSUERECORD_H
