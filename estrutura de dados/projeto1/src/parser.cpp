#include <stack>
#include <string>
#include <vector>


bool parser(std::string xml) {
    using namespace std;

    int xml_len = xml.length();
    stack<string> tag_stack; 
    vector<string> tags;

    //  builds tag vector
    string tag = "";
    bool in_tag = false;

    for (int i = 0; i < xml_len; i++) {
        if (xml[i] == '<') {
            in_tag = true;
        }

        if (in_tag) {
            tag.push_back(xml[i]);
        }

        if (xml[i] == '>') {
            in_tag = false;
            tags.push_back(tag);
            tag = "";
            }
    }

    //  check the tags validity with a stack
    int tags_size = tags.size();

    for (int i = 0; i < tags_size; i++) {
        string tag = tags[i];

        if (tag_stack.empty()) {
            tag_stack.push(tag);
            continue;
        }

        if (tag[1] == '/') {
            string top_tag = tag_stack.top();
            top_tag.insert(1, "/");
            if (top_tag == tag) {
                tag_stack.pop();
            } else {
                return false;
            }
            continue;
        }
        tag_stack.push(tag);
    }

    if (!tag_stack.empty()) return false;

    return true;
}

