#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(int argc,char * argv[])
{
	int fd=open("input.txt",O_RDONLY,0);
	char buf[100];
	char wri[100];
	read(fd,buf,100);
	int i;
	int count=0;
	for(i=0;i<strlen(buf);i++)
	{
		if((buf[i]<'a' || buf[i]>='z') && (buf[i]<'A' || buf[i]>'Z'))
		{
			wri[count]=buf[i];
			count++;
		}
	
	}
	FILE* ptr=fopen("task3.txt","w");
	for(i=0;i<count;i++)
	{
		fputc(wri[i],ptr);
		
	}
	fclose(ptr);
	return 0;

	

}
          
