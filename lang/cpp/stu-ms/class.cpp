#include "header.h"
Student::Student(unsigned Id,string Name,string Sex,unsigned Age,string Kurasu){
    id=Id;
    name=Name;
    if(Sex!="男"&&Sex!="女"){
        cerr<<endl<<"错误:性别必须为“男”或“女”!"<<endl;
        exit(1);
    }else{
        sex=Sex;
    }
    age=Age;
    kurasu=Kurasu;
}
unsigned Student::getId(){return id;}
string Student::getName(){return name;}
string Student::getSex(){return sex;}
unsigned Student::getAge(){return age;}
string Student::getKurasu(){return kurasu;}

Pupil::Pupil(unsigned Id,string Name,string Sex,unsigned Age,string Kurasu,unsigned En,unsigned Math,unsigned Cn):Student(Id,Name,Sex,Age,Kurasu){
    markEn=En;
    markMath=Math;
    markCn=Cn;
}
unsigned Pupil::getMarkEn(){return markEn;}
unsigned Pupil::getMarkMath(){return markMath;}
unsigned Pupil::getMarkCn(){return markCn;}
int Pupil::get(){return PUPIL;}

Junior::Junior(unsigned Id,string Name,string Sex,unsigned Age,string Kurasu,unsigned En,unsigned Math,unsigned Cn,unsigned Geo,unsigned His):Pupil(Id,Name,Sex,Age,Kurasu,En,Math,Cn){
    markGeo=Geo;
    markHis=His;
}
unsigned Junior::getMarkGeo(){return markGeo;}
unsigned Junior::getMarkHis(){return markHis;}
int Junior::get(){return JUNIOR;}

Senior::Senior(unsigned Id,string Name,string Sex,unsigned Age,string Kurasu,string Major,unsigned En,unsigned Pgm,unsigned Hm):Student(Id,Name,Sex,Age,Kurasu){
    major=Major;
    markEn=En;
    markPgm=Pgm;
    markHm=Hm;
}
string Senior::getMajor(){return major;}
unsigned Senior::getMarkEn(){return markEn;}
unsigned Senior::getMarkPgm(){return markPgm;}
unsigned Senior::getMarkHm(){return markHm;}
int Senior::get(){return SENIOR;}
