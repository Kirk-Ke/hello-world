#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
struct stu
{
	int id;
	char name[20];
	int score;

}s[20],t[20];
void paixu(struct stu *p,int n)
{
	int i,j,t1,t2;
	struct stu *k1,*k2;
	char name[20];
	for(i=0;i<n-1;i++)
	{
		k1=p+i;
		for(j=i+1;j<n;j++)
		{
			k2=p+j;
			if(k1->score<k2->score)
			{
				t1=k1->id;
                k1->id=k2->id;
				k2->id=t1;
				strcpy(name,k1->name);
				strcpy(k1->name,k2->name);
				strcpy(k2->name,name);
				t2=k1->score;
                k1->score=k2->score;
				k2->score=t2;
			}
		}
	}
}
int exam(int sum)
{
	int r1,r2,i,a,c,A,num=0;//r1,r2为两随机值,i为存符号的数组的下标,a为学生答案,A为正确答案,c为第c次出题,num为正确数
	char fh[4]={'+','-','*','/'};//存符号的数组
	for(c=1;c<=sum;c++)
	{
		srand(time(NULL));//用来设置rand()产生随机数时的随机种子??
        i=rand()%4;//i为从0到3的随机数
	    r1=rand()%100+1;//r1为从1到100的随机数
	    switch(i)
		{
	    case 0:
			r2=rand()%(101-r1);//r2为从0到100-r1的随机数
			A=r1+r2;
			break;
		case 1:
		    r2=rand()%(r1+1);//r2为从0到r1之间的随机数
			A=r1-r2;
			break;
		case 2:
			r2=rand()%(100/r1)+1;//r2为从1到100/r1的随机数
			A=r1*r2;
			break;
		case 3:
			while(1)
			{
				r2=rand()%r1+1;//r2为从1到r1的随机数
				if(r1%r2==0)
					break;//确保除法能整除
			}
			A=r1/r2;
			break;
		}
	    printf("%d%c%d=",r1,fh[i],r2);
	    scanf("%d",&a);
	    if(a==A)
			num++;
	}
	return num;
}

int practice()
{
	int r1,r2,i,a,A,c,num=0;//r1,r2为两随机值,i为存符号的数组的下标，a为学生答案,A为正确答案,c为已用机会,num为正确数
	char fh[4]={'+','-','*','/'};//存符号的数组
	srand(time(NULL));//用来设置rand()产生随机数时的随机种子??
    i=rand()%4;//i为从0到3的随机数
	r1=rand()%100+1;//r1为从1到100的随机数
	switch(i)
	{
	    case 0:
			r2=rand()%(101-r1);//r2为从0到100-r1的随机数
			A=r1+r2;
			break;
		case 1:
		    r2=rand()%(r1+1);//r2为从0到r1之间的随机数
			A=r1-r2;
			break;
		case 2:
			r2=rand()%(100/r1)+1;//r2为从1到100/r1的随机数
			A=r1*r2;
			break;
		case 3:
			while(1)
			{
				r2=rand()%r1+1;//r2为从1到r1的随机数
				if(r1%r2==0)
					break;//确保除法能整除
			}
			A=r1/r2;
			break;
	}
	for(c=0;c<3;c++)
	{
		printf("%d%c%d=",r1,fh[i],r2);
		scanf("%d",&a);
		if(a==A)
		{
			printf("  正确");
			printf("\n");
			num++;
			break;
		}
		else 
		{
			printf("  错误");
			printf("\n");
		}
	}//实现有三次改正机会
	if(c==3)
		printf("正确答案为：\n%d%c%d=%d\n",r1,fh[i],r2,A);//当三次机会用完仍错误时输出算式及答案
	return num;
}

