#include <bits/stdc++.h> 
using namespace std; 
 
typedef struct
{
	char question[100],op1[20],op2[20],op3[20],op4[20];
	char ans;
}Type_question;

void getdata()
{
	Type_question temp;
	cout<<"Enter question\n";
	getchar();
	gets(temp.question);
	cout<<"Now enter the 4 options\n";
	gets(temp.op1);
	gets(temp.op2);
	gets(temp.op3);
	gets(temp.op4);
	cout<<"Enter the correct option\n";
	cin>>temp.ans;
	FILE *fp;
	fp = fopen("questions.bin","ab");
	fwrite(&temp,sizeof(Type_question),1,fp);
	fclose(fp);
}

void showdata()
{
	Type_question temp;
	FILE *fp;
	fp = fopen("questions.bin","rb");
	cout<<"\nShowing the file contents\n";
	while(fread(&temp,sizeof(Type_question),1,fp))
	{
		cout<<temp.question<<"\n";
		cout<<temp.op1<<"\n"<<temp.op2<<"\n"<<temp.op3<<"\n"<<temp.op4<<"\n";
		cout<<"Answer is option : "<<temp.ans<<"\n\n";
	}
	fclose(fp);
}

int main() 
{ 
	int n;
	cout<<"How many questions to enter?\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		getdata();
	}
	showdata();
    return 0; 
}

