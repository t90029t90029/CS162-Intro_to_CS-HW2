//Shang-Chun, Lin
//cs162 program #2

//This program is to practice writting a program that it automatically formats your document as you type.
//We will allow the user to type in a few paragraphs of text based on that it will display it formatted
//in a easy to read format.

//discussion:	the strategy is to make several functions and do the function calls in the main.
//		the process will be 1.read in 2.check the input is satisfying the condition or not
//		3.once we make sure the input is correct then we capitalize the first characters in each paragraph
//		4.the first word in each paragraph will be automatically intended by tab
//		5.two spaces will occur after every period, exclamation mark, question mark
//		6.display how many characters and words are in the article
//		In this case, the main idea is to clip and paste the article into different array,
//		when some tabs or spaces are added into the original one.


#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//global constants
const int ARTI = 3001;
//the prototypes of functions
void read_in(char article[]);		//These three function is to check the input does satisfy the condition that the limitation of the number of the words
void check_paragraph(char article[]);	//
void check_sentence(char article[]);	// 
void capit(char article[]); 		//capitalize
void auto_tab(char article[],char tab_arti[]);
void auto_space(char tab_arti[],char final_arti[]);
void calculate_c(char final_arti[],int & characters);
void calculate_w(char final_arti[],int & words);

int main()
{
	//variables here
	char article[ARTI];
	int len = strlen(article);
	char tab_arti[ARTI];
	char final_arti[ARTI+100];
	int characters = 0;		//the total number of characters
	int words = 0;
	cout<<"Welcome to use this program that will help you to format your document as you type."<<endl;
	cout<<"Rules:\nYou will be allowed to type in a few paragraphs of text based on that it will"<<
	" display it formatted in a easy to read format."<<endl;
	cout<<"You are allowed to enter in a text ending with a # sign to complete the entire process."<<endl
	<<"A sentence is to be no more than 130 characters and a paragraph no more than 300 characters."<<endl;

	read_in(article);
	check_paragraph(article);
	check_sentence(article);
	capit(article);
	auto_tab(article,tab_arti);
	auto_space(tab_arti,final_arti);
	calculate_c(final_arti,characters);
	calculate_w(final_arti,words);

	cout<<"Your document has "<<characters<<" characters and "<<words<<" words. It is formatted below: "<<endl
	<<final_arti<<endl;

	return 0;
}






//the definition of functions

void read_in(char article[])
{
	cout<<"Please enter your article."<<endl;
	cin.get(article,ARTI,'#');
	cin.ignore(3000,'#');
	return;
}

void check_paragraph(char article[])
{
	int c = 0;	//characters
	int i = 0;
	int len = strlen(article);
	while(i < len)
	{
		if(article[i] == '\n')
		{
			if(c>299)
			{
				cout<<"You typed over 300 characters in one single paragraph."<<
				"Please enter it again within 300 words."<<endl;

				read_in(article);
				len = strlen(article);
				i = 0;
			}
			c = 0;
		}

		++c;
		++i;
	}
	return;
}

void check_sentence(char article[])
{
	int c = 0;      //characters
	int i = 0;
	int len = strlen(article);
	while(i < len)
	{
		if(article[i] == '!'|| article[i] == '?' || article[i] == '.')
		{
			if(c>129)
			{
				cout<<"You typed over 130 characters in one single sentence."<<
				"Please enter it again within 130 words."<<endl;

				read_in(article);
				check_paragraph(article);
				len = strlen(article);
				i = 0;
			}
			c = 0;
		}

		++c;
		++i;
	}
	return;
}


void capit(char article[])
{
	article[0] = toupper(article[0]);   //capitalize the first character in the article

	int i =0;       //a variable of the for loop
	int leng = strlen(article);

	for(i=0;leng-i>0;++i)                   //capitalize the first word in each sentence
	{
		if(article[i] == '.' || article[i] == '?' || article[i] == '!' || article[i] == '\n')   // '.' is a period
		{
			if(article[i+1] != ' ')
			{
				article[i+1] = toupper(article[i+1]);
			}
			if(article[i+1] == ' ')		//if the user type a typo with one more space
			{
				article[i+2] = toupper(article[i+2]);
			}

		}
	}

	return;
}


void auto_tab(char article[],char tab_arti[])
{
	int i = 0;       //a variable of the for loop
	int leng = strlen(article);
	int tabs = 1;	//how many tabs have been added
	tab_arti[0] = '\t';

	while(leng-i>0)
	{
		tab_arti[i+tabs] = article[i];

		if(article[i] == '\n')
		{	
			tab_arti[i+tabs+1] = '\t';

			++tabs;
		}
		++i;
	}
	//      cout<<tab_arti<<endl;   //to debug
	return;
}

void auto_space(char tab_arti[],char final_arti[])
{
	int i = 0;       //a variable of the for loop
	int leng = strlen(tab_arti);
	int spa = 0;      //how many spaces have been added

	while(leng-i>0)
	{
		final_arti[i+spa] = tab_arti[i];

		if(tab_arti[i] == '.' || tab_arti[i] == '?' || tab_arti[i] == '!')
		{
			final_arti[i+spa+1] = ' ';
			final_arti[i+spa+2] = ' ';
			spa += 2;
		}
		++i;
	}
	//      cout<<final_arti<<endl;   //to debug
	return;
}

void calculate_c(char final_arti[],int & characters)
{
	int i = 0;

	while( final_arti[i] != '#')
	{
		characters += 1;
		i += 1;
	}
	return;
}

void calculate_w(char final_arti[],int & words)
{
	int i = 0;

	while( final_arti[i] != '#')
	{
		if(final_arti[i] == ' ' || final_arti[i] == '\n')
		{
			words += 1;
		}
		i += 1;
	}
	return;
}
	
