// Import Libraries
#include <iostream> // IO Library
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <vector>
#ifndef ONLINE_JUDGE
// #include "libraries.h"
// #include "app/framework.cpp"
#endif



// Import namespace 'std'
using namespace std;

bool DEBUG_MODE = true;

typedef long long ll;

struct Struct {
    int a,b;
} q[100001];
int rear=0,front=1;

void push(int a,int b) {
    q[++rear].a = a;
    q[rear].b = b;
}
bool empty() {
    return (rear+1==front);
}
void pop() {
    if (empty()) return;
    ++front;
}
const Struct & query(int k) {
    return q[front+k-1];
}

#define RequestAnInt "%d"

// Main Function
int main(int argc, char *argv[]) {
    int n;
    int t;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&t);
        if (t==1) {
            int xx,yy;
            scanf("%d%d",&xx,&yy);
            push(xx,yy);
        } else {
            if (empty()) {
                printf("error\n");
            } else {
                printf("%d %d\n",query(1).a,query(1).b);
                pop();
            }
        }
    }
    return 0;
}


// Functions Definition


