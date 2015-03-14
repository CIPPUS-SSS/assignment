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

/* 插入红黑树 */
void rbtree_insert(rbtree tree,int key,int val);
rbtree_node _rbtree_insert(rbtree_node node,int key,int val);

/* 删除最小值和删除最小值的辅助函数 */
void rbtree_delete_min(rbtree tree);
rbtree_node _rbtree_delete_min(rbtree_node root);

/* 红色结点向左移动 */
rbtree_node move_red_left(rbtree_node h);

/* 红色结点向右移动 */
rbtree_node move_red_right(rbtree_node h);

/* 删除最大值和删除最大值的辅助函数 */
int rbtree_delete_max(rbtree tree);
rbtree_node _rbtree_delete_max(rbtree_node node);

/* 删除任意结点 */
int rbtree_delete(rbtree tree,int key);
rbtree_node _rbtree_delete(rbtree_node node,int key);

/* 自底向上调整 */
rbtree_node fixup(rbtree_node node);

#endif


