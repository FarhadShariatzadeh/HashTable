#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* InsertionSort(char* data) {
  char temp;
  int i;
  int j;
 
  int n = strlen(data);

  for (i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
      if (data[i] > data[j]) {
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }
  }
  return data;
}

