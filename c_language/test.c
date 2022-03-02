#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// make func add string to string
char* add_string(char* str1, char* str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* result = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

// make func Dijkstra Algorithm
int* Dijkstra(int** matrix, int len){
    int* distance = (int*)malloc(sizeof(int) * len);
    int* visited = (int*)malloc(sizeof(int) * len);
    int* path = (int*)malloc(sizeof(int) * len);
    int* result = (int*)malloc(sizeof(int) * len);
    int min = 0;
    int min_index = 0;
    
    for(int i = 0; i < len; i++){
        distance[i] = matrix[0][i];
        visited[i] = 0;
        path[i] = 0;
    }
    visited[0] = 1;
    for(int i = 0; i < len - 1; i++){
        min = INT_MAX;
        for(int j = 0; j < len; j++){
            if(visited[j] == 0 && distance[j] < min){
                min = distance[j];
                min_index = j;
            }
        }
        visited[min_index] = 1;
        for(int j = 0; j < len; j++){
            if(visited[j] == 0 && matrix[min_index][j] != INT_MAX){
                if(distance[j] > distance[min_index] + matrix[min_index][j]){
                    distance[j] = distance[min_index] + matrix[min_index][j];
                    path[j] = min_index;
                }
            }
        }
    }
    result[0] = distance[len - 1];
    result[1] = path[len - 1];
    return result;
}

// make func get min of array
int get_min(int* array, int len){
    int min = array[0];
    for(int i = 1; i < len; i++){
        if(array[i] < min){
            min = array[i];
        }
    }
    return min;
}

// make func get max of array
int get





int main(){
    

    return 0;
}