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
	int r1,r2,i,a,c,A,num=0;//r1,r2Ϊ�����ֵ,iΪ����ŵ�������±�,aΪѧ����,AΪ��ȷ��,cΪ��c�γ���,numΪ��ȷ��
	char fh[4]={'+','-','*','/'};//����ŵ�����
	for(c=1;c<=sum;c++)
	{
		srand(time(NULL));//��������rand()���������ʱ���������??
        i=rand()%4;//iΪ��0��3�������
	    r1=rand()%100+1;//r1Ϊ��1��100�������
	    switch(i)
		{
	    case 0:
			r2=rand()%(101-r1);//r2Ϊ��0��100-r1�������
			A=r1+r2;
			break;
		case 1:
		    r2=rand()%(r1+1);//r2Ϊ��0��r1֮��������
			A=r1-r2;
			break;
		case 2:
			r2=rand()%(100/r1)+1;//r2Ϊ��1��100/r1�������
			A=r1*r2;
			break;
		case 3:
			while(1)
			{
				r2=rand()%r1+1;//r2Ϊ��1��r1�������
				if(r1%r2==0)
					break;//ȷ������������
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
	int r1,r2,i,a,A,c,num=0;//r1,r2Ϊ�����ֵ,iΪ����ŵ�������±꣬aΪѧ����,AΪ��ȷ��,cΪ���û���,numΪ��ȷ��
	char fh[4]={'+','-','*','/'};//����ŵ�����
	srand(time(NULL));//��������rand()���������ʱ���������??
    i=rand()%4;//iΪ��0��3�������
	r1=rand()%100+1;//r1Ϊ��1��100�������
	switch(i)
	{
	    case 0:
			r2=rand()%(101-r1);//r2Ϊ��0��100-r1�������
			A=r1+r2;
			break;
		case 1:
		    r2=rand()%(r1+1);//r2Ϊ��0��r1֮��������
			A=r1-r2;
			break;
		case 2:
			r2=rand()%(100/r1)+1;//r2Ϊ��1��100/r1�������
			A=r1*r2;
			break;
		case 3:
			while(1)
			{
				r2=rand()%r1+1;//r2Ϊ��1��r1�������
				if(r1%r2==0)
					break;//ȷ������������
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
			printf("  ��ȷ");
			printf("\n");
			num++;
			break;
		}
		else 
		{
			printf("  ����");
			printf("\n");
		}
	}//ʵ�������θ�������
	if(c==3)
		printf("��ȷ��Ϊ��\n%d%c%d=%d\n",r1,fh[i],r2,A);//�����λ��������Դ���ʱ�����ʽ����
	return num;
}

void main()
{
    int a,b=1,c,j,sum=0,num=0,score,SIZE=0,t1,t2=0;//jΪ�ṹ��������±�,sumΪ��������numΪ��ȷ����scoreΪ���Ե÷�,SIZE��ʾ��SIZE��ѧ��,t1������ʱ���ѧ�ţ�t2Ϊ��ǰѧ����Ϣ�±꣬t������ʱ�������??
	char name[20];//��ʱ�������
	FILE *fp;
	double pc;//pcΪ��ȷ��
	while(b==1)
	{
		sum=0;
		num=0;
		printf("С���ѣ���ӭ������Сѧ����\n");
	    printf("1.������ϰ\n");
	    printf("2.���㿼��\n");
  	    printf("3.�ɼ���ѯ\n");
	    printf("4.�ɼ�����\n");
	    printf("5.�ɼ�ɾ��\n");
	    printf("0.�˳�\n");
	    printf("��ѡ��:\n");
        scanf("%d",&a);
	    switch(a)
		{
	    case 1:while(a==1)
			   {
				   num+=practice();
				   sum++;
				   printf("��ѡ��:\n0.�˳���ϰ\n1.������ϰ\n");
				   scanf("%d",&a);
				   if(a==0)
				   {
					   pc=(float)num/sum*100.0;
					   printf("������Ϊ%d ��ȷ��Ϊ%d ��ȷ��Ϊ%4.2lf%%\n",sum,num,pc);
					   printf("�����:\n  0.�˳�ϵͳ\n  1.����������\n��ѡ��");
				       scanf("%d",&b);
					   if(b==0)
						   printf("*���˳�ϵͳ.\n");
				   }
			   }
			   break;
		case 2:///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(SIZE)
			{
				if((fp=fopen("stu.txt","r"))==NULL)
				{
					printf("�޷����ļ�\n");
				    exit(0);
				}//���ļ���������Ϣ����ֻ����ʽ���ļ�
			    for(j=0;j<SIZE;j++)
				    fscanf(fp,"%d%s%d",&s[j].id,s[j].name,&s[j].score);//���ļ���ṹ�����������Ϣ
			    fclose(fp);//���ļ�
			}//����ļ�������Ϣ�����ļ���ṹ�����������Ϣ
			printf("������ѧ�ţ�");
			scanf("%d",&t1);
			for(j=0;j<SIZE;j++)
				if(t1==s[j].id)
				{
					t2=j;
					break;
				}//�����ѧ���Ѵ���
			if(j==SIZE)
			{
				SIZE++;
				t2=SIZE-1;
				s[t2].id=t1;
			}//�����ѧ��������
			printf("������������");
			scanf("%s",&s[t2].name);
			printf("���������������");
			scanf("%d",&sum);
			if(isalpha(sum)==1||iscntrl(sum)==1||isspace(sum)==1||ispunct(sum)==1)
				printf("����Ƿ�");
			else
			{
			    num=exam(sum);
                pc=(double)num/sum*100.0;
			    score=(int)pc;
			    if(score>s[t2].score)
				    s[t2].score=score;
			    printf("�ܷ�Ϊ%d ��ȷ��Ϊ%d ������Ϊ%d\n",score,num,sum-num);
			    if((fp=fopen("stu.txt","w"))==NULL)
				{
				    printf("�޷����ļ�\n");
				    return;
				}//���ļ�
			    for(j=0;j<SIZE;j++)
				    fprintf(fp,"%d\t%s\t%d\n",s[j].id,s[j].name,s[j].score);//�ӽṹ���������ļ������Ϣ
			    fclose(fp);//���ļ�
			}
			printf("�����:\n  0.�˳�ϵͳ\n  1.����������\n��ѡ��");
		    scanf("%d",&b);
			if(b==0)
				printf("*���˳�ϵͳ.\n");
			break;//*************����
		case 3:
			if((fp=fopen("stu.txt","r"))==NULL)
			{
				printf("�޷����ļ�\n");
				exit(0);
			}//���ļ�
			for(j=0;j<SIZE;j++)
				fscanf(fp,"%d%s%d",&s[j].id,s[j].name,&s[j].score);//���ļ���ṹ�����������Ϣ
			fclose(fp);//���ļ�
			c=1;
			while(c)
			{
				printf("��������Ҫ��ѯ��ѧ��ѧ�ţ�");
			    scanf("%d",&t1);
			    for(j=0,t2=-1;j<SIZE;j++)
				    if(t1==s[j].id)
					{
					    t2=j;
				        c=0;
						break;
					}//�����ѧ��ѧ���Ѵ���
				if(t2==-1)
				{
					c=1;
					printf("��ѧ�Ų�����\n");
				}//�����ѧ��������
			}
			printf("������������");
			scanf("%s",s[t2].name);
			printf("%d  %s  %d\n",s[t2].id,s[t2].name,s[t2].score);
            printf("�����:\n  0.�˳�ϵͳ\n  1.����������\n��ѡ��");
		    scanf("%d",&b);
			if(b==0)
				printf("*���˳�ϵͳ.\n");
			break;
		case 4://///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if((fp=fopen("stu.txt","r"))==NULL)
			{
				printf("�޷����ļ�\n");
				exit(0);
			}//���ļ�
			for(j=0;j<SIZE;j++)
				fscanf(fp,"%d%s%d",&s[j].id,s[j].name,&s[j].score);//���ļ���ṹ�����������Ϣ
			fclose(fp);//���ļ�
			printf("����ǰ\n");
			for(j=0;j<SIZE;j++)
				printf("%d  %s  %d\n",s[j].id,s[j].name,s[j].score);//�������ǰ
			printf("\n");
			paixu(s,SIZE);
			printf("�����\n");
			for(j=0;j<SIZE;j++)
				printf("%d  %s  %d\n",s[j].id,s[j].name,s[j].score);//��������
			printf("\n");
			if((fp=fopen("stu.txt","w"))==NULL)
				{
					printf("�޷����ļ�\n");
					return;
				}//���ļ�
			for(j=0;j<SIZE;j++)
				fprintf(fp,"%d\t%s\t%d\n",s[j].id,s[j].name,s[j].score);//�ӽṹ���������ļ������Ϣ
			fclose(fp);//���ļ�
			printf("�����:\n  0.�˳�ϵͳ\n  1.����������\n��ѡ��");
		    scanf("%d",&b);
			if(b==0)
				printf("*���˳�ϵͳ.\n");
			break;
		case 5:	
			if((fp=fopen("stu.txt","r"))==NULL)
			{
				printf("�޷����ļ�\n");
				exit(0);
			}//���ļ�
			for(j=0;j<SIZE;j++)
				fscanf(fp,"%d%s%d",&s[j].id,s[j].name,&s[j].score);//���ļ���ṹ�����������Ϣ
			fclose(fp);//���ļ�
			printf("��������Ҫɾ����ѧ��ѧ�ţ�");
			scanf("%d",&t1);
			for(j=0,t2=-1;j<SIZE;j++)
		    if(t1==s[j].id)
			{
				t2=j;
				break;
			}//�����ѧ��ѧ�Ŵ���
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
					printf("�޷����ļ�\n");
					return;
				}//���ļ�
				for(j=0;j<SIZE;j++)
					fprintf(fp,"%d\t%s\t%d\n",s[j].id,s[j].name,s[j].score);//�ӽṹ���������ļ������Ϣ
			    fclose(fp);//���ļ�
			}//��������ɾ��
					
			if(t2==-1)
			    printf("��ѧ�Ų����ڣ�ɾ��ʧ��\n");//�����ѧ��������
			printf("�����:\n  0.�˳�ϵͳ\n  1.����������\n��ѡ��");
		    scanf("%d",&b);
			if(b==0)
				printf("*���˳�ϵͳ.\n");
			break;
		case 0:
			b=0;
			printf("*���˳�ϵͳ.\n");
			break;
		}
	}
}
