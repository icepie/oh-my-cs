#include "header.h"

void tabHead(int type){
    cout<<setfill(' ')<<setw(10)<<"学号";
    cout<<setfill(' ')<<setw(10)<<"姓名";
    cout<<setfill(' ')<<setw(10)<<"性别";
    cout<<setfill(' ')<<setw(10)<<"年龄";
    cout<<setfill(' ')<<setw(10)<<"班级";
    if(type==SENIOR)
        cout<<setfill(' ')<<setw(10)<<"专业";
    if(type==PUPIL||type==JUNIOR){
        cout<<setfill(' ')<<setw(10)<<"语文";
        cout<<setfill(' ')<<setw(10)<<"数学";
    }
    cout<<setfill(' ')<<setw(10)<<"英语";
    if(type==JUNIOR){
        cout<<setfill(' ')<<setw(10)<<"历史";
        cout<<setfill(' ')<<setw(10)<<"地理";
    }
    if(type==SENIOR){
        cout<<setfill(' ')<<setw(10)<<"程序设计";
        cout<<setfill(' ')<<setw(10)<<"高数";
    }
    cout<<endl;
}

void printInfo(Student* iOne,int type){
    cout<<setfill(' ')<<setw(10)<<iOne->getId();
    cout<<setfill(' ')<<setw(10)<<iOne->getName();
    cout<<setfill(' ')<<setw(10)<<iOne->getSex();
    cout<<setfill(' ')<<setw(10)<<iOne->getAge();
    cout<<setfill(' ')<<setw(10)<<iOne->getKurasu();
    if(type==SENIOR)
        cout<<setfill(' ')<<setw(10)<<iOne->getMajor();
    if(type==PUPIL||type==JUNIOR){
        cout<<setfill(' ')<<setw(10)<<iOne->getMarkCn();
        cout<<setfill(' ')<<setw(10)<<iOne->getMarkMath();
    }
    cout<<setfill(' ')<<setw(10)<<iOne->getMarkEn();
    if(type==JUNIOR){
        cout<<setfill(' ')<<setw(10)<<iOne->getMarkHis();
        cout<<setfill(' ')<<setw(10)<<iOne->getMarkGeo();
    }
    if(type==SENIOR){
        cout<<setfill(' ')<<setw(10)<<iOne->getMarkPgm();
        cout<<setfill(' ')<<setw(10)<<iOne->getMarkHm();
    }
    cout<<endl;
}

void searchInfo(int type,int key,unsigned value){
   vector <Student*> pStu;
    vector <Student*> p=readInfo(PUPIL);
    vector <Student*> j=readInfo(JUNIOR);
    vector <Student*> s=readInfo(SENIOR);
    switch(type){
    case PUPIL:
        pStu=p;
        break;
    case JUNIOR:
        pStu=j;
        break;
    case SENIOR:
        pStu=s;
        break;
    }
    int cnt=0;
    tabHead(type);
    switch(key){
    case ID:
        for(int i=0;i<pStu.size();i++){
            if(value==pStu[i]->getId())
                printInfo(pStu[i],type);
            else
                cnt++;
        }
        break;
    case AGE:
        for(int i=0;i<pStu.size();i++){
            if(value==pStu[i]->getAge())
                printInfo(pStu[i],type);
            else
                cnt++;
        }
        break;
    case MARKEN:
        for(int i=0;i<pStu.size();i++){
            if(value==pStu[i]->getMarkEn())
                printInfo(pStu[i],type);
            else
                cnt++;
        }
        break;
    case MARKMATH:
        for(int i=0;i<pStu.size();i++){
            if(value==pStu[i]->getMarkMath())
                printInfo(pStu[i],type);
            else
                cnt++;
        }
        break;
    case MARKCN:
        for(int i=0;i<pStu.size();i++){
            if(value==pStu[i]->getMarkCn())
                printInfo(pStu[i],type);
            else
                cnt++;
        }
        break;
    case MARKGEO:
        for(int i=0;i<pStu.size();i++){
            if(value==pStu[i]->getMarkGeo())
                printInfo(pStu[i],type);
            else
                cnt++;
        }
        break;
    case MARKHIS:
        for(int i=0;i<pStu.size();i++){
            if(value==pStu[i]->getMarkHis())
                printInfo(pStu[i],type);
            else
                cnt++;
        }
        break;
    case MARKPGM:
        for(int i=0;i<pStu.size();i++){
            if(value==pStu[i]->getMarkPgm())
                printInfo(pStu[i],type);
            else
                cnt++;
        }
        break;
    case MARKHM:
        for(int i=0;i<pStu.size();i++){
            if(value==pStu[i]->getMarkHm())
                printInfo(pStu[i],type);
            else
                cnt++;
        }
        break;
    }
    if(cnt==pStu.size())
        cout<<"无结果"<<endl;
}

