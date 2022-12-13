#include <iostream>
#include "vector.h"
#include <cstdlib>
#include <ctime>

int main()
{
    using namespace std;
    using namespace VECTOR;
    srand(time(0));
    double dir;
    Vector step;
    Vector locate(0.0,0.0);
    double target;
    double dstep;
    unsigned long steps=0;

    cout << "Input target distance(q to quit): ";
    while(cin>>target)
    {
        cout << "Input step length: ";
        if(!(cin>>dstep))
            break;
        while(locate.magval() < target)
        {
            dir = rand() % 360;
            step.reset(dstep,dir,Vector::POL);
            locate = locate + step;
            steps++;
        }
        locate.rect_set();
        cout << "Current location of (x,y) is " << locate;
        locate.polar_set();
        cout << " or " << locate << endl;

        cout << "一共走了：" << steps << "步" << "  平均步长：" << target/steps << endl;
        steps=0;
        locate.reset(0.0,0.0,Vector::RECT);
        cout << "Input target distance(q to quit): ";
    }
    cout << "Bye!" << endl;
    cin.clear();
    while(cin.get()!='\n')
        continue;
    return 0;
}
