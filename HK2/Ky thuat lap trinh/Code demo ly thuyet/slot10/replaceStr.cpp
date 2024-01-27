#include <cstring> // for strlen and strcpy
#include <string>  // for std::string
#include <iostream>

using namespace std; 



int findPosOfSubStr(char* src, char* sub, int start){
	int lenSrc = strlen(src);
	int lenSub = strlen(sub);
	for (int i = start; i < lenSrc; i++){
		int count = 0;
		for (int j = 0; j < lenSub; j++)
			if (src[i + j] == sub[j])
				count++;
		if (count == lenSub) return i;
	}
	return -1;
}


char* replaceStr(char* src, char* sub, char* rep) {
    if (src == NULL || sub == NULL || rep == NULL) {
        return NULL;
    }
    int lenSrc = strlen(src);
    int lenSub = strlen(sub);
    int lenRep = strlen(rep);
    int count = 0;
    int start = 0;
    
	while (true){
		int posSub = findPosOfSubStr(src, sub, start);
		if (posSub == -1) break;
		else {
			count += 1;
			start = posSub + 1;
		}
	}
    
    int newLen = lenSrc + count * (lenRep - lenSub);
    
    if (newLen == 0)
    	return NULL;
    char* newStr = new char[newLen + 1];
    // can not allocate the new array of characters
    if (newStr == NULL) {
        return NULL;
    }
    
    start = 0;
    int curSrc = 0, curNewStr = 0;
    while (true){
    	int posSub = findPosOfSubStr(src, sub, start);
    	
		if (posSub == -1) break;
    	
    	for (; curSrc < posSub; curSrc++)
    		newStr[curNewStr++] = src[curSrc];
    	
    	for (int j = 0; j < lenRep; j++)
    		newStr[curNewStr++] = rep[j];
    	
		curSrc += lenSub;
    	start = posSub + 1;
    	
    	cout << posSub << " " << curSrc  << " " << newStr << endl;
	}
    
    if (curSrc < lenSrc){
    	for (; curSrc < lenSrc; curSrc++)
    		newStr[curNewStr++] = src[curSrc];
	}
	
    newStr[curNewStr] = '\0';
    
    return newStr;

}

int main(){
	char src[] = "brown dog and brown fox";
	char sub[] = "brow";
	char rep[] = "cya";
	char* newStr  = replaceStr(src, sub, rep);
	
	
	for (int i = 0; i < strlen(newStr); i++)
		cout << newStr[i];
	
	delete[] newStr;
	return 0; 
	
}