void searchInfo(int type,int key,string value){
    vector <Student*> pStu;
    vector <Student*> p=readInfo(PUPIL);
    vector <Student*> j=readInfo(JUNIOR);
    vector <Student*> s=readInfo(SENIOR);
    switch(type){
    case PUPIL:
        pStu=p;
        break;
    case JUNIOR:
        pStu=j;
        break;
    case SENIOR:
        pStu=s;
        break;
    }
    int cnt=0;
    tabHead(type);
    switch(key){
    case NAME:
        for(int i=0;i<pStu.size();i++){
            if(value==pStu[i]->getName())
                printInfo(pStu[i],type);
            else
                cnt++;
        }
        break;
    case SEX:
        for(int i=0;i<pStu.size();i++){
            if(value==pStu[i]->getSex())
                printInfo(pStu[i],type);
            else
                cnt++;
        }
        break;
    case KURASU:
        for(int i=0;i<pStu.size();i++){
            if(value==pStu[i]->getKurasu())
                printInfo(pStu[i],type);
            else
                cnt++;
        }
        break;
    case MAJOR:
        for(int i=0;i<pStu.size();i++){
            if(value==pStu[i]->getMajor())
                printInfo(pStu[i],type);
            else
                cnt++;
        }
        break;
    }
    if(cnt==pStu.size())
        cout<<"无结果"<<endl;
}

vector <Student*> getInfo(int type,unsigned value){
    int cnt=0;
    vector <Student*> pStu;
    vector <Student*> reStu;
    vector <Student*> p=readInfo(PUPIL);
    vector <Student*> j=readInfo(JUNIOR);
    vector <Student*> s=readInfo(SENIOR);
    switch(type){
    case PUPIL:
        pStu=p;
        break;
    case JUNIOR:
        pStu=j;
        break;
    case SENIOR:
        pStu=s;
        break;
    }
    for(int i=0;i<pStu.size();i++){
        if(value==pStu[i]->getId())
            reStu.push_back(pStu[i]);
        else
            cnt++;
    }
    if(cnt==pStu.size()){
        cerr<<"无结果"<<endl;
        exit(2);
    }
    else
        return reStu;
}

vector <Student*> getInfo(int type,string value){
    int mnt=0;
    vector <Student*> pStu;
    vector <Student*> reStu;
    vector <Student*> p=readInfo(PUPIL);
    vector <Student*> j=readInfo(JUNIOR);
    vector <Student*> s=readInfo(SENIOR);
    switch(type){
    case PUPIL:
        pStu=p;
        break;
    case JUNIOR:
        pStu=j;
        break;
    case SENIOR:
        pStu=s;
        break;
    }
    for(int i=0;i<pStu.size();i++){
        if(value==pStu[i]->getName())
            reStu.push_back(pStu[i]);
        else
            mnt++;
    }
    if(mnt==pStu.size()){
        cerr<<"无结果"<<endl;
        exit(2);
    }
    else
        return reStu;
}

