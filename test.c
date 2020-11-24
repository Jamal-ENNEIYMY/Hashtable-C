#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hashtable.h>

int main(int argc, void** argv){

	hashtable_t* ht = create_hashtable(5);
	
	int* c = (int*) malloc(sizeof(int));
	*c = 784532135;
	
	insert_item(ht, "ABA", c);
	*c = 5;
	insert_item(ht, "ABB", c); *c = 54646541;
	insert_item(ht, "ABC", c); *c = 443337;
	insert_item(ht, "ACD", c); *c = 789864;
	insert_item(ht, "AQD", c); *c = 789864;
	insert_item(ht, "RBD", c); *c = 789864;
	
	for(int i=0; i<ht->size; i++){
		hash_item_t* e = ht->items[i];
		char indent[50];
		strcpy(indent, "");
		while (e != NULL) {
			printf("%s%s : %d\n", indent, e->key, *((int*) e->value));
			e = e->next;
			strcat(indent, " ");
		}
	}
	destroy_hashtable(ht);
	return 0;
}
