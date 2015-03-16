#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "skiplist.h"

static char str[1000];

void walk(skiplist list){
	if(list == NULL){
		return;
	}
	s_node x = list->head;
	// ignore head
	x = x->forward[0];
	char key [4];
	int i;
	while( !IS_SENTINEL(x) ){
		sprintf(key,"%d",x->key);
		strcat(str,key);
		x = x->forward[0];
	}
}



int main(){
	skiplist list;
	skiplist_init(list);
	int i;
	int *val;
	for(i=0;i<10;i++){
		skiplist_insert(list,i,i);
	}
	walk(list);
	if( strcmp(str,"0123456789") != 0 ){
		printf("test failed\n");
		exit(1);
	}
	for(i=0;i<10;i++){
		val = skiplist_search(list,i);
		if(val==NULL || *val!=i){
			printf("search test failed at %d\n",i);
			exit(1);
		}
	}
	skiplist_delete(list,5);
	str[0]='\0';
	walk(list);
	if( strcmp(str,"012346789") != 0 ){
		printf("test failed\n");
		exit(1);
	}
	printf("test ok!\n");
}
