#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gen_ht.h"



void PrintHashtable(Hashtable* ht) {
  printf("\n");
  int i;
  for (i = 0; i < ht->num_buckets; i++) {
    printf("%d: ", i);
    Node* node = ht->buckets[i];
    while (node != NULL) {
      printf("[%s:%s] ", node->key, node->val);

       node = node->next;
    }
    printf("\n");
  }
  printf("\n");
}


int main() {
  Hashtable* ht = CreateHashtable(WORD_SIZE);

  FILE * fp;
  char line[WORD_SIZE];
  fp = fopen("words2.txt", "r");
  while (fgets(line, WORD_SIZE, fp) != NULL) {
    Insert(ht, strtok(line, "\n"));
  }
  PrintHashtable(ht);

  char* value = Get(ht, "aal");
  if (strcmp(value, "laa") == 0) {
    printf("test passed!\n");
  }

  fclose(fp);
  DestroyHashtable(ht, 1);
  return 0;
  }
