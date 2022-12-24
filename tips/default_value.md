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
    
    return 0; 
}
```
执行`sample.cpp`中的函数`SampleB()`, 前者还有相同的问题。