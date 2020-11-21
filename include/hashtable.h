#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

typedef struct hash_elem_t {
	struct hash_elem_t* next;
	void* value;
	char* key;
} hash_item_t;

typedef struct {
	hash_item_t* items;
	unsigned int size;
	unsigned int cnt;
} hashtable_t;


hashtable_t* create_hashtable(unsigned size);

void destroy_hashtable(hashtable_t*);

// return current cnt
unsigned insert_item(hashtable_t*, char*, void*);
void* search(hashtable_t*, char*);
void remove_item(hashtable_t*, char*);
void show(hashtable_t*, char*);

#endif
