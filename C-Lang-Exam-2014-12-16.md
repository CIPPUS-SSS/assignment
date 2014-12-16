### C-Language-Exam-2014-12-16
#### BEGIN.
写出是十进制转二进制的程序。至少2种方法。(手写代码，然后上机运行，看看自己的抽象能力)

#### 1.
`if (x==0) x++ else x--` 和 `x == 0 ? x++ : x--` 有什么区别 ? 请解释语句和表达式的区别。
#### 2.
我们常常会有这样的代码片段 `if ((x = max(x, y ,z)) > N) { ... }`，若不加括号
`if (x = max(x, y, z) > N) { .. }` 会出现什么问题 ? 此类问题你还能想到哪些 ?

#### 3
C语言经过哪几个步骤到可执行文件(exe,out...)? 每个阶段做了什么，简要说明。
`static`关键字在不同的上下文中有不同的含义，请简要说明，这些特性分别用在什么地方?

#### 4
```
typedef void * paradigm;

struct tree {
    enum {EXPR, STMT, CTRL} kind;
    union {
        paradigm child;
        int index;
    } u;
};

struct {
    unsigned a: 4;
    unsigned b: 4;
} i;

extern int off;

paradigm * tag;
```
这段程序最少分配了多少字节的内存(32位机器)。

#### 5
```
int c;
int lines = 0, words = 0, chars = 0;
FILE * fp = fopen(__FILE__, "r");

while ((c = fgetc(fp) != EOF) {
    switch(c) {
    case '\n': lines++;
    case ' ':
    case '\t': words++;
    default: chars++;
    }
}
```
这段程序做了什么? 是否有不妥之处 ?

#### 6
写一个函数复制两个数组，要求效率尽可能高。原型帮你写好
```
/* src means source array, copy to others,
 * dst means destination array, to copy.
 * size means array length 
 */
void (int const * src, int const * dst, int size)
```

#### 7
下面这段程序是10转16进制时的一个代码片段，请问做了什么 ? 为什么能这样做 ?
```
putchar("0123456789ABCDEF"[value & 0xFF]);
```

#### 8
下面这段程序有一个 bug, 请找出来, 请说出你找到的方法，其次，这段代码有什么可改进的。由此回想一下，你在编码的过程中，是否需要注意什么。程序内容为打印50以内的质数。
```
#define N 50
int main()
{
    int primes[N];
	int pc, m, k;

    primes[0]=2;    /* 2 is first prime */
	pc = 1;         /* 2 include */
	m  = 3;         /* from 3 begin */
	while ( pc < N ) {
	    k = 0;
	    while(primes[k] * primes[k] <= m) {
		    if (m % primes[k] = 0) { /* m bing-go */
		        m += 2;
		        k = 1;
		    } else k++;
        }
	    primes[pc++] = m;
	    m += 2;
	}
	
    printf("\n The first %d prime numbers are:\n",N);
	for(k=0; k < pc; k++) printf("%d ",primes[k]);
    
    return 0;
}
```

#### 9
中国象棋有个将帅问题，棋盘上只有将和帅。请写出一段程序，输出将帅的所有合法位置。只用一个变量。位置对应分布如下。
```
         1____2_____3
         |    |     |
         4————5—————6
         |    |     |
         7____8_____9
```

####10

```
#include <stdio.h>
void f(int x ){
    printf("%d",x);
    if(x==10){
    	
    }else{
        f(x+1);
        printf("%d",x);
    }   
}
int main(){
    f(0);
}
```

以上代码的输出是什么

#### END.
写出你在C语言中觉得最酷炫的一个语言特性！并说明为什么。
`(talk is cheap , show me the code)`