vector <Student*> sortSingle(int type,int way){
    vector <Student*> pStu;
    vector <Student*> p=readInfo(PUPIL);
    vector <Student*> j=readInfo(JUNIOR);
    vector <Student*> s=readInfo(SENIOR);
    switch(type){
    case PUPIL:
        pStu=p;
        break;
    case JUNIOR:
        pStu=j;
        break;
    case SENIOR:
        pStu=s;
        break;
    }
    Student* temp=0;
    switch(way){
    case MARKEN:
        for(int i=0;i<pStu.size();i++){
            for(int j=i+1;j<pStu.size();j++){
                if(pStu[i]->getMarkEn()<pStu[j]->getMarkEn()){
                    temp=pStu[i];
                    pStu[i]=pStu[j];
                    pStu[j]=temp;
                }
            }
        }
        break;
    case MARKMATH:
        for(int i=0;i<pStu.size();i++){
            for(int j=i+1;j<pStu.size();j++){
                if(pStu[i]->getMarkMath()<pStu[j]->getMarkMath()){
                    temp=pStu[i];
                    pStu[i]=pStu[j];
                    pStu[j]=temp;
                }
            }
        }
        break;
    case MARKCN:
        for(int i=0;i<pStu.size();i++){
            for(int j=i+1;j<pStu.size();j++){
                if(pStu[i]->getMarkCn()<pStu[j]->getMarkCn()){
                    temp=pStu[i];
                    pStu[i]=pStu[j];
                    pStu[j]=temp;
                }
            }
        }
        break;
    case MARKGEO:
        for(int i=0;i<pStu.size();i++){
            for(int j=i+1;j<pStu.size();j++){
                if(pStu[i]->getMarkGeo()<pStu[j]->getMarkGeo()){
                    temp=pStu[i];
                    pStu[i]=pStu[j];
                    pStu[j]=temp;
                }
            }
        }
        break;
    case MARKHIS:
        for(int i=0;i<pStu.size();i++){
            for(int j=i+1;j<pStu.size();j++){
                if(pStu[i]->getMarkHis()<pStu[j]->getMarkHis()){
                    temp=pStu[i];
                    pStu[i]=pStu[j];
                    pStu[j]=temp;
                }
            }
        }
        break;
    case MARKPGM:
        for(int i=0;i<pStu.size();i++){
            for(int j=i+1;j<pStu.size();j++){
                if(pStu[i]->getMarkPgm()<pStu[j]->getMarkPgm()){
                    temp=pStu[i];
                    pStu[i]=pStu[j];
                    pStu[j]=temp;
                }
            }
        }
        break;
    case MARKHM:
        for(int i=0;i<pStu.size();i++){
            for(int j=i+1;j<pStu.size();j++){
                if(pStu[i]->getMarkHm()<pStu[j]->getMarkHm()){
                    temp=pStu[i];
                    pStu[i]=pStu[j];
                    pStu[j]=temp;
                }
            }
        }
        break;
    }

    return pStu;
}

vector <Student*> sortAll(int type){
    vector <Student*> pStu;
    vector <Student*> p=readInfo(PUPIL);
    vector <Student*> j=readInfo(JUNIOR);
    vector <Student*> s=readInfo(SENIOR);
    switch(type){
    case PUPIL:
        pStu=p;
        break;
    case JUNIOR:
        pStu=j;
        break;
    case SENIOR:
        pStu=s;
        break;
    }
    Student* temp=0;
    for(int i=0;i<pStu.size();i++){
        for(int j=i+1;j<pStu.size();j++){
            unsigned iAll=0,jAll=0;
            switch(type){
            case PUPIL:
                iAll=pStu[i]->getMarkEn()+pStu[i]->getMarkMath()+pStu[i]->getMarkCn();
                jAll=pStu[j]->getMarkEn()+pStu[j]->getMarkMath()+pStu[j]->getMarkCn();
                break;
            case JUNIOR:
                iAll=pStu[i]->getMarkEn()+pStu[i]->getMarkMath()+pStu[i]->getMarkCn()+pStu[i]->getMarkGeo()+pStu[i]->getMarkHis();
                jAll=pStu[j]->getMarkEn()+pStu[j]->getMarkMath()+pStu[j]->getMarkCn()+pStu[j]->getMarkGeo()+pStu[j]->getMarkHis();
                break;
            case SENIOR:
                iAll=pStu[i]->getMarkEn()+pStu[i]->getMarkPgm()+pStu[i]->getMarkHm();
                jAll=pStu[j]->getMarkEn()+pStu[j]->getMarkPgm()+pStu[j]->getMarkHm();
            }
            if(iAll<jAll){
                temp=pStu[i];
                pStu[i]=pStu[j];
                pStu[j]=temp;
            }
        }
    }

    return pStu;
}

