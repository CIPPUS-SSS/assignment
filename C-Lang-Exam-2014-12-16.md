### C-Language-Exam-2014-12-16
#### BEGIN.
写出是十进制转二进制的程序。至少2种方法。(手写代码，然后上机运行，看看自己的抽象能力)

#### 1.
`if (x==0) x++; else x--;` 和 `x == 0 ? x++ : x--` 有什么区别 ? 请解释语句和表达式的区别。
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

while ((c = fgetc(fp)) != EOF) {
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
putchar("0123456789ABCDEF"[value & 0xF]);
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

> %e5%86%99%e4%b8%80%e7%b3%bb%e5%88%97%e6%96%87%e7%ab%a0%e5%85%b3%e4%ba%8e%e5%a6%82%e4%bd%95%e4%bb%8e0%e5%88%b0%e8%83%bd%e5%ba%94%e5%af%b9%e5%a4%a7%e5%a4%9a%e6%95%b0%e4%b8%9a%e5%8a%a1%e7%9a%84%e7%a8%8b%e5%ba%8f%e5%91%98%ef%bc%8c%e5%be%97%e7%ad%89%e6%88%91%e5%b7%a5%e4%bd%9c%e4%b8%80%e5%b9%b4%e4%bb%a5%e5%90%8e%e4%ba%86%ef%bc%8c%e7%95%99%e7%bb%99%e5%b7%a5%e4%bd%9c%e5%ae%a4%e4%b8%80%e4%b8%aa%e5%bd%a9%e8%9b%8b%ef%bc%8c%e4%b8%80%e5%ae%9a%e8%a6%81%e6%8a%8a%e5%b7%a5%e4%bd%9c%e5%ae%a4%e5%81%9a%e4%b8%8b%e5%8e%bb%e5%95%8a%7e%7e%7e%ef%bc%8c%e6%8a%8a%e8%bf%99%e4%b8%aa%e9%a1%b9%e7%9b%ae%e7%95%99%e5%a5%bd%7e%7e%7e%7e%7e
