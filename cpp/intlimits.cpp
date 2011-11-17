#include <iostream>
#include <climits>

using std::cout;
using std::endl;

volatile int char_min = CHAR_MIN;

int main(void)
{
    cout << "Size of boolean type is "
        << sizeof(bool) << " byte(s)"
        << "\n\n";

    cout << "Number of bits in a character: "
        << CHAR_BIT << '\n';
    cout << "Size of character types is "
        <<sizeof(char)
        << " byte" << '\n';
    cout << "Signed char min: "
        << SCHAR_MIN << " max: "
        <<SCHAR_MAX << '\n';
    cout << "Unsigned char min: 0 max: "
        << UCHAR_MAX << '\n';

    cout << "Default char is ";

    if (char_min < 0)
        cout << "signed";
    else if (char_min == 0)
        cout << "unsigned";
    else
        cout << "non-standard";
    cout << "\n\n";

    cout << "Size of short int types is "
        << sizeof(short) << " bytes"
        << '\n';
    cout << "Signed short min: "
        << SHRT_MIN << " max: "
        << SHRT_MAX << '\n';
    cout << "Unsigned short min: 0 max: "
        << USHRT_MAX << "\n\n";

    cout << "Size of int types is "
        << sizeof(int) << " bytes"
        << '\n';
    cout << "Signed int min: "
        << INT_MIN << " max: "
        << INT_MAX << '\n';
    cout << "Unsigned int min: 0 max: "
        << UINT_MAX << "\n\n";

    cout << "Size of long int types is "
        << sizeof(long) << " bytes"
        << '\n';
    cout << "Signed long min: " <<
        LONG_MIN << " max: "
        << LONG_MAX << '\n';
    cout << "Unsigned long min: 0 max: "
        << ULONG_MAX << endl;
    cout << "Long long size = "<< sizeof(long long)<<endl;
    cout << "Long double"<< sizeof(long double) << endl;
    return 0;
}
