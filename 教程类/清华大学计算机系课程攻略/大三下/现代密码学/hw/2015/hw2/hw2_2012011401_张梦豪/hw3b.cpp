#include <stdio.h>    
#include <fstream>
#include <math.h>    
using namespace std;
//Ѱ����Կ����    
int find_key_lenth(char*pass,int len)      
{    
    //pass����,len ���ĳ��ȣ���λͳ����ȵ����ģ�ȡ�����Ĳ���Ϊd;    
    int d=0,count,MaxCount=0;    
    int step;
    for(step=1;step<10;step++)      //�ƶ�������1-10;    
    {    
        count=0;                            
        int j;
        for(j=0;j<len&&(j+step-2)<len;j++)    
        {    
            if(pass[j]==pass[j+step]&&pass[j+1]==pass[j+step+1])       
                count++;    
        }    
        if(count>MaxCount)    
        {    
            MaxCount=count;    
            d=step;    
        }    
    }    
    return d;    
}    
// ������Կ������
void decode(char*pass,char*ming,int d,int len)    
{    
    float v[26]={0};               //V��W�����飻    
    int per_len=len/d;             //ÿ�鳤�ȣ�    
    double A[26]={0.082,0.015,0.028,0.043,0.127,              //Ӣ����ĸƵ�ʱ�A    
              0.022,0.02,0.061,0.07,0.002,0.008,    
              0.04,0.024,0.067,0.075,0.019,0.001,    
              0.06,0.063,0.091,0.028,0.01,0.023,0.001,0.02,0.001};    
                       
    double B[26]={0};              //�洢W*Aֵ    
    char*key;                      //��Կ    
    //key=new char[d];      
    char temp[d];
    key = temp;
    int i;
    for(i=0;i<d;i++)    
    {    
        int j=0;    
        while(1)                     //ͳ��ÿ��a--z���ֵ�Ƶ�ʴ���V[26]��    
        {    
            if((i+d*j)>=len) break;    
            v[pass[i+d*j]-'A']+=1;    
            j++;                
        }   
        int k;            
        for(k=0;k<26;k++)          //����W    
            v[k]=v[k]/per_len;    
   
        for(k=0;k<26;k++)              //����B[i]=Ai*V;    
        {    
            int l;
            for(l=0;l<26;l++)          
                B[k]+=A[l]*v[(l+k)%26];         
        }    
        //�ҳ�B�е���0.065��ӽ���ֵ����±꼴Ϊ��Կ    
        double max=1;                        
        int c;    
        for(k=0;k<26;k++)                
        {       
            if(fabs(B[k]-0.065)<max)    
            {    
            	max=fabs(B[k]-0.065);
				c=k;           
            }    
        }    
        key[i]=c;            
        //���B��V��    
        for(k=0;k<26;k++)    
        {    
            B[k]=0;    
            v[k]=0;    
        }    
        printf("%c",'A'+key[i]);    
    }       
    //���ܲ���ʾ    
    
    printf("\n\n����:\n");    
    for(i=0;i<len;i++)    
    {    
		int tmp;    
		tmp=pass[i]-'A';    
		ming[i]=(tmp-key[i%d]+26)%26+'a';    
		printf("%c",ming[i]); 
    }     
    printf("\n\n");   
    return ;    
}    
int main()    
{    
    char password[4635]={0}; //����    
    char mingwen[4635]={0};  //���� 
	ifstream fin("3bin.txt");      
    int i=0,d;    
    printf("����:\n");  
	char ch;  
    while (fin>>ch)
    {
    	password[i]=ch;
    	i++;
    }
    fin.close();
    int j;
    for(j=0;j<i;j++)    
    {    
        printf("%c",password[j]);    
    }      
    d=find_key_lenth(password,i-1);    
    printf("\n\nd==%d\n",d);    
    printf("key=");    
    decode(password,mingwen,d,i-1);      
    ofstream fout("3bout.txt");
    for (j=0;j<i;j++)
    {
    	fout<<mingwen[j]; 
    }
    fout.close();   
    return 0;    
}    
