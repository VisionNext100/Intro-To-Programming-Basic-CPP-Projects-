#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char** argv){
    char temp1{};
    char temp2{};
    char temp3{};
    ifstream fin;
    ofstream fout;
    fin.open(argv[1]);
    fout.open(argv[2]);
    while(fin.get(temp1)){
        bool checkStatus=false;
        if(temp1=='/'){
            checkStatus=true;
            fin.get(temp2);
                if(temp2=='/'){
                    checkStatus=false;
                    while(fin.get(temp2)) if(temp2=='\n') break;
                    fin.putback('\n');
                    continue;
                }else if(temp2=='*'){
                    checkStatus=true;
                    while(fin.get(temp2)){
                        if(temp2=='*'){
                            fin.get(temp3);
                            if(temp3=='/'){
                                checkStatus=false;
                                break;
                            }else{
                            fin.putback(temp3);
                            continue;
                        }
                    }
                }
                continue;
            }else{
                checkStatus=false;
                fin.putback(temp2);
            }
        }

    if(temp1=='\\'){
        checkStatus=true;
        fout<<temp1;
        if(fin.get(temp2)){
                fout<<temp2;
                checkStatus=false;
        }
        continue;
    }

    if(temp1=='\"'){
        fout<<temp1;
        checkStatus=true;
        while(fin.get(temp2)){
            fout<<temp2;
            if(temp2=='\\'){
                if(fin.get(temp3)) fout<<temp3;
                continue;
            }
                if(temp2=='\"'){
                    checkStatus=false;
                    break;
                }
            }
        continue;
        }
        fout<<temp1;
    }
    fin.close();
    fout.close();
    return 0;
}
