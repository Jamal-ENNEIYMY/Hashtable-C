#include <hashtable.h>
#include <stdlib.h>

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

void destroy_hashtable(hashtable_t* ht){
}

unsigned insert_item(hashtable_t* ht, char* k, void* v){
	return 0;
}

void* search(hashtable_t* ht, char* k){
	return NULL;
}

void remove_item(hashtable_t* ht, char* k){

}

void show(hashtable_t* ht, char* k){

}

