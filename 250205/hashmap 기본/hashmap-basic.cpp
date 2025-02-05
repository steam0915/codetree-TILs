#include <iostream>
#include <string> 

using namespace std;

int n;
int K[100001];

int main() {
    cin >> n;

    while(n--) {
        string cmd;
        cin >> cmd;

        if(cmd == "add") {
            int k,v;
            cin >> k >> v;
            
            K[k] = v;
        }

        else if(cmd == "find") {
            int k;
            cin >> k;

            (!K[k]) ? cout << "None\n" : cout << K[k] << endl;
        }

        else {
            int k;
            cin >> k;

            K[k] = 0;
        }
    }
    return 0;
}