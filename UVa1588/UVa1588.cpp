#include<iostream>
//#include<fstream>
#include<string>

using namespace std;

#define out cout
//ofstream fout("result.txt");

bool check(int *array){
    bool flag = false;
    for(int i = 0; i < 200; i++){
        int n = *(array+i);
        if(n > 3){
            return false;
        }
        if(flag){
            if(n == 0){
                return true;
            }
        }else{
            if(n != 0){
                flag = true;
            }
        }
    }
    return true;
}

void fill_zero(int *array, int length){
    fill(array, array+length, 0);
}

int substance_length(int *array, int length){
    int begin = 0, end = length;
    bool flag = false;
    for(int i = 0; i < length; i++){
        int n = *(array+i);
        if(flag){
            if(n == 0){
                end = i;
                break;
            }
        }else{
            if(n != 0){
                begin = i;
                flag = true;
            }
        }
    }
    return end-begin;
}

int main(){
    string up, bottom;
    while(cin>>up>>bottom){
        if(up.length() > bottom.length())
            swap(up, bottom);
        int up_length = up.length(), bottom_length = bottom.length();
        int result = 200;
        int up_int[100], bottom_int[300];
        fill_zero(&up_int[0], 100);
        for(int i = 0; i < up_length; i++){
            up_int[i] = up[i]-48;
        }

        fill_zero(&bottom_int[0], 300);
        for(int i = 0; i < bottom_length; i++){
            bottom_int[i+100] = bottom[i]-48;
        }

        for(int i = 100-up_length; i < 100+bottom_length; i++){
            int instance[300];
            for(int i = 0; i < 300; i++)
                instance[i] = bottom_int[i];
            for(int j = 0; j < up_length; j++){
                instance[i+j]+=up_int[j];
            }
            if(check(instance)){
                int instance_length = substance_length(instance, 300);
                if(result > instance_length){
                    result = instance_length;
                }
            }
        }
        out<<result<<endl;
    }
}