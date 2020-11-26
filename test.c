#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hashtable.h>

int main(int argc, void** argv){

	hashtable_t* ht = create_hashtable(5);
	
	int vals[12]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	char* keys[12] = {"ADA", "BOB", "CAL", "DAV", "ELO", "FIZ", "GAG", "HOL", "IKA", "JAD", "KAM", "LOL"};
	
	// inserting items
	for (int i=0; i<12; i++){
		insert_item(ht, keys[i], &vals[i]);
	}
	
	void* v = find_item(ht, "KIM");
	if(v != NULL)
		printf("The value of 'KIM' is %d\n", *((int*) v));
	else
		printf("Key not found\n");
		
	printf("Length of index %d is %d.\n", 1, count_items_at(ht, 1));
	printf("Removing 'ELO': \n");
	remove_item(ht, "ELO");
	
	show_all(ht);
	destroy_hashtable(ht);
	return 0;
}
