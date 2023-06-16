#include <stdio.h> // Tier-1
#include <stdlib.h>
#include <string.h>
#include "user_dal.h"
#include "user_service.h"
#include "user_control.h"
#include"user.h"

int user_save(user_t *u) {
    FILE *file = fopen("user.db", "ab");  // Open the file in binary write mode

    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    fwrite(u, sizeof(user_t), 1, file);  // Write the user structure to the file

    fclose(file);  // Close the file

    return 1;
}

user_t* find_user_by_id(int *id) {
    FILE *file = fopen("user.db", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    user_t *user = (user_t* )malloc(sizeof(user_t));
    if (user == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return NULL;
    }

    while (fread(user, sizeof(user_t), 1, file) == 1) {
        if (user->id == *id) {
            fclose(file);
            return user;
        }
    }
  

    fclose(file);
    free(user);
    printf("Record Not Found"); // Do not print in this file
    return NULL;
}

user_t* find_user_by_email(char* email) {
    FILE* file = fopen("user.db", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    user_t temp_user;
    while (fread(&temp_user, sizeof(user_t), 1, file) == 1) {
        if (strcmp(temp_user.email, email) == 0) {
            fclose(file);
            user_t* user = (user_t*) malloc(sizeof(user_t));
            if (user == NULL) {
                printf("Error allocating memory.\n");
                return NULL;
            }
            *user = temp_user; // Copy the data to the allocated memory
            return user;
        }
    }

    fclose(file);
    printf("Record not found.\n");// Do not print in this file
    return NULL;
}

int user_get_max_id() {
    FILE* file = fopen("user.db", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1; // Return -1 to indicate an error
    }

    int max_id = -1; // Initialize with a value that is lower than any possible ID

    user_t temp_user;
    while (fread(&temp_user, sizeof(user_t), 1, file) == 1) {
        if (temp_user.id > max_id) {
            max_id = temp_user.id;
        }
    }

    fclose(file);

    if (max_id == -1) {
        printf("No records found.\n");
    }

    return max_id;
}

void user_update(int id, char* new_email,char* password) {
    FILE* file = fopen("user.db", "r+b");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    user_t temp_user;
    while (fread(&temp_user, sizeof(user_t), 1, file) > 0) {
        if (temp_user.id == id) {
            // Update the record with new values
            strncpy(temp_user.email, new_email, sizeof(temp_user.email));
            strncpy(temp_user.password, password, sizeof(temp_user.password));

            // Move the file pointer back to the beginning of the record
            fseek(file, -sizeof(user_t), SEEK_CUR);

            // Write the updated record back to the file
            fwrite(&temp_user, sizeof(user_t), 1, file);

            printf("Record updated successfully.\n"); // Do not use print in this file
            fclose(file);
            
        }
    }

    fclose(file);
    printf("Record not found.\n"); // Do not user print in this file
}





