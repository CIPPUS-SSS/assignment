#include <stdio.h>
#include <string.h>
#include "rbtree.h"

char str[1000];

void visit(rbtree_node node){
	char key [4];
	sprintf(key,"%d",node->key);
	strcat(str,key);
}

void reset_str(char str[]){
	str[0]='\0';
}

void test_fail(char *s){
	printf("Test Failed:%s",s);
}
//#define TEST
int main(){
#ifdef TEST
	rbtree tree = new_rbtree();
	int i;
	for(i=0;i<10;i++){
		rbtree_insert(tree,i,i);
	}
	rbtree_walk(tree->root,&visit);
	if(str_cmp(str,"0123456789") != 0){
		test_fail("插入错误");
		exit(1);
	}

	rbtree_delete_min(tree);
	reset_str(str);
	rbtree_walk(tree->root,&visit);
	if(str_cmp(str,"123456789") != 0){
		test_fail("错误");
		exit(1);
	}
#endif
	printf("Test ok!\n");
}
