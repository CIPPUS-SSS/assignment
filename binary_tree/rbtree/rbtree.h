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


/* 删除最小值和删除最小值的辅助函数 */
void rbtree_delete_min(rbtree tree,int key);
rbtree_node _rbtree_delete_min(rbtree_node root);

/* 红色结点向左移动 */
rbtree_node move_red_left(rbtree_node h);

/* 红色结点向右移动 */
rbtree_node move_red_right(rbtree_node h);

/* 删除最大值和删除最大值的辅助函数 */
int delete_max(rbtree tree);
rbtree_node _delete_max(rbtree_node h);

/* 自底向上调整 */
rbtree_node fixup(rbtree_node node);

#endif


