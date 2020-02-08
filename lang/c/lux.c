#include<stdio.h>

int main(int argc,char *argv[])

{

if(argc==1||argc>2)

printf("请输入想要编辑的文件名如:fillname\n");

if(argc==2)

printf("编辑%s\n",argv[1]);

return 0;

}