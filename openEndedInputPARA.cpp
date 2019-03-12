#include <bits/stdc++.h> 
using namespace std; 
 
typedef struct
{
	char para[1000];
}Type_para;

void getdata()
{
	Type_para temp;
	cout<<"Enter the paragraph\n";
	getchar();
	gets(temp.para);
	FILE *fp;
	fp = fopen("paragraphs.bin","ab");
	fwrite(&temp,sizeof(Type_para),1,fp);
	fclose(fp);
}

void showdata()
{
	Type_para temp;
	FILE *fp;
	fp = fopen("paragraphs.bin","rb");
	cout<<"\nShowing the file contents\n";
	while(fread(&temp,sizeof(Type_para),1,fp))
	{
		cout<<temp.para<<"\n";
	}
	fclose(fp);
}

int main() 
{ 
	int n;
	cout<<"How many paragraphs to enter?\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		getdata();
	}
	showdata();
    return 0; 
}

