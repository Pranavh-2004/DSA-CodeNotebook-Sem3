//			FSFunctions.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "FileSystem.h"

static CMDVAL s_cmds [] = {{"cd", CD_CMD}, {"mkdir", MKDIR_CMD}, 
		{"ls", LS_CMD},	{"touch", TOUCH_CMD}, {"exit", EXIT_CMD},
		{NULL, INVALID_CMD}};
	

void InitDirName (M_DIRECTORY *p_mdir, char *dir_name)
{
	if ((p_mdir -> directoryName = 
		(char *) malloc (strlen (dir_name)+1)) == NULL)
	{
		perror ("Memory allocation failure for directoryName");
		exit (0);
	}
	strcpy (p_mdir->directoryName, dir_name);
}


int ValidateCmd (char *m_cmd)
{
	int i;
	for (i = 0; s_cmds[i].s_cmd != NULL; i ++)
		if (strcmp (m_cmd, s_cmds [i].s_cmd) == 0)
			break;
	return (s_cmds[i].Val);
}

// Allocate space for the file system itself
M_FILESYSTEM *allocate_fs (char *dir_name)
{
	M_FILESYSTEM *p_mfs;

	if ((p_mfs = (M_FILESYSTEM *) malloc (sizeof (M_FILESYSTEM))) == NULL)
	{
		perror ("memory allocation failure in allocate_directory");
		exit (0);
	}
	p_mfs->rootDirectory = allocate_directory (dir_name, NULL);
	return p_mfs;
}

// Allocate space for each directory
M_DIRECTORY *allocate_directory (char *dir_name, M_DIRECTORY *parent_dir)
{
	M_DIRECTORY *p_mdir;
	   	
	if ((p_mdir = (M_DIRECTORY *) malloc (sizeof (M_DIRECTORY))) == NULL)
	{
		perror ("Memory allocaton failure in allocate_directory 2");
		exit (0);
	}
	p_mdir->subdirectories = NULL;
	p_mdir->next = NULL;
	p_mdir->files = NULL;
	p_mdir->parent = parent_dir;
	InitDirName (p_mdir, dir_name);
	return p_mdir;
}

void AddSibling (M_DIRECTORY *p_curdir, M_DIRECTORY *newDir)
{
	M_DIRECTORY *p_cur, *p_prev;

	for (p_cur = p_curdir; p_cur != NULL; 
				p_prev = p_cur, p_cur = p_cur->next)
		;
	p_prev->next = newDir;
}

// Check for duplicate directory names
bool CheckDuplicates (M_DIRECTORY *p_mdir, char *dir_name)
{
	bool retVal = false;
	M_DIRECTORY *p_temp;

	for (p_temp = p_mdir; p_temp != NULL; p_temp = p_temp->next)
	{
		if (strcmp (p_temp->directoryName, dir_name) == 0)
		{
			retVal = true;
			break;
		}
	}
	return retVal;
}

// Check for duplicate file names
bool CheckDuplicateFiles (MYFILE *p_files, char *file_name)
{
	bool retVal = false;
	MYFILE *p_temp;

	for (p_temp = p_files; p_temp != NULL; p_temp = p_temp->nextfile)
	{
		if (strcmp (p_temp->file_name, file_name) == 0)
		{
			retVal = true;
			break;
		}
	}
	return retVal;
}

// Create a sub-directory in the current directory
int MakeDirectory (M_DIRECTORY *p_curdir, char *dir_name)
{
	M_DIRECTORY *p_mdir;
	int retVal = 0;   // 0 - success, -1 - failure

	if (!CheckDuplicates (p_curdir->subdirectories, dir_name))
	{
		if ((p_mdir = 
		(M_DIRECTORY *) malloc (sizeof (M_DIRECTORY))) == NULL)
		{
			perror ("Mem alloc failure in allocate_directory 2");
			exit (0);
		}
	
		p_mdir->parent = p_curdir;
		InitDirName (p_mdir, dir_name);
		// If the head of subdirectories is NULL
		if (p_curdir->subdirectories == NULL)
			p_curdir->subdirectories = p_mdir;
		else	// Adding a sibling directory
			AddSibling (p_curdir->subdirectories, p_mdir);
		p_mdir->next = NULL; 
		p_mdir->files = NULL;
	}
	else
	{
		retVal = -1;
		printf ("This name already exists\n");
	}
	return retVal;
}

