// Assignment # 1
// Task # 1
// Abdullah Tahir
// Section : 9A
// Roll no : 21L-5419

#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>
#include<time.h>
using namespace std;

int main()
{
    string Size;
    ifstream Dictionary;
    int size = 0;
    //-------------------------------------
    // Calculating total lines in file
    //-------------------------------------
    Dictionary.open("Dictionary.txt");
    for (int i = 0; !Dictionary.eof(); i++)
    {
        getline(Dictionary, Size);
        size++;
    }
    Dictionary.close();
    //-------------------------------------
    // Calculating words in each line
    //-------------------------------------
    int space = 0, * no_of_words_arr;
    no_of_words_arr = new int[size];
    Dictionary.open("Dictionary.txt");
    for (int i = 0; i < size; i++)
    {
        getline(Dictionary, Size);
        for (int j = 0; Size[j] != '\0'; j++)
        {
            if (Size[j] == ' ')
            {
                space++;
            }
        }
        space = space + 1;
        no_of_words_arr[i] = space;
        space = 0;
    }
    Dictionary.close();
    //-------------------------------------
    // Initializing array having exact size
    // and storing data in it
    //-------------------------------------
    string** Words;
    Words = new string * [size];
    for (int i = 0; i < size; i++)
    {
        Words[i] = new string[no_of_words_arr[i]];
    }
    Dictionary.open("Dictionary.txt");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < no_of_words_arr[i]; j++)
        {
            Dictionary >> Words[i][j];
        }
    }
    Dictionary.close();
    //-------------------------------------
    // Now taking input from the user to 
    // paraphrase it using our dictionary
    //-------------------------------------
    char* Input, ** search; int spc = 0;
    Input = new char[1000];
    cout << "Enter your text here : ";
    cin.getline(Input, 1000);
    //-------------------------------------
    // Counting words in input str and 
    // creating array of exact size
    //-------------------------------------
    for (int i = 0; Input[i] != '\0'; i++) { if (Input[i] == ' ') { spc++; } } spc = spc + 1;
    search = new char* [spc]; int j = 0;
    for (int i = 0; i < spc; i++)
    {
        int l = 0;
        for (; Input[j] != '\0'; j++)
        {
            if (Input[j] == ' ')
            {
                break;
            }
            l++;
        }
        j++; l++;
        search[i] = new char[l];
    }
    //-------------------------------------
    // Conveting the input single array
    // data into array of words
    //-------------------------------------
    int k = 0;
    for (int i = 0; i < spc; i++, k++)
    {
        int j = 0;
        for (; Input[k] != '\0'; j++, k++)
        {
            if (Input[k] == ' ')
            {
                break;
            }
            search[i][j] = Input[k];
        }
        search[i][j] = '\0';
    }
    //-------------------------------------
    // Now storing array of char words
    // in array string words so that 
    // compraing will be easy  
    //-------------------------------------
    string* compare_words;
    compare_words = new string[spc];
    for (int i = 0; i < spc; i++)
    {
        compare_words[i] = search[i];
    }
    //-------------------------------------
    // Now comparing and paraphrasing
    //-------------------------------------
    srand(time(0));
    for (int inc = 0; inc < spc;)
    {
        int temp = inc;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < no_of_words_arr[i]; j++)
            {
                if (compare_words[inc] == Words[i][j])
                {
                    int random;
                    random = 0 + (rand() % no_of_words_arr[i]);
                    if (random == 0)
                    {
                        random += 1;
                    }
                    compare_words[inc] = Words[i][random];
                    inc++;
                }
            }
        }
        if (inc == temp)
        {
            inc++;
        }
    }
    cout << "\nParaphrased text : ";
    for (int i = 0; i < spc; i++)
    {
        cout << compare_words[i] << " ";
    }
    cout << endl;
    //-------------------------------------
    // Deleting all dynamically allocated 
    // memory
    //-------------------------------------
    delete[]no_of_words_arr; no_of_words_arr = 0;
    for (int i = 0; i < size; i++) { delete[]Words[i]; }Words = 0;
    delete[]Input; Input = 0;
    for (int i = 0; i < spc; i++) { delete[]search[i]; }search = 0;
    delete[]compare_words; compare_words = 0;
    //-------------------------------------
    return 0;
}