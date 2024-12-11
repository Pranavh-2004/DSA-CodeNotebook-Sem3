//TRIE houses lower case english alphabets only

#include<stdio.h>
#include<stdlib.h>

typedef struct trie
{
	struct trie *child[26];
	int endOfWord;
}TRIE;

TRIE* createNode();
void insertPattern(TRIE *root,char *pattern);
int searchPattern(TRIE *root,char *pattern);
void destroyTrie(TRIE *root);
void displayTrie(TRIE *root,char *pattern,int level);
void displayTrieOfLength(TRIE *root,char *pattern,int level,int length);
TRIE* deletePattern(TRIE *root,char *str,int level,int length);

int main()
{
	TRIE *root=createNode();
	
	insertPattern(root,"cats");
	insertPattern(root,"cat");
	insertPattern(root,"car");
	insertPattern(root,"data");
	
	if(searchPattern(root,"ca"))
		printf("ca present\n");
	else
		printf("ca not present\n");
	
	if(searchPattern(root,"cats"))
		printf("cats present\n");
	else
		printf("cats not present\n");
	
	if(searchPattern(root,"cat"))
		printf("cat present\n");
	else
		printf("cat not present\n");
	
	if(searchPattern(root,"car"))
		printf("car present\n");
	else
		printf("car not present\n");
	
	if(searchPattern(root,"data"))
		printf("data present\n");
	else
		printf("data not present\n");
	
	char str[20];
	
	printf("Patterns housed in trie\n");
	displayTrie(root,str,0);
	
	printf("Patterns housed in trie of length 4\n");
	displayTrieOfLength(root,str,0,4);
	
	root=deletePattern(root,"cat",0,3);
	root=deletePattern(root,"data",0,4);
	root=deletePattern(root,"cap",0,3);
	
	printf("Patterns housed in trie after deletion\n");
	displayTrie(root,str,0);
	
	destroyTrie(root);
	free(root);
	root=NULL;
}

TRIE* createNode()
{
	TRIE *newNode=malloc(sizeof(TRIE));
	
	for(int i=0;i<26;i++)
		newNode->child[i]=NULL;
	
	newNode->endOfWord=0;
	
	return newNode;
}

void insertPattern(TRIE *root,char *pattern)
{
	int index;
	while(*pattern)
	{
		index=*pattern-'a';
		
		if(root->child[index]==NULL)
			root->child[index]=createNode();
		
		root=root->child[index];
		pattern++;
	}
	root->endOfWord=1;
}
int searchPattern(TRIE *root,char *pattern)
{
	int index;
	
	while(*pattern)
	{
		index=*pattern-'a';
		
		if(root->child[index]==NULL)
			return 0;
		
		root=root->child[index];
		pattern++;
	}
	return root->endOfWord;
}

void destroyTrie(TRIE *root)
{
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		{
			destroyTrie(root->child[i]);
			printf("%c freed\n",i+'a');
			free(root->child[i]);
			root->child[i]=NULL;
		}
	}
}

void displayTrie(TRIE *root,char *str,int level)
{
	if(root->endOfWord==1)
	{
		str[level]='\0';
		printf("%s\n",str);
	}
	
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		{
			str[level]=i+'a';
			displayTrie(root->child[i],str,level+1);
		}
	}
}

void displayTrieOfLength(TRIE *root,char *str,int level,int length)
{
	if(root->endOfWord==1 && level==length)
	{
		str[level]='\0';
		printf("%s\n",str);
	}
	
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		{
			str[level]=i+'a';
			displayTrieOfLength(root->child[i],str,level+1,length);
		}
	}
}

int isEmpty(TRIE *root)
{
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
			return 0;
	}
	return 1;
}

TRIE* deletePattern(TRIE *root,char *str,int level,int length)
{
	if(root==NULL)	//Base case for unsuccessful deletion
		return root;	//return NULL;
	
	if(length==level)	//Base case for successful deletion
	{
		if(root->endOfWord==1)
			root->endOfWord=0;
		
		if(isEmpty(root))
		{
			free(root);
			root=NULL;
		}
		return root;
	}

	int index=str[level]-'a';
	
	root->child[index]=deletePattern(root->child[index],str,level+1,length);
	
	if(root->endOfWord==0 && isEmpty(root))
	{
		free(root);
		root=NULL;
	}
	return root;
}