#include<bits/stdc++.h>
#include<conio.h>
#include<dos.h>
#include<ctime>
using namespace std;

class L1
{
	char alpha[26];
	int check[26];
	double timeTaken,accuracy,score;
	public: L1()
			{
				srand(time(NULL));
				for(int i=0;i<26;i++)
					check[i]=1;
				for(int i=0;i<26;i++)
				{
					int num = rand()%26;
					if(check[num])
					{
						check[num]=0;
						alpha[i] = num + 97;
						continue;						
					}
					else
					{
						while(check[num]!=1)
						{
							num++;
							num=num%26;
						}
						alpha[i] = num + 97;
						check[num]=0;    
					}
				}
			}
			double playL1()
			{
				system("CLS");
				cout<<"Starting Level 1\n10 letter will be shown on the screen, press the corresponding key\nPress any key...\n";
				getch();
				clock_t begin = clock();
				system("CLS");
				accuracy=0;
				char ch;
				for(int i=0;i<10;i++)
				{
					cout<<alpha[i]<<"\n";
					ch=getch();
					if(ch==alpha[i])
						accuracy++;
					system("CLS");
				}
				clock_t end = clock();
				timeTaken = double(end-begin)/1000;
				cout<<"Time taken was "<<timeTaken<<endl;
				timeTaken = (30-timeTaken)*50/27;                  //Formula to calculate time score
				cout<<"Accuracy was "<<accuracy<<endl;
				accuracy = accuracy*50/10;						   //Formula to calculate accuracy score
				if(accuracy < 5)
					score = 0;
				else
					score = timeTaken +accuracy ;
				return score;
			}
			// void show()
			// {
			// 	cout<<"\n\nStarted showing\n";
			// 	for(int i=0;i<26;i++)
			// 	{
			// 		cout<<alpha[i]<<"  ";
			// 	}
			// 	cout<<"\n";
			// }
};

class L2
{
	char words[100][15];
	double timeTaken,accuracy,score;
	public: 
		    L2()
			{
				//To get words from the file "words.txt" and paste them in array (i.e words[100][15])
				accuracy = 0;
				score = 0;
				timeTaken =0;
				ifstream fp;
				fp.open("words.txt");
				for(int i=0;i<100;i++)
				{
					fp>>words[i];
				}
				//Now to randomise the first 10 words
				int num;
				srand(time(NULL));
				char temp[15];
				for(int i=0;i<10;i++)
				{
					num = rand()%100;
					strcpy(temp,words[i]);
					strcpy(words[i],words[num]);	
					strcpy(words[num],temp);
				}
			}
			double playL2()
			{	
				int wrong=0;		//keeps track of how many words wrongly typed
				char arr[20][15];
				system("CLS");
				char temp[15];		//User's typed word
				cout<<"Ten words will be displayed on the screen\nType them in quick succession\nPress any key....";
				getch();
				system("CLS");
				clock_t start = clock();
				for(int i=0;i<10;i++)
				{
					cout<<words[i]<<"\n";
					cin>>temp;
					if(strcmp(temp,words[i])==0)
						cout<<accuracy++<<endl;
					else
					{
						strcpy(arr[wrong],words[i]);
						strcpy(arr[wrong+1],temp);
						wrong+=2;
					}
				    system("CLS");
				}
				clock_t end = clock();
				timeTaken = (end-start)/1000.0;
				if(!wrong)
				{
					cout<<"Well done, you typed all of them correctly\n";
				}
				else
				{
					cout<<"Wrongly typed words are\n";
					for(int i=0;i<=(wrong-2);i+=2)
					{
						cout<<arr[i]<<"\t";
					}
					cout<<"\n";
					for(int i=1;i<=(wrong-1);i+=2)
					{
						cout<<arr[i]<<"\t";
					}	
				}
				cout<<"\n";
				cout<<"Time taken was "<<timeTaken<<endl;
				timeTaken = (90-timeTaken)*50/70;                  //Formula to calculate time score
				cout<<"Accuracy was "<<accuracy<<endl;
				accuracy = accuracy*50/10;						   //Formula to calculate accuracy score
				if(accuracy < 5)
					score = 0;
				else
					score = timeTaken +accuracy ;
				return score;
			}
			// void show()
			// {
			// 	for(int i=0;i<100;i++)
			// 	{
			// 		cout<<words[i]<<" ";
			// 	}
			// }
};

class L3
{
	string collection[25];
	int score;
	public: L3()
			{
				score=0;
				cout<<"adsfadsfas\n";
				ifstream fp;
				fp.open("sentence.txt");
				string temp;
				//To get the 25 strings from the file
				for(int i=0;i<25;i++)                     
				{
					getline(fp,temp,'\n');
					collection[i]=temp;
				}
				srand(time(NULL));		//Now to randomise the first 3 strings
				for(int i=0;i<3;i++)
				{
					int num=rand()%26;
					string temp;
					temp=collection[i];
					collection[i]=collection[num];
					collection[num]=temp;
				}
				fp.close();
			}

