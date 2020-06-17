#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdlib.h>

using namespace std;

const int PUPIL=0;
const int JUNIOR=1;
const int SENIOR=2;
const int ALL=3;

const int ID=11;
const int AGE=12;
const int MARKEN=13;
const int MARKMATH=14;
const int MARKCN=15;
const int MARKGEO=16;
const int MARKHIS=17;
const int MARKPGM=18;
const int MARKHM=19;

const int NAME=51;
const int SEX=52;
const int KURASU=53;
const int MAJOR=54;




class Student{
protected:
    unsigned id;
    string name;
    string sex;
    unsigned age;
    string kurasu; //class
public:
    Student(unsigned Id,string Name,string Sex,unsigned Age,string Kurasu);
    unsigned getId();
    string getName();
    string getSex();
    unsigned getAge();
    string getKurasu();
    virtual unsigned getMarkEn(){}
    virtual unsigned getMarkMath(){}
    virtual unsigned getMarkCn(){}
    virtual unsigned getMarkGeo(){}
    virtual unsigned getMarkHis(){}
    virtual unsigned getMarkPgm(){}
    virtual unsigned getMarkHm(){}
    virtual string getMajor(){}
    virtual int get(){}
};

class Pupil:public Student{
protected:
    unsigned markEn;
    unsigned markMath;
    unsigned markCn;
public:
    Pupil(unsigned Id,string Name,string Sex,unsigned Age,string Kurasu,unsigned En,unsigned Math,unsigned Cn);
    virtual unsigned getMarkEn();
    unsigned getMarkMath();
    unsigned getMarkCn();
    virtual int get();
};

class Junior:public Pupil{
private:
    unsigned markGeo;
    unsigned markHis;
public:
    Junior(unsigned Id,string Name,string Sex,unsigned Age,string Kurasu,unsigned En,unsigned Math,unsigned Cn,unsigned Geo,unsigned His);
    unsigned getMarkGeo();
    unsigned getMarkHis();
    virtual int get();
};

class Senior:public Student{
private:
    string major;
    unsigned markEn;
    unsigned markPgm;
    unsigned markHm;
public:
    Senior(unsigned Id,string Name,string Sex,unsigned Age,string Kurasu,string Major,unsigned En,unsigned Pgm,unsigned Hm);
    string getMajor();
    virtual unsigned getMarkEn();
    unsigned getMarkPgm();
    unsigned getMarkHm();
    virtual int get();
};

void tabHead(int type);  //打印表头
void printInfo(Student* iOne,int type);  //打印单个固定类型学生信息
void searchInfo(int type,int key,unsigned value);  //查找单个固定类型学生信息
void searchInfo(int type,int key,string value);  //查找单个固定类型学生信息
vector <Student*> getInfo(int type,unsigned value);  //获取单个学生信息
vector <Student*> getInfo(int type,string value);  //获取单个学生信息
void allInfo();  //打印全部信息
void statNum(int type);  //统计学生人数
void stat(int type,unsigned id);  //统计个人总分
void stat(int type,string name); //统计个人总分
void stat(int type);  //统计单科平均分

vector <Student*> sortSingle(int type,int way);  //按单科成绩排序
vector <Student*> sortAll(int type);  //按总成绩排序
vector <Student*> readInfo(int type);  //从文件读取特定类型的单个学生数据汇总为vector <Student*>
void writeInfo(int type,Student* stu);  //向文件写入特定类型的单个学生数据
Student* insertInfo(int type);  //从输入读入特定类型的学生数据
void delInfo(int type,unsigned id);  //按学号删除学生数据

#endif // HEADER_H_INCLUDED
