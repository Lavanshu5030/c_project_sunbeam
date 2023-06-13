#include <stdio.h> // Tier-2
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // To use 'R_OK'
#include "user_service.h"
#include "user_dal.h"
#include "user.h"

int user_authenticate(char* email, char* password) {
    FILE* file = fopen("user.db", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0; // Return 0 to indicate authentication failure
    }

    user_t temp_user;
    while (fread(&temp_user, sizeof(user_t), 1, file) == 1) {
        if (strcmp(temp_user.email, email) == 0 && strcmp(temp_user.password, password) == 0) {
            fclose(file);
            return 1; // Return 1 to indicate authentication success
        }
    }

    fclose(file);
    return 0; // Return 0 to indicate authentication failure
}

int user_register(user_t* user) {
    int max_id = user_get_max_id();
    int new_id = max_id + 1;

    user_t new_user;
    new_user.id = new_id;
    strcpy(new_user.email, user->email);
    strcpy(new_user.name, user->name);
    
    user_accept(&new_user);
    user_save(&new_user);
    return 0;
    printf("User registered successfully with ID: %d\n", new_id);
}


int owner_register(user_t *owner) {
    // Check if the "user.db" file exists and is readable
    if (access("user.db", R_OK) == 0) {
        // Delete the "user.db" file
        if (remove("user.db") != 0) {
            printf("Error deleting the file.\n");
            return 0;  // Return 0 to indicate failure
        }
    }

    // Set the ID of the owner
    owner->id = 1;

    // Open the "user.db" file in write binary mode
    FILE* file = fopen("user.db", "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;  // Return 0 to indicate failure
    }

    // Write the owner to the file
    fwrite(owner, sizeof(user_t), 1, file);

    // Close the file
    fclose(file);

    return 1;  // Return 1 to indicate success
}

