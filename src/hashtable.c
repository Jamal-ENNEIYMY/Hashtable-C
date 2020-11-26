#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// djb
static unsigned hash_fct(char* k){
	unsigned hash = 5381;
	while (*(k++))
		hash = (hash * 33) + *(k);
	return hash;
}

hashtable_t* create_hashtable(unsigned size){
	hashtable_t* ht = (hashtable_t*) malloc(sizeof(hashtable_t));
	if(!ht) return NULL; // malloc error
	if((ht->items = (hash_item_t**) malloc(size * sizeof(hash_item_t*))) == NULL){
		free(ht->items);
		return NULL;
	}
	
	ht->size = size;

	for (unsigned i=0; i < size; i++)
		ht->items[i] = NULL;

	return ht;
}

static void free_item(hash_item_t* it){
	free(it->key);
	// munmap_chunk() when the type is changed  -> item->value should be always allocated
	// In our case we'll work with ints or basic types so it will raise the above error.
	//free(it->value);
	free(it);
}

void destroy_hashtable(hashtable_t* ht){
	for(int i = 0; i < ht->size; i++){
		hash_item_t* item = ht->items[i];
		while(item != NULL){
			hash_item_t* e = item;
			item = item->next;
			free_item(e);
		}
	}

	free(ht->items);
	free(ht);
}

int insert_item(hashtable_t* ht, char* k, void* v){
	if(v == NULL) {
		printf("Null data cannot be inserted\n");
		return -1;
	}
	// int [-2^31, 2^31-1]  unsigned  [0, 2^32 - 1] 
	unsigned h = hash_fct(k) % ht->size;

	hash_item_t* e = ht->items[h];
	
	while(e != NULL) {
		if( !strcmp(e->key, k)){
			// replace existed value
			e->value = v;
			return 1;
		}
		e = e->next;
	}
	
	// if the key doesn't exist
	if((e = (hash_item_t*) malloc(sizeof(hash_item_t) + strlen(k) + 1)) == NULL){
		return -1;	
	}
	
	e->key = (char*) malloc(sizeof(k));
	strcpy(e->key, k);
	e->value = (void*) malloc(sizeof(v)); 
	e->value = v;
	
	e->next = ht->items[h];
	ht->items[h] = e;
	
	return 0;
}

void* find_item(hashtable_t* ht, char* k){
	// slot sould be in [0, ht->size]
	unsigned int slot = hash_fct(k) % ht->size;
	hash_item_t* item = ht->items[slot];
	
	while (item != NULL) {
		if(strcmp(item->key, k) == 0)
			return item->value;
		item = item -> next;
	}
	return NULL;
}

void show_item(hashtable_t* ht, char* k){
	void* v = find_item(ht, k);
	if (v != NULL) {
		printf("%d",*((int*) v));
	}
	else
		printf("The value of this key is not available!");
}

void show_all(hashtable_t* ht){
	for(int i=0; i<ht->size; i++){
		hash_item_t* e = ht->items[i];
		char indent[50];
		strcpy(indent, "");
		while (e != NULL) {
			if(strcmp(indent, "") == 0) printf("%2d ", i);
			else                        printf("   ");
			printf("%s%s : %d\n", indent, e->key, *((int*) e->value));
			e = e->next;
			strcat(indent, " ");
		}
	}
}

int remove_item(hashtable_t* ht, char* k){
	// keep a reference to the previous item
	// remove by setting prev -> next directly then freeing item.
	unsigned int slot = hash_fct(k) % ht->size;
	hash_item_t* item = ht->items[slot];
	hash_item_t* prev;
  while (item != NULL) {
		if(strcmp(item->key, k) == 0) {
			prev->next = item->next;
			free_item(item);
			return 0;
		}
		prev = item;
		item = item -> next;
	}
	return -1;
}

int count_items_at (hashtable_t* ht, int idx) {
	
	if (idx < 0 || idx >= ht->size){
		printf("Invalid Index\n");
		return -1;
	}
	
	hash_item_t* item = ht->items[idx];
	
	int c = 0;
	
	while (item != NULL) {
		c++;
		item = item -> next;
	}
	
	return c;
}
