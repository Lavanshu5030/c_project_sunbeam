#ifndef __ISSUERECORD_SERVICE_H
#define __ISSUERECORD_SERVICE_H

int issuerecord_add(char isbn[ISBN_LENGTH], int member_id, int *issuerecord_id);
int issuerecord_edit(int issuerecord_id, copy_t *bc);

#endif