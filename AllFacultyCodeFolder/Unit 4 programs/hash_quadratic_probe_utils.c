/*				hash_quadratic_probe_utils.c				*/
#include<stdio.h>
#include<stdlib.h>
#include "hash_linear_probe.h"

static int capacity;

/* this function gives a unique hash code to the given key */
int hashcode(int key)
{
    return (key % capacity);
}

void init_array(struct hashtable_item *array, int max)
{
    int i;
    capacity = max;

    for (i = 0; i < max; i++) 
    {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}

/* to insert a key in the hash table */
int insert(struct hashtable_item *array, int key, int value, int size)
{

    int index = hashcode(key);
    int i = index;
    int h = 1;

    /* creating new item to insert in the hash table array */
    struct item *new_item = (struct item*) malloc(sizeof(struct item));

    new_item->key = key;
    new_item->value = value;

    /* probing through the array until we reach an empty space */

    while (array[i].flag == 1) 
    {
        if (array[i].data->key == key) 
        {
            /* case where already existing key matches the given key */
            printf("\n Key already exists, hence updating its value \n");
            array[i].data->value = value;
            return size;
        }

        i = (i + (h * h)) % capacity;
        h++;
        if (i == index) 
        {
            printf("\n Hash table is full, cannot insert any more item \n");
            return size;
        }
    }

    array[i].flag = 1;
    array[i].data = new_item;
    size++;
    printf("\n Key (%d) has been inserted \n", key);
    return size;
} 

     
/* to remove an element from the hash table */
int remove_element(struct hashtable_item *array, int key, int size)
{
    int index = hashcode(key);
    int  i = index;
    int h = 1;

    /* probing through array until we reach an empty space where not even once an element had been present */
    while (array[i].flag != 0) 
    {
        if (array[i].flag == 1  &&  array[i].data->key == key ) 
        {
            // case when data key matches the given key
            array[i].flag =  2;
            array[i].data = NULL;
            size--;
            printf("\n Key (%d) has been removed \n", key);
            return size;
        }
        i = (i + (h * h)) % capacity;
        h++;
         if (i == index)
            break;
    }
    printf("\n This key does not exist \n");
    return size;
}

     
/* to display all the elements of hash table */
void display(struct hashtable_item *array)
{
    int i;
    for (i = 0; i < capacity; i++)
    {
        struct item *current = (struct item*) array[i].data;
        if (current == NULL) 
            printf("\n Array[%d] has no elements \n", i);
       else
            printf("\n Array[%d] has elements -: \n  %d (key) and %d(value) ", i, current->key, current->value);
    }
}