vector <Student*> readInfo(int type){
    vector <Student*> buf;
    string inBuf;
    char a;
    if(type==PUPIL){
        int i=0;
        unsigned id;
        string name;
        string sex;
        unsigned age;
        string kurasu;
        unsigned En;
        unsigned Math;
        unsigned Cn;
        ifstream inFile("PUPIL.txt");
        if(!inFile){
            ofstream makeFile("PUPIL.txt");
            makeFile.close();
        }
        while(inFile>>inBuf){
            switch(i){
            case 0:
                id=atoi(inBuf.c_str());
                break;
            case 1:
                name=inBuf;
                break;
            case 2:
                sex=inBuf;
                break;
            case 3:
                age=atoi(inBuf.c_str());
                break;
            case 4:
                kurasu=inBuf;
                break;
            case 5:
                En=atoi(inBuf.c_str());
                break;
            case 6:
                Math=atoi(inBuf.c_str());
                break;
            case 7:
                Cn=atoi(inBuf.c_str());
                break;
            }
            i++;
            if(i==8){
                i=0;
                Student* temp=new Pupil(id,name,sex,age,kurasu,En,Math,Cn);
                buf.push_back(temp);
            }
        }
        if(!inBuf.size())
            cout<<setfill(' ')<<setw(10)<<"小学生无结果"<<endl;
        inFile.close();
    }else if(type==JUNIOR){
        int i=0;
        unsigned id;
        string name;
        string sex;
        unsigned age;
        string kurasu;
        unsigned En;
        unsigned Math;
        unsigned Cn;
        unsigned Geo;
        unsigned His;
        ifstream inFile("JUNIOR.txt");
        if(!inFile){
            ofstream makeFile("JUNIOR.txt");
            makeFile.close();
        }
        while(inFile>>inBuf){
            switch(i){
            case 0:
                id=atoi(inBuf.c_str());
                break;
            case 1:
                name=inBuf;
                break;
            case 2:
                sex=inBuf;
                break;
            case 3:
                age=atoi(inBuf.c_str());
                break;
            case 4:
                kurasu=inBuf;
                break;
            case 5:
                En=atoi(inBuf.c_str());
                break;
            case 6:
                Math=atoi(inBuf.c_str());
                break;
            case 7:
                Cn=atoi(inBuf.c_str());
                break;
            case 8:
                Geo=atoi(inBuf.c_str());
                break;
            case 9:
                His=atoi(inBuf.c_str());
                break;
            }
            i++;
            if(i==10){
                i=0;
                Student* temp=new Junior(id,name,sex,age,kurasu,En,Math,Cn,Geo,His);
                buf.push_back(temp);
            }
        }
        if(!inBuf.size())
            cout<<setfill(' ')<<setw(10)<<"中学生无结果"<<endl;
        inFile.close();
    }else if(type==SENIOR){
        int i=0;
        unsigned id;
        string name;
        string sex;
        unsigned age;
        string kurasu;
        string Major;
        unsigned En;
        unsigned Pgm;
        unsigned Hm;
        ifstream inFile("SENIOR.txt");
        if(!inFile){
            ofstream makeFile("SENIOR.txt");
            makeFile.close();
        }
        while(inFile>>inBuf){
            switch(i){
            case 0:
                id=atoi(inBuf.c_str());
                break;
            case 1:
                name=inBuf;
                break;
            case 2:
                sex=inBuf;
                break;
            case 3:
                age=atoi(inBuf.c_str());
                break;
            case 4:
                kurasu=inBuf;
                break;
            case 5:
                Major=inBuf;
                break;
            case 6:
                En=atoi(inBuf.c_str());
                break;
            case 7:
                Pgm=atoi(inBuf.c_str());
                break;
            case 8:
                Hm=atoi(inBuf.c_str());
                break;
            }
            i++;
            if(i==9){
                i=0;
                Student* temp=new Senior(id,name,sex,age,kurasu,Major,En,Pgm,Hm);
                buf.push_back(temp);
            }
        }
        if(!inBuf.size())
            cout<<setfill(' ')<<setw(10)<<"大学生无结果"<<endl;
        inFile.close();
    }
    return buf;
}

void allInfo(){
    cout<<"-小学生-"<<endl;
    tabHead(PUPIL);
    vector <Student*> p=readInfo(PUPIL);
    for(int i=0;i<p.size();i++)
        printInfo(p[i],PUPIL);
    cout<<endl;

    cout<<"-中学生-"<<endl;
    tabHead(JUNIOR);
    vector <Student*> j=readInfo(JUNIOR);
    for(int i=0;i<j.size();i++)
        printInfo(j[i],JUNIOR);
    cout<<endl;

    cout<<"-大学生-"<<endl;
    tabHead(SENIOR);
    vector <Student*> s=readInfo(SENIOR);
    for(int i=0;i<s.size();i++)
        printInfo(s[i],SENIOR);
    cout<<endl;
}

