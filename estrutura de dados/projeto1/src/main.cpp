#include <iostream>
#include <fstream>
#include <string>

bool parser(std::string);


int main() {
    using namespace std;

    char xmlfilename[100];
    cin >> xmlfilename;

    ifstream xml;
    xml.open(xmlfilename);

    string xml_string;
    string line;
    while (getline(xml, line, '\n')) {
        xml_string += line;
    }

    bool status = parser(xml_string);

    printf("%b\n", status);

    return 0;
}