			int playL3()
			{
				system("CLS");
				int w=0;
				string temp,wrong[50],temp1,temp2;
				cout<<"You will be shown 3 sentences\nWrite them and press enter\nPress any key to continue...\n";
				getch();
				system("CLS");
				for(int i=0;i<3;i++)
				{
				    cout<<collection[i]<<"\n";
				    getline(cin, temp);
				    istringstream tempss(temp);
				    istringstream okss(collection[i]);
				    do
				    {
				    	okss>>temp1;
				    	tempss>>temp2;
				    	if(temp1 != temp2)
				    	{
				    		wrong[w]=temp1;
				    		wrong[w+1]=temp2;
				    		w+=2;
				    	}
				    	else
				    	{
				    		score++;
				    	}
				    }while(okss);			
					cout<<"\n";					
				    system("CLS");
				}
				if(!w)
				{
					cout<<"Well done, you typed all of them correctly\n";
				}
				else
				{
					cout<<"Wrongly typed words are\n";
					for(int i=0;i<(w-2);i+=2)
					{
						cout<<wrong[i]<<"\t";
					}
					cout<<"\n";
					for(int i=1;i<(w-1);i+=2)
					{
						cout<<wrong[i]<<"\t";
					}	
				}
				return score;
			}

			void show()
			{
				for(int i=0;i<3;i++)
					cout<<collection[i]<<"\n";
			}

};

typedef struct
{
	char para[1000];
}Type_para;

class L4
{
	float score;
 public:
 	L4()
 	{
 		score =0;
 	}
 	void playL4()
 	{
 		system("CLS");
 		cout<<"You will be shown a paragraph\nType the paragraph as fast and as accurately as you can\n";
		int w=0,noOfWords=0; 
		char temp[1000];	
 		string temp1,temp2,wrong[50],userinput,stringtemp;
		srand(time(NULL));
		int random = rand()%3;
		cout<<"\nRandom = "<<random<<endl;
		FILE* fp;
		fp = fopen("paragraphs.bin","rb");
		for(int i=0;i<3;i++)
		{
			fread(&temp,sizeof(Type_para),1,fp);
			if(i==random)
			{
				stringtemp = temp;
				cout<<stringtemp;
			    getline(cin, userinput);
			    istringstream tempss(stringtemp);
			    istringstream okss(userinput);
			    do
			    {
			    	noOfWords++;
			    	okss>>temp1;
			    	tempss>>temp2;
			    	if(temp1 != temp2)
			    	{
			    		wrong[w]=temp1;
			    		wrong[w+1]=temp2;
			    		w+=2;
			    	}
			    	else
			    	{
			    		score++;
			    	}
			    }while(okss);			
				cout<<"\n";
				break;
				system("CLS");
			}		
		}
		if(!w)
		{
			cout<<"Well done, you typed all of them correctly\n";
		}
		else
		{
			cout<<"Wrongly typed words are\n";
			for(int i=0;i<(w-2);i+=2)
			{
				cout<<wrong[i]<<"\t";
			}
			cout<<"\n";
			for(int i=1;i<(w-1);i+=2)
			{
				cout<<wrong[i]<<"\t";
			}	
		}	
		cout<<"The noOfWords are "<<noOfWords<<endl;			
		cout<<"The score is "<<score<<endl;			
	}
};

typedef struct
{
	char question[100],op1[20],op2[20],op3[20],op4[20];
	char ans;
}Type_question;

class L5
{
	int arr[5],score;
    public: L5()
		{
			int num=0;
			srand(time(NULL));
			for(int i=0;i<5;i++)
			{
				num = num + rand()%6 + 1;
				arr[i] = num;
			}
		}

		int playL5()
		{
			char option;
			int counter=0;
			system("CLS");
			cout<<"You will be shown 5 MCQ questions\nAnswer by pressing the option 'a' 'b' 'c' or 'd'\n";
			cout<<"Press any key to continue\n";
			getch();
			system("CLS");

			Type_question temp;
			FILE *fp;
			fp = fopen("questions.bin","rb");

			for(int i=0;i<30;i++)
			{
				fread(&temp,sizeof(Type_question),1,fp);
				if( i == arr[counter] )
				{
					cout<<temp.question<<"\n";
					cout<<"(a) "<<temp.op1<<"\n"<<"(b) "<<temp.op2<<"\n"<<"(c) "<<temp.op3<<"\n"<<"(d) "<<temp.op4<<"\n";
					option = getch();
					if(option == temp.ans)
					{
						score++;
						cout<<":) Correct";
						_sleep(600);
						system("CLS");
					}
					else
					{
						cout<<":( Incorrect";
						_sleep(600);
						system("CLS");
					}
					counter++;
				}
				if(counter == 5)
					break;
			}
			return score;
		}

};

int main()
{
	L2 ok;
	cout<<"Your score was "<<ok.playL2()<<endl;
	return 0;
}