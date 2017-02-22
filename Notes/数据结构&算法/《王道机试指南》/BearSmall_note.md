# 王道机试指南

# 例 2.1 排序 （九度教程第 1 题）
>时间限制：1 秒            内存限制：32 兆           特殊判题：否

>题目描述： 对输入的n个数进行排序并输出。

>输入： 输入的第一行包括一个整数n(1<=n<=100)。接下来的一行包括n个整数。

>输出： 可能有多组测试数据，对于每组数据，将排序后的n个整数输出，每个数后面都有一个空格。每组测试数据的结果占一行。

>样例输入：

>>4

>>1 4 3 2

>样例输出：

>>1 2 3 4

>来源： 2006年华中科技大学计算机保研机试真题

### 参考答案1

```c
#include <stdio.h>
int main () {
    int n;
    int buf[100]; //定义我们将要使用的变量n，并用buf[100]来保存将要排序的数字
    while (scanf ("%d",&n) != EOF) { //输入n,并实现多组数据的输入
        for (int i = 0;i < n;i ++) {
             scanf("%d",&buf[i]);
         }
        //输入待排序数字
        for (int i = 0;i < n;i ++) {
            for (int j = 0;j < n - 1 - i;j ++) {
                if (buf[j] > buf[j + 1]) {
                    int tmp = buf[j];
                    buf[j] = buf[j + 1];
                    buf[j+1] = tmp;
                }
            }
         }
        //冒泡排序主体
        for (int i = 0;i < n;i ++) {
                 printf("%d ",buf[i]);
         }
        //输出完成排序后的数字,注意,题面输出要求在每个数字后都添加一个空格
         printf("\n"); //输出换行
    }
    return 0;
}
```

### 参考答案2【改进版】

```c
#include<stdio.h>
#include<algorithm>
using namespace std;
int main () {
    int n;
    int buf[10000];
    while (scanf ("%d",&n) != EOF) {
    for (int i = 0;i < n;i ++) {
         scanf    ("%d",&buf[i]);
    }
     sort(buf,buf + n); //使用该重载形式,表明将要使用自己定义的排列规则
    for (int i = 0;i < n;i ++) {
         printf("%d ",buf[i]);
    }
     printf("\n");
    }
    return 0;
}
```

### 参考答案3【改进版】

```c
#include<stdio.h>
#include<algorithm>
using namespace std;

bool cmp (int x,int y) { //定义排序规则
	return x > y;
}
int main () {
    int n;
    int buf[100];
    while (scanf ("%d",&n) != EOF) {
        for (int i = 0;i < n;i ++) {
             scanf("%d",&buf[i]);
        }
        sort(buf,buf + n,cmp);
        //使用该重载形式,我们表明将要使用自己定义的排列规则
        for (int i = 0;i < n;i ++) {
             printf("%d ",buf[i]);
        }
        printf("\n");
    }
    return 0;
}
```

### 我的代码

```c
#include<iostream>
using namespace std;

int MAX = 100;

void sort(int *p,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(p[j]>p[j+1]){
                int temp = p[j];
                p[j] = p [j+1];
                p[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    int a[MAX];
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,n);
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
```



# 例 2.2 成绩排序 （九度教程第 2 题）
>时间限制：1 秒            内存限制：32 兆           特殊判题：否

> 题目描述：有N个学生的数据，将学生数据按成绩高低排序，如果成绩相同则按姓名
字符的字母序排序，如果姓名的字母序也相同则按照学生的年龄排序，并输出N个学生排序后的信息。

> 输入：测试数据有多组，每组输入第一行有一个整数N（N<=1000），接下来的N行包括N个学生的数据。每个学生的数据包括姓名（长度不超过
100的字符串）、年龄（整形数）、成绩（小于等于100的正数）。

> 输出：将学生信息按成绩进行排序，成绩相同的则按姓名的字母序进行排序。然后输出学生信息，按照如下格式：姓名 年龄 成绩

> 样例输入：
```
3
abc 20 99
bcd 19 97
bed 20 97
```

> 样例输出：
```
bcd 19 97
bed 20 97
abc 20 99
```

- 提示：学生姓名的字母序区分字母的大小写，如A要比a的字母序靠前(因为A的ASC码比a的ASC码要小)。
- 来源：2000年清华大学计算机研究生机试真题

### 参考代码

```c
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct E {
    char name[101];
    int age;
    int score;
}buf[1000];

bool cmp(E a,E b) { //实现比较规则
    if (a.score != b.score)
        return a.score < b.score;  //若分数不相同则分数低者在前
    int tmp = strcmp(a.name,b.name);
    if (tmp != 0)
        return tmp < 0; //若分数相同则名字字典序小者在前
    else
        return a.age < b.age; //若名字也相同则年龄小者在前
}

int main () {
    int n;
    while (scanf ("%d",&n) != EOF) {
        for (int i = 0;i < n;i ++) {
            scanf ("%s%d%d",buf[i].name,&buf[i].age,&buf[i].score);
         }
        // 输入
        sort(buf,buf + n,cmp); //利用自己定义的规则对数组进行排序
        for (int i = 0;i < n;i ++) {
            printf ("%s %d %d\n",buf[i].name,buf[i].age,buf[i].score);
        }
        //输出排序后结果
    }
    return 0;
}
```

### 参考代码【改进版】

```c
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct E {
 char name[101];
 int age;
 int score;
 bool operator < (const E &b  ) const { //利用C++算符重载直接定义小于运算符
	if (score != b.score) return score < b.score;
	int tmp = strcmp(name,b.name);
	if (tmp != 0) return tmp < 0;
	else return age < b.age;
 }
}buf[1000];

int main () {
 int n;
 while (scanf ("%d",&n) != EOF) {
	for (int i = 0;i < n;i ++) {
	   scanf ("%s%d%d",buf[i].name,&buf[i].age,&buf[i].score);
	}
	sort(buf,buf + n);
	for (int i = 0;i < n;i ++) {
	   printf ("%s %d %d\n",buf[i].name,buf[i].age,buf[i].score);
	}
 }
 return 0;
}
```

### 我的代码

```c

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

struct E{
    char name[10];
    int age;
    int score;
}buf[100];

bool cmp(E e1,E e2){
    if(e1.score!=e2.score)
        return e1.score<e2.score;
    int temp = strcmp(e1.name,e2.name);
    if(temp!=0)
        return temp<0;
    return e1.age<e2.age;
}

int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>buf[i].name>>buf[i].age>>buf[i].score;
        }
        sort(buf,buf+n,cmp);
        for(int i=0;i<n;i++){
            cout<<buf[i].name<<" "<<buf[i].age<<" "<<buf[i].score<<endl;
        }
    }
    return 0;
}


```