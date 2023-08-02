#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/fake_sgbd.h"



int main(){

    Fake_sgbd* sgbd = new_Fake_sgdb();

    while(1){

        char query[MAX_QUERY_LENGTH];

        printf("fake_sql> ");

        fgets(query,MAX_QUERY_LENGTH,stdin);

        process_query(sgbd, query);

    }

    free_Fake_sgdb(sgbd);
}


