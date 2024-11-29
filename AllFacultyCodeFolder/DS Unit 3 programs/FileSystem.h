//			FileSystem.h

#define MAX_STR		50

// Each file's representation
typedef struct myfile
{
	char *file_name;
	struct myfile *nextfile;
} MYFILE;

typedef struct m_directory
{
	char* directoryName;
    	struct m_directory *subdirectories; 
	// Head of subdirectories linked list
    	struct m_directory *next;           
	// Next sibling directory
    	MYFILE *files;                      
	// Head of files linked list
    	struct m_directory *parent;         
	// Pointer to parent directory
} M_DIRECTORY;

// Structure to represent the File System
typedef struct FileSystem 
{
    M_DIRECTORY *rootDirectory;
} M_FILESYSTEM ;

enum CmdVal {CD_CMD, MKDIR_CMD, LS_CMD, TOUCH_CMD, EXIT_CMD, INVALID_CMD};
typedef struct cmdval
{
	char *s_cmd;		// Supported command
	enum CmdVal Val;	// An integer value for the command
} CMDVAL;

int ValidateCmd (char *);
M_FILESYSTEM *allocate_fs (char *);
M_DIRECTORY *allocate_directory (char *, M_DIRECTORY *);
int MakeDirectory (M_DIRECTORY *, char *);  // -1 on failure
M_DIRECTORY *ChangeDirectory (M_FILESYSTEM *, char *);
void ShowFiles (M_FILESYSTEM *);
int CreateFile (M_DIRECTORY *, char *);  // returns -1 on failure

void AddSibling (M_DIRECTORY *, M_DIRECTORY *);
void free_mem (M_FILESYSTEM *);