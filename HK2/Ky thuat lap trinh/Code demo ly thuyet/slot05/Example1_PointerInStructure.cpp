#include <iostream>
#include <string.h>
using namespace std;

struct Video {
	char* title;
	char category[5];
	int quantity;
};

void setTitle(Video*& v){
	char tmp[100];
	cin.get(tmp, 100);
	v = new Video;
	v->title = new char[strlen(tmp) + 1];
	strcpy(v->title, tmp);
}

int main() {
    Video* ptr;
    setTitle(ptr);
    
    cout << "The title of video: " << ptr->title;
    
	delete[] ptr->title;
    delete ptr;
    
    return 0;
}
