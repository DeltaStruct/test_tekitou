#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    std::string str = "aaaaaaaaaaa", in = argv[2], en = "zzzzzzzzzzz";
    str[0] = argv[1][0], en[0] = argv[1][0];
    while(str!=en){
        FILE* fp;
        if ((fp = popen((std::string("echo -n ")+str+" | md5sum").c_str(), "r"))==NULL){
            cerr << "faild md5sum" << endl;
            exit(EXIT_FAILURE);
        }
        char buf[1024]; std::string res;
        fgets(buf, sizeof(buf), fp),res = buf;
        for (int i(0);i < res.size();++i){
            if (res[i]==' '){res.resize(i);break;}
        }
        pclose(fp);
        if (res==in) cout << str << endl;
        auto it = str.rbegin();
        for (decltype(it) e = str.rend();it!=e;++it){
            if (*it!='z'){ ++(*it); break; }
            else *it = 'a';
        }
    }
}
