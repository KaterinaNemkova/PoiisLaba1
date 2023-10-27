
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Rule {
private:
    string from;
    string replacement;
public:

    Rule(const string& from, const string& replacement) : from(from), replacement(replacement) {}

    string apply(const string& input) const {
        string output = input;
        size_t pos = output.find(from);
        if (pos != string::npos) {
            return output.replace(pos, from.size(), replacement);
        }
        return output;
    }

};

class MarkovAlgorithm {
private:
    vector<Rule> rules;

public:
    MarkovAlgorithm(const vector<Rule>& rules) : rules(rules) {}

    string apply(const string& input) {
        string result = input;
        bool changed;
        do {
            changed = false;
            for (const auto& rule : rules) {
                    string old = result;
                    result = rule.apply(result);
                    
                    changed = old != result;
            }

        } while (changed);

        return result;
    }

};


