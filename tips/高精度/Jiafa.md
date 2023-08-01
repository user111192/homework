# 高精度加法
## 例 1
例如: 1111111111111+9, 列成`竖式`, 
```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 +                         9
 
 ---------------------------
 
```
先算个位, 

`1`+`9`=`10`, 
满`10`, 向十位进`1`。
```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 +                         9
                         1
 ---------------------------
                           0
```

接下来, 处理**进位**。
十位: 1+1=2 -> 2
```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 +                         9
                         1
 ---------------------------
                         2 0
```
百位: 无进位, 直接照抄. 1 -> 1
```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 +                         9
                         1
 ---------------------------
                       1 2 0
```
千位: 1 -> 1<br />
万位: ...<br />
...: ...<br />
最高位: 1 -> 1

最终结果: 
```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 +                         9
                         1
 ---------------------------
   1 1 1 1 1 1 1 1 1 1 1 2 0
```

所以, 1111111111111+**9**=`1111111111120`

## 例 2
1111111111111+8888888888889, 
这个算式变成了`高精度`+`高精度`了。

还是列成<kbd>竖式</kbd>,
```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 + 8 8 8 8 8 8 8 8 8 8 8 8 9
 
 ---------------------------
 
```
先算个位,

`1`+`9`=`10`,
满`10`, 向十位进`1`。
```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 + 8 8 8 8 8 8 8 8 8 8 8 8 9
                         1
 ---------------------------
                           0
```

接下来, 算十位。

`1`+`8`+1=`10`,
满`10`, 向百位进`1`。
```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 + 8 8 8 8 8 8 8 8 8 8 8 8 9
                       1 1
 ---------------------------
                         0 0
```

千位, 万位...以此类推。
```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 + 8 8 8 8 8 8 8 8 8 8 8 8 9
                     1 1 1
 ---------------------------
                       0 0 0
```
```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 + 8 8 8 8 8 8 8 8 8 8 8 8 9
                   1 1 1 1
 ---------------------------
                     0 0 0 0
```
......
```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 + 8 8 8 8 8 8 8 8 8 8 8 8 9
   1 1 1 1 1 1 1 1 1 1 1 1
 ---------------------------
     0 0 0 0 0 0 0 0 0 0 0 0
```
最高位: 
`1`+`8`+1=`10`, 
向前一位进1. 
```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 + 8 8 8 8 8 8 8 8 8 8 8 8 9
 1 1 1 1 1 1 1 1 1 1 1 1 1
 ---------------------------
   0 0 0 0 0 0 0 0 0 0 0 0 0
```
```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 + 8 8 8 8 8 8 8 8 8 8 8 8 9
 1 1 1 1 1 1 1 1 1 1 1 1 1
 ---------------------------
 1 0 0 0 0 0 0 0 0 0 0 0 0 0
```

所以,

`1111111111111`+`8888888888889`=`10000000000000`=10<sup>13</sup>

```text
   1 1 1 1 1 1 1 1 1 1 1 1 1
 + 8 8 8 8 8 8 8 8 8 8 8 8 9
 1 1 1 1 1 1 1 1 1 1 1 1 1
 ---------------------------
 1 0 0 0 0 0 0 0 0 0 0 0 0 0
```
----

## 代码
1. 首先导入头文件。
```c++
// 1. Import libraries
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>
// Import namespace 'std'
using namespace std;
```
2. 初始化变量。
```c++
// 2. Initialize variables
const int MAX = 1000;
char s[MAX+1];
int a[MAX+1], vis[MAX+1],c[MAX+2];
```
3. 定义主函数`main()`
```c++
// 3. Define Main Function
int main(int argc, char **argv) {
    for (int i=0;i<1001;i++) {
        s[i]='0';
        a[i]=0, vis[i]=0, c[i]=0;
    } // If you use global variables, this initialization does not need used.
```
这里如果使用全局变量，这个初始化可以不用。
4. 输入(包含了处理)变量
```c++
    // 4. Input and process variables
    scanf("%s",s+1);
    int lena = strlen(s+1);

    for (int i=1;i<=lena+1;i++)
        a[i] = s[lena-i+1] - '0';

    scanf("%s",s+1);
    int lenb = strlen(s+1);
    for (int i=1;i<=lenb+1;i++)
        vis[i] = s[lenb-i+1] - '0';

    int lenc = (lena>lenb)?lena:lenb;
```
5. 真正的高精度计算到这里才开始。计算代码
```c++
    // 5. Calculate
    for (int i=1;i<=101;i++)
        c[i] = 0;
    for (int i=1;i<=lenc;i++) {
        // c[i] = a[i] + vis[i]; <-- Wrong! 
        c[i] = a[i] + vis[i] + c[i]; // <-- Correct
        // c[i] += a[i] + vis[i]; <-- Plan B, Correct too
        // 处理进位
        c[i+1] = c[i] / 10;
        c[i] = c[i] % 10;
    }
    // 处理 overflow
    if (c[lenc+1]>0)
        lenc++;
```
6. 输出
```c++
    // 6. Output
    for (int i=lenc;i>=1;i--)
        printf("%d", c[i]);
    return 0;
}
```

----

### 附: 完整代码

```c++
// 1. Import libraries
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>
// Import namespace 'std'
using namespace std;

// 2. Initialize variables
const int MAX = 1000;
char s[MAX+1];
int a[MAX+1], vis[MAX+1],c[MAX+2];


// 3. Define Main Function
int main(int argc, char **argv) {
    for (int i=0;i<1001;i++) {
        s[i]='0';
        a[i]=0, vis[i]=0, c[i]=0;
    } // If you use global variables, this initialization does not need used.
    
    // 4. Input and process variables
    scanf("%s",s+1);
    int lena = strlen(s+1);

    for (int i=1;i<=lena+1;i++)
        a[i] = s[lena-i+1] - '0';

    scanf("%s",s+1);
    int lenb = strlen(s+1);
    for (int i=1;i<=lenb+1;i++)
        vis[i] = s[lenb-i+1] - '0';

    int lenc = (lena>lenb)?lena:lenb;

    // 5. Calculate
    for (int i=1;i<=101;i++)
        c[i] = 0;
    for (int i=1;i<=lenc;i++) {
        // c[i] = a[i] + vis[i]; <-- Wrong! 
        c[i] = a[i] + vis[i] + c[i]; // <-- Correct
        // c[i] += a[i] + vis[i]; <-- Plan B, Correct too
        // 处理进位
        c[i+1] = c[i] / 10;
        c[i] = c[i] % 10;
    }
    // 处理 overflow
    if (c[lenc+1]>0)
        lenc++;

    // 6. Output
    for (int i=lenc;i>=1;i--)
    printf("%d", c[i]);
    return 0;
}
```

`Control`, 缩写为<kbd>Ctrl</kbd>, 扩写为唱，跳，rap，篮球。
你还敢<kbd>Ctrl+C</kbd>吗?

