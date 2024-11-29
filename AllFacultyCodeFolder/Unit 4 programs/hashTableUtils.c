//			hashTableUtils.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTable.h"

unsigned long hash_function(char *str)
{
    unsigned long i = 0;

    for (int j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}

LINKEDLIST *allocate_list()
{
    // Allocates memory for a LinkedList pointer.
    LINKEDLIST *list = (LINKEDLIST *) malloc (sizeof(LINKEDLIST));
    if (list == NULL)
    {
	printf ("malloc failure\n");
	exit (1);
    }
    list->next = NULL;
    return list;
}

LINKEDLIST *linkedlist_insert(LINKEDLIST *list, HT_ITEM *item)
{
    // Inserts the item onto the LinkedList.
    if (!list)
    {
        LINKEDLIST *head = allocate_list();
        head->item = item;
        head->next = NULL;
        list = head;
        return list;
    }
    else if (list->next == NULL)
    {
        LINKEDLIST *node = allocate_list();
        node->item = item;
        node->next = NULL;
        list->next = node;
        return list;
    }

    LINKEDLIST *temp = list;

    while (temp->next->next)
    {
        temp = temp->next;
    }

    LINKEDLIST *node = allocate_list();
    node->item = item;
    node->next = NULL;
    temp->next = node;
    return list;
}

void free_item(HT_ITEM *item)
{
    // Frees an item.
    free(item->key);
    free(item->value);
    free(item);
}


HT_ITEM *linkedlist_remove(LINKEDLIST *list)
{
    // Removes the head from the LinkedList.
    // Returns the item of the popped element.
    if (!list)
        return NULL;

    if (!list->next)
        return NULL;

    LINKEDLIST *node = list->next;
    LINKEDLIST *temp = list;
    temp->next = NULL;
    list = node;
    HT_ITEM *it = malloc (sizeof (HT_ITEM));
    if (it == NULL)
    {
	printf ("malloc failure\n");
	exit (1);
    }
    memcpy(temp->item, it, sizeof(HT_ITEM));
    free_item(temp->item);
    free(temp);
    return it;
}


void free_linkedlist(LINKEDLIST *list)
{
    LINKEDLIST *temp = list;

    while (list)
    {
        temp = list;
        list = list->next;
        free_item(temp->item);
        free(temp);
    }
}

LINKEDLIST **create_overflow_buckets(HASHTABLE *table)
{
    // Create the overflow buckets; an array of LinkedLists.
    LINKEDLIST **buckets = (LINKEDLIST **)calloc(table->size, sizeof(LINKEDLIST *));
    
    if (buckets == NULL)
    {
	printf ("malloc failure\n");
	exit (1);
    }

    for (int i = 0; i < table->size; i++)
        buckets[i] = NULL;

    return buckets;
}

void free_overflow_buckets(HASHTABLE *table)
{
    // Free all the overflow bucket lists.
    LINKEDLIST **buckets = table->overflow_buckets;

    for (int i = 0; i < table->size; i++)
        free_linkedlist(buckets[i]);

    free(buckets);
}

HT_ITEM *create_item(char *key, char *value)
{
    // Creates a pointer to a new HashTable item.
    HT_ITEM *item = (HT_ITEM *)malloc(sizeof(HT_ITEM));
    item->key = (char *)malloc(strlen(key) + 1);
    item->value = (char *)malloc(strlen(value) + 1);
    if ((item == NULL) || (key == NULL) || (value == NULL))
    {
	printf ("malloc failure\n");
	exit (1);
    }
    strcpy(item->key, key);
    strcpy(item->value, value);
    return item;
}

HASHTABLE *create_table(int size)
{
    // Creates a new HashTable.
    HASHTABLE *table = (HASHTABLE *)malloc(sizeof(HASHTABLE));
    if (table == NULL)
    {
	printf ("Malloc failure in create_table()\n");
	exit (1);
    }
    table->size = size;
    table->count = 0;
    table->items = (HT_ITEM **)calloc(table->size, sizeof(HT_ITEM *));
    if (table->items == NULL)
    {
        printf ("calloc failure\n");
	exit (1);
    }

    for (int i = 0; i < table->size; i++)
        table->items[i] = NULL;

    table->overflow_buckets = create_overflow_buckets(table);

    return table;
}


void free_table(HASHTABLE *table)
{
    // Frees the table.
    for (int i = 0; i < table->size; i++)
    {
        HT_ITEM *item = table->items[i];

        if (item != NULL)
            free_item(item);
    }

    // Free the overflow bucket lists and its items.
    free_overflow_buckets(table);
    free(table->items);
    free(table);
}

void handle_collision(HASHTABLE *table, unsigned long index, HT_ITEM *item)
{
    LINKEDLIST *head = table->overflow_buckets[index];

    //printf ("Trying to handle collision\n");
    if (head == NULL)
    {
	//printf ("head was NULL index was %d\n", index);
        // Creates the list.
        head = allocate_list();
        head->item = item;
        table->overflow_buckets[index] = head;
        return;
    }
    else
    {
	//printf ("head was non NULL index was %d\n", index);
        // Insert to the list.
        table->overflow_buckets[index] = linkedlist_insert(head, item);
        return;
    }
}

void ht_insert(HASHTABLE *table, char *key, char *value)
{
    // Creates the item.
    HT_ITEM *item = create_item(key, value);

    // Computes the index.
    int index = hash_function(key);

    HT_ITEM *current_item = table->items[index];

    if (current_item == NULL)
    {
        // Key does not exist.
        if (table->count == table->size)
        {
            // HashTable is full.
            printf("Insert Error: Hash Table is full\n");
            free_item(item);
            return;
        }

        // Insert directly.
        table->items[index] = item;
        table->count++;
    }
    else
    {
        // Scenario 1: Update the value.
        if (strcmp(current_item->key, key) == 0)
        {
            strcpy(table->items[index]->value, value);
            return;
        }
        else
        {
	    //printf ("Collision has occurred\n");
            // Scenario 2: Handle the collision.
            handle_collision(table, index, item);

            return;
        }
    }
}

char *ht_search(HASHTABLE *table, char *key)
{
    // Searches for the key in the HashTable.
    // Returns NULL if it doesn't exist.
    int index = hash_function(key);	// Get the hash value of the key
    HT_ITEM *item = table->items[index];
    LINKEDLIST *head = table->overflow_buckets[index];
    LINKEDLIST *ptemp;
    char *retVal = NULL;

    // Provide only non-NULL values.
    if (item != NULL)
    {
        if (strcmp(item->key, key) == 0)
	    retVal = item->value;
	else
	{
 	    if (head != NULL)
	    {
		for (ptemp = head; ptemp != NULL; ptemp = ptemp->next)
		{
			if (strcmp (ptemp->item->key, key) == 0)
			{
			    retVal = ptemp->item->value;
			    break;
			}
		}
	    }
	}
    }	
    return retVal;
}

void ht_delete(HASHTABLE *table, char *key)
{
    // Deletes an item from the table.
    int index = hash_function(key);
    HT_ITEM *item = table->items[index];
    LINKEDLIST *head = table->overflow_buckets[index];

    if (item == NULL)
    {
        // Does not exist.
        return;
    }
    else
    {
        if (head == NULL && strcmp(item->key, key) == 0)
        {
            // Collision chain does not exist.
            // Remove the item.
            // Set table index to NULL.
            table->items[index] = NULL;
            free_item(item);
            table->count--;
            return;
        }
        else if (head != NULL)
        {
            // Collision chain exists.
            if (strcmp(item->key, key) == 0)
            {
                // Remove this item.
                // Set the head of the list as the new item.
                free_item(item);
                LINKEDLIST *node = head;
                head = head->next;
                node->next = NULL;
                table->items[index] = 
			create_item(node->item->key, node->item->value);
                free_linkedlist(node);
                table->overflow_buckets[index] = head;
                return;
            }

            LINKEDLIST *curr = head;
            LINKEDLIST *prev = NULL;

            while (curr)
            {
                if (strcmp(curr->item->key, key) == 0)
                {
                    if (prev == NULL)
                    {
                        // First element of the chain.
                        // Remove the chain.
                        free_linkedlist(head);
                        table->overflow_buckets[index] = NULL;
                        return;
                    }
                    else
                    {
                        // This is somewhere in the chain.
                        prev->next = curr->next;
                        curr->next = NULL;
                        free_linkedlist(curr);
                        table->overflow_buckets[index] = head;
                        return;
                    }
                }

                curr = curr->next;
                prev = curr;
            }
        }
    }
}

void print_search(HASHTABLE *table, char *key)
{
    char *val;

    if ((val = ht_search(table, key)) == NULL)
    {
        printf("Key:%s does not exist\n", key);
        return;
    }
    else
    {
        printf("Key:%s, Value:%s\n", key, val);
    }
}

void print_list_items (LINKEDLIST *plist)
{
	LINKEDLIST *ptemp;

	for (ptemp = plist; ptemp != NULL; ptemp = ptemp->next)
	    printf ("\tKey is %s Value is %s\n", ptemp->item->key, 
						ptemp->item->value);
}

void print_table(HASHTABLE *table)
{
    printf("\nHash Table\n-------------------------------------------\n");

    for (int i = 0; i < table -> size; i++)
    {
        if (table -> items[i])
        {
            printf("Index:%d, Key:%s, Value:%s\n", i, table -> items[i] -> key, table -> items[i] -> value);
        }
	// If we have encountered collision
	if (table->overflow_buckets[i])
	    print_list_items (table->overflow_buckets[i]);
    }

    printf("--------------------------------------------\n\n");
}