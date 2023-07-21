#include <iostream>
using namespace std;

class complex{
    int real,image;
public:
    complex(int r=0,int i=0){
        real=r;
        image=i;
    }
    void show()
    {
        if(image>0){
            if(image==1)
                cout<<real<<"+"<<"i"<<endl;
            else
                cout<<real<<"+"<<image<<"i"<<endl;
        }
        else if(image<0){
            if(image==-1)
                cout<<real<<"-i"<<endl;
            else
                cout<<real<<image<<"i"<<endl;
        }
        else cout<<real<<endl;
    }
    complex operator+(const complex &c2){
        //双目运算符
        complex temp;
        temp.real=this->real+c2.real;
        temp.image=this->image+c2.image;
        return temp;
    }
    bool operator==(const complex &c2){
        if(this->real==c2.real&&this->image==c2.image)
            return true;
        else return false;
    }
    friend ostream& operator<<(ostream &myout,const complex&c);
    friend istream& operator>>(istream &myin,complex&c);


};
//这是友元调用
// complex operator+(const complex &c1,const complex &c2){
//         complex temp;
//         temp.real=c1.real+c2.real;
//         temp.image=c1.image+c2.image;
//         return temp;
// }  

ostream& operator<<(ostream &myout,const complex &c){
    if(c.image>0){
            if(c.image==1)
                cout<<c.real<<"+"<<"i"<<endl;
            else
                cout<<c.real<<"+"<<c.image<<"i"<<endl;
        }
    else if(c.image<0){
            if(c.image==-1)
                cout<<c.real<<"-i"<<endl;
            else
                cout<<c.real<<c.image<<"i"<<endl;
        }
    else cout<<c.real<<endl;
    return myout;
}
istream& operator>>(istream &myin,complex &c){
    cin>>c.real>>c.image;
    return myin;
}



int main()
{
    complex c1(1,2),c2(3,4);
    c1.show();
    c2.show();
    //这是显示调用
    // complex c3=c1.operator+(c2);
    complex c3=c1+c2;
    c3.show();
    if(c1==c2)
        cout<<"true"<<endl;
    else cout<<"false"<<endl;
    cout<<"------------------"<<endl;
    cout<<c1<<c2;
    cin>>c1>>c2;
    cout<<c1<<c2;
    return 0;

}