#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct mealcard{
     char num[15];
     int info;
     char name[20];
     double money;
}students[100];//����һ��������Ϣ�Ľṹ
int i=0;//��¼ѧ������
int count;//��¼��������
int info;//�ж��Ƿ��ʧ��1�����ʧ,����û�й�ʧ
char num[15];//��������
char name[20];//ѧ������
double money;//���
FILE *fp;

void creat();//����������Ϣ�ļ�
void buy();//����ǰ�󷹿����
void con();//��Ǯ����ʾǰ����
void add();//����·���
void move();//ע��û���õķ���
void set();//���ù�ʧ��Ϣ������ע����ʧ�ͼӹ�ʧ����
void look();//�鿴������Ϣ
void puanduan();//�жϷ����Ÿ�ʽ �Ƿ���ȷ
void read_file();//�ж��ļ��Ƿ���ڣ������ļ���Ϣ 
int main(void)
{
     int choice;
     read_file();
     
     do 
     {   
          printf("  |------------���˵�------------|\n");
          printf("  |                              |\n");
          printf("  |----������Ҫѡ��Ĳ������----|\n");
          printf("  |----1---�½��������ļ�--------|\n");
          printf("  |----2-------��--------------|\n");
          printf("  |----3-------��Ǯ--------------|\n");
          printf("  |----4------����·�-----------|\n");
          printf("  |----5------ע���ɷ���---------|\n");
          printf("  |----6---��ӹ�ʧ������ʧ----|\n");
          printf("  |----7---�鿴������Ϣ----------|\n");
          printf("  |----0------�˳�ϵͳ-----------| \n");
          printf("  |------------------------------|\n");
          scanf("%d",&choice);
     switch(choice)
     {
          case 0:printf("--�ǳ���л��ʹ�ñ����,����Ѿ������˳�,��������ɽ���\n");
                 printf("--��������������ʲô�õ��������ӭ�����лл\n");
                 break;
          case 1:creat(); break;
          case 2:buy(); break; 
          case 3:con();break;
          case 4:add();break;
          case 5:move();break;
          case 6:set(); break;
          case 7:look();break;
          default: exit(0);
     }
     }while(choice!=0); 

     return 0;
}
void read_file()//�ж��ļ��Ƿ���ڣ������ļ���Ϣ 
{
	 if((fp=fopen("card.dat.txt","r+"))!=NULL)//�ж��Ƿ������ļ�
     {
          printf("�ļ��Ѿ�����\n\n");
          fseek(fp,0,2);//ָ���ļ�����λ��
        if(ftell(fp)>0)//ָ��ָ��ղŶ�λ��λ�ã��ж��ļ��Ƿ����
        {
          rewind(fp);//��λ���ײ� 
          printf("�����ļ��Ѿ���������ѧ��������\n\n���Ҫ�����������ļ�����Ϣ�밴1��Ҫ�鿴��������Ϣ�밴7��лл\n");
          while(!feof(fp))
          {
          	fscanf(fp,"%s%s%lf%d\n",students[i].num,students[i].name,&students[i].money,&students[i].info);  
            printf("%s\n",students[i].num);//����Ѿ��е�ѧ������
            i++;//��¼����
          }         
          if(fclose(fp))
          {
               printf("�ļ��ر�ʧ��\n");
               exit(0);
          }
        } 
         
      }
    else;
}
void puanduan()
{
	int j,c;
	 do//�ж����뷹����ʽ�Բ��� 
      {
      	int n=strlen(num);
      	for(j=0;j<n;j++)
      	{
      		if(num[j]>='0'&&num[j]<='9')
      		{
      			c=1;
			}
			else
			{
				c=0;
				printf("������ķ����Ÿ�ʽ���ԣ����������룬лл\n");
				scanf("%s",num);
				break;
			}
		}
	
	  }while(c==0);
}
void creat()
{
		int k,a=0,b=0,c,j;        
    if((fp=fopen("card.dat.txt","w"))==NULL)//���ļ� 
	{
		printf("�ļ��򿪴���\n");
		exit(0);
	}
     printf("�����뿨�ţ�0��ʾֹͣ����������Ϣ���������˵�\n");
     printf("�������뿨�Ų��ó���15λ��\n");
     
     do{
       scanf("%s",num);
      
	   puanduan();//�����жϺ����жϷ������Ƿ�Ϸ� 
      for(k=0;k<i;k++)
	  {
		if(strcmp(students[k].num,num)==0)
		{
		   	b=1;
		   	printf("�˿����Ѿ���ע����,���������뷹���ţ�лл\n");
		   	break;
		}
		else b=0; 
	  }
   }while(b==1);
		   
	 while(1)
	 {
		
		 strcpy(students[i].num,num);
		 
		 printf("���������������лл\n");
		 scanf("%s",name);
		 strcpy(students[i].name,name);
		 printf("��������ķ���Ǯ��лл\n");
		 scanf("%lf",&money);
		 while(money<0)
		 {
		 	printf("����Ľ�����Ϊ����\n");
		 	printf("������������ķ���Ǯ��лл\n");
		 	scanf("%lf",&money);
		 }
		 students[i].money=money;
		 printf("��������Ĺ�ʧ��Ϣ��0����û�й�ʧ��1�����ʧ\n");
		 scanf("%d",&info);
		  while(info!=0&&info!=1)
		  {
		  	printf("��ʧ��Ϣֻ����1��0��ʾ���벻Ҫ�����������֣�лл\n");
		  	printf("������������Ĺ�ʧ��Ϣ��0����û�й�ʧ��1�����ʧ\n");
		  	scanf("%d",&info);
		  }
		  students[i].info=info; 
		  fprintf(fp,"%s %s %.0f %d\n",students[i].num,students[i].name,students[i].money,students[i].info);//�ĵ� 
		  i++;// 
	
		   do
		   {
		   	printf("�����������Ŀ��ţ�0����ֹͣ���뿨��\n");
		   	scanf("%s",num);
		   	puanduan();
		   if(strcmp(num,"0")==0)
		   {
		 	return ;
		   } 
		   	for(k=0;k<i;k++)
		   	{
		   	 if(strcmp(students[k].num,num)==0)
		   	 {
		   	 	a=1;
		   	 	printf("�˿����Ѿ���ע����\n");
		   	 	break;
			 }
		   
		   else 
		   a=0; 
   	      }
	  } while(a==1);
	  
   }

	 if(fclose(fp))
	 {
		printf("�ļ��ر�ʧ��\n");
		exit(0);
 	 }
 	 printf("�ļ���Ϣ�����ɹ�,�������˵�\n\n"); 
    
    
}