// Minimal implementation of the "cd" command
M_DIRECTORY *ChangeDirectory (M_FILESYSTEM *p_fs, char *dirName)
{
	M_DIRECTORY *p_mdir;
	
	if (strcmp (dirName, "root") == 0)
		p_mdir = p_fs->rootDirectory;
	else
	{
		for (p_mdir = p_fs->rootDirectory->subdirectories;
			p_mdir != NULL; p_mdir = p_mdir->next)
			if (strcmp (dirName, p_mdir->directoryName) == 0)
				break;
	}
	return p_mdir;
}

void ShowFiles (M_FILESYSTEM *p_fs)
{
	M_DIRECTORY *p_mdir;
	M_DIRECTORY *p_temp;
	MYFILE *p_mfile;

	if (p_fs != NULL)
	{
		p_mdir = p_fs->rootDirectory;
		printf ("%s\n", p_mdir->directoryName);
		p_mdir = p_mdir->subdirectories;
		// Display the names of all the subdirectories under root
		if (p_mdir != NULL)
		{
			printf ("\t%s", p_mdir->directoryName);
			for (p_temp = p_mdir->next; p_temp != NULL;
					p_temp = p_temp->next)
				printf ("\t%s", p_temp->directoryName);
		}
		printf ("\n");
		p_mdir = p_fs->rootDirectory;
		// Display all the files in the root directory
		if (p_mdir != NULL)
		{
			for (p_mfile = p_mdir->files; p_mfile != NULL;
					p_mfile = p_mfile->nextfile)
				printf ("%s\n", p_mfile->file_name);
		}
		p_mdir = p_fs->rootDirectory->subdirectories;
		// Display files in subdirectories
		for (p_temp = p_mdir; p_temp != NULL; p_temp = p_temp->next)
		{
			printf ("Directory name: %s\n", 
						p_temp->directoryName);
			for (p_mfile=p_temp->files; p_mfile != NULL;
					p_mfile=p_mfile->nextfile)
				printf ("%s\t", p_mfile->file_name);
			printf ("\n");
		}
		printf ("\n");
	}
	

}

// Implementation of the "touch" command to create a file
int CreateFile (M_DIRECTORY *p_mdir, char *fileName)
{
	MYFILE *p_myfile;
	MYFILE *p_temp, *p_prev;
	int len = strlen (fileName) + 1;
	int retVal = 0;		// 0 - success, -1 on failure

	if (!CheckDuplicateFiles (p_mdir->files, fileName))
	{
		if ((p_myfile = (MYFILE *) malloc (sizeof (MYFILE))) == NULL)
		{
			printf ("malloc failure in CreateFile\n");
			exit (0);
		}
		p_myfile->nextfile = NULL;

		if (p_mdir->files == NULL) 
		// This is the first file being added
		{
			p_mdir->files = p_myfile;
			if ((p_mdir->files->file_name = malloc (len)) == NULL)
			{
				printf ("malloc failure in CreateFile\n");
				exit (0);
			}
			strcpy (p_mdir->files->file_name, fileName);
		}
		else
		{
			for (p_temp = p_mdir->files; p_temp != NULL;
				p_prev = p_temp, p_temp = p_temp->nextfile)
				;
		
			p_prev->nextfile = p_myfile;
			if ((p_prev->nextfile->file_name = 
				(char *) malloc (len)) == NULL)
			{
				printf ("malloc failure in CreateFile\n");
				exit (0);
			}	
			strcpy (p_prev->nextfile->file_name, fileName);
		}
	}	
	else
	{
		retVal = -1;
		printf ("A file with this name already exists in this dir\n");
	}
	return retVal;
}

void free_mem (M_FILESYSTEM *p_fs)
{
	// To be implemented


}

