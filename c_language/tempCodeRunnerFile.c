 for(int i = 0; i < final_num - 1; i++){
        for(int j = 0; j < final_num - 1 - i; j++){
            if(strcmp(result[j], result[j + 1]) > 0) {
                strcpy(tmp, result[j]);
                strcpy(result[j], result[j + 1]);
                strcpy(result[j + 1], tmp);
            }
        }
    }
