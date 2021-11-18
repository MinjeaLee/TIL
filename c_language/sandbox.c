void insert(char arr[], char ch, int index) {
    char* p;
    int len;
    len = strlen(arr);

    for (p = arr + len; p > arr + index; p--){
        *p = *(p - 1);
    }
    *(arr + in