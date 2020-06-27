#include<iostream>
using namespace std;


const int NULLKEY = 0;


const int ENDFLAG = 0;


const int TableSize = 15;


const int mod = 6;


typedef int KeyType;


typedef char InfoType;


typedef struct
{
KeyType key;
InfoType otherinfo;
}HashTable;


int H(KeyType key);//散列函数 


void CreateHashTable(HashTable[]);//使用顺序存储结构建立散列表 


void OutputHashTable(HashTable[]);//输出散列表


int SearchHash(HashTable[], KeyType key);//在散列表中查找关键字为key的结点 


int main()
{
HashTable HT[TableSize];

for(int i=0; i<TableSize; i++)//将散列表每个结点的key分量初始化为NULLKEY
 HT[i].key = NULLKEY;

KeyType key;

int res;

CreateHashTable(HT);

OutputHashTable(HT);

cout << "Input the key you want to search: " ;

cin >> key;

while (key!=ENDFLAG)//直到读入的是ENDFLAG(0)，循环退出 
{
res = SearchHash(HT, key);

if (res==-1)
 cout << "Not find the key " << key << endl;
else 
 cout << "Find the key " << key << ", position = " << res << endl;
 
cout << "Input the key you want to search: " ;//继续读入下一个要查找的key
cin >> key;
}

return 0;
}


int H(KeyType key)//散列函数 
{
return key%mod ;
}


void CreateHashTable(HashTable HT[])
{//使用顺序存储结构建立散列表
int pos;

KeyType key;

cout << "Input your keys: " ;
cin >> key;

while (key!=ENDFLAG)//直到读入的是ENDFLAG(0)，循环退出
{
pos = H(key) ;//根据散列函数计算散列地址 

   for(int i=0; i<TableSize; i++)
   {    
    if ( HT[pos].key==NULLKEY ) //当前散列地址的key值为空 
       {
   HT[pos].key = key; //将key值写入当前散列地址 
   break;
       }
       pos = (pos+1)%TableSize ; //当前散列地址非空，使用线性探测法计算下一个散列地址
        }
     
   cin >> key;//继续读入下一个要写入的key 
    }
}

void OutputHashTable(HashTable HT[])
{
for(int i=0; i<TableSize; i++)
cout << "关键字：" << HT[i].key << ", 地址：" << i << endl; 
}


int SearchHash(HashTable HT[], KeyType key)
{//在散列表中查找关键字为key的结点 


int pos = H(key) ;//根据散列函数计算散列地址

for(int i=0; i<TableSize; i++)
{
  if(HT[pos].key==key)//当前散列地址的key值就是要查找的key值 
    return pos ;
  if(HT[pos].key==NULLKEY)//当前散列地址的key值为空 
    return -1;
    
  pos = (pos + 1) % TableSize;//当前散列地址非空且不是要查找的key值，使用线性探测法计算下一个查找地址
    }
}