void statNum(int type){
    int num=0;
    vector <Student*> p=readInfo(PUPIL);
    vector <Student*> j=readInfo(JUNIOR);
    vector <Student*> s=readInfo(SENIOR);
    switch(type){
    case PUPIL:
        num=p.size();
        cout<<"小学生";
        break;
    case JUNIOR:
        num=j.size();
        cout<<"中学生";
        break;
    case SENIOR:
        num=s.size();
        cout<<"大学生";
        break;
    case ALL:
        num=p.size()+j.size()+s.size();
        break;
    }
    cout<<"总人数:"<<num<<endl;
}

void stat(int type,unsigned id){
    unsigned mark=0;
    switch(type){
    case PUPIL:
        mark=getInfo(type,id)[0]->getMarkEn()+getInfo(type,id)[0]->getMarkMath()+getInfo(type,id)[0]->getMarkCn();
        break;
    case JUNIOR:
        mark=getInfo(type,id)[0]->getMarkEn()+getInfo(type,id)[0]->getMarkMath()+getInfo(type,id)[0]->getMarkCn()+getInfo(type,id)[0]->getMarkGeo()+getInfo(type,id)[0]->getMarkHis();
        break;
    case SENIOR:
        mark=getInfo(type,id)[0]->getMarkEn()+getInfo(type,id)[0]->getMarkPgm()+getInfo(type,id)[0]->getMarkHm();
        break;
    }
    cout<<getInfo(type,id)[0]->getId()<<"-"<<getInfo(type,id)[0]->getName()<<"总分:"<<mark<<endl;
}

void stat(int type,string name){
    unsigned mark=0;
    for(int i=0;i<getInfo(type,name).size();i++){
        switch(type){
        case PUPIL:
           mark=getInfo(type,name)[i]->getMarkEn()+getInfo(type,name)[i]->getMarkMath()+getInfo(type,name)[i]->getMarkCn();
           break;
        case JUNIOR:
           mark=getInfo(type,name)[i]->getMarkEn()+getInfo(type,name)[i]->getMarkMath()+getInfo(type,name)[i]->getMarkCn()+getInfo(type,name)[i]->getMarkGeo()+getInfo(type,name)[i]->getMarkHis();
           break;
        case SENIOR:
           mark=getInfo(type,name)[i]->getMarkEn()+getInfo(type,name)[i]->getMarkPgm()+getInfo(type,name)[i]->getMarkHm();
           break;
        }
        cout<<getInfo(type,name)[i]->getId()<<"-"<<getInfo(type,name)[i]->getName()<<"总分:"<<mark<<endl;
        mark=0;
    }
}

void stat(int type){
    vector <Student*> p=readInfo(PUPIL);
    vector <Student*> j=readInfo(JUNIOR);
    vector <Student*> s=readInfo(SENIOR);
    float mark=0;
    switch(type){
    case MARKCN:
        for(int i=0;i<p.size();i++)
            mark+=p[i]->getMarkCn();
        cout<<"小学语文平均分:"<<(mark/p.size())<<endl;
        mark=0;
        for(int i=0;i<j.size();i++)
            mark+=j[i]->getMarkCn();
        cout<<"中学语文平均分:"<<(mark/j.size())<<endl;
        mark=0;
        break;
    case MARKMATH:
        for(int i=0;i<p.size();i++)
            mark+=p[i]->getMarkMath();
        cout<<"小学数学平均分:"<<(mark/p.size())<<endl;
        mark=0;
        for(int i=0;i<j.size();i++)
            mark+=j[i]->getMarkMath();
        cout<<"中学数学平均分:"<<(mark/j.size())<<endl;
        mark=0;
        break;
    case MARKEN:
        for(int i=0;i<p.size();i++)
            mark+=p[i]->getMarkEn();
        cout<<"小学英语平均分:"<<(mark/p.size())<<endl;
        mark=0;
        for(int i=0;i<j.size();i++)
            mark+=j[i]->getMarkEn();
        cout<<"中学英语平均分:"<<(mark/j.size())<<endl;
        mark=0;
        for(int i=0;i<s.size();i++)
            mark+=s[i]->getMarkEn();
        cout<<"大学英语平均分:"<<(mark/s.size())<<endl;
        mark=0;
        break;
    case MARKGEO:
        for(int i=0;i<j.size();i++)
            mark+=j[i]->getMarkGeo();
        cout<<"中学地理平均分:"<<(mark/j.size())<<endl;
        mark=0;
        break;
    case MARKHIS:
        for(int i=0;i<j.size();i++)
            mark+=j[i]->getMarkHis();
        cout<<"中学历史平均分:"<<(mark/j.size())<<endl;
        mark=0;
        break;
    case MARKPGM:
        for(int i=0;i<s.size();i++)
            mark+=s[i]->getMarkPgm();
        cout<<"大学程序设计平均分:"<<(mark/s.size())<<endl;
        mark=0;
        break;
    case MARKHM:
        for(int i=0;i<s.size();i++)
            mark+=s[i]->getMarkHm();
        cout<<"大学高数平均分:"<<(mark/s.size())<<endl;
        mark=0;
        break;
    }
}

