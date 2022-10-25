#include<fstream>
#include<iostream>
#include "Dictionary.h"
#include "List.h"
using namespace std;

string filename; //stores filename


SinglyLinkedList<Dictionary> SLL;
//Modify the above readFileData() function inside the Parser.h file to insert the parsed 
//dictionary objects into a singly linked list.

void readFileData(ListNode<Dictionary> **headnode) //reads text from a file and writes it to the AVL tree
{
	Dictionary *dict;

	string word, meaning;

	fstream fin;
	cout << "\e[46mEnter the filename\x1b[0m "; 
	cin.ignore();
  cin >> filename;

	fin.open(filename);
    cout << "\e[0;32mFile reading succesful.\x1b[0m\n";


    while( fin >> word )  //write into file name
    { 
        fin.ignore();
        getline(fin,meaning);
        dict = new Dictionary(word,meaning);

      ListNode<Dictionary>* nn= new ListNode<Dictionary>;
      nn->data = *dict;
      
      if (*headnode != NULL)
      {
          ListNode<Dictionary>* temp= *headnode;
          while(temp->next != NULL)
          {
               temp = temp->next;
          }
          temp->next = nn;
      }
      else
      {
          *headnode = nn;
      }   

      delete dict;
}
	fin.close();
}

//modify the writeToFile(ListNode *headNode) function inside the Parser.h file to convert a linked list into a text file.

void writeToFile(ListNode<Dictionary> *headnode) //write the linked list to a text file
{
  string word, meaning;
  
  fstream dictFile; //create fstream object for the file
  cout << "\e[46mEnter the filename\x1b[0m "; 
	cin.ignore();
  cin >> filename;
  dictFile.open(filename, std::ios::app); //create/open a text file in append mode. new information is always added to the end

  ListNode<Dictionary> *loc = headnode;

    while(loc!= NULL) 
    { 
        dictFile << loc->data.word<< " " << loc->data.meaning << endl; 
        loc= loc->next;   
    }
  
  dictFile.close();
  cout << "\e[0;32mDictionary entries added.\x1b[0m\n";
}

void mainMenu() //menu function
{
  string word, meaning; //stores the word and meaning
  char choice = 0;  //stores user choice for the actions
  SinglyLinkedList<Dictionary> list;

  cout << "\e[1;35mInput 's' to terminate the program anytime.\e[0;37m" << endl;
  while (choice != 's') //while loop until 's' is entered
  {
    cout << "\n\x1b[36mPlease select an action: " << endl << endl;
    cout << "\t1. Read file data" << endl;
    cout << "\t2. Write to file" << endl;
    cout << "\t3. Print List" << endl;
    cout << "\t4. Reverse print the list" << endl;
    cout << "\t5. Reverse the list" << endl;
    cout << "\t6. Rearrange list by odd/even length" << endl;
    cout << "\t7. Filter list by letter" << endl;
    
    

    cout << "\x1b[0m"; cin >> choice; cout << endl;
    switch(choice)  //switch statement to check user input and calling respective functions
    {
      case('1'):
      {
        readFileData(&list.head);
      }; break;
      case('2'):
      {
        writeToFile(list.head);
      }; break;
      case('3'):
      {
          list.print_List();
      }; break;
      case('4'):
      {
          list.printReverse(list.head);
      }break;
      case('5'):
      {
          list.head=list.reverseList(list.head);
          cout << "The list is reversed";
          writeToFile(list.head);
      }break;
      case('6'):
      {
          list.head = list.rearrangeByEvenOddLength(list.head);
          cout << "The list is rearranged";
          writeToFile(list.head);
      }break;
      case('7'):
      {
          cout << "Enter the letter you want to filter the list with:";
          string S;
          cin.ignore();
          cin >> S;
          list.FilterByLetters(list.head, S);
          cout << "The list is filtered!";
          writeToFile(list.head);
      }break;
      case('s'):
      {
        cout << "\e[1;33mProgram terminated." << endl;
      }; break;
      default:
        cout << "\x1b[31mInvalid action selected!\x1b[37m" << endl;
    }
  }
}


