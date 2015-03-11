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
	node.color = !node.color;
	node.left.color = !node.left.color;
	node.right.color = !node.right.color;
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

/* 辅助函数,判断结点是否为红色,如果结点为NULL,为黑色 */
int is_red(rbtree_node node){
	if(node==NULL)return -1;
	return node.color==RED;
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

/* 
 * 查找操作
 * 和普通的二叉搜索树的方法一样
 */
int* rbtree_search(rbtree tree,int key){
	rbtree_node node =  tree.root
		while(node!=NULL){
			if ( key == node.key)return &node.val;
			else if ( key < node.key) x = x.left;
			else if ( key > node.key) x = x.right;
		}
	return NULL;
}

/* 
 * 插入操作
 * 先自顶向下搜索,再自底向上调整
 */
rbtree_node rbtree_insert(rbtree_node node,int key,int val){
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

	/* 情况3:调整平衡 */	
	if(is_red(node.right)&&!is_red(node.left))
		node = rotate_left(node);
	/* 情况2:强制左倾 */
	if(is_red(node.left)&&is_red(node.left.left))
		node = rotate_right(node);
	/* 情况3:分解4-node */
	if(is_red(node.left)&&is_red(node.right))
		flip_colors(node);
	return node;
}

/*
 * 删除最小值
 */
void rbtree_delete_min(rbtree tree,key){
	rbtree_node root = tree.root
	if(root==NULL)
		return;
	if(!is_red(root.left)&&!is_red(root.right))
		root.color = RED;
	//TODO:释放空间
	root = _rbtree_delete_min(root);
	if(root!=NULL) root.color = BLACK;
}

/*
 * 删除最小值辅助函数
 */
rbtree_node _rbtree_delete_min(rbtree_node root){
	if(root.left==NULL)
		return NULL;
	/*
	 * 如果向下两个任何一个是红色的,
	 * 就不用把红色传递下去,因为下面的红色可以
	 * 用来构成最后删除结点的红色.
	 * red        
     * /    \     
     * black black
     * /          
     * black      
	 *
	 */
	if(!is_red(h.left)&&!is_red(h.left.left))
		root = move_red_left(root);
	root.left = _rbtree_delete_min(h.left);
	return fixup(root);
}
/*
 * 向下移动红色,
 * 首先是对h变色,
 * 因为红色结点是不能相邻的,
 * 右边结点的左结点是红色,会产生冲突,
 * 要排除这种情况,重新平衡
 */
rbtree_node move_red_left(rbtree_node h){
	// 先更换颜色,因为更换颜色不影响平衡.
	// 抽象含义就是从父结点要挪用一个点,但是如果导致出现"多"结点
	// 就从兄弟结点移过来一个.
	// 把所有的情况都考虑进去了.
	flip_colors(h);// 其实这一步就是借上面的结点,回头看下二三树的向下移动就能明白了.
				   // 列一下二三树删除的情况.
	if(!is_red(h.right.left)){
		/* 如果右结点的左结点是红色,存在冲突,需要调整
		 * black    
         * /    \   
         * red   red
         * /     /  
         * black red
		 *
		 * 需要对右结点进行右旋,变成.
		 * 
		 * black      
         * /    \     
         * red   red  
         * /      \   
         * black   red
		 *
		 * 然后对当前根节点左旋
		 *
		 * black
         * /    \     
         * red   red
         * /      
         * red   	
		 * /
		 * black
		 *
		 * 最后变色
		 *
		 * red 
         * /    \     
         * black black
         * /      
         * red   	
		 * /
		 * black
		 *
		 */

		h.right = rotate_right(h.right);
	}
	return h;
}
//TODO:删除最大值
//注意:操作是不对称的.
/*
 * 自底向上调整
 */
rbtree_node fixup(rbtree_node root){
	/* 情况3:调整平衡 */	
	if(is_red(node.right)&&!is_red(node.left))
		node = rotate_left(node);
	/* 情况2:强制左倾 */
	if(is_red(node.left)&&is_red(node.left.left))
		node = rotate_right(node);
	/* 情况3:分解4-node */
	if(is_red(node.left)&&is_red(node.right))
		flip_colors(node);
	return node;
}




