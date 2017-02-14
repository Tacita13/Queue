//Client file
//******************************************************************
//
//   Programador : Isamar López Rodríguez 
//   Archivo     : menu.cpp               Fecha : 10/11/16
//
//******************************************************************
//    Propósito :This file holds the main that finally displays the values
//               of the class queue while using a menu to guide the user.
//
//******************************************************************
#include <iostream>
#include "queue.h"
#include <string>
using namespace std;


int menu();
void execute(queue<string>&);

int main(){

    queue<string> list;
    execute(list);

    return 0;
}

// Display the menu and get a choice.
int menu(){
    int choice;

    cout <<"======================================================\n";
    cout << "\nWhat do you wish to do with your list?\n\n"
    << "1. Push an element\n"
    << "2. Pop an element\n"
    << "3. Peek Front\n"
    << "4. Peek back\n"
    << "5. Move to Front\n"
    << "6. Size\n"
    << "7. Print\n"
    << "8. Clear\n"
    << "9. Quit\n"
    << "Enter your choice: ";
    cin >> choice;

return choice;
}

//excecute the given choice between 1 and 9
void execute(queue<string>& list){

    string element="";
    int index=0;
    int choice=0;
    do{

    choice=menu();

    switch (choice){
    case 1: cout << "\nWhich element would you like to push?\n";
             cin >> element;
             list.push(element);
             list.print();
    break;
    case 2: list.pop();
            list.print();

    break;
    case 3:
        if(list.empty())
            cout<<"Empty list. Cannot peek front.\n";
        else{
            cout << "\nThe element in the front is: "<<list.front()<<endl;
            list.print();
        }
    break;
    case 4:
        if(list.empty())
            cout<<"Empty list. Cannot peek back.\n";
        else{
            cout << "\nThe element in the back is: "<<list.back()<<endl;
            list.print();
        }
    break;
    case 5: cout << "Which element would you like to move front?\n";
        cin >> index;
        list.moveToFront(index);
        list.print();
    break;

    case 6: cout<<"\nThe size of the list is: "<< list.size()<<endl;
    break;

    case 7: list.print();
    break;

    case 8: cout<< "\nList is now empty.\n";
            list.clear();
    break;

    case 9: cout << "\nProgram ending.\n";
    break;

    default: cout << "The valid choices are 1 through 8. Run the\n"
                  << "program again and select one of those.\n";
    }

    }while(choice !=9);

}
