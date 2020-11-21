#include <stdio.h>
#include <hashtable.h>

int main(int argc, void** argv){
	hashtable_t* ht = create_hashtable(5);
	for (int i=0; i<ht->size; i++)
		printf("%p\n", ht->items[i]);
	destroy_hashtable(ht);
	return 0;
}