void writeInfo(int type,Student* stu){
    ofstream pOutFile("PUPIL.txt",ios::app);
    ofstream jOutFile("JUNIOR.txt",ios::app);
    ofstream sOutFile("SENIOR.txt",ios::app);
    switch(type){
    case PUPIL:
        pOutFile<<endl<<stu->getId()<<" "<<stu->getName()<<" "<<stu->getSex()<<" "<<stu->getAge()<<" "<<stu->getKurasu()<<" "<<stu->getMarkEn()<<" "<<stu->getMarkMath()<<" "<<stu->getMarkCn();
        break;
    case JUNIOR:
        jOutFile<<endl<<stu->getId()<<" "<<stu->getName()<<" "<<stu->getSex()<<" "<<stu->getAge()<<" "<<stu->getKurasu()<<" "<<stu->getMarkEn()<<" "<<stu->getMarkMath()<<" "<<stu->getMarkCn()<<" "<<stu->getMarkGeo()<<" "<<stu->getMarkHis();
        break;
    case SENIOR:
        sOutFile<<endl<<stu->getId()<<" "<<stu->getName()<<" "<<stu->getSex()<<" "<<stu->getAge()<<" "<<stu->getKurasu()<<" "<<stu->getMajor()<<" "<<stu->getMarkEn()<<" "<<stu->getMarkPgm()<<" "<<stu->getMarkHm();
        break;
    }
    sOutFile.close();
    jOutFile.close();
    pOutFile.close();
    cout<<"保存完成"<<endl;
}

Student* insertInfo(int type){
    Student* re;
    unsigned id;
    string name;
    string sex;
    unsigned age;
    string kurasu;
    if(type==PUPIL){
        unsigned markEn;
        unsigned markMath;
        unsigned markCn;
        cout<<"-添加小学生-"<<endl;
        cout<<"学号:";
        cin>>id;
        cout<<"姓名:";
        cin>>name;
        cout<<"性别:";
        cin>>sex;
        cout<<"年龄:";
        cin>>age;
        cout<<"班级:";
        cin>>kurasu;
        cout<<"英语成绩:";
        cin>>markEn;
        cout<<"数学成绩:";
        cin>>markMath;
        cout<<"语文成绩:";
        cin>>markCn;
        re=new Pupil(id,name,sex,age,kurasu,markEn,markMath,markCn);
    }else if(type==JUNIOR){
        unsigned markEn;
        unsigned markMath;
        unsigned markCn;
        unsigned markGeo;
        unsigned markHis;
        cout<<"-添加中学生-"<<endl;
        cout<<"学号:";
        cin>>id;
        cout<<"姓名:";
        cin>>name;
        cout<<"性别:";
        cin>>sex;
        cout<<"年龄:";
        cin>>age;
        cout<<"班级:";
        cin>>kurasu;
        cout<<"英语成绩:";
        cin>>markEn;
        cout<<"数学成绩:";
        cin>>markMath;
        cout<<"语文成绩:";
        cin>>markCn;
        cout<<"地理成绩:";
        cin>>markGeo;
        cout<<"历史成绩:";
        cin>>markHis;
        re=new Junior(id,name,sex,age,kurasu,markEn,markMath,markCn,markGeo,markHis);
    }else if(type==SENIOR){
        string Major;
        unsigned markEn;
        unsigned markPgm;
        unsigned markHm;
        cout<<"-添加大学生-"<<endl;
        cout<<"学号:";
        cin>>id;
        cout<<"姓名:";
        cin>>name;
        cout<<"性别:";
        cin>>sex;
        cout<<"年龄:";
        cin>>age;
        cout<<"班级:";
        cin>>kurasu;
        cout<<"专业:";
        cin>>Major;
        cout<<"英语成绩:";
        cin>>markEn;
        cout<<"程序设计成绩:";
        cin>>markPgm;
        cout<<"高数成绩:";
        cin>>markHm;
        re=new Senior(id,name,sex,age,kurasu,Major,markEn,markPgm,markHm);
    }
    vector <Student*> p=readInfo(PUPIL);
    vector <Student*> j=readInfo(JUNIOR);
    vector <Student*> s=readInfo(SENIOR);
    for(int i=0;i<p.size();i++){
        if(id==p[i]->getId()){
            cerr<<"添加失败:本学号已有记录！"<<endl;
            tabHead(PUPIL);
            printInfo(p[i],PUPIL);
            exit(3);
        }
    }
    for(int i=0;i<j.size();i++){
        if(id==j[i]->getId()){
            cerr<<"添加失败:本学号已有记录！"<<endl;
            tabHead(JUNIOR);
            printInfo(j[i],JUNIOR);
            exit(3);
        }
    }
    for(int i=0;i<s.size();i++){
        if(id==s[i]->getId()){
            cerr<<"添加失败:本学号已有记录！"<<endl;
            tabHead(SENIOR);
            printInfo(s[i],SENIOR);
            exit(3);
        }
    }

    return re;
}

