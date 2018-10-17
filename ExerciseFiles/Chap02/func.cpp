// func.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
using namespace std;

void func()
{
    puts("this is func()");
}
int func(int i){
return 2*i;
}
int main( int argc, char ** argv )
{
    puts("this is main()");
    func();
    printf("%d\n",func(42));
    return 0;
}

