#include <stdio.h>
#include <stdlib.h>

enum rbtree_node_color {RED,BLACK}; /* 结点颜色,用入度表示 */

/* 红黑树结点 */
typedef struct rbtree_node_t {
	int key; 						/* 键 */
	int value; 						/* 值 */
	struct rbtree_node_t* left;  	/* 左结点 */
	struct rbtree_node_t* right; 	/* 右结点 */
	struct rbtree_node_t* parent; 	/* 父结点 */
	enum rbtree_node_color color;	/* 结点颜色 */
} *rbtree_node;

/* 构建结点 */
rbtree_node new_node(int key,int value,enum rbtree_node_color color,rbtree_node left,rbtree_node right){
	rbtree_node node = malloc(sizeof(struct rbtree_node_t));

	node->key = key;
	node->value = value;
	node->color = color;
	node->left = left;
	node->right = right;
	if(left!=NULL)left->parent=node;
	if(right!=NULL)right->parent=node;
	node->parent=NULL;
	return node;
}

/* 更换颜色 */
void flip_colors(rbtree_node node){
	node.color = RED;
	node.left.color = BLACK;
	node.right.color = BLACK;
}

/* 左旋 */
void rotate_left(rbtree_node node){
	rbtree_node x = node.right;
	node.right = x.left;
	x.left = node;
	x.color = node.color;
	node.color = RED;
}

/* 右旋 */
void rotate_right(rbtree_node node){
	rbtree_node x = node.left;
	node.left = x.right;
	x.right = node;
	x.color = node.color;
	node.color = RED;
}

/* 红黑树 */
typedef struct rbtree_t {
	rbtree_node root;
} *rbtree;

/* 创建红黑树 */
rbtree new_rbtree(){
	rbtree t = malloc(sizeof(rbtree_t));
	t->root = NULL;
	return t;
}

/* 插入操作 */
rbtree_node insert(rbtree_node node,int key,int val){
	if(node == NULL){
		return new_node(key,val,RED,NULL,NULL);
	}
	if(key < node.key)
		node = insert(node.left,key,val);
	else if(key > node.key)
		node = insert(node.right,key,val);
	else node.val = val;

	/* 1. 如果插入到右边,只需要变色.
	 * 2. 如果插入到左结点的左边,右旋,变成情况1.
	 * 3. 如果插入到左结点的右边,左旋,变成情况2.
	 * 根据递归的顺序,可以把这些操作统一,自底向上返回.
	*/
	/* 情况3 */	
	if(is_red(node.right)&&!is_red(node.left))
		node = rotate_left(node);
	if(is_red(node.left)&&is_red(node.left.left))
		node = rotate_right(node);
	if(is_red(node.left)&&is_red(node.right))
		flip_colors(node);
	return node;
}

/* 判断结点是否为红色,如果结点为NULL,为黑色 */
int is_red(rbtree_node node){
	if(node==NULL)return -1;
	return node.color==RED;
}
