#include "header.h"

int main(int argc,const char* argv[]){
    vector <string> arg;
    for(int i=1;i<argc;i++){
        arg.push_back(argv[i]);
    }
    arg.push_back("None");
    if(arg[0]=="None"){
        cout<<"使用说明:"<<endl<<endl;
        cout.setf(std::ios::left);
        cout.width(25);
        cout<<"insert [类型]";
        cout<<setfill(' ')<<setw(75)<<"添加数据 [类型]可为:PUPIL,JUNIOR,SENIOR 分别代表:小学生、中学生、大学生"<<endl<<endl;
        cout.width(25);
        cout.setf(std::ios::left);
        cout<<"search";
        cout<<setfill(' ')<<setw(75)<<"查询数据"<<endl<<endl;
        cout.width(25);
        cout.setf(std::ios::left);
        cout<<"show";
        cout<<setfill(' ')<<setw(75)<<"显示数据 显示所有数据"<<endl<<endl;
        cout.width(25);
        cout.setf(std::ios::left);
        cout<<"edit [学号]";
        cout<<setfill(' ')<<setw(75)<<"编辑数据 根据学号检索"<<endl<<endl;
        cout.width(25);
        cout.setf(std::ios::left);
        cout<<"delete [类型] [学号]";
        cout<<setfill(' ')<<setw(75)<<"删除数据 根据类型(同 insert)、学号检索"<<endl<<endl;
        cout.width(25);
        cout.setf(std::ios::left);
        cout<<"count [方式]";
        cout<<setfill(' ')<<setw(75)<<"统计数据 [方式]可为:ALL,PUPIL,JUNIOR,SENIOR,SCORE,AVERAGE 分别代表:总人数、小学生数、中学生数、大学生数、个人总成绩、单科平均分"<<endl<<endl;
        cout.width(25);
        cout.setf(std::ios::left);
        cout<<"sort [方式]";
        cout<<setfill(' ')<<setw(75)<<"数据排序 [方式]可为:ALL,SINGLE 分别代表:总成绩、单科成绩"<<endl<<endl;
    }else if(arg[0]=="insert"){
        int type;
        if(arg[1]=="PUPIL")
            type=PUPIL;
        else if(arg[1]=="JUNIOR")
            type=JUNIOR;
        else if(arg[1]=="SENIOR")
            type=SENIOR;
        else if(arg[1]=="None"){
            cerr<<"参数错误:未输入第二个参数"<<endl;
            exit(4);
        }
        else{
            cerr<<"参数错误:没有参数["<<arg[1]<<"]"<<endl;
            exit(5);
        }
        writeInfo(type,insertInfo(type));
    }else if(arg[0]=="search"){
        int type,key;
        string value;
        int val;
        cout<<"查询范围(输入数字-小学[0]、中学[1]、大学[2]):";
        cin>>type;
        while(type!=0&&type!=1&&type!=2){
            cerr<<"输入错误:请输入0、1、2,其中之一"<<endl<<":";
            cin>>type;
        }
        switch(type){
        case PUPIL:
            cout<<"查询类型(输入数字-学号[11]、年龄[12]、英语成绩[13]、数学成绩[14]、语文成绩[15]、姓名[51]、性别[52]、班级[53]):";
            cin>>key;
            while(key!=11&&key!=12&&key!=13&&key!=14&&key!=15&&key!=51&&key!=52&&key!=53){
                cerr<<"输入错误:请输入11、12、13、14、15、51、52、53,其中之一"<<endl<<":";
                cin>>key;
            }
            break;
        case JUNIOR:
            cout<<"查询类型(输入数字-学号[11]、年龄[12]、英语成绩[13]、数学成绩[14]、语文成绩[15]、地理成绩[16]、历史成绩[17]、姓名[51]、性别[52]、班级[53]):";
            cin>>key;
            while(key!=11&&key!=12&&key!=13&&key!=14&&key!=15&&key!=16&&key!=17&&key!=51&&key!=52&&key!=53){
                cerr<<"输入错误:请输入11、12、13、14、15、16、17、51、52、53,其中之一"<<endl<<":";
                cin>>key;
            }
            break;
        case SENIOR:
            cout<<"查询类型(输入数字-学号[11]、年龄[12]、英语成绩[13]、程序设计成绩[18]、高数成绩[19]、姓名[51]、性别[52]、班级[53]、专业[54]):";
            cin>>key;
            while(key!=11&&key!=12&&key!=13&&key!=18&&key!=19&&key!=51&&key!=52&&key!=53&&key!=54){
                cerr<<"输入错误:请输入11、12、13、18、19、51、52、53、54,其中之一"<<endl<<":";
                cin>>key;
            }
            break;
        }
        cout<<"查询值:";
        cin>>value;
        if(key<30){
            val=atoi(value.c_str());
            searchInfo(type,key,val);
        }else
            searchInfo(type,key,value);
    }else if(arg[0]=="show")
        allInfo();
    else if(arg[0]=="edit"){
        if(arg[1]=="None"){
            cerr<<"参数错误:未输入第二个参数"<<endl;
            exit(4);
        }
        int id=atoi(arg[1].c_str());
        int cnt=0,hitI=-1,type;
        vector <Student*> p=readInfo(PUPIL);
        vector <Student*> j=readInfo(JUNIOR);
        vector <Student*> s=readInfo(SENIOR);
        vector <unsigned> Ids;
        for(int i=0;i<p.size();i++){
            if(id==p[i]->getId()){
                type=p[i]->get();
                hitI=i;
            }
            else{
                cnt++;
                Ids.push_back(p[i]->getId());
            }
        }
        for(int i=0;i<j.size();i++){
            if(id==j[i]->getId()){
                type=j[i]->get();
                hitI=i;
            }
            else{
                cnt++;
                Ids.push_back(j[i]->getId());
            }
        }
        for(int i=0;i<s.size();i++){
            if(id==s[i]->getId()){
                type=s[i]->get();
                hitI=i;
            }
            else{
                cnt++;
                Ids.push_back(s[i]->getId());
            }
        }
        if(cnt==p.size()+j.size()+s.size())
            cout<<"无结果"<<endl;
        else{
            Student* stu;
            Student* outStu;

            unsigned Id;
            string Name;
            string Sex;
            unsigned Age;
            string Kurasu;
            unsigned markEn;
            unsigned markMath;
            unsigned markCn;
            unsigned markGeo;
            unsigned markHis;
            string Major;
            unsigned markPgm;
            unsigned markHm;

            bool isE=false;
            int key;
            if(type==PUPIL){
                stu=p[hitI];
                Id=stu->getId();
                Name=stu->getName();
                Sex=stu->getSex();
                Age=stu->getAge();
                Kurasu=stu->getKurasu();
                markEn=stu->getMarkEn();
                markMath=stu->getMarkMath();
                markCn=stu->getMarkCn();
                cout<<"修改类型(输入数字-学号[11]、年龄[12]、英语成绩[13]、数学成绩[14]、语文成绩[15]、姓名[51]、性别[52]、班级[53]):";
                cin>>key;
                while(key!=11&&key!=12&&key!=13&&key!=14&&key!=15&&key!=51&&key!=52&&key!=53){
                    cerr<<"输入错误:请输入11、12、13、14、15、51、52、53,其中之一"<<endl<<":";
                    cin>>key;
                }
                switch(key){
                case ID:
                    do{
                        isE=false;
                        cout<<":";
                        cin>>Id;
                        for(int i=0;i<Ids.size();i++){
                            if(Id==Ids[i]){
                                isE=true;
                                cerr<<"此学号已存在"<<endl;
                            }
                        }
                    }while(isE);
                    break;
                case NAME:
                    cout<<":";
                    cin>>Name;
                    break;
                case SEX:
                    cout<<":";
                    cin>>Sex;
                    while(Sex!="男"&&Sex!="女"){
                        cerr<<endl<<"错误:性别必须为“男”或“女”!"<<endl;
                        cout<<":";
                        cin>>Sex;
                    }
                    break;
                case AGE:
                    cout<<":";
                    cin>>Age;
                    break;
                case KURASU:
                    cout<<":";
                    cin>>Kurasu;
                    break;
                case MARKEN:
                    cout<<":";
                    cin>>markEn;
                    break;
                case MARKMATH:
                    cout<<":";
                    cin>>markMath;
                    break;
                case MARKCN:
                    cout<<":";
                    cin>>markCn;
                    break;
                }
                outStu=new Pupil(Id,Name,Sex,Age,Kurasu,markEn,markMath,markCn);
                delInfo(PUPIL,stu->getId());
                writeInfo(PUPIL,outStu);
            }else if(type==JUNIOR){
                stu=j[hitI];
                Id=stu->getId();
                Name=stu->getName();
                Sex=stu->getSex();
                Age=stu->getAge();
                Kurasu=stu->getKurasu();
                markEn=stu->getMarkEn();
                markMath=stu->getMarkMath();
                markCn=stu->getMarkCn();
                markGeo=stu->getMarkGeo();
                markHis=stu->getMarkHis();
                cout<<"修改类型(输入数字-学号[11]、年龄[12]、英语成绩[13]、数学成绩[14]、语文成绩[15]、地理成绩[16]、历史成绩[17]、姓名[51]、性别[52]、班级[53]):";
                cin>>key;
                while(key!=11&&key!=12&&key!=13&&key!=14&&key!=15&&key!=16&&key!=17&&key!=51&&key!=52&&key!=53){
                    cerr<<"输入错误:请输入11、12、13、14、15、16、17、51、52、53,其中之一"<<endl<<":";
                    cin>>key;
                }
                switch(key){
                   case ID:
                        do{
                            isE=false;
                            cout<<":";
                            cin>>Id;
                            for(int i=0;i<Ids.size();i++){
                                if(Id==Ids[i]){
                                    isE=true;
                                    cerr<<"此学号已存在"<<endl;
                                }
                            }
                        }while(isE);
                        break;
                    case NAME:
                        cout<<":";
                        cin>>Name;
                        break;
                    case SEX:
                        cout<<":";
                        cin>>Sex;
                        while(Sex!="男"&&Sex!="女"){
                            cerr<<endl<<"错误:性别必须为“男”或“女”!"<<endl;
                            cout<<":";
                            cin>>Sex;
                        }
                        break;
                    case AGE:
                        cout<<":";
                        cin>>Age;
                        break;
                    case KURASU:
                        cout<<":";
                        cin>>Kurasu;
                        break;
                    case MARKEN:
                        cout<<":";
                        cin>>markEn;
                        break;
                    case MARKMATH:
                        cout<<":";
                        cin>>markMath;
                        break;
                    case MARKCN:
                        cout<<":";
                        cin>>markCn;
                        break;
                    case MARKGEO:
                        cout<<":";
                        cin>>markGeo;
                        break;
                    case MARKHIS:
                        cout<<":";
                        cin>>markHis;
                        break;
                    }
                    outStu=new Junior(Id,Name,Sex,Age,Kurasu,markEn,markMath,markCn,markGeo,markHis);
                    delInfo(JUNIOR,stu->getId());
                    writeInfo(JUNIOR,outStu);
                }else if(type==SENIOR){
                    stu=s[hitI];
                    Id=stu->getId();
                    Name=stu->getName();
                    Sex=stu->getSex();
                    Age=stu->getAge();
                    Kurasu=stu->getKurasu();
                    Major=stu->getMajor();
                    markEn=stu->getMarkEn();
                    markPgm=stu->getMarkPgm();
                    markHm=stu->getMarkHm();
                    cout<<"修改类型(输入数字-学号[11]、年龄[12]、英语成绩[13]、程序设计成绩[18]、高数成绩[19]、姓名[51]、性别[52]、班级[53]、专业[54]):";
                    cin>>key;
                    while(key!=11&&key!=12&&key!=13&&key!=18&&key!=19&&key!=51&&key!=52&&key!=53&&key!=54){
                        cerr<<"输入错误:请输入11、12、13、18、19、51、52、53、54,其中之一"<<endl<<":";
                        cin>>key;
                    }
                    switch(key){
                    case ID:
                        do{
                            isE=false;
                            cout<<":";
                            cin>>Id;
                            for(int i=0;i<Ids.size();i++){
                                if(Id==Ids[i]){
                                    isE=true;
                                    cerr<<"此学号已存在"<<endl;
                                }
                            }
                        }while(isE);
                        break;
                    case NAME:
                        cout<<":";
                        cin>>Name;
                        break;
                    case SEX:
                        cout<<":";
                        cin>>Sex;
                        while(Sex!="男"&&Sex!="女"){
                            cerr<<endl<<"错误:性别必须为“男”或“女”!"<<endl;
                            cout<<":";
                            cin>>Sex;
                        }
                        break;
                    case AGE:
                        cout<<":";
                        cin>>Age;
                        break;
                    case KURASU:
                        cout<<":";
                        cin>>Kurasu;
                        break;
                    case MAJOR:
                        cout<<":";
                        cin>>Major;
                        break;
                    case MARKEN:
                        cout<<":";
                        cin>>markEn;
                        break;
                    case MARKPGM:
                        cout<<":";
                        cin>>markPgm;
                        break;
                    case MARKHM:
                        cout<<":";
                        cin>>markHm;
                        break;
                    }
                    outStu=new Senior(Id,Name,Sex,Age,Kurasu,Major,markEn,markPgm,markHm);
                    delInfo(SENIOR,stu->getId());
                    writeInfo(SENIOR,outStu);
                }
            }
        }else if(arg[0]=="delete"){
            int type,id;
            if(arg[1]=="PUPIL")
                type=PUPIL;
            else if(arg[1]=="JUNIOR")
                type=JUNIOR;
            else if(arg[1]=="SENIOR")
                type=SENIOR;
            else if(arg[1]=="None"){
                cerr<<"参数错误:未输入第二个参数"<<endl;
                exit(4);
            }
            else{
                cerr<<"参数错误:没有参数["<<arg[1]<<"]"<<endl;
                exit(5);
            }
            if(arg[2]=="None"){
                cerr<<"参数错误:未输入第三个参数"<<endl;
                exit(4);
            }else
                id=atoi(arg[2].c_str());
            delInfo(type,id);
        }else if(arg[0]=="count"){
            int type,key;
            int id;
            string name;
            if(arg[1]=="ALL")
                statNum(ALL);
            else if(arg[1]=="PUPIL")
                statNum(PUPIL);
            else if(arg[1]=="JUNIOR")
                statNum(JUNIOR);
            else if(arg[1]=="SENIOR")
                statNum(SENIOR);
            else if(arg[1]=="SCORE"){
                cout<<"查询范围(输入数字-小学生[0]、中学生[1]、大学生[2]):";
                cin>>type;
                while(type!=0&&type!=1&&type!=2){
                    cerr<<"输入错误:请输入0、1、2,其中之一"<<endl<<":";
                    cin>>type;
                }
                cout<<"查询类型(输入数字-学号[11]、姓名[51]):";
                cin>>key;
                while(key!=11&&key!=51){
                    cerr<<"输入错误:请输入11、51,其中之一"<<endl<<":";
                    cin>>key;
                }
                switch(key){
                case ID:
                    cout<<":";
                    cin>>id;
                    stat(type,id);
                    break;
                case NAME:
                    cout<<":";
                    cin>>name;
                    stat(type,name);
                    break;
                }
            }
            else if(arg[1]=="AVERAGE"){
                cout<<"查询科目(输入数字-英语[13]、数学[14]、语文[15]、地理[16]、历史[17]、程序设计[18]、高数[19]):";
                cin>>key;
                while(key!=13&&key!=14&&key!=15&&key!=16&&key!=17&&key!=18&&key!=19){
                    cerr<<"输入错误:请输入13、14、15、16、17、18、19,其中之一"<<endl<<":";
                    cin>>key;
                }
                stat(key);
            }else if(arg[1]=="None"){
                cerr<<"参数错误:未输入第二个参数"<<endl;
                exit(4);
            }else{
                cerr<<"参数错误:没有参数["<<arg[1]<<"]"<<endl;
                exit(5);
            }
        }else if(arg[0]=="sort"){
            if(arg[1]=="ALL"){
                int type;
                cout<<"查询范围(输入数字-小学生[0]、中学生[1]、大学生[2]):";
                cin>>type;
                while(type!=0&&type!=1&&type!=2){
                    cerr<<"输入错误:请输入0、1、2,其中之一"<<endl<<":";
                    cin>>type;
                }
                vector <Student*> stu=sortAll(type);
                tabHead(type);
                for(int i=0;i<stu.size();i++){
                    printInfo(stu[i],type);
                }
            }else if(arg[1]=="SINGLE"){
                int type,key;
                cout<<"查询范围(输入数字-小学生[0]、中学生[1]、大学生[2]):";
                cin>>type;
                while(type!=0&&type!=1&&type!=2){
                    cerr<<"输入错误:请输入0、1、2,其中之一"<<endl<<":";
                    cin>>type;
                }
                switch(type){
                case PUPIL:
                    cout<<"查询科目(输入数字-英语成绩[13]、数学成绩[14]、语文成绩[15]):";
                    cin>>key;
                    while(key!=13&&key!=14&&key!=15){
                        cerr<<"输入错误:请输入13、14、15,其中之一"<<endl<<":";
                        cin>>key;
                    }
                    break;
                case JUNIOR:
                    cout<<"查询科目(输入数字-英语成绩[13]、数学成绩[14]、语文成绩[15]、地理成绩[16]、历史成绩[17]):";
                    cin>>key;
                    while(key!=13&&key!=14&&key!=15&&key!=16&&key!=17){
                        cerr<<"输入错误:请输入13、14、15、16、17,其中之一"<<endl<<":";
                        cin>>key;
                    }
                    break;
                case SENIOR:
                    cout<<"查询科目(输入数字-英语成绩[13]、程序设计成绩[18]、高数成绩[19]):";
                    cin>>key;
                    while(key!=13&&key!=18&&key!=19){
                        cerr<<"输入错误:请输入13、18、19,其中之一"<<endl<<":";
                        cin>>key;
                    }
                    break;
                }
                vector <Student*> stu=sortSingle(type,key);
                tabHead(type);
                for(int i=0;i<stu.size();i++)
                    printInfo(stu[i],type);

            }else if(arg[1]=="None"){
                cerr<<"参数错误:未输入第二个参数"<<endl;
                exit(4);
            }else{
                cerr<<"参数错误:没有参数["<<arg[1]<<"]"<<endl;
                exit(5);
            }
        }else{
            cerr<<"参数错误:没有参数["<<arg[0]<<"]"<<endl;
                exit(5);
        }

    /*vector <Student*> stu=sortSingle(PUPIL,MARKCN);
    tabHead(PUPIL);
    for(int i=0;i<stu.size();i++){
        printInfo(stu[i],PUPIL);
    }*/
    return 0;
}