void main()
{
    int a,b=1,c,j,sum=0,num=0,score,SIZE=0,t1,t2=0;//j为结构体数组的下标,sum为出题数，num为正确数，score为考试得分,SIZE表示第SIZE个学生,t1用于临时存放学号，t2为当前学生信息下标，t用于临时存放数组??
	char name[20];//临时存放姓名
	FILE *fp;
	double pc;//pc为正确率
	while(b==1)
	{
		sum=0;
		num=0;
		printf("小朋友，欢迎你来到小学算数\n");
	    printf("1.计算练习\n");
	    printf("2.计算考试\n");
  	    printf("3.成绩查询\n");
	    printf("4.成绩排序\n");
	    printf("5.成绩删除\n");
	    printf("0.退出\n");
	    printf("请选择:\n");
        scanf("%d",&a);
	    switch(a)
		{
	    case 1:while(a==1)
			   {
				   num+=practice();
				   sum++;
				   printf("请选择:\n0.退出练习\n1.继续练习\n");
				   scanf("%d",&a);
				   if(a==0)
				   {
					   pc=(float)num/sum*100.0;
					   printf("出题数为%d 正确数为%d 正确率为%4.2lf%%\n",sum,num,pc);
					   printf("你可以:\n  0.退出系统\n  1.进入主界面\n请选择：");
				       scanf("%d",&b);
					   if(b==0)
						   printf("*已退出系统.\n");
				   }
			   }
			   break;
		case 2:///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(SIZE)
			{
				if((fp=fopen("stu.txt","r"))==NULL)
				{
					printf("无法打开文件\n");
				    exit(0);
				}//当文件里已有信息，以只读方式打开文件
			    for(j=0;j<SIZE;j++)
				    fscanf(fp,"%d%s%d",&s[j].id,s[j].name,&s[j].score);//从文件向结构体数组读入信息
			    fclose(fp);//关文件
			}//如果文件已有信息，从文件向结构体数组读入信息
			printf("请输入学号：");
			scanf("%d",&t1);
			for(j=0;j<SIZE;j++)
				if(t1==s[j].id)
				{
					t2=j;
					break;
				}//如果该学生已存在
			if(j==SIZE)
			{
				SIZE++;
				t2=SIZE-1;
				s[t2].id=t1;
			}//如果该学生不存在
			printf("请输入姓名：");
			scanf("%s",&s[t2].name);
			printf("请输入出题数量：");
			scanf("%d",&sum);
			if(isalpha(sum)==1||iscntrl(sum)==1||isspace(sum)==1||ispunct(sum)==1)
				printf("输入非法");
			else
			{
			    num=exam(sum);
                pc=(double)num/sum*100.0;
			    score=(int)pc;
			    if(score>s[t2].score)
				    s[t2].score=score;
			    printf("总分为%d 正确数为%d 错误数为%d\n",score,num,sum-num);
			    if((fp=fopen("stu.txt","w"))==NULL)
				{
				    printf("无法打开文件\n");
				    return;
				}//开文件
			    for(j=0;j<SIZE;j++)
				    fprintf(fp,"%d\t%s\t%d\n",s[j].id,s[j].name,s[j].score);//从结构体数组向文件输出信息
			    fclose(fp);//关文件
			}
			printf("你可以:\n  0.退出系统\n  1.进入主界面\n请选择：");
		    scanf("%d",&b);
			if(b==0)
				printf("*已退出系统.\n");
			break;//*************需检测
		case 3:
			if((fp=fopen("stu.txt","r"))==NULL)
			{
				printf("无法打开文件\n");
				exit(0);
			}//开文件
			for(j=0;j<SIZE;j++)
				fscanf(fp,"%d%s%d",&s[j].id,s[j].name,&s[j].score);//从文件向结构体数组读入信息
			fclose(fp);//关文件
			c=1;
			while(c)
			{
				printf("请输入所要查询的学生学号：");
			    scanf("%d",&t1);
			    for(j=0,t2=-1;j<SIZE;j++)
				    if(t1==s[j].id)
					{
					    t2=j;
				        c=0;
						break;
					}//如果该学生学号已存在
				if(t2==-1)
				{
					c=1;
					printf("该学号不存在\n");
				}//如果该学生不存在
			}
			printf("请输入姓名：");
			scanf("%s",s[t2].name);
			printf("%d  %s  %d\n",s[t2].id,s[t2].name,s[t2].score);
            printf("你可以:\n  0.退出系统\n  1.进入主界面\n请选择：");
		    scanf("%d",&b);
			if(b==0)
				printf("*已退出系统.\n");
			break;
		case 4://///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if((fp=fopen("stu.txt","r"))==NULL)
			{
				printf("无法打开文件\n");
				exit(0);
			}//开文件
			for(j=0;j<SIZE;j++)
				fscanf(fp,"%d%s%d",&s[j].id,s[j].name,&s[j].score);//从文件向结构体数组读入信息
			fclose(fp);//关文件
			printf("排序前\n");
			for(j=0;j<SIZE;j++)
				printf("%d  %s  %d\n",s[j].id,s[j].name,s[j].score);//输出排序前
			printf("\n");
			paixu(s,SIZE);
			printf("排序后\n");
			for(j=0;j<SIZE;j++)
				printf("%d  %s  %d\n",s[j].id,s[j].name,s[j].score);//输出排序后
			printf("\n");
			if((fp=fopen("stu.txt","w"))==NULL)
				{
					printf("无法打开文件\n");
					return;
				}//开文件
			for(j=0;j<SIZE;j++)
				fprintf(fp,"%d\t%s\t%d\n",s[j].id,s[j].name,s[j].score);//从结构体数组向文件输出信息
			fclose(fp);//关文件
			printf("你可以:\n  0.退出系统\n  1.进入主界面\n请选择：");
		    scanf("%d",&b);
			if(b==0)
				printf("*已退出系统.\n");
			break;
		case 5:	
			if((fp=fopen("stu.txt","r"))==NULL)
			{
				printf("无法打开文件\n");
				exit(0);
			}//开文件
			for(j=0;j<SIZE;j++)
				fscanf(fp,"%d%s%d",&s[j].id,s[j].name,&s[j].score);//从文件向结构体数组读入信息
			fclose(fp);//关文件
			printf("请输入所要删除的学生学号：");
			scanf("%d",&t1);
			for(j=0,t2=-1;j<SIZE;j++)
		    if(t1==s[j].id)
			{
				t2=j;
				break;
			}//如果该学生学号存在
			if(t2!=-1)
			{
				for(j=0;j<t2;j++)
				{
				    t[j].id=s[j].id;
				    strcpy(t[j].name,s[j].name);
                    t[j].score=s[j].score;
				}
			    for(;j<SIZE-1;j++)
				{
				    t[j].id=s[j+1].id;
				    strcpy(t[j].name,s[j+1].name);
                    t[j].score=s[j+1].score;
				}
			    SIZE--;
			    if((fp=fopen("stu.txt","w"))==NULL)
				{
					printf("无法打开文件\n");
					return;
				}//开文件
				for(j=0;j<SIZE;j++)
					fprintf(fp,"%d\t%s\t%d\n",s[j].id,s[j].name,s[j].score);//从结构体数组向文件输出信息
			    fclose(fp);//关文件
			}//若存在则删除
					
			if(t2==-1)
			    printf("该学号不存在，删除失败\n");//如果该学生不存在
			printf("你可以:\n  0.退出系统\n  1.进入主界面\n请选择：");
		    scanf("%d",&b);
			if(b==0)
				printf("*已退出系统.\n");
			break;
		case 0:
			b=0;
			printf("*已退出系统.\n");
			break;
		}
	}
}
