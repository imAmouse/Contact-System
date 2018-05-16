//
// Created by 官文豪 on 18-4-9.
//

#include <iostream>
using namespace std;

class triangle{
private:
    double deepline,high,area;//底、高、面积
public:
    triangle(){area=(deepline*high)/2;}//
    triangle(double deepline,double high):deepline(deepline),high(high){area=(deepline*high)/2;}
    bool operator>(triangle &compare);
    bool operator<(triangle &compare);
    bool operator>=(triangle &compare);
    bool operator<=(triangle &compare);
    bool operator!=(triangle &compare);
    bool operator==(triangle &compare);


};
bool triangle::operator>(triangle &compare) {
    if(this->area>compare.area)
        return true;
    else
        return false;
}
bool triangle::operator<(triangle &compare) {
    if(this->area<compare.area)
        return true;
    else
        return false;
}
bool triangle::operator>=(triangle &compare) {
    if(this->area>=compare.area)
        return true;
    else
        return false;
}
bool triangle::operator<=(triangle &compare) {
    if(this->area<=compare.area)
        return true;
    else
        return false;
}
bool triangle::operator!=(triangle &compare) {
    if(this->area!=compare.area)
        return true;
    else
        return false;
}
bool triangle::operator==(triangle &compare) {
    if(this->area==compare.area)
        return true;
    else
        return false;
}

void compare(triangle t1,triangle t2){
    if(t1>t2)   cout<<"t1>t2"<<'\t'<<"true"<<'\n';
    else        cout<<"t1>t2"<<'\t'<<"false"<<'\n';
    if(t1<t2)   cout<<"t1<t2"<<'\t'<<"true"<<'\n';
    else        cout<<"t1<t2"<<'\t'<<"false"<<'\n';
    if(t1>=t2)  cout<<"t1>=t2"<<'\t'<<"true"<<'\n';
    else        cout<<"t1>=t2"<<'\t'<<"false"<<'\n';
    if(t1<=t2)  cout<<"t1<=t2"<<'\t'<<"true"<<'\n';
    else        cout<<"t1<=t2"<<'\t'<<"false"<<'\n';
    if(t1!=t2)  cout<<"t1!=t2"<<'\t'<<"true"<<'\n';
    else        cout<<"t1!=t2"<<'\t'<<"false"<<'\n';
    if(t1==t2)  cout<<"t1==t2"<<'\t'<<"true"<<'\n';
    else        cout<<"t1==t2"<<'\t'<<"false"<<'\n';
}

int main(){
    triangle t1(5,5);
    double deepline,high;
    cout<<"The triangle(5,5) will be compared,\nplease input the other triangle:\n";
    cin>>deepline>>high;
    triangle t2(deepline,high);
    compare(t1,t2);
    //system("pause");
    return 0;
}