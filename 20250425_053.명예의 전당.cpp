//URL :https://school.programmers.co.kr/learn/courses/30/lessons/138477

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void insertion_sort(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


int* solution(int k, int score[], size_t score_len) {
    int* answer = (int*)malloc(sizeof(int) * score_len); 
    int* hall_of_fame = (int*)malloc(sizeof(int) * k);  
    int fame_count = 0; 

    for (int day = 0; day < score_len; day++) {
        if (fame_count < k) {
            hall_of_fame[fame_count++] = score[day];
        } else {
            insertion_sort(hall_of_fame, fame_count);
            if (score[day] > hall_of_fame[0]) {
                hall_of_fame[0] = score[day];
            }
        }

        insertion_sort(hall_of_fame, fame_count);
        answer[day] = hall_of_fame[0];
    }

    free(hall_of_fame);
    return answer;
}