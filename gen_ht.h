#define NUM_BUCKETS 420000
#define WORD_SIZE 40

#ifndef GEN_HT_H
#define GEN_HT_H


typedef struct Node {
  char* val;
  char* key;
  struct Node* next;
} Node;

typedef struct {
  Node** buckets;
  int num_elements;
  int num_buckets;
  } Hashtable;


Node* CreateNode(char* key, char* value);

Hashtable* CreateHashtable(int num_buckets);

void Insert(Hashtable* ht, char* key);

#endif 
