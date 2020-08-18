#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorting.c"
#include "gen_ht.h"

Node* CreateNode(char* key, char* value) {
  Node* node = (Node*)malloc(sizeof(Node));

  node->next = NULL;
  node->key = key;
  node->val = value;
  return node;
}

void DestroyNode(Node* node) {
  free(node->key);
  free(node->val);
  free(node);
  }

void DestroyList(Node* head) {
  while (head != NULL) {
    Node* next = head->next;
    DestroyNode(head);
    head = next;
  }
}

Hashtable* CreateHashtable(int num_buckets) {
  Hashtable* ht = (Hashtable*)malloc(sizeof(Hashtable));
  ht->buckets = (Node**)malloc(WORD_SIZE * num_buckets);
  int i;
  for (i = 0; i < num_buckets; i++) {
    ht->buckets[i] = NULL;
  }
  ht->num_buckets = num_buckets;
  ht->num_elements = 0;
  return ht;
  }


void DestroyHashtable(Hashtable* ht, int destroyNodes) {
  int i;
  if (destroyNodes == 1) {
    for (i = 0; i < ht->num_buckets; i++) {
      DestroyList(ht->buckets[i]);
      }
  }

  free(ht->buckets);
  free(ht);
  }

int HashString(char* key, int buckets) {
  int len = strlen(key);
  int i;
  int acc = 0;
  for (i = 0; i < len; i++) {
    acc += key[i];
  }
  return acc % buckets;
}

void Insert(Hashtable* ht, char* val) {
  char* new_word = (char*)malloc(sizeof(char) * WORD_SIZE);
  strcpy(new_word, val);
  char* key = InsertionSort(val);
  int index = HashString(key, ht->num_buckets);
  char* new_key = (char*)malloc(sizeof(char) * WORD_SIZE);
  strcpy(new_key, key);

  Node* new_node = CreateNode(new_key, new_word);
    if (ht->buckets[index] != NULL) {
      if (strcmp(new_key, ht->buckets[index]->key) == 0) {
        new_node->next = ht->buckets[index];
        } else {
            while (ht->buckets[index] != NULL) {
              index++;
               }
            } 
         }
  ht->buckets[index] = new_node;

  ht->num_elements++;
}


char* Get(Hashtable* ht, char* key) {
  int index = HashString(key, ht->num_buckets);
  char* list = (char*)malloc(sizeof(char) * WORD_SIZE);
  int size = 0;
  Node* node = ht->buckets[index];
  if (node == NULL)
    return NULL;
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
     return node->val;
    }

    node = node->next;
    }
  return NULL;
}
