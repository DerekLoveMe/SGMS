#include<stdio.h> 
#include<string.h>
#include<windows.h>
typedef struct 
{
	char num[15];
	char name[15];
	char sex[10];
	int math; 
	int computer;
	int english;
	int phy;
	float aver;
}Student;
Student stu[99];



int input(Student stud[],int n)//输入若干条记录
{
	int i=0;
	char sign,x[10];
	float a=0.0;    
	while(sign!='n'&&sign!='N') 
	{
		printf("输入学生学号:"); 
		scanf("%s",stu[n+i].num); 
		printf("输入学生姓名:"); 
		scanf("%s",stu[n+i].name);
		printf("输入学生性别（男输入1，女输入2）:"); 
		scanf("%s",stu[n+i].sex);
		printf("输入学生的计算机、数学、英语、大物分数:");
		scanf("%d%d%d%d",&stu[n+i].computer,&stu[n+i].math,&stu[n+i].english,&stu[n+i].phy);
		a=1.0*(stu[n+i].computer+stu[n+i].math+stu[n+i].english+stu[n+i].phy)/4; 
		stu[n+i].aver=a;
		gets(x);   //清除多余的输入 
		printf("是否继续输入?(Y/N):\n");
		scanf("%c",&sign);
		i++; 
	} 
	return(n+i);
}



