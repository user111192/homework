# 设定初始值的重要性

----

```c++
#include <iostream> 

using namespace std; 

...
```

设置变量时, **一定**要记得设定初始值。

e. g. `sample.cpp`
```c++
...

int SampleA() {
    int bad; // not correct
    int good = 0; // correct
    cout << bad << " " << good;
    
    return 0; 
}
```
执行`sample.cpp`中的函数`SampleA()`, 输出立马显现:
```
-389148303 0
```
~~(第一个数其实每一次运行都不一样)~~

## 数组

e. g. `sample.cpp`
```c++
...

int SampleB() {
    int bad[100]; 
    // It is not correct
    
    int good[100]; 
    for (int i=0;i<100;i++) 
        good[i] = 0;
    // It is correct
    // or: memset(good, 0, sizeof(good)); 
    
    return 0; 
}
```
执行`sample.cpp`中的函数`SampleB()`, 前者`bad`数组还有相同的问题。