void buy()//�� 
{
	int j,flag=-1,sum=0,k;
	 if(i==0)
	 {
	 	printf("���Ƚ��������ļ���лл\n");
	 	return ;
	 }
	if((fp=fopen("card.dat.txt","r+"))==NULL)//���ļ� 
	{
		printf("�ļ��򿪴���\n");
		exit(0);
	}
	do
	 {
	 	printf("��������Ŀ��ţ����Ҳ��ܳ���15λ����0����ֹͣ���򷹡����������˵�\n");
	 	scanf("%s",num);
	 	puanduan();
		if(strcmp(num,"0")==0)
		{
		 	return ;
		} 
	 	
	for(j=0;j<i;j++)//���ҷ��� 
	{
		if(strcmp(students[j].num,num)==0)
		{
			flag=j;
			break;
		}
	}
		if(flag==-1)
		{
		printf("�Ҳ����ÿ��ţ����������룬лл\n");
		sum++;	
		}
		if(sum==5)//�޶�������� 
		{
			printf("������Ŀ����Ѿ��ﵽ5���ˣ�ϵͳ���������˵�\n");
			return ;
		}		 
   }while(flag==-1);
        if(students[flag].info==1)//�ж��Ƿ񶳽� 
        {
   	     printf("������Ŀ����Ѿ����ᣨ��ʧ��\n");
   	     return ;
         }
         else if(students[flag].money<5)
         {
         	printf("����,���Ǯ����ʹ�ã�лл\n");
         	return ;
		 }
		 else
		 {
		 	printf("��������Ҫ�򷹵ķ�Ǯ\n");
		 	scanf("%lf",&money);
		 }
		 while(money<0)
		 {
		 	printf("�����������ķ�Ǯ����Ϊ����\n");
		 	printf("���������������Ǯ\n");
		 	scanf("%lf",&money);
		 }
		 if(students[flag].money>=money)//����򷹵�ǰ���� 
		 {
		 	printf("��ǰ:\n");
		 	printf("�����ţ�%s  ��%.2f\n",students[flag].num,students[flag].money);
		 	students[flag].money=students[flag].money-money;
		 	printf("�򷹺�:\n");	
		 	printf("�����ţ�%s ��%.2f\n\n",students[flag].num,students[flag].money);
	        printf("���˴����ѳɹ���,�Զ��������˵�\n\n");
	     }
		else
		  {
		  	printf("���㣬���Ǯ\n");
		  	return;
		  }
		for(j=0;j<i;j++)//д���ļ� 
	    {
		fprintf(fp,"%d %s %.0f %d\n",students[j].num,students[j].name,students[j].money,students[j].info);	
	    }
		if(fclose(fp))
   	    {
		printf("�ļ��ر�ʧ��\n");
		exit(0);
	    }
}

