#ifndef __ISSUERECORD_DAL_H
#define __ISSUERECORD_DAL_H

#include"issuerecord.h"

int issuerecord_save(issuerecord_t *ir);
int get_max_issuerecord_id();
int issuerecord_update(issuerecord_t *ir);
int issuerecord_find_by_id(int issuerecord_id, issuerecord_t *ir);

#endif