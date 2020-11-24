#include <hashtable.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// First try
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
	ht->cnt = 0;

	for (unsigned i=0; i < size; i++)
		ht->items[i] = NULL;

	return ht;
}

static void free_item(hash_item_t* it){
	free(it->key);
	// munmap_chunk() when the type is changed  -> item->value should be always allocated
	free(it->value);
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
	
	unsigned h = hash_fct(k) % ht->size;

	hash_item_t* e = ht->items[h];
	
	while(e != NULL) {
		if( !strcmp(e->key, k)){
			// replace existed value
			e->value = v;
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
	
	ht->cnt++;
	
	return 0;
}

void* search(hashtable_t* ht, char* k){
	return NULL;
}

void remove_item(hashtable_t* ht, char* k){

}

void show(hashtable_t* ht, char* k){
	
}
