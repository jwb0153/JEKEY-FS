#include<stdbool.h>
#include"user.h"
#include<stdlib.h>

int checkUser(struct user* allUsers, const char* name){
    for(int i = 0; &allUsers+i < &allUsers+TOTAL_USER; i++){
        if(&(allUsers+i)->user_name[USER_NAME_MAX_LENGTH] == name[USER_NAME_MAX_LENGTH]){
            printf("User exists! ID:%s\n",&(allUsers+i)->user_id);
            return i;
        }else if(&(allUsers+i+1)->user_id == 0){
            return USER_NAME_MAX_LENGTH+1;
            printf("User does not exist!");
        }
    }
    // Users are all registered, and not here 
    return 0;
}

struct user* login(struct user* allUsers, const char* name, const char* password){
    
    return 0;
}

bool createUser(struct user* allUsers, const char* name, const char* password){
    struct user* u;
    // Does user exist?
    int id = checkUser(allUsers,name);
    if(id == 0){
        //CREATE
        u->user_name[USER_NAME_MAX_LENGTH] = name[USER_NAME_MAX_LENGTH];
        u->user_password[USER_PASSWORD_MAX_LENGTH] = password[USER_PASSWORD_MAX_LENGTH];
        saveUser(u->user_id);
        return true;
    }
    return false;
}

void initUser(){
    struct user* u;
    u->user_id = NULL;
    u->user_name[USER_NAME_MAX_LENGTH]=NULL;
    u->user_password[USER_PASSWORD_MAX_LENGTH]=NULL;
}

bool openUser(struct user* u){
    return false;
}

void listUser(struct user* u){
    int i = checkUser(u,u->user_name);
    if(i != 0 && i != USER_NAME_MAX_LENGTH+1)
        printf("User %d: ", i,"%s", (u+i)->user_name[USER_NAME_MAX_LENGTH]);
}

void saveUser(struct user* u){
    // TODO save
    // TODO save
    int e = EXIT_SUCCESS;
    /* Get path from argument to main else default to output.txt */
    char *path = FILENAME;
    /* Open file for writing and obtain file pointer */
    FILE *file = fopen(path, "w");
    /* Print error message and exit if fopen() failed */
    if (!file)
    {
    perror(path);
    return EXIT_FAILURE;
    }
    /* Writes text to file. Unlike puts(), fputs() does not add a new-line. */
    if (fputs("Output in file.\n", file) == EOF)
    {
    perror(path);
    e = EXIT_FAILURE;
    }
    /* Close file */
    if (fclose(file))
    {
    perror(path);
    return EXIT_FAILURE;
    }
    return e;
}
