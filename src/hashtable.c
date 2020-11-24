#include <hashtable.h>
#include <stdlib.h>
#include <string.h>

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
	free(it->value);
	free(it);
}

void destroy_hashtable(hashtable_t* ht){
	for(int i = 0; i < ht->size; i++){
		hash_item_t* item = ht->items[i];
		if (item != NULL)
			free_item(item);
	}

	free(ht->items);
	free(ht);
}

unsigned int hashFunction(char* key){
	long int hashValue = 0;
	unsigned int i = 0;
	unsigned int keyLenght = strlen(key);
	hashtable_t* ht;
	for (i = 0; i < keyLenght ; i++)
	{
		hashValue = hashValue * 37 + key[i];
	}
	hashValue = hashValue % ht->size;
}
void insert_item(hashtable_t* ht, char* k, void* v){

}
void* search(hashtable_t* ht, char* k){
	
	/* here we need a hash function to find the hash value.
	hash value is used to find to the location of 
	key's item.*/

	unsigned int slot = hashFunction(k);
	hash_item_t* item = ht->items[slot];

	if (item == NULL)
	{
		return;
	}
	while (item != NULL)
	{
		if(strcmp(item->key,k) == 0){
			printf("",item->value);
		}else
		{
			item = item -> next;
		}
		
	}
	return NULL;
}

void remove_item(hashtable_t* ht, char* k){

}
