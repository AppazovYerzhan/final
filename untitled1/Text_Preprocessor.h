#ifndef UNTITLED1_TEXT_PREPROCESSOR_H
#define UNTITLED1_TEXT_PREPROCESSOR_H
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;

class Text_Preprocessor {
private:
    ifstream inFile;

private:
    string line;
    stringstream buffer;
public:
    Text_Preprocessor() {}
    Text_Preprocessor(const string &name) {
        inFile.open(name);
    }
    ~Text_Preprocessor() {
        inFile.close();
    }
    const ifstream &getInFile() const {
        return inFile;
    }
    void find_max_sentence(){
        while (getline(inFile, line)) {
            line.erase(remove(line.begin(), line.end(), ','), line.end());
            line.erase(remove(line.begin(), line.end(), '"'), line.end());
            line.erase(remove(line.begin(), line.end(), '.'), line.end());
            line.erase(remove(line.begin(), line.end(), ';'), line.end());
            line.erase(remove(line.begin(), line.end(), ':'), line.end());
            line.erase(remove(line.begin(), line.end(), '!'), line.end());
            line.erase(remove(line.begin(), line.end(), '?'), line.end());
            transform(line.begin(), line.end(), line.begin(), ::tolower);   //lowercase
            unordered_map<string, int> unorderedMap;
            unorderedMap["Yerzhan"]++;
        }
    }

};


#endif //UNTITLED1_TEXT_PREPROCESSOR_H
