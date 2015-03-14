#include <stdio.h>
#include <stdlib.h>
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
	printf("Test Failed:%s\n",s);
}

#define TEST
int main(){
#ifdef TEST
	rbtree tree = new_rbtree();
	int i;
	for(i=0;i<10;i++){
		rbtree_insert(tree,i,i);
	}

	rbtree_walk(tree->root,&visit);
	if(strcmp(str,"0123456789") != 0){
		test_fail("插入错误");
		exit(1);
	}

	rbtree_delete_min(tree);
	reset_str(str);
	rbtree_walk(tree->root,&visit);
	if(strcmp(str,"123456789") != 0){
		test_fail("删除最小值错误");
		exit(1);
	}

	rbtree_delete_max(tree);
	reset_str(str);
	rbtree_walk(tree->root,&visit);
	if(strcmp(str,"12345678") != 0){
		test_fail("删除最大值错误");
		exit(1);
	}

	int *val = rbtree_search(tree,1);
	if(val == NULL || *val != 1){
		test_fail("查找错误");
	}

	rbtree_delete(tree,5);
	reset_str(str);
	rbtree_walk(tree->root,&visit);
	if(strcmp(str,"1234678") != 0){
		test_fail("删除任意值错误");
		exit(1);
	}

	printf("Test ok!\n");
#endif
}
