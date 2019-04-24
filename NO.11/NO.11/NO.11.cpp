//
//  NO.11.cpp
//  NO.11
//
//  Created by 沈平原 on 2019/4/12.
//  Copyright © 2019 沈平原. All rights reserved.
//

#include "NO.11.hpp"
int calang(vector<int> a,int &b)
{
    auto c=a.begin();
    auto d=a.end()-2;
    int e=0;
    for(;c!=d;++c)
    {
        e+=*c;
    }
    e=b+e;
    b=e/60;
    return e%60;
}

int calangh(vector<int> a ,int &b)
{
    auto c=a.begin();
    auto d=a.end()-2;
    int e=0;
    for(;c!=d;++c)
    {
        e+=*c;
    }
    e=b+e;
    return e;
}

void calangg(vector<int> &a,vector<int> &b,vector<int> &c,int d,vector<string> &e)
{
    
    for(auto i=0;i!=c.size()-2;++i)
    {
        c[i]+=d;
        if(c[i]<0)
        {
            c[i]=60+c[i];
            b[i]=b[i]-1;
            if(b[i]<0)
            {
                b[i]=60+b[i];
                a[i]=a[i]-1;
            }
            
        }
        if(c[i]>=60)
        {
            c[i]=c[i]-60;
            b[i]=b[i]+1;
        }
        if(b[i]>=60)
        {
            b[i]=b[i]-60;
            a[i]=a[i]+1;
        }
        string f=to_string(a[i])+"°"+to_string(b[i])+"'"+to_string(c[i])+'"';
        e.push_back(f);
    }
   
}


void calanggg(vector<int> &a,vector<int> &b,vector<int> &c,vector<string> &d)
{
    int i=0;
    {
        if(c[c.size()-2]<c[i])
        {
            c[i]=c[c.size()-2]+60-c[i];
            if(b[b.size()-2]<b[i])
            {
                b[i]=b[b.size()-2]+60-b[i]-1;
                a[i]=a[a.size()-2]+180-a[i]-1;
            }
            else{
                b[i]=b[b.size()-2]-b[i]-1;
                a[i]=a[a.size()-2]+180-a[i];
            }
        }
        else{
            c[i]=c[c.size()-2]-c[i];
            if(b[b.size()-2]<b[i])
            {
                b[i]=b[b.size()-2]+60-b[i];
                a[i]=a[a.size()-2]+180-a[i]-1;
            }
            else{
                b[i]=b[b.size()-2]-b[i];
                a[i]=a[a.size()-2]+180-a[i];
            }
            
        }
        
    }
    string f=to_string(a[i])+"°"+to_string(b[i])+"'"+to_string(c[i])+'"';
    d.push_back(f);
    for(i=0;i!=c.size()-3;++i)
    {
        if(c[i]<c[i+1])
        {
            c[i+1]=c[i]+60-c[i+1];
            if(b[i]<b[i+1])
            {
                b[i+1]=b[i]+60-b[i+1]-1;
                a[i+1]=a[i]+180-a[i+1]-1;
            }
            else{
                b[i+1]=b[i]-b[i+1]-1;
                a[i+1]=a[i]+180-a[i+1];
            }
        }
        else{
            c[i+1]=c[i]-c[i+1];
            if(b[i]<b[i+1])
            {
                b[i+1]=b[i]+60-b[i+1];
                a[i+1]=a[i]+180-a[i+1]-1;
            }
            else{
                b[i+1]=b[i]-b[i+1];
                a[i+1]=a[i]+180-a[i+1];
            }
            
        }
        string f=to_string(a[i+1])+"°"+to_string(b[i+1])+"'"+to_string(c[i+1])+'"';
        d.push_back(f);
        
    }
    
    
    
}



double hu(double a, double b, double c)
{
    double PI=3.1415926;
    double f;
    if(a<0) f=-1.0;
    else f=1.0;
    if(a<0)
    {
        a = a * (-1.0);
    }
    double d = a + b/60 + c/3600;
    double e =f * (d * PI)/180;
    return e;

}
