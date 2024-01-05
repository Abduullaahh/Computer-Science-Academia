#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(int argc,char * argv[])
{

	int fd=open("input",O_RDONLY,0);
	char buf[100];
	char wri[100];
	read(fd,buf,100);
	int i;
	int count=0;
	for(i=0;i<strlen(buf);i++)
	{
	   if(buf[i]<='9' && buf[i]>='1')
           {
		wri[count]=buf[i];
		count++;
	   }
	
	}
	FILE* ptr=fopen("task2.txt","w");
	for(i=0;i<count;i++)
	{
		fputc(wri[i],ptr);
	}
	fclose(ptr);
	return 0;

	

}
