#include <bits/stdc++.h>

class FileSystem {
private:
    struct Folder {
        unordered_map<string, Folder *> subFolders;
        unordered_map<string, string> files;
    };

    Folder *root;


public:
    FileSystem() {
        root = new Folder();
    }

    vector<string> ls(string path) {
        Folder *currDir = root;
        if (path != "/")
            path += '/';
        int last = 0;

        for (int i = 1; i < path.length(); i++) {
            if (path[i] == '/') {
                string curr = path.substr(last + 1, i - last - 1);
                
                auto &subFolders = currDir->subFolders;

                if (subFolders.find(curr) == subFolders.end()) {
                    auto& files = currDir->files;
                    if (files.find(curr) != files.end()) {
                        return vector<string>{curr};
                    }

                    return {};
                }

                currDir = subFolders[curr];
                last = i;
            }
        }


        vector<string> res;

       for (auto &subFolder: currDir->subFolders) {
            res.push_back(subFolder.first);
        }
        
        for (auto &file: currDir->files) {
            res.push_back(file.first);
        }

        sort(res.begin(), res.end());

        return res;
    }

    void mkdir(string path) {
        Folder *currDir = root;
        if (path != "/")
            path += '/';
        int last = 0;

        for (int i = 1; i < path.length(); i++) {
            if (path[i] == '/') {
                string curr = path.substr(last + 1, i - last - 1);
                auto &subFolders = currDir->subFolders;
                

                if (subFolders.find(curr) == subFolders.end())
                    subFolders[curr] = new Folder();

                currDir = subFolders[curr];
                last = i;
            }
        }
    }

    void addContentToFile(string filePath, string content) {
        Folder *currDir = root;
        if (filePath != "/")
         filePath += '/';
        int last = 0;

        for (int i = 1; i < filePath.length(); i++) {
            if (filePath[i] == '/') {
                string curr = filePath.substr(last + 1, i - last - 1);
                auto &subFolders = currDir->subFolders;

                if (i == (filePath.length() - 1)) {
                    auto& files = currDir->files;
                    files[curr] = files.find(curr) == files.end() ? content : files[curr] + content;
                    return;
                    
                } else if (subFolders.find(curr) == subFolders.end()) {
                    subFolders[curr] = new Folder();
                    
                }

                currDir = subFolders[curr];
                last = i;
            }
        }

    }

    string readContentFromFile(string filePath) {
        Folder *currDir = root;
        if (filePath != "/")
         filePath += '/';
        int last = 0;

        for (int i = 1; i < filePath.length(); i++) {
            if (filePath[i] == '/') {
                string curr = filePath.substr(last + 1, i - last - 1);
                auto &subFolders = currDir->subFolders;

                if (i == (filePath.length() - 1)) {
                    auto& files = currDir->files;
                    return files[curr];
                } 

                currDir = subFolders[curr];
                last = i;
            }
        }
        
        return "";
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
**/