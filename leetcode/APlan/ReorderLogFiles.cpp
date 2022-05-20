
class Solution {
private:
    bool isDigitLog(string &log) {
        for (int i = 0; i < log.length(); i++) {
            if (log[i] == ' ') {
                return log[i + 1] >= '0' && log[i + 1] <= '9';
            }
        }
        
        return false;
    }
    
    static string getLetterLogContent(const string &log) {
        for (int i = 0; i < log.length(); i++) {
            if (log[i] == ' ') {
                return log.substr(i + 1);
            }
        }
        
        return "";
    }

    static string getLetterLogId(const string &log) {
        for (int i = 0; i < log.length(); i++) {
            if (log[i] == ' ') {
                return log.substr(0, i);
            }
        }
        
        return "";
    }
    
    static bool letterLogCmp(const string &a, const string& b) {
        if (getLetterLogContent(a) == getLetterLogContent(b)) {
            return getLetterLogId(a) < getLetterLogId(b);
        }
        
        return getLetterLogContent(a) < getLetterLogContent(b);
    }

    

public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        if (logs.empty()) {
            return {};
        }
            
        int digitPos = logs.size() - 1;
        
        for (int i = logs.size() - 1; i >= 0; i--) {
            string& log = logs[i];
            
            if (isDigitLog(log)) {
                string tmp = logs[digitPos];
                logs[digitPos] = logs[i];
                logs[i] = tmp;
                
                digitPos--;
            }
        }
        
        int letterLogsSize = digitPos + 1;
        sort(logs.begin(), logs.begin() + letterLogsSize, letterLogCmp);
        
        return logs;
    }
};