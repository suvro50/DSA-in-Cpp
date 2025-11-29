#include <iostream>
using namespace std;

// Remove white space from a string & convert upper cases to lower
string removeSpaceToLower(string str)
{
    int len=str.length();
    if(len ==0 ) return "";
    if(str[len-1]==' ')
        return removeSpaceToLower(str.substr(0,len-1));
    else
        return removeSpaceToLower(str.substr(0,len-1))
               + string(1,tolower(str[len-1])) ;
}
int main()
{
    cout<<removeSpaceToLower("Hello World It's Me.")<<endl;
}


// string convert_String(string str, int index = 0) {

//     if (index == str.length()){
//         return "";
//     }

//     char ch = str[index];

//     if (ch >= 'A' && ch <= 'Z'){
//         ch = ch + 32;
//     }


//     if (ch != ' '){
//         return ch + convert_String(str, index + 1);
//     }
//     else{
//         return convert_String(str, index + 1); 
//     }
    
// }


// int main() {

//     string str;
//     cout << "Enter a string: ";
//     getline(cin, str);

//     string result = convert_String(str);

//     cout << "String: " << result << endl;

//     return 0;
// }
