#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<string, int> usernameMap;
    
    for (int i = 0; i < n; ++i) {
        string username;
        cin >> username;
        
        if (usernameMap.find(username) == usernameMap.end()) {
            // Username not found, insert it with count 0
            usernameMap[username] = 0;
            cout << "OK" << endl;
        } else {
            // Username found, increment count and suggest new username
            ++usernameMap[username];
            cout << username << usernameMap[username] << endl;
        }
    }
    
    return 0;
}