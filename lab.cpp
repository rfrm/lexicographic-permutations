#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string empty;

inline string remove(char c, string chars){
    chars.erase(chars.begin()+chars.find(c));
    return chars;
}

inline string insert_front(char c, string chars){
    chars.insert(0, 1, c);
    return chars;
}

string swap(string perm, string chars){
    int n = perm.size();
    char p = perm.front();
    string swaped(chars);

    vector<char> gt;
    for(auto candidate:chars)
        if(p < candidate)
            gt.push_back(candidate);

    if(!gt.empty()){
        char next_p = *min_element(gt.begin(), gt.end());
        swaped = remove(next_p, swaped);
        sort(swaped.begin(), swaped.end());
        return insert_front(next_p, swaped).substr(0, n);
    }
    else
        return empty;
}

string nextPermutation(string perm, string chars){
    int n = perm.size();
    if(n==1)
        return swap(perm, chars);
    else{
        char p = perm.front();
        string ps = perm.substr(1, n);
        string next_ps = nextPermutation(ps, remove(p, chars));
        if(!next_ps.empty())
            return insert_front(p, next_ps);
        else
            return swap(perm, chars);
    }
}

int main(int argc, char **argv){

    string chars(argv[1]);
    int length = atoi(argv[2]);
    sort(chars.begin(), chars.end());
    string perm(chars.begin(), chars.begin()+length);

    while(true){
        if(!perm.empty()){
            cout << perm << endl;
            perm = nextPermutation(perm, chars);
        }
        else
            break;
    }
    return 0;
}
