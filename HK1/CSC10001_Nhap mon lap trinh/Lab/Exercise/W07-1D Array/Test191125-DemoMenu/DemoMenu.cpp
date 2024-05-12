//
//  Test191125-DemoMenu.cpp
//  Test191125-DemoMenu
//
//  Created by HTThanh on 11/25/19.
//  Copyright © 2019 HTThanh. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int choice = 0;
    while(true){
        cout << "1. Do task 1" << endl;
        cout << "2. Do task 2" << endl;
        cout << "3. Do task 3" << endl;
        cout << "0. Exit" << endl;
        
        cout << "Your choice: ";
        cin >> choice;
        
        if(choice == 1){
            cout << "Doing task 1" << endl;
        }
        else if(choice == 2){
            cout << "Doing task 2" << endl;
        }
        else if(choice == 3){
            cout << "Doing task 3" << endl;
        }
        else if(choice == 0){
            cout << "Exiting" << endl;
            break;
        }
        else{
            cout << "Incorrect" << endl;
        }
    }
    return 0;
}
