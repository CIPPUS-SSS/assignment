/*
 * 定义红黑树结点和红黑树的数据结构。
 */
#ifndef _RBTREE_H_
#define _RBTREE_H_

/* 结点颜色，用入度表示 */
enum rbtree_node_color {RED,BLACK}; 

/* 键为int，值为int的红黑树结点 */
struct rbtree_node_t {
	int key; 						/* 键 */
	int val; 						/* 值 */
	struct rbtree_node_t* left;  	/* 左结点 */
	struct rbtree_node_t* right; 	/* 右结点 */
	enum rbtree_node_color color;	/* 结点颜色 */
};
typedef struct rbtree_node_t *rbtree_node;

/* 创建红黑树结点 */
rbtree_node new_node(int key,int value,enum rbtree_node_color color,rbtree_node left,rbtree_node right);

/* 红黑树 */
struct rbtree_t {
	rbtree_node root;
};
typedef struct rbtree_t *rbtree;

/* 创建红黑树 */
rbtree new_rbtree();

/* 中序遍历红黑树 */
void rbtree_walk(rbtree_node node,void (*visti)(rbtree_node node));

/* 搜索红黑树 */
int* rbtree_search(rbtree tree,int key);

/* 查询最小值 */
int* rbtree_min(rbtree tree);

/* 插入红黑树 */
void rbtree_insert(rbtree tree,int key,int val);

/* 删除最小值 */
void rbtree_delete_min(rbtree tree);

/* 删除最大值 */
int rbtree_delete_max(rbtree tree);

/* 删除任意结点 */
int rbtree_delete(rbtree tree,int key);


#endif


