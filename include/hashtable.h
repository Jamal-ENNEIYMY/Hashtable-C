#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

typedef struct hash_item_t {
	struct hash_item_t* next;
	void* value;
	char* key;
} hash_item_t;

typedef struct {
	hash_item_t** items;
	unsigned int size;
	unsigned int cnt;
} hashtable_t;

hashtable_t* create_hashtable(unsigned size);

void destroy_hashtable(hashtable_t*);

// returns -1 : error		0 : all good 		1 : already existing key
int insert_item(hashtable_t*, char*, void*);
void* find_item(hashtable_t*, char*);
// 0 removed successfully   -1 : not found;
int remove_item(hashtable_t*, char*);
void show_item(hashtable_t*, char*);
void show_all(hashtable_t*);
int count_items_at (hashtable_t*, int);

#endif
