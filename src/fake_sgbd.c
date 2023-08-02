#include "../include/fake_sgbd.h"

struct fake_sgbd{
    char current_selected_db[MAX_DATABASE_LENGTH];
    char is_selected_db;
};


Fake_sgbd* new_Fake_sgdb(){
    Fake_sgbd* sgbd = (Fake_sgbd*) malloc(sizeof(Fake_sgbd));
    if(sgbd != NULL){
        sgbd->is_selected_db = FALSE;
    }
    return sgbd;
}

void process_query(Fake_sgbd* sgbd, char* query){

        query[strcspn(query,"\n")] = '\0';

        if(strncmp(query,"CREATE DATABASE", 15) == 0){

            process_create_database_query(query);

        }else if(strncmp(query,"USE", 3) == 0){

            process_use_query(sgbd, query);

        }else if(strncmp(query,"CREATE TABLE", 12) == 0){
    
            process_create_table_query(sgbd, query);

        }else if(strncmp(query,"DROP TABLE", 10) == 0){

            process_drop_table_query(sgbd, query);

        }else{

            printf("Comando invalido...\n");

        }

    return;
}

void process_create_database_query(char* query){

    char databaseName[MAX_DATABASE_LENGTH];
    sscanf(query,"CREATE DATABASE %s", databaseName);
    char system_cmd[MAX_QUERY_LENGTH] = "mkdir ";


    char database_path[MAX_PATH_LENGTH] = DATABASES_PATH;
    strcat(database_path, databaseName);
    strcat(system_cmd, database_path);

    system(system_cmd);
    
    char file_name[MAX_FILE_NAME_LENGTH];
    strcpy(file_name,databaseName);
    strcat(file_name, DB_INFO_EXTENSION);

    char file_path[MAX_PATH_LENGTH] = DATABASES_PATH;
    strcat(file_path, databaseName);
    strcat(file_path, "\\");
    strcat(file_path, file_name);

    FILE* config = fopen(file_path, "w");
    fprintf(config,"TABLES: 0");
    printf("database %s criado com sucesso.\n",databaseName);
    fclose(config);

    return;
}


void process_use_query(Fake_sgbd* sgbd, char* query){

    char databaseName[MAX_DATABASE_LENGTH];
    sscanf(query,"USE %s", databaseName);
    
    sgbd->is_selected_db = TRUE;
    strcpy(sgbd->current_selected_db, databaseName);

    printf("DATABASE %s SELECIONADO\n");

    return;
}

void process_create_table_query(Fake_sgbd* sgbd, char* query){
    char tablename[MAX_TABLE_NAME_LENGTH];
    sscanf(query,"CREATE TABLE %s", tablename);
    char file_name[MAX_FILE_NAME_LENGTH];
    strcpy(file_name, tablename);
    strcat(file_name, TABLE_EXTENSION);
    char file_path[MAX_PATH_LENGTH] = DATABASES_PATH;
    strcat(file_path,sgbd->current_selected_db);
    strcat(file_path,"\\");
    strcat(file_path, file_name);

    FILE* table = fopen(file_path, "w");
    fprintf(table, "tabela %s", tablename);
    fclose(table);

    return;
}


void process_insert_into_values_query(Fake_sgbd* sgbd, char* query){
    return;
}

void process_update_set_where_query(Fake_sgbd* sgbd, char* query){
    return;
}

void process_delete_from_where_query(Fake_sgbd* sgbd, char* query){
    return;
}

void process_drop_table_query(Fake_sgbd* sgbd, char* query){
    char system_cmd[MAX_CMD_LENGTH] = DELETE_FILE_CMD;
    char tablename[MAX_TABLE_NAME_LENGTH];
    sscanf(query, "DROP TABLE %s", tablename);
    char file_name[MAX_FILE_NAME_LENGTH];
    strcpy(file_name, tablename);
    strcat(file_name, TABLE_EXTENSION);
    char file_path[MAX_PATH_LENGTH] = DATABASES_PATH;
    strcat(file_path,sgbd->current_selected_db);
    strcat(file_path,"\\");
    strcat(file_path, file_name);
    strcat(system_cmd, file_path);

    system(system_cmd);
    
    return;
}

void process_drop_database_query(Fake_sgbd* sgbd, char* query){


    return;
}

void free_Fake_sgdb(Fake_sgbd* sgdb){
    free(sgdb);
}

