#include <stdio.h>
#include <stdlib.h>
#include "skiplist.h"




/* 创建新结点 */
s_node new_s_node(int key,int val){
	s_node x = (s_node)malloc(sizeof(struct s_node_t));
	x->key = key;
	x->val = val;
	x->forward = (s_node *)malloc( sizeof(s_node) * SKIPLIST_MAX_HEIGHT);
	return x;
}

struct s_node_t SENTINEL = {0,0,NULL};

int cmp(s_node node,int key){
	/* SENTINEL 是无限大 */
	if(node == &SENTINEL)
		return 1;
	if(node->key < key)
		return -1;
	if(node->key == key)
		return 0;
	if(node->key > key)
		return 1;
}

int IS_SENTINEL(s_node node){
	return node == &SENTINEL;
}

static unsigned int random_level(){
	int h = 1;
	long r = random();
	/* random(3) 的每一位都是随机的,所以可以重复利用这些bit */
	int bit;
	/* 与到一位0的位就会停止 */
	for(bit = 0; r & (1<<bit);bit++) h++;
	return h > SKIPLIST_MAX_HEIGHT ? SKIPLIST_MAX_HEIGHT : h;
}

#define P(x) printf(x)

/* 跳表插入 */
int skiplist_insert(skiplist list,int key,int val){
	s_node update[SKIPLIST_MAX_HEIGHT];
	int i;
	s_node x = list->head;
	for(i=0;i<list->level;i++){
		while( cmp(x->forward[i],key) < 0 ){
			x = x->forward[i];
		}	
		update[i] = x;
	}
	x = x->forward[0];
	if( cmp(x,key) == 0)
		x->val = val;
	else{
		unsigned int lvl = random_level();
		if(lvl > list->level){
			for(i=list->level;i<lvl;i++){
				update[i] = list->head;
			}
			list->level = lvl;
		}
		x = new_s_node(key,val);
		for(i=0;i<list->level;i++){
			x->forward[i] = update[i]->forward[i];
			update[i]->forward[i]=x;
		}
	}
}

/* 跳表查找 */
int* skiplist_search(skiplist list,int key){
	s_node x = list->head;
	int i;
	for(i=list->level-1;i>=0;i--){
		while( cmp(x->forward[i],key) < 0 ) x = x->forward[i];
	}
	x  = x->forward[0];
	if(x->key==key)return &x->key;
	else return NULL;
}

/* 跳表删除 */
int skiplist_delete(skiplist list,int key){
	s_node update[SKIPLIST_MAX_HEIGHT];
	s_node x = list->head;	
	int i;
	for(i=list->level-1;i>=0;i--){
		while(x->forward[i]->key < key)
			x = x->forward[i];
		update[i] = x;
	}
	x = x->forward[0];
	if(x->key == key){
		for(i=0;i<list->level;i++){
			if(update[i]->forward[i] != x)
				break;
			update[i]->forward[i] = x->forward[i];
		}
		free(x);
		while(list->level > 0 && 
				IS_SENTINEL(list->head->forward[list->level]))
			list->level = list->level - 1;
	}
}
