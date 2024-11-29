/*				hash_linear_probe_main.c				*/
#include <stdio.h>
#include <stdlib.h>
#include "hash_linear_probe.h"

int main(int argc, char **argv)
{
    int capacity, choice, key, value;
    int size = 0; // Number of valid elements in the array
    struct hashtable_item *array;
    if (argc < 2)
    {
        printf("Usage: %s <capacity>\n", argv[0]);
        exit(1);
    }

    capacity = atoi(argv[1]);
    array = malloc(capacity * sizeof(struct hashtable_item *));
    if (array == NULL)
    {
        printf("Malloc failure in main\n");
        exit(2);
    }

    init_array(array, capacity);
    do
    {
        printf("\n Implementation of Hash Table with Linear Probe in C \n\n");
        printf("MENU-:  \n1.Inserting item in the Hash Table"
               "\n2.Removing item from the Hash Table"
               "\n3.Check the size of Hash Table"
               "\n4.Display a Hash Table"
               "\n5. Quit from the program"
               "\n\n Please enter your choice -:");
        scanf("%d", &choice);
        choice &= 0xff;
        if (choice == 5)
        {
            printf("Breaking out\n");
            break;
        }

        switch (choice)
        {
        case 1:
            printf("Inserting element in Hash Table\n");
            printf("Enter key -:\t");
            scanf("%d", &key);
            printf("Enter value -:\t");
            scanf("%d", &value);
            printf("Calling insert\n");
            size = insert(array, key, value, size);
            break;

        case 2:
            printf("Deleting in Hash Table \n Enter the key to delete-:");
            scanf("%d", &key);
            size = remove_element(array, key, size);
            break;

        case 3:
            printf("Size of Hash Table is-:%d\n", size);
            break;

        case 4:
            display(array);
            break;

        default:
            printf("Wrong Input\n");
        }
    } while (1);
    return 0;
}
