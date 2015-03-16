/* 跳表的最大高度 */
#ifndef SKIPLIST_MAX_HEIGHT
#define SKIPLIST_MAX_HEIGHT 28
#endif

/* 跳表 */
struct skiplist_t{
	int level;
	struct s_node_t *head;
};

typedef struct skiplist_t *skiplist;

/* 跳表结点 */
struct s_node_t{
	int key;
	int val;
	struct s_node_t **forward;
};

typedef struct s_node_t *s_node;


int* skiplist_search(skiplist list,int key);

int skiplist_delete(skiplist list,int key);

s_node new_s_node(int key,int val);

/* 初始化链表 */
#define skiplist_init(list)									\
	do{														\
		list = (skiplist)malloc(sizeof(struct skiplist_t));	\
		s_node head = new_s_node(0,0);						\
		list->head = head;									\
		list->level = 1;									\
		int i;												\
		extern struct s_node_t SENTINEL;							\
		for (i=0;i<SKIPLIST_MAX_HEIGHT;i++) {				\
			head->forward[i]=&SENTINEL;						\
		}													\
	}while(0)												\

int IS_SENTINEL(s_node node);
