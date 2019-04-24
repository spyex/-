//
//  main.cpp
//  NO.11
//
//  Created by 沈平原 on 2019/4/12.
//  Copyright © 2019 沈平原. All rights reserved.
//

#include <iostream>
#include "NO.11.hpp"
#include <math.h>
#include <fstream>
#include <iomanip>
int main(int argc, const char * a[])
{
    int n=(argc-6)/4;
    int angli=(n-2)*180;
   
    
    vector<int> h,min,sec;
    vector<string> oriang,gaiang,zuoang;
    for(int i=1;i<=(argc-n);)
    {
        int num1=stoi(a[i]);
        ++i;
        h.push_back(num1);
        num1=stoi(a[i]);
        ++i;
        min.push_back(num1);
        num1=stoi(a[i]);
        ++i;
        sec.push_back(num1);
    }
    
    for(auto i=0;i!=sec.size()-1;++i)
    {
        string w;
        w=to_string(h[i])+"°"+to_string(min[i])+"'"+to_string(sec[i])+'"';
        oriang.push_back(w);
    }
    
    
    
    vector<double> len,xlen,ylen,xlenb,ylenb,xleng,yleng,xlenz,ylenz;
    for(int i=(3*(n+1)+1);i<=(3*(n+1)+1)+n-1;++i)
    {
        double num2=stod(a[i]);
        len.push_back(num2);
    }
 
    
    
    
    int sece=0;
    int secce=calang(sec,sece);
    int mince=calang(min,sece);
    int houce=calangh(h,sece);
    
    
    int difh,difmin,difsec,dif,difyun;
    string sdif,sce;
   if(houce<angli)
   {
       difsec=60-secce;
       difmin=59-mince;
       difh=angli-1-houce;
       dif=-(difsec+60*difmin+60*60*difh);
       difyun=-dif;
       sdif="-"+to_string(difh)+"°"+to_string(difmin)+"'"+to_string(difsec)+'"';
   }
   else{
       difsec=secce;
       difmin=mince;
       difh=houce-angli;
       dif=difsec+60*difmin+60*60*difh;
       difyun=dif;
       sdif=to_string(difh)+"°"+to_string(difmin)+"'"+to_string(difsec)+'"';
   }
    int yun=60*sqrt(n);
    string syun="±"+to_string(yun)+'"';
    sce=to_string(houce)+"°"+to_string(mince)+"'"+to_string(secce)+'"';
    string sangli=(to_string(angli)+"°")+"00\'"+"00"+'"';
    int ceavr=-dif/n;
   
    calangg(h, min, sec, ceavr, gaiang);
    
    if((yun-difyun)<0)
    {
        cout<<"误差大于容许值";
        return 0;
    }
   
    
    
    
    
    double lend=0;
    for(auto q=len.begin();q!=len.end();++q)
    {
        lend+=*q;
    }
    
    
    calanggg(h, min, sec, zuoang);
    string zuo=a[1+3*n];
    zuo=zuo+"°"+a[2+3*n]+"'"+a[3+3*n]+'"';
    zuoang.insert(zuoang.begin(), zuo);
    
    for(int i=0;i!=sec.size()-3;++i)
    {
        double x,y;
        x=len[i+1]*cos(hu(h[i],min[i],sec[i]));
        y=len[i+1]*sin(hu(h[i],min[i],sec[i]));
        xlen.push_back(x);
        ylen.push_back(y);
    }
    
 
    xlen.insert(xlen.begin(),len[0]*cos(hu(h[h.size()-2],min[min.size()-2],sec[sec.size()-2])));
        ylen.insert(ylen.begin(),len[0]*sin(hu(h[h.size()-2],min[min.size()-2],sec[sec.size()-2])));
    double fx=0,fy=0;
    for(auto i=xlen.begin();i!=xlen.end();++i)
    {
        fx+=*i;
    }
    for(auto i=ylen.begin();i!=ylen.end();++i)
    {
        fy+=*i;
    }
    double D=0;
    for(auto i=len.begin();i!=len.end();++i)
    {
        D+=*i;
    }
    for(auto i=0;i!=len.size();++i)
    {
        xlenb.push_back(-fx/D*len[i]);
    }
    for(auto i=0;i!=len.size();++i)
    {
        ylenb.push_back(-fy/D*len[i]);
    }
   
    double xz=stod(a[argc-2]),yz=stod(a[argc-1]);
    xlenz.push_back(xz);
    ylenz.push_back(yz);
    for(auto i=0;i!=len.size();++i)
    {
        xleng.push_back(xlen[i]+xlenb[i]);
        yleng.push_back(ylen[i]+ylenb[i]);
        xlenz.push_back(xleng[i]+xlenz[i]);
        ylenz.push_back(yleng[i]+ylenz[i]);
        
    }
    
    double f=sqrt(fx*fx+fy*fy);
    
    ofstream out("/Users/shenpingyuan/Desktop/文本文件/test.txt",ofstream::app);
    out<<endl<<"A"<<setiosflags(ios::fixed)<<setprecision(2)<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<xlenb[0]<<'\t'<<xlenb[0]<<'\t'<<'\t'<<'\t'<<xlenz[0]<<'\t'<<ylenz[0]<<'\t'<<"A"<<endl;
    
    
    
    for(int i=0;i<n-1;++i)
    {
        out<<setiosflags(ios::fixed)<<setprecision(2)<<'\t'<<ceavr<<'"'<<'\t'<<'\t'<<'\t'<<'\t'<<zuoang[i]<<'\t'<<len[i]<<'\t'<<xlen[i]<<'\t'<<ylen[i]<<'\t'<<xleng[i]<<'\t'<<yleng[i]<<endl;
        out<<i+1<<setiosflags(ios::fixed)<<setprecision(2)<<'\t'<<oriang[i]<<'\t'<<gaiang[i]<<'\t'<<'\t'<<'\t'<<'\t'<<xlenb[i]<<'\t'<<ylenb[i]<<'\t'<<'\t'<<'\t'<<xlenz[i+1]<<'\t'<<ylenz[i+1]<<'\t'<<i+1<<endl;
        
    }
   
    out<<setiosflags(ios::fixed)<<setprecision(2)<<'\t'<<ceavr<<'"'<<'\t'<<'\t'<<'\t'<<'\t'<<zuoang[n-1]<<'\t'<<len[n-1]<<'\t'<<xlen[n-1]<<'\t'<<ylen[n-1]<<'\t'<<xleng[n-1]<<'\t'<<yleng[n-1]<<endl;
    out<<"A"<<setiosflags(ios::fixed)<<setprecision(2)<<'\t'<<oriang[n-1]<<'\t'<<gaiang[n-1]<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<xlenz[n-1+1]<<'\t'<<ylenz[n-1+1]<<'\t'<<"A"<<endl;
    
    out<<1<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<setiosflags(ios::fixed)<<setprecision(2)<<zuoang[0]<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<1<<endl;
    
    double t=f/D;
    out<<'\n'<<'\n'<<"测="<<sce<<'\t'<<"D="<<D<<'\t'<<"fx="<<fx<<'\n'<<"理="<<sangli<<'\t'<<"fy="<<fy<<'\n'<<"差="<<sdif<<'\t'<<"f="<<f<<'\n'<<"允="<<syun<<endl;
    out<<setiosflags(ios::fixed)<<setprecision(6)<<"T="<<t;
   

    
return 0;
    }
    
