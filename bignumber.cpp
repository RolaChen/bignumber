#include"bignumber.h"

bignumber::bignumber()
{
 sign='+';
}

bignumber::~bignumber()
{
}

void bignumber::readline()
{
 string line;
 cin>>line;
 if(line=="END")
  exit(0);
 int add=line.find_first_of("+");
 int minus=line.find_first_of("-");
 int mul=line.find_first_of("*");
 int div=line.find_first_of("/");
 int equal=line.find_first_of("=");
 int location;
 if(add>0)
 {
  sign='+';
  location=add;
 }
 else if(minus>0)
 {
  sign='-';
  location=minus;
 }
 else if(mul>0)
 {
  sign='*';
  location=mul;
 }
 else if(div>0)
 {
  sign='/';
  location=div;
 }
 else
 {
  cout<<"The input is illegal"<<endl;
  system("pause");
  exit(0);
 }
 if(equal==-1)
 {
  cout<<"The input is illegal"<<endl;
  system("pause");
  exit(0);
 }
 a=line.substr(0,location);
 b=line.substr(location+1,equal-location-1);
 print();
}

string Add(string a,string b)
{
 /*int a1[100],b1[100];
 memset(a1,0,sizeof(a1));
 memset(b1,0,sizeof(b1));
 a1[0]=a.length();
 b1[0]=b.length();
 for(int i=1;i<=a1[0];i++)
  a1[i]=a[a1[0]-i]-'0';
 for(int i=1;i<=b1[0];i++)
  b1[i]=b[b1[0]-i]-'0';
 int result[100];
    memset(result,0,sizeof(result));
 int k=max(a.length(),b.length());
 for(int i=1;i<=k;i++)
 {
  result[i]=(a1[i]+b1[i])%10;
  a1[i+1]=a1[i+1]+(a1[i]+b1[i])/10;
 }
 if(result[k+1]>0)
  result[0]=k+1;
 else
  result[0]=k;
 for(int i=result[0];i>0;i--)
     cout<<result[i];
 cout<<endl;*/
 int k=max(a.length(),b.length());
 int al=a.length()-1,bl=b.length()-1;
 string c(k+1,'0');
 for(int i=k; i>=0; i--)
 {
  if(al>=0&&bl>=0)
  {
   c[i]=(c[i]-'0'+(a[al]-'0')+(b[bl]-'0'))%'10';
   c[i-1]=(c[i-1]-'0'+(a[al]-'0')+(b[bl]-'0'))/'10';
  }
  else if(bl>=0)
  {
   c[i]=(c[i]-'0'+(b[bl]-'0'))%'10';
   c[i-1]=(c[i-1]-'0'+b[bl]-'0')/'10';
  }
  else if(al>=0)
  {
   c[i]=(c[i]-'0'+(a[al]-'0'))%'10';
   c[i-1]=(c[i-1]-'0'+a[al]-'0')/'10';
  }
  al--,bl--;
 }
 if(c[0]=='0')
  c=c.substr(1);
 return c;
}

string Multiply(string a,string b)
{
 int size1=a.size(),size2=b.size();
 string str(size1+size2,'0');
 for(int i=size2-1;i>=0;--i)
 {
  int mul=0,add=0;
  for(int j=size1-1;j>=0;--j)
  {
   int temp1=(b[i]-'0')*(a[j]-'0')+mul;
   mul=temp1/10;
   temp1=temp1%10;
   int temp2=str[i+j+1]-'0'+temp1+add;
   str[i+j+1]=temp2%10+48;
   add=temp2/10;
  }
   str[i]+=mul+add;
 }
 if(str[0]=='0')
 str=str.substr(1,str.size());
 return str;
}

string dezero(string str)
{
 long int i;
 for(i=0;i<str.length();i++)
 {
  if(str.at(i)>48) 
   break;
 }
 if(i==str.length())
  return "0";
 str.erase(0,i);
 return str;
}

int judge(string a1, string b1)
{
 if(a1.length()>b1.length())
  return 1;
 if(a1.length()<b1.length())
  return -1;
 long int i;
 for(i=0;i<a1.length();i++)
 {
  if(a1.at(i)>b1.at(i))
   return 1;
  if(a1.at(i)<b1.at(i))
   return -1;
 }
 return 0;
}

string Minus(string a,string b)
{
 a=dezero(a);
 b=dezero(b);
 long int i,j=0;
 string c="0";
 string c1,c2;
 string d="-";
 if(judge(a,b)==0)
  return c;
 if(judge(a,b)==1)
 {
  c1=a;
  c2=b;
 }
 if(judge(a,b)==-1)
 {
  c1=b;
  c2=a;
  j=-1;//j用来判断是否要加上-号
 }
 reverse(c1.begin(),c1.end());//reverse函数用于反转在[first,last)范围内的顺序011-〉110
 reverse(c2.begin(),c2.end());
 for(i=0;i<c2.length();i++)
 {
  if(c2.at(i)>=48&&c2.at(i)<=57)//ascll码48到57是数字0~9
   c2.at(i)-=48;
  if(c2.at(i)>=97&&c2.at(i)<=122)//97-122是小写字母
   c2.at(i)-=87;
 }
 for(i=0;i<c1.length();i++)
 {
  if(c1.at(i)>=48&&c1.at(i)<=57)
   c1.at(i)-=48;
  if(c1.at(i)>=97&&c1.at(i)<=122)
   c1.at(i)-=87;
 }
 for(i=0;i<c2.length();i++)
 {
  c1.at(i)=c1.at(i)-c2.at(i);
 }
 for(i=0;i<c1.length()-1;i++)
 {
  if(c1.at(i)<0)
  {
   c1.at(i)+=10;
   c1.at(i+1)--;
  }
 }
 for(i=c1.length()-1;i>=0;i--)
 {
  if(c1.at(i)>0)
   break;
 }
 c1.erase(i+1,c1.length());
 for(i=0;i<c1.length();i++)
 {
  if(c1.at(i)>=10) 
   c1.at(i)+=87;
  if(c1.at(i)<10) 
   c1.at(i)+=48;
 }
 reverse(c1.begin(),c1.end());
 if(j==-1)
  c1.insert(0,d);//在首位插入-号
 return c1;
}

string Divide(string a,string b)
{
 if(b.length()==1&&b.at(0)==48) 
  return "error";
 long int i,j;
 string c1,c2,d,e;
 if(judge(a,b)==0) 
  return "1";
 if(judge(a,b)==-1)
 {
  return "0";
 }
 c1=dezero(a);
 c2=dezero(b);
 d="";
 e="";
 for(i=0;i<c1.length();i++)
 {
  j=0;
  d=d+c1.at(i);
  d=dezero(d);
  while(judge(d,b)>=0)
  {
   d=Minus(d,b);//调用之前的减法函数minus
   d=dezero(d);
   j++;
  }
  e=e+"0";
  e.at(i)=j;
 }
 for(i=0;i<e.length();i++)
 {
  if(e.at(i)>=10) e.at(i)+=87;
  if(e.at(i)<10) e.at(i)+=48;
 }
 e=dezero(e);
 return e;

}

}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