void con()//��ֵ 
{
	 int j,flag=-1,sum=0; 
	 if(i==0)
	 {
	 	printf("���Ƚ��������ļ���лл\n");
	 	return ;
	 }
	 else
	 {
	if((fp=fopen("card.dat.txt","w+"))==NULL)
	{
		printf("�ļ��򿪴���\n");
		exit(0);
	}
		  
	do
	 {
	 	printf("��������Ŀ��ţ����Ҳ��ܳ���15λ��,����0����ֹͣ����ֵ�����������˵�\n");
	 	scanf("%s",num);
	 	puanduan();
	 	if(strcmp(num,"0")==0)//// 
		{
		 	return ;
		} 
	 
 	    for(j=0;j<i;j++)//���ҷ��� 
	    {
		if(strcmp(students[j].num,num)==0)
		{
			flag=j;
			break;
		}
	    }
		if(flag==-1)
		{
		printf("�Ҳ����ÿ��ţ����������룬лл\n");
		sum++;	
		}
		if(sum==5)
		{
			printf("������Ŀ����Ѿ��ﵽ5���ˣ�ϵͳ���������˵�\n");
			return ;
		}	 
   }while(flag==-1);
        if(students[flag].info==1)
        {
   	     printf("������Ŀ����Ѿ����ᣨ��ʧ��\n");
   	     return ;
         }
         else
		 {
		 	printf("��������Ҫ����ֵ���Ľ��\n");
		 	scanf("%lf",&money); 
		    while(money<0)
		    {
		 	printf("�����������Ľ�����Ϊ����\n");
		 	printf("������������ĳ�ֵ���\n");
		 	scanf("%lf",&money);
		    }
		    printf("��ֵǰ��\n");
		 	printf("�����ţ� %s ��%.2f\n",students[flag].num,students[flag].money);
		 	
		 	students[flag].money=students[flag].money+money;
		 	
		 	printf("��ֵ��\n");	
		 	printf("�����ţ�%s ��%.2f\n\n",students[flag].num,students[flag].money);
            for(j=0;j<i;j++)
  	        {
		     fprintf(fp,"%s %s %.0f %d\n",students[j].num,students[j].name,students[j].money,students[j].info);	
	        }

	        if(fclose(fp))
	        {
	         printf("�ļ��ر�ʧ��\n");
	          exit(0);
	        } 
		  
	         printf("���˴γ�ֵ�ɹ���,���������˵�\n\n");

		   }
	} 
}
void add()
{
	int j,flag=-1,sum=0; 
	
	if(i==0)
	{
		printf("���Ƚ��������ļ�\n");
		return ;
		
	}
	else if(i>100)
	{
		printf("���ݿ��Ѿ�����\n");
		return ;
		 
	}
	if((fp=fopen("card.dat.txt","w+"))==NULL)
	{
		printf("�ļ��򿪴���\n");
		exit(0);
	}
		  
	printf("��������Ҫ����ӡ��Ŀ��ţ����Ҳ��ܳ���15λ����0����ֹͣ��ӣ��������˵�\n");
	do
	{  
		scanf("%s",num);
		puanduan();
        if(strcmp(num,"0")==0)
		{
		   	return ;
		} 
	 	
 	    for(j=0;j<i;j++)//���ҷ��� 
		if(strcmp(students[j].num,num)==0)
		{
			flag=1;
			sum++;
			printf("�˺��Ѿ���ע��,���������룬лл\n");
			break;
		}
		else
		flag=0;
	    
		if(sum==5)
		{
			printf("������Ŀ����Ѿ��ﵽ5���ˣ�ϵͳ���������˵�\n");
			return ;
		}	 
   }while(flag==1);
   strcpy(students[i].num,num); 
   printf("��������������\n");
   scanf("%s",name);
   strcpy(students[i].name,name);
   printf("���������ĳ�ʼ����Ǯ\n");
   scanf("%lf",&money);
    while(money<0)
		    {
		 	printf("�����������Ľ�����Ϊ����\n");
		 	printf("������������Ľ��\n");
		 	scanf("%lf",&money);
		    }
		    students[i].money=money;
		    printf("���������Ĺ�ʧ��Ϣ,0����û�й�ʧ��1�����Ѿ���ʧ\n");
		    scanf("%d",&info);
		    students[i].info=info;
		    i++;//������������ 
		for(j=0;j<i;j++)
		{
		   fprintf(fp,"%s %s %.0f %d\n",students[j].num,students[j].name,students[j].money,students[j].info);	
		}
		
		if(fclose(fp))
	    {
		printf("�ļ��ر�ʧ��\n");
		exit(0);
	    } 
		printf("�����ɹ�,���������˵�\n\n");
}
void move()//ע������ 
{
	int j,flag=-1,sum=0,k; 
	if(i==0)
	 {
	 	printf("���Ƚ��������ļ���лл\n");
	 	return ;
	 }
	if((fp=fopen("card.dat.txt","w+"))==NULL)
		 	{
		 		printf("�ļ���ʧ��\n");
				 exit(0); 
			 }
	 do
	 {
	 	printf("��������Ҫ��ע�����Ŀ��ţ����ҿ��Ų��ܳ���15λ��,0����ȡ������\n");
	 	scanf("%s",num);
	 	puanduan();
	 	if(strcmp(num,"0")==0)
		{
		   	return ;
		} 
	 
		
	for(j=0;j<i;j++)//���ҷ��� 
	{
		if(strcmp(students[j].num,num)==0)
		{
			flag=j;
			i--; //ע����iҲҪ�仯������һ�� 
			break;
		}
	}
		if(flag==-1)
		{
		printf("�Ҳ����ÿ��ţ����������룬лл\n");
		sum++;	
		}
		if(sum==5)
		{
			printf("������Ŀ����Ѿ��ﵽ5���ˣ�ϵͳ���������˵�\n");
			return ;
		}	 
   }while(flag==-1);
   for(k=flag;k<i;k++)//ȫ����ǰ��һ����λ 
   {
   	students[k]=students[k+1];
    }
    for(j=0;j<i;j++)
	{
		   fprintf(fp,"%s %s %.0f %d\n",students[j].num,students[j].name,students[j].money,students[j].info);	
	}

	if(fclose(fp))
	{
	printf("�ļ��ر�ʧ��\n");
	exit(0);
	} 
   printf("�����ɹ������������˵�\n\n");
	    
}
void set()// ��ӻ�����ʧ 
{
	int j,flag=-1,info1,sum=0,k;
	if(i==0)
	
	{
		printf("���Ƚ����ļ�,лл");
		return ; 
	}
    if((fp=fopen("card.dat.txt","w+"))==NULL)
	{
		printf("�ļ��򿪴���\n");
		exit(0);
	}
	do
	 {
	 	printf("��������Ҫ����ӻ��߽����ʧ���Ŀ��ţ����ҿ��Ų��ܳ���15λ����0����ȡ���������ز˵�\n");
	 	scanf("%s",num);
	 	puanduan();
	 	if(strcmp(num,"0")==0)
		{
		   	return ;
		} 
	 	
 	    for(j=0;j<i;j++)//���ҷ��� 
	    {
		if(strcmp(students[j].num,num)==0)
		{
			flag=j;
			break;
		}
	    }
		if(flag==-1)
		{
		printf("�Ҳ����ÿ��ţ����������룬лл\n");
		sum++;	
		}
		if(sum==5)
		{
			printf("������Ŀ����Ѿ��ﵽ5���ˣ�ϵͳ���������˵�\n");
			return ;
		}	 
   }while(flag==-1);
   printf("��������Ҫ�Ķ��Ĺ�ʧ��Ϣ��0����û�й�ʧ��1�����ʧ\n");//�ı��ʧ��Ϣ 
   scanf("%d",&info1);
   while(info1!=0&&info1!=1)
   {
   	printf("��ʧ��Ϣ���벻�ԣ�����������\n");
   	scanf("%d",&info1);
   }
   students[flag].info=info1;
    for(j=0;j<i;j++)//д���ļ� 
	{
		fprintf(fp,"%s %s %.0f %d\n",students[j].num,students[j].name,students[j].money,students[j].info);	
	}

	if(fclose(fp))
	{
	printf("�ļ��ر�ʧ��\n");
	exit(0);
	} 
    printf("�����ɹ�,���������˵�\n\n"); 

}
void look()//�鿴�����ļ���Ϣ 
{
	int s=0,k;
	if(i==0)
	
	{
		printf("���Ƚ����ļ�,лл\n");
		return ; 
	}
	if((fp=fopen("card.dat.txt","r+"))==NULL)
	{
		printf("�ļ��򿪴���\n");
		exit(0);
	}
	printf("�ļ�������Ϣ���£�����0����û�й�ʧ��1�����ʧ\n");
           for(s=0;s<i;s++)
           {
		   
			 fscanf(fp,"%s%s%lf%d",students[s].num,students[s].name,&students[s].money,&students[s].info);//�����ļ���ȫ����Ϣ���ṹ������ 
			 if(strcmp(students[s].num,"0")==0)
			 continue;
			 printf("�����ţ�%s\n������%s\n�� %.2f\n��ʧ��Ϣ��%d\n\n",students[s].num,students[s].name,students[s].money,students[s].info);

		      } 
		      if(fclose(fp))
		      {
		      	printf("�ر��ļ�ʧ��\n");
		      	exit(0);
			  }
}
