//			hashTableUtilsSimple.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTableSimple.h"

static int collision_handling;

unsigned long hash_function(char *str)
{
    unsigned long i = 0;

    for (int j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}


void linear_probe (HASHTABLE *table, int index, HT_ITEM *item)
{
	int i;

	printf ("Starting index is %d\n", index);

	for (i = index + 1; i != index; i ++)
	{
		i %= CAPACITY;
		if (table->items[i] == NULL)
		{
			printf ("New index is %d\n", i);
			table->items[i] = item;
			table->count ++;
			break;
		}
	}
	if (i == index)
		printf ("Table is full\n");
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

    return table;
}

void free_item(HT_ITEM *item)
{
    // Frees an item.
    free(item->key);
    free(item->value);
    free(item);
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
    free(table->items);
    free(table);
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
	    // Call any method (linear, quadratic probing or double
            // hashing to handle collision
	    printf ("Collision has occurred\n");
	    linear_probe (table, index, item);
            return;
        }
    }
}

char *ht_search(HASHTABLE *table, char *key)
{
    // Searches for the key in the HashTable.
    // Returns NULL if it doesn't exist.
    int index = hash_function(key);
    HT_ITEM *item = table->items[index];
   

    // Provide only non-NULL values.
    if (item != NULL)
    {
        if (strcmp(item->key, key) == 0)
            return item->value;
    }

    return NULL;
}

void ht_delete(HASHTABLE *table, char *key)
{
    // Deletes an item from the table.
    int index = hash_function(key);
    HT_ITEM *item = table->items[index];
    
    if (item == NULL)
    {
        // Does not exist.
        return;
    }
    else
    {
        if (strcmp(item->key, key) == 0)
        {
            // Collision chain does not exist.
            // Remove the item.
            // Set table index to NULL.
            table->items[index] = NULL;
            free_item(item);
            table->count--;
            return;
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

void print_table(HASHTABLE *table)
{
    printf("\nHash Table\n-------------------------------------------\n");

    for (int i = 0; i < table -> size; i++)
    {
        if (table -> items[i])
        {
            printf("Index:%d, Key:%s, Value:%s\n", i, table -> items[i] -> key, table -> items[i] -> value);
        }
    }

    printf("--------------------------------------------\n\n");
}