void delInfo(int type,unsigned id){
    vector <Student*> p=readInfo(PUPIL);
    vector <Student*> j=readInfo(JUNIOR);
    vector <Student*> s=readInfo(SENIOR);
    Student* stu;
    int cnt=0;
    switch(type){
    case PUPIL:
        for(int i=0;i<p.size();i++){
            if(id==p[i]->getId()){
                ofstream pOutFile("PUPIL.txt");
                for(int k=0;k<p.size();k++){
                    if(k!=i){

                        stu=p[k];
                        pOutFile<<stu->getId()<<" "<<stu->getName()<<" "<<stu->getSex()<<" "<<stu->getAge()<<" "<<stu->getKurasu()<<" "<<stu->getMarkEn()<<" "<<stu->getMarkMath()<<" "<<stu->getMarkCn()<<endl;

                    }else
                        cout<<"删除:"<<p[k]->getId()<<"-"<<p[k]->getName()<<endl;
                }
                pOutFile.close();
            }else
                cnt++;
        }
        if(cnt==p.size())
            cout<<"删除失败:无此学号的学生记录"<<endl;
        break;
    case JUNIOR:
        for(int i=0;i<j.size();i++){
            if(id==j[i]->getId()){
                ofstream jOutFile("JUNIOR.txt");
                for(int k=0;k<j.size();k++){
                    if(k!=i){

                        stu=j[k];
                        jOutFile<<stu->getId()<<" "<<stu->getName()<<" "<<stu->getSex()<<" "<<stu->getAge()<<" "<<stu->getKurasu()<<" "<<stu->getMarkEn()<<" "<<stu->getMarkMath()<<" "<<stu->getMarkCn()<<" "<<stu->getMarkGeo()<<" "<<stu->getMarkHis()<<endl;

                    }else
                        cout<<"删除:"<<j[k]->getId()<<"-"<<j[k]->getName()<<endl;
                }
                jOutFile.close();
            }else
                cnt++;
        }
        if(cnt==j.size())
            cout<<"删除失败:无此学号的学生记录"<<endl;
        break;
    case SENIOR:
        for(int i=0;i<s.size();i++){
            if(id==s[i]->getId()){
                ofstream sOutFile("SENIOR.txt");
                for(int k=0;k<s.size();k++){
                    if(k!=i){

                        stu=s[k];
                        sOutFile<<stu->getId()<<" "<<stu->getName()<<" "<<stu->getSex()<<" "<<stu->getAge()<<" "<<stu->getKurasu()<<" "<<stu->getMajor()<<" "<<stu->getMarkEn()<<" "<<stu->getMarkPgm()<<" "<<stu->getMarkHm()<<endl;

                    }else
                        cout<<"删除:"<<s[k]->getId()<<"-"<<s[k]->getName()<<endl;
                }
                sOutFile.close();
            }else
                cnt++;
        }
        if(cnt==s.size())
            cout<<"删除失败:无此学号的学生记录"<<endl;
        break;
    }
}
