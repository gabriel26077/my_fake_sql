#ifndef FAKE_SGDB
#define FAKE_SGDB

#define DATABASES_PATH ".\\DATABASES\\"

#define MAX_QUERY_LENGTH 100
#define MAX_DATABASE_LENGTH 50
#define MAX_TABLE_NAME_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100
#define MAX_PATH_LENGTH 100
#define MAX_CMD_LENGTH 200

#define DELETE_FILE_CMD "del "

#define TABLE_EXTENSION ".table"
#define DB_INFO_EXTENSION ".infodb"

#define FALSE 0
#define TRUE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fake_sgbd Fake_sgbd;

Fake_sgbd* new_Fake_sgdb();

void process_query(Fake_sgbd* sgbd, char* query);
void process_create_database_query(char* query);
void process_use_query(Fake_sgbd* sgbd, char* query);
void process_create_table_query(Fake_sgbd* sgbd, char* query);
void process_insert_into_values_query(Fake_sgbd* sgbd, char* query);
void process_update_set_where_query(Fake_sgbd* sgbd, char* query);
void process_delete_from_where_query(Fake_sgbd* sgbd, char* query);
void process_drop_table_query(Fake_sgbd* sgbd, char* query);
void process_drop_database_query(Fake_sgbd* sgbd, char* query);

void free_Fake_sgdb(Fake_sgbd* sgbd);

#endif