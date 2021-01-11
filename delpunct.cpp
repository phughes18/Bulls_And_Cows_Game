#include <iostream>



void print_chars(const char arr[])

// Remove punctuation from a string.
// Parameters: 
//    arr : buffer for the resulting string without punctuation (the target)
//    s   : a C-string to remove punctuation from (the source)
//    p   : a C-string with the punctuation to remove
// Pre-condition: s is not the empty string
// Post-condition: arr will be a replica of s, but with all of the 
// punctuation defined in p removed.
void remove_punct(char arr[], std::string s, char p[])



int main()
{
    using namespace std;

    string s1 = "Lions, Tigers, and Bears? Oh, my!!!";
    cout << s1 << endl;
/*
    char buf[BUFSIZE]; 
    for (char &c : buf)
        c = '\0';

    char p[] = ",.!?";
    print_chars(p);

    remove_punct(buf, s1, p);
    cout << buf << endl;
    print_chars(buf);
*/
    return 0;
}





