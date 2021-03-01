#include <stdio.h>
#include "slist.h"
#include "snode.h"

struct slist *song_list;

int main(void)   {

    struct snode *node;

    song_list = slist_create();

    slist_add_back(song_list, "Thinking Out Loud");
    slist_add_back(song_list, "See You Again");
    slist_add_back(song_list, "Trap Queen");
    slist_add_back(song_list, "Sugar");
    slist_add_back(song_list, "Shut Up and Dance");
    slist_add_back(song_list, "Blank Space");
    slist_add_back(song_list, "Watch Me");
    slist_add_front(song_list, "Uptown Funk");
    slist_add_back(song_list, "Earned It");
    slist_delete(song_list, "Sugar");
    printf("Here are the top %d songs:\n", slist_length(song_list));

    printf("Content of the list as follows.\n");
    slist_traverse(song_list);

    node = slist_find(song_list, "Uptown Funk");
    printf("Search 'Uptown Funk', node address %p\n", node);
    node = slist_find(song_list, "Earned It");
    printf("Search 'Earned It', node address %p\n", node);
    node = slist_find(song_list, "Sugar");
    printf("Search 'Sugar', node address %p\n", node); 
    node = slist_find(song_list, "My Heart Will Go On");
    printf("Search 'My Heart Will Go On', node address %p\n", node);  // should be NULL
    
    slist_destroy(song_list);

    return 0;
}
