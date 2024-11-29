//			hashTableSimple.h

#define CAPACITY 500 // Size of the HashTable.
#define MAX_LEN	100

#define LINEAR_PROBE	1
#define QUADRATIC_PROBE	2
#define DOUBLE_HASHING	3

// HashTable item.
typedef struct Ht_item
{
    char *key;
    char *value;
} HT_ITEM;

// The HashTable.
typedef struct HashTable
{
    // Contains an array of pointers to items.
    HT_ITEM **items;
    int size;
    int count;
} HASHTABLE;

HASHTABLE *create_table(int);
void ht_insert(HASHTABLE *, char *, char *);
char *ht_search(HASHTABLE *, char *);
void ht_delete(HASHTABLE *, char *);
void print_table(HASHTABLE *);
void free_table(HASHTABLE *);