void display(Student stud[],int n) //显示所有记录
{ 
	int i ;
	printf("-------------------------------------------------------------------------------\n"); 
	printf(" 学号  |  姓名  |   性别  |  计算机  |  数学   |  英语   |  大物  |  平均成绩 \n"); 
	printf("-------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++) 
	{ 
		printf("%-10s%-10s%-10s%-10d%-10d%-10d%-10d%-10.2lf\n\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].computer,stu[i].math,stu[i].english,stu[i].phy,stu[i].aver);                                                
	}
}



int revise(Student stud[],int n)//修改
{
	int i=0,choice=1;
	char x[10]; 
	while(choice!=0)
	{   
		printf("请输入您要修改的学生的学号:\n");
		scanf("%s",x);
		while(strcmp(stu[i].num,x)!=0&&i<n) i++; 
		if(i==n) 
		{
			printf("\n未找到结果\n"); 
			return(n);
		}                                                                    
		printf("|-------可修改的内容-------+ \n"); 
		printf("| 姓名              请按 1 |\n");
		printf("| 性别              请按 2 |\n");
		printf("| 计算机            请按 3 |\n");
		printf("| 数学              请按 4 |\n");
		printf("| 英语              请按 5 |\n");
		printf("| 大物              请按 6 |\n");
		printf("| 退出              请按 0 |\n");
		printf("+--------------------------+\n");
		printf("请输入您的选择：");
		scanf("%d", &choice);
		switch(choice)
		{                                                          
			case 0:break; 
			case 1:
			printf("请输入新姓名：");
			scanf("%s", stu[i].name);
			break; 
			case 2:
			printf("请输入新性别：");
			scanf("%s", stu[i].sex);
			break; 
			case 3:                                               
			printf("请输入新的计算机分数：");    
			scanf("%d", &stu[i].computer);
			break;
			case 4:
			printf("请输入新的数学分数：");
			scanf("%d",&stu[i].math);
			break;
			case 5:
			printf("请输入新的英语分数：");                                          
			scanf("%d", &stu[i].english);
			break;
			case 6:
			printf("请输入新的大物分数：");                                          
			scanf("%d", &stu[i].phy);
			break;
			default:
			printf("\n无效选项!");
			break;
		} 
		break;	
	}
	return n;
}



int del(Student stud[],int n) //按姓名查找，删除一条记录  
{
	char s[20]; 
	int i;
	int j; 
	i=0;
	printf("输入要删除记录的姓名:"); 
	scanf("%s",s); 
	while(strcmp(stu[i].name,s)!=0&&i<n) i++; 
	if(i==n) 
	{
		printf("\n未找到结果\n"); 
		return(n);
	}                                                                    
	for(j=i;j<n-1;j++) //删除操作 
	{ 
		strcpy(stu[j].num,stu[j+1].num); 
		strcpy(stu[j].name,stu[j+1].name); 
		stu[j].computer=stu[j+1].computer; 
		stu[j].math=stu[j+1].math; 
		stu[j].english=stu[j+1].english; 
		stu[j].phy=stu[j+1].phy;
		stu[j].aver=stu[j+1].aver; 
	} 
	printf("\n删除成功!\n"); 
	return(n-1); 
}



int empty(Student stud[],int n)
{
	FILE *fp;                     //定义文件指针
	char filename[9] = "save.txt";                    //定义文件名  文件名为save
	if((fp=fopen(filename,"w"))==NULL)             //打开文件
	{
		printf("打开失败\n");
		
	}
	fprintf(fp,"0");
	fclose(fp); //关闭文件
	n=0;
	return n;
}



void inquiry_name(Student stud[],int n) //按姓名查找并显示一个记录 
{
	char s[20];                    
	int i=0; 
	printf("输入姓名:"); 
	scanf("%s",s); 
	while(strcmp(stu[i].name,s)!=0&&i<n) i++; //查找判断 
	if(i==n) 
	{
		printf("\n未找到结果\n"); 
		
	}
	printf("该学生学号、性别是:%s,%s\n",stu[i].num,stu[i].sex); //输出该学生信息 
	printf("计算机、高数、英语、大物、平均成绩是:%d,%d,%d,%d,%f\n",stu[i].computer,stu[i].math,stu[i].english,stu[i].phy,stu[i].aver);               
}  



void inquiry_num(Student stud[],int n) //按学号查找并显示一个记录 
{
	char s[20];                    
	int i=0; 
	printf("输入学号:"); 
	scanf("%s",s); 
	while(strcmp(stu[i].num,s)!=0&&i<n) i++; //查找判断 
	if(i==n) 
	{
		printf("\n未找到结果\n"); 
		
	}
	printf("该学生姓名、学号、性别是:%s,%s,%s\n",stu[i].name,stu[i].num,stu[i].sex); //输出该学生信息 
	printf("计算机、高数、英语、大物、平均成绩是:%d,%d,%d,%d,%f\n",stu[i].computer,stu[i].math,stu[i].english,stu[i].phy,stu[i].aver);               
}  



void sort_num(Student stud[],int n) //按学号排序 
{
	int i,j,p,q,r,w;
	float y;
	char x[20],t[10];
	for(i=0;i<n-1;i++) //冒泡法排序 
		for(j=0;j<n-1-i;j++) 
			if(strcmp(stud[j].num,stud[j+1].num)>0) 
			{
				strcpy(t,stud[j].num); 
				strcpy(stud[j].num,stud[j+1].num); 
				strcpy(stud[j+1].num,t); 
				strcpy(t,stud[j].sex); 
				strcpy(stud[j].sex,stud[j+1].sex); 
				strcpy(stud[j+1].sex,t); 
				strcpy(x,stud[j].name); 
				strcpy(stud[j].name,stud[j+1].name); 
				strcpy(stud[j+1].name,x); 
				y=stu[j].aver;stu[j].aver=stu[j+1].aver;stu[j+1].aver=y;
				p=stu[j].computer;stu[j].computer=stu[j+1].computer;stu[j+1].computer=p;
				q=stu[j].math;stu[j].math=stu[j+1].math;stu[j+1].math=q;
				r=stu[j].english;stu[j].english=stu[j+1].english;stu[j+1].english=r;
				w=stu[j].phy;stu[j].phy=stu[j+1].phy;stu[j+1].phy=w;
			} 
}



void sort_aver(Student stud[],int n) //按平均成绩排序 
{
	int i,j,p,q,r,w;
	float y;
	char x[20],t[10];
	for(i=0;i<n-1;i++) //冒泡法排序 
		for(j=0;j<n-1-i;j++) 
			if(stu[j].aver<stu[j+1].aver)
			{
				y=stu[j].aver;stu[j].aver=stu[j+1].aver;stu[j+1].aver=y;
				p=stu[j].computer;stu[j].computer=stu[j+1].computer;stu[j+1].computer=p;
				q=stu[j].math;stu[j].math=stu[j+1].math;stu[j+1].math=q;
				r=stu[j].english;stu[j].english=stu[j+1].english;stu[j+1].english=r;
				w=stu[j].phy;stu[j].phy=stu[j+1].phy;stu[j+1].phy=w;
				strcpy(x,stu[j].name);
				strcpy(stu[j].name,stu[j+1].name);
				strcpy(stu[j+1].name,x);
				strcpy(t,stu[j].num);
				strcpy(stu[j].num,stu[j+1].num);
				strcpy(stu[j+1].num,t);	   
				strcpy(t,stu[j].sex); 
				strcpy(stu[j].sex,stu[j+1].sex); 
				strcpy(stu[j+1].sex,t); 
			}
	
}



void sort_computer(Student stud[],int n) //按计算机成绩排序 
{
	int i,j,p,q,r,w;
	float y;
	char x[20],t[10];
	for(i=0;i<n-1;i++) //冒泡法排序 
		for(j=0;j<n-1-i;j++)  
			if(stu[j].computer<stu[j+1].computer)
			{   
				y=stu[j].aver;stu[j].aver=stu[j+1].aver;stu[j+1].aver=y;
				p=stu[j].computer;stu[j].computer=stu[j+1].computer;stu[j+1].computer=p;
				q=stu[j].math;stu[j].math=stu[j+1].math;stu[j+1].math=q;
				r=stu[j].english;stu[j].english=stu[j+1].english;stu[j+1].english=r;
				w=stu[j].phy;stu[j].phy=stu[j+1].phy;stu[j+1].phy=w;
				strcpy(x,stu[j].name);
				strcpy(stu[j].name,stu[j+1].name);
				strcpy(stu[j+1].name,x);
				strcpy(t,stu[j].num);
				strcpy(stu[j].num,stu[j+1].num);
				strcpy(stu[j+1].num,t);	
				strcpy(t,stu[j].sex); 
				strcpy(stu[j].sex,stu[j+1].sex); 
				strcpy(stu[j+1].sex,t); 
			}
		
}



void sort_english(Student stud[],int n) //按英语成绩排序 
{
	int i,j,p,q,r,w;
	float y;
	char x[20],t[10];
	for(i=0;i<n-1;i++) //冒泡法排序 
		for(j=0;j<n-1-i;j++)  
			if(stu[j].english<stu[j+1].english)
			{   
				y=stu[j].aver;stu[j].aver=stu[j+1].aver;stu[j+1].aver=y;
				p=stu[j].computer;stu[j].computer=stu[j+1].computer;stu[j+1].computer=p;
				q=stu[j].math;stu[j].math=stu[j+1].math;stu[j+1].math=q;
				r=stu[j].english;stu[j].english=stu[j+1].english;stu[j+1].english=r;
				w=stu[j].phy;stu[j].phy=stu[j+1].phy;stu[j+1].phy=w;
				strcpy(x,stu[j].name);
				strcpy(stu[j].name,stu[j+1].name);
				strcpy(stu[j+1].name,x);
				strcpy(t,stu[j].num);
				strcpy(stu[j].num,stu[j+1].num);
				strcpy(stu[j+1].num,t);	   
				strcpy(t,stu[j].sex); 
				strcpy(stu[j].sex,stu[j+1].sex); 
				strcpy(stu[j+1].sex,t); 
			}
		
}



void sort_math(Student stud[],int n) //按数学成绩排序 
{
	int i,j,p,q,r,w;
	float y;
	char x[20],t[10];
	for(i=0;i<n-1;i++) //冒泡法排序 
		for(j=0;j<n-1-i;j++)   
			if(stu[j].math<stu[j+1].math)
			{   
				y=stu[j].aver;stu[j].aver=stu[j+1].aver;stu[j+1].aver=y;
				p=stu[j].computer;stu[j].computer=stu[j+1].computer;stu[j+1].computer=p;
				q=stu[j].math;stu[j].math=stu[j+1].math;stu[j+1].math=q;
				r=stu[j].english;stu[j].english=stu[j+1].english;stu[j+1].english=r;
				w=stu[j].phy;stu[j].phy=stu[j+1].phy;stu[j+1].phy=w;
				strcpy(x,stu[j].name);
				strcpy(stu[j].name,stu[j+1].name);
				strcpy(stu[j+1].name,x);
				strcpy(t,stu[j].num);
				strcpy(stu[j].num,stu[j+1].num);
				strcpy(stu[j+1].num,t);	   
				strcpy(t,stu[j].sex); 
				strcpy(stu[j].sex,stu[j+1].sex); 
				strcpy(stu[j+1].sex,t); 
			}
			
}



void sort_phy(Student stud[],int n) //按大物成绩排序 
{ 
	int i,j,p,q,r,w;
	float y;
	char x[20],t[10];
	for(i=0;i<n-1;i++) //冒泡法排序 
		for(j=0;j<n-1-i;j++) 
			if(stu[j].phy<stu[j+1].phy)
			{   
				y=stu[j].aver;stu[j].aver=stu[j+1].aver;stu[j+1].aver=y;
				p=stu[j].computer;stu[j].computer=stu[j+1].computer;stu[j+1].computer=p;
				q=stu[j].math;stu[j].math=stu[j+1].math;stu[j+1].math=q;
				r=stu[j].english;stu[j].english=stu[j+1].english;stu[j+1].english=r;
				w=stu[j].phy;stu[j].phy=stu[j+1].phy;stu[j+1].phy=w;
				strcpy(x,stu[j].name);
				strcpy(stu[j].name,stu[j+1].name);
				strcpy(stu[j+1].name,x);
				strcpy(t,stu[j].num);
				strcpy(stu[j].num,stu[j+1].num);
				strcpy(stu[j+1].num,t);	   
				strcpy(t,stu[j].sex); 
				strcpy(stu[j].sex,stu[j+1].sex); 
				strcpy(stu[j+1].sex,t); 
			}
		
}



void sta(Student stud[],int n)//按分数段统计人数
{
	int i,j,a,max,min,k,l,q,p,w;
	k=0,l=0,p=0,q=0,w=0;
	printf("你想统计哪科成绩: 1.计算机 2.数学 3.英语 4.大物 5.平均 \n");
	scanf("%d",&j);
	printf("输入分数段上限和下限:\n");
	scanf("%d%d",&max,&min);
	if(max<min)
	{
		a=max;max=min;min=a;  
	}
	if(j==1)
	{
		for(i=0;i<99;i++)
		{
			if(stu[i].computer>min&&stu[i].computer<max)  k++;
		}
		printf("分数段的人数为 :%d",k);
	}
	else if(j==2)
	{
		for(i=0;i<99;i++)
		{
			if(stu[i].math>min&&stu[i].math<max)  l++;
		}
		printf("分数段的人数为 :%d",l);
		}
	else if(j==3)
		{
		for(i=0;i<99;i++)
		{
			if(stu[i].english>min&&stu[i].english<max)  p++;
		}
		printf("分数段的人数为 :%d",p);
		}
	else if(j==4)
		{
		for(i=0;i<99;i++)
		{
			if(stu[i].phy>min&&stu[i].phy<max)  
			w++;
		}
		printf("分数段的人数为 :%d",w);
		}
	else if(j==5)
	{
		for(i=0;i<99;i++)
		{
			if(stu[i].aver>min&&stu[i].aver<max)  q++;
		}
		printf("分数段的人数为 :%d",q);
	}
	printf("\n\n");
	
}



int read(Student stud[],int n) //从文件中读入数据 
{
	int i=0,num; 
	FILE *fp; //定义文件指针 
	char filename[9] = "save.txt"; //定义文件名  文件名为save
	if((fp=fopen(filename,"rt+"))==NULL) //打开文件 
	{
		printf("\n请先输入信息\n"); //打开失败信息 
		return(n); 
	} 
	fscanf(fp,"%d",&num); //读入总记录量 
	n=num;
	while(i<num) //循环读入数据
	{ 
		fscanf(fp,"%s %s %s %d %d %d %d %f\n",stu[i].num,stu[i].name,stu[i].sex,&stu[i].computer,&stu[i].math,&stu[i].english,&stu[i].phy,&stu[i].aver);
		i++;
	}
	fclose(fp); //关闭文件
	return(n); 
}



void save(Student stud[],int n)               //将所有记录写入文件
{
	int i=0;
	FILE *fp;                     //定义文件指针
	char filename[9] = "save.txt";                    //定义文件名  文件名为save
	if((fp=fopen(filename,"w"))==NULL)             //打开文件
	{
		printf("打开失败\n");
		
	}
	fprintf(fp,"%d\n",n);             //循环写入数据
	while(i<n)
	{
		fprintf(fp,"%s %s %s %d %d %d %d %f\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].computer,stu[i].math,stu[i].english,stu[i].phy,stu[i].aver);
		i++;
	}
	fclose(fp);           //关闭文件
}



int menu()          //菜单函数 
{ 
	int c;                                                     
	do
	{ 
		printf("\n+--------------------------------------------------------------+\n");
		printf("|                   学 生 成 绩 管 理 系 统                    |\n");
		printf("|               Studens Grades Management System               |\n");
		printf("+--------------------------------------------------------------+\n");
		printf("|\t\t                                               |\n"); 
		printf("|\t[1.] 编辑信息        \t     [2.] 显示全部信息         |\n");
		printf("|\t\t                                               |\n");
		printf("|\t[3.] 按学号/姓名查询 \t     [4.] 进行排序             |\n"); 
		printf("|\t\t                                               |\n"); 
		printf("|\t[5.] 统计分数段      \t     [0.] 退出                 |\n"); 
		printf("|\t\t                                               |\n"); 
		printf("+----------------------------------------------------作者：刘墩+\n"); 
		printf("\n请选择(0-5):"); 
		scanf("%d",&c);
	}
	while(c<0||c>6); 
	return(c); //返回选择 
}



int edit()
{
	printf("1. 录入\n"); 
	printf("2. 修改\n"); 
	printf("3. 删除 \n"); 
	printf("4. 清空 \n"); 
	printf("按其它数字键退出 \n");
	int i;
	scanf("%d",&i);
	return i;
}



int inquiry()
{
	printf("1. 按姓名查询\n"); 
	printf("2. 按学号查询\n");  
	printf("按其它数字键退出\n");
	int i;
	scanf("%d",&i);
	return i;
}



int sort()
{
	printf("1. 按学号\n"); 
	printf("2. 按计算机成绩\n");
	printf("3. 按数学成绩\n");
	printf("4. 按英语成绩\n");
	printf("5. 按大物成绩\n");
	printf("6. 按平均成绩\n");
	printf("按其它数字键退出\n");
	int i;
	scanf("%d",&i);
	return i;
}



void main()    //主函数 
{ 
	system("color 3F");
	int n=0; 
	for(;;)
	{
		for(;;) 
		{ 
			switch(menu()) 
			{ 
				case 1:  switch(edit())
				{
					case 1:n=input(stu,n);display(stu,n);save(stu ,n); break;			  
					case 2:revise(stu ,n);display(stu,n);save(stu ,n); break;
					case 3:n=del(stu ,n);display(stu,n);save(stu ,n); break;
					case 4:n=empty(stu ,n);save(stu ,n);printf("清空成功"); break;
				}
				break; 
				case 2:n=read(stu,n);display(stu,n);break; 
				case 3: 
				switch(inquiry())
				{
					case 1:n=read(stu,n);inquiry_name(stu,n);break;
					case 2:n=read(stu,n);inquiry_num(stu ,n);break;			   
				} 
				break; 
				case 4:  switch(sort())
				{
					case 1:sort_num(stu,n);display(stu,n);save(stu ,n); break ;          
					case 2:sort_computer(stu ,n);display(stu,n);save(stu ,n);break;
					case 3:sort_math(stu ,n);display(stu,n); save(stu ,n);break;
					case 4:sort_english(stu ,n);display(stu,n);save(stu ,n); break;
					case 5:sort_phy(stu ,n);display(stu,n);save(stu ,n); break;
					case 6:sort_aver(stu ,n);display(stu,n);save(stu ,n); break;
				}
				break; 
				case 5:n=read(stu,n);sta(stu,n);break; 
				case 0: 
					system("pause"); 
					exit(0);   //结束程序 
			} 
		}
	}
}
