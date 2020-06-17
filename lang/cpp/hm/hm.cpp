/*本程序有关的两个数据文件：
base.txt－基础数据文件(必须存在，且按规定格式保存)
person.txt－人员信息文件(可选)
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;
//全局数据，对象
double ManagerSalary;       //经理固定月薪
double SalesManagerSalary;  //销售经理固定月薪
double SalesManagerPercent; //销售经理提成％
double SalesPercent;        //销售人员提成％
double WagePerHour;         //技术人员小时工资
int ID;                     //员工标识(要保证唯一)

class Person  //员工类
{
protected:
  int No;  //编号
  char Name[20];  //姓名
  int Duty;       //岗位
  double Earning; //收入
  Person *next;
public:
  Person(char ID,char *Name,int Duty)
  {
    this->Duty=Duty;
    strcpy(this->Name,Name);
    this->No=ID;
  }
  virtual void CalcSalary()=0; 
  virtual void Output()=0;
  friend class Company;
};

class Manager:public Person  //经理类
{
public:
  Manager(char ID,char *Name,int Duty):Person(ID,Name,Duty){}
  void CalcSalary(){Earning=ManagerSalary;}
  void Output()
  {
    CalcSalary();
    cout<<No<<"\t"<<Name<<"\t经理\t"<<Earning<<endl;
  }
};

class SalesManager:public Person  //销售经理类
{
private:
  double Amount;
public:
  SalesManager(char ID,char *Name,int Duty):Person(ID,Name,Duty){}
  void SetAmount(double s)
  {
    Amount=s;
  }
  void CalcSalary()
  {
    Earning=SalesManagerSalary+Amount*SalesManagerPercent/100;
  }
  void Output()
  {
    CalcSalary();
    cout<<No<<"\t"<<Name<<"\t销售经理\t"<<Earning<<endl;
  }
};

class Technician:public Person  //技术员类
{
private:
  double t;
public:
  Technician(char ID,char *Name,int Duty,double T):Person(ID,Name,Duty)
  {
    this->t=T;
  }
  double GetT()
  {
    return t;
  }
  void SetT(double T)
  {
    this->t=T;
  }
  void CalcSalary()
  {
    Earning=WagePerHour*t;
  }
  void Output()
  {
    CalcSalary();
    cout<<No<<"\t"<<Name<<"\t技术员\t"<<t<<"\t"<<Earning<<endl;
  }
};

class Sales:public Person  //销售员类
{
private:
  double Amount;
public:
  Sales(char ID,char *Name,int Duty,double Amount):Person(ID,Name,Duty)
  {
    this->Amount=Amount;
  }
  double GetAmount()
  {
    return Amount;
  }
  void SetAmount(double Amount)
  {
    this->Amount=Amount;
  }
  void CalcSalary()
  {
    Earning=SalesPercent/100*Amount;
  }
  void Output()
  {
    CalcSalary();
    cout<<No<<"\t"<<Name<<"\t销售员\t"<<Amount<<"\t"<<Earning<<endl;
  }
};

class Company  //公司类
{
private:
  Person *Worker;  //员工表
  void Clear();  //清除内存中数据
public:
  Company()
  {
    Worker=0;      
    Load();
  }
  ~Company()
  {
    Person *p;
    p=Worker;
    while(p)
    {
      p=p->next;
      delete Worker;
      Worker=p;
    }
    Worker=0;
  }
  void Add();     //增加人员
  void Delete();  //删除人员
  void Modify();  //修改人员
  void Query();   //查询人员
  void Set();     //基础数据设置
  void Save();    //数据存盘(包括基础数据，人员数据)
  void Load();    //数据装入(包括基础数据，人员数据)
};
  
void Company::Clear()  //清除内存中人员数据(内部使用)
{
  Person* p=Worker;
  while(p)
  {
    Worker=p->next;
    delete p;
    p=Worker;
  }
}

void Company::Add()
{
  Person *p;  //新结点指针
  int Duty;  
  char Name[20];
  double Amount,T;

  cout<<"\n** 新增员工 **\n";  
  
  //输入员工信息
  ID++;
  cout<<"输入岗位(1-经理2-销售经理3-销售员4-技术员):";  cin>>Duty;
  cout<<"输入姓名:";  cin>>Name;
  if(Duty==3)
  {
    cout<<"本月销售额:";  cin>>Amount;
  }
  else if(Duty==4)
  {
    cout<<"本月工作小时数(0-168):";  
    cin>>T;
  }

  //创建新员工结点
  switch(Duty)
  {
    case 1:p=new Manager(ID,Name,Duty); break;
    case 2:p=new SalesManager(ID,Name,Duty);  break;
    case 3:p=new Sales(ID,Name,Duty,Amount);   break;
    case 4:p=new Technician(ID,Name,Duty,T);  break;
  }
  p->next=0;

  //员工结点加入链表
  if(Worker)  //若已经存在结点
  {
    Person *p2;
    p2=Worker;
    while(p2->next)  //查找尾结点
    {
      p2=p2->next;
    }
    p2->next=p;  //连接
  }
  else  //若不存在结点(表空)
  {
    Worker=p;  //连接
  }  
}

void Company::Delete()  //删除人员
{
  int No;
  cout<<"\n** 删除员工 **\n";
  cout<<"ID:";  cin>>No;

  //查找要删除的结点
  Person *p1,*p2;  p1=Worker;
  while(p1)
  {
    if(p1->No==No)
      break;
    else
    {
      p2=p1;
      p1=p1->next;
    }
  }

  //删除结点
  if(p1!=NULL)//若找到结点，则删除
  {
    if(p1==Worker)  //若要删除的结点是第一个结点
    {
      Worker=p1->next;
      delete p1;
    }
    else  //若要删除的结点是后续结点
    {
      p2->next=p1->next;
      delete p1;
    }
    cout<<"找到并删除\n";
  }
  else  //未找到结点
    cout<<"未找到!\n";
}

void Company::Modify()
{

  int No,Duty;
  char Name[20];  
  double Amount,T;

  cout<<"\n** 修改员工 **\n";
  cout<<"ID:";  cin>>No;

  //查找要修改的结点
  Person *p1,*p2;  p1=Worker;
  while(p1)
  {
    if(p1->No==No)
      break;
    else
    {
      p2=p1;
      p1=p1->next;
    }
  }

  //修改结点
  if(p1!=NULL)//若找到结点
  {
    p1->Output();
    cout<<"调整岗位(1-经理2-销售经理3-销售员4-技术员):";  cin>>Duty;
    if(p1->Duty!=Duty)  //若岗位发生变动
    {    
      //修改其它数据
      cout<<"输入姓名:";  cin>>Name;      
      if(Duty==3)
      {
        cout<<"本月销售额:";  cin>>Amount;
      }
      else if(Duty==4)
      {
        cout<<"本月工作小时数(0-168):";  
        cin>>T;
      }

      //创建新员工结点
      Person *p3;
      switch(Duty)
      {
        case 1:p3=new Manager(p1->No,Name,Duty); break;
        case 2:p3=new SalesManager(p1->No,Name,Duty);  break;
        case 3:p3=new Sales(p1->No,Name,Duty,Amount);   break;
        case 4:p3=new Technician(p1->No,Name,Duty,T);  break;
      }

      //员工结点替换到链表
      p3->next=p1->next;
      if(p1==Worker)  //若要替换的结点是第一个结点
        Worker=p3;
      else  //若要删除的结点是后续结点
        p2->next=p3;

      //删除原来的员工结点
      delete p1;
    }
    else  //若岗位没有变动
    {
      cout<<"输入姓名:";  cin>>p1->Name;
      if(Duty==3)
      {
        cout<<"本月销售额:";cin>>Amount; ((Sales *)p1)->SetAmount(Amount);
      }
      else if(Duty==4)
      {
        cout<<"本月工作小时数(0-168):";cin>>T; ((Technician *)p1)->SetT(T);
      }
    }
    cout<<"修改成功!\n";
  }
  else  //未找到结点
    cout<<"未找到!\n";
}

void Company::Query()
{
  cout<<"\n** 查询人员本月销售信息 **\n";
  
  double sum=0;   //销售额总和
  Person *p=Worker;
  while(p)
  {
    if(p->Duty==3)sum+=((Sales *)p)->GetAmount();
    p=p->next;
  }

  p=Worker;
  double sum2=0;  //工资总和
  while(p)
  {
    if(p->Duty==2)((SalesManager *)p)->SetAmount(sum);
    p->Output();
    sum2+=p->Earning;
    p=p->next;
  }

  cout<<"本月盈利:"<<sum*0.20-sum2<<endl;
  cout<<"(按照20％利润计算)\n";
}

void Company::Set()
{
  cout<<"\n** 设置基础数据 **\n";
  cout<<"经理固定月薪["<<ManagerSalary<<"元]:";
cin>>ManagerSalary; 
  cout<<"销售经理固定月薪["<<SalesManagerSalary<<"元]:"; 
cin>>SalesManagerSalary;  
  cout<<"销售经理提成["<<SalesManagerPercent<<"％]:";
cin>>SalesManagerPercent; 
  cout<<"销售人员提成["<<SalesPercent<<"％]:";
cin>>SalesPercent;
  cout<<"技术人员小时工资["<<WagePerHour<<"(元/小时)]:"; 
cin>>WagePerHour;
  cout<<"员工标识[>="<<ID<<"]:";
cin>>ID;
}

void Company::Save()  //数据存盘(包括基础数据，人员数据),均采用文本文件
{
  ofstream fPerson,fBase;
  char c;

  cout<<"\n保存人员和基础数据,是否继续?[Y/N]:";  cin>>c;
  if(toupper(c)!='Y')return;

  //保存人员编号、姓名、岗位
  fPerson.open("person.txt",ios::out);  
  Person *p=Worker;
  while(p)
  {
    fPerson<<p->No<<"\t"<<p->Name<<"\t"<<p->Duty<<"\t";
    if(p->Duty==3)
      fPerson<<((Sales*)p)->GetAmount()<<"\t";
    else if(p->Duty==4)
      fPerson<<((Technician *)p)->GetT()<<"\t";
    fPerson<<endl;
    p=p->next;
  }
  fPerson.close();

  //保存基础数据
  fBase.open("base.txt",ios::out);
  fBase<<"经理固定月薪\t"<<ManagerSalary<<endl;  
  fBase<<"销售经理固定月薪\t"<<SalesManagerSalary<<endl;  
  fBase<<"销售经理提成％\t"<<SalesManagerPercent<<endl; 
  fBase<<"销售人员提成％\t"<<SalesPercent<<endl;        
  fBase<<"技术人员小时工资\t"<<WagePerHour<<endl;       
  fBase<<"ID\t"<<ID<<endl;
  fPerson.close();

  cout<<"\n保存人员和基础数据已经完成...\n";
}

void Company::Load()  //数据装入(包括基础数据，人员数据)
{
  //基础数据装入
  ifstream fBase;
  char buf[80];  //buf用于保存数据文件中的注释字符串
  fBase.open("base.txt",ios::in);
  fBase>>buf>>ManagerSalary;       //经理固定月薪
  fBase>>buf>>SalesManagerSalary;  //销售经理固定月薪
  fBase>>buf>>SalesManagerPercent; //销售经理提成％
  fBase>>buf>>SalesPercent;        //销售人员提成％
  fBase>>buf>>WagePerHour;         //技术人员小时工资
  fBase>>buf>>ID;                  //员工标识
  fBase.close();  

  //清除内存人员数据
  Clear();    
  //人员数据数据装入
  ifstream fPerson;
  Person *p=Worker;
  int No;  char Name[20];  int Duty;
  double Amount,T;


  fPerson.open("person.txt",ios::in);
  //读一条记录
  fPerson>>No>>Name>>Duty;
  if(Duty==3)fPerson>>Amount;
  else if(Duty==4)fPerson>>T;

  while(fPerson.good())
  {
    //创建员工结点
    switch(Duty)
    {
      case 1:p=new Manager(No,Name,Duty);  break;
      case 2:p=new SalesManager(No,Name,Duty);  break;
      case 3:p=new Sales(No,Name,Duty,Amount);  break;
      case 4:p=new Technician(No,Name,Duty,T);  break;
    }
    p->next=0;

    //员工结点加入链表
    if(Worker)  //若已经存在结点
    {
      Person *p2;
      p2=Worker;
      while(p2->next)  //查找尾结点
      {
        p2=p2->next;
      }
      p2->next=p;  //连接
    }
    else  //若不存在结点(表空)
    {
      Worker=p;  //连接
    }  

    //读下一条记录
    fPerson>>No>>Name>>Duty;
    if(Duty==3)fPerson>>Amount;
    else if(Duty==4)fPerson>>T;
  }
  fPerson.close();

  cout<<"\n人员和基础数据已经装入...\n";
}

int main()
{
  char c;
  Company a;
  do
  {
    cout<<"\n*** 公司人员管理系统 ***\n";
    cout<<"1－增加人员\n";
    cout<<"2－删除人员\n";
    cout<<"3－修改人员\n";
    cout<<"4－查询本月经营信息\n";
    cout<<"5－基础数据设置\n";
    cout<<"6－数据保存\n";
    cout<<"7－数据读取\n";
    cout<<"8－退出\t请选择(1-8):";

    cin>>c;
    switch(c)
    {
      case '1':  a.Add();   break;
      case '2':  a.Delete();break;
      case '3':  a.Modify();break;
      case '4':  a.Query(); break;
      case '5':  a.Set();   break;
      case '6':  a.Save();  break;
      case '7':  a.Load();  break;
    }
  }while(c!='8');
}
