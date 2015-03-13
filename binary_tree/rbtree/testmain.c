#include <stdio.h>
#include "rbtree.h"
int main(){
	rbtree tree = new_rbtree();
	int i;
	for(i=0;i<10;i++){
		rbtree_insert(tree,i,i);
	}
	// printf("after deletiton\n");
	// rbtree_delete_min(tree);
	rbtree_walk(tree->root);
}
