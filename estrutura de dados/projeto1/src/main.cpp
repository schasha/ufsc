#include <fstream>
#include <iostream>
#include <string>

bool parser(std::string);
std::string getTagContent(std::string, std::string, int = 1);
int vacuumArea(std::string, int, int, int, int);


int main() {
    using namespace std;

    char xmlfilename[100];
    cin >> xmlfilename;

    ifstream xml;
    xml.open(xmlfilename);

    // xml file to string
    string xml_string;
    string line;
    while (getline(xml, line, '\n')) {
        xml_string += line;
    }

    // checks validity
    if (!parser(xml_string)) {
        cout << "erro" << "\n";
        return 0;
    }

    // counts cenarios
    int cenarios_num = 0;
    string::size_type start = 0;
    while ((start = xml_string.find("<cenario>", start)) != string::npos) {
        cenarios_num++;
        start += 9;
    }

    // runs every cenario
    for (int i = 0; i < cenarios_num; i++) {
        string cenario = getTagContent(xml_string, "cenario", i + 1);
        string nome = getTagContent(cenario, "nome");
        string matrix = getTagContent(cenario, "matriz");
        int m = stoi(getTagContent(cenario, "altura"));
        int n = stoi(getTagContent(cenario, "largura"));
        int x = stoi(getTagContent(cenario, "x"));
        int y = stoi(getTagContent(cenario, "y"));
        cout << nome << ' ' << vacuumArea(matrix, m, n, x, y) << "\n";
    }

    return 0;
}

