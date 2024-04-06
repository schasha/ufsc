#include <string>


std::string getTagContent(std::string xml, std::string tag, int pos = 1) {
    using namespace std;

    int xml_len = xml.length();
    string content;

    // open and close tags
    tag.insert(0, "<");
    tag.push_back('>');

    string close_tag = tag;
    close_tag.insert(1, "/");

    // parses for content
    string current_tag = "";
    int current_pos = 1;
    bool in_tag = false;
    bool in_content = false;

    for (int i = 0; i < xml_len; i++) {
        if (xml[i] == '<')
            in_tag = true;
        
        if (in_tag)
            current_tag.push_back(xml[i]);

        if (in_content)
            content.push_back(xml[i]);

        if (xml[i] == '>') {
            in_tag = false;
            if (current_tag == tag) {
                if (current_pos == pos)
                    in_content = true;
                current_pos++;
            }
            if (current_tag[1] == '/' && current_pos - 1 == pos)
                if (current_tag == close_tag)
                    break;
            current_tag = "";
        }
    }

    // removes surplus ending tag
    for (int i = 0; i < static_cast<int>(close_tag.length()); i++) 
        content.pop_back();

    return content;
}
