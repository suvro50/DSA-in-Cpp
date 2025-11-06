#include <iostream>
using namespace std;

string convert_String(string str, int index = 0) {

    if (index == str.length()){
        return "";
    }

    char ch = str[index];

    if (ch >= 'A' && ch <= 'Z'){
        ch = ch + 32;
    }


    if (ch != ' '){
        return ch + convert_String(str, index + 1);
    }
    else{
        return convert_String(str, index + 1); 
    }
    
}


int main() {

    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string result = convert_String(str);

    cout << "String: " << result << endl;

    return 0;
}
