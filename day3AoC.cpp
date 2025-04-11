#include <string>
#include <iostream>
#include <fstream>

unsigned long long int fFind_n_Calc_Mul(int StartingLoc, std::string& Input);
unsigned long long int fFind_n_Calc_EnabledMul(int StartingLoc,bool isEnabled, std::string& Input);
int main(){
    std::ifstream input_file;
    std::string Input;
    int Result1 = 0;
    int Result2 = 0;
    input_file.open("C:\\Users\\USER\\Desktop\\AoC2024Inputs\\aocday3.txt");
//    input_file.open("C:\\Users\\USER\\Desktop\\input.txt");
    if(input_file.is_open()){
        std::getline(input_file,Input);
    }
    Result1 = fFind_n_Calc_Mul(0, Input);
    Result2 = fFind_n_Calc_EnabledMul(0,0,Input);
  //  std::cout<<Input<<"\n";
    std::cout << Result1 << "\n" ;
    std::cout << Result2 << "\n" ;
    return 0;
}

unsigned long long int fFind_n_Calc_Mul(int StartingLoc, std::string& Input){
    int found = Input.find ("mul(", StartingLoc);
    if(found == std::string::npos){
        return 0;
    }
    int num1 =0, num2 =0,i = 0;
    while ( -1 < Input[found+4+i]-'0' && Input[found+4+i]-'0' < 10 ){
//        std::cout<<"input for num1 = "<<Input[found+4+i]<<"\n";
        num1 = num1*10+Input[found+4+i]-'0';
        i++;
    }
    if(Input[found+4+i] != ','){
        int foundsum = found+4+i;
        return 0+ fFind_n_Calc_Mul(foundsum,Input);
    }else{
        i++;
        while ( -1 < Input[found+4+i]-'0' && Input[found+4+i]-'0' < 10 ){
//            std::cout<<"input for num2 = "<<Input[found+4+i]<<"\n";
            num2 = num2*10+Input[found+4+i]-'0';
            i++;
        }
    }
//    std::cout<<num1<< " _ "<<num2<<"\n";
    if(Input[found+4+i]==')'){
        int foundsum = found+4+i;
//        std::cout <<num1 << " * "<<num2<< " =  ";
        int mul = num1 * num2;
//        std::cout<< mul << " | " <<foundsum <<"\n";
        return mul + fFind_n_Calc_Mul(foundsum,Input);
    }
    int foundsum = found+4+i;
    return 0+ fFind_n_Calc_Mul(foundsum,Input);
//    std::cout<<num1<< "\n";
}

unsigned long long int fFind_n_Calc_EnabledMul(int StartingLoc,bool isEnabled, std::string& Input){
    int found = Input.find ("mul(", StartingLoc);
    if(found == std::string::npos){
//            std::cout<<"Exit 2 \n";
        return 0;
    }
    bool isDo = true;
    int nextDo = Input.find("do()",StartingLoc);
    int nextDont = Input.find("don't()",StartingLoc);
    if (nextDo == std::string::npos){
        nextDo = Input.size();
    }
    if (nextDont == std::string::npos){
        nextDont = Input.size();
    }
    if (found > nextDont && nextDo > nextDont){
        isDo = false;
        return 0 + fFind_n_Calc_EnabledMul(nextDo,isDo,Input);
    }

    int num1 =0, num2 =0,i = 0;
    while ( -1 < Input[found+4+i]-'0' && Input[found+4+i]-'0' < 10 ){
//        std::cout<<"input for num1 = "<<Input[found+4+i]<<"\n";
        num1 = num1*10+Input[found+4+i]-'0';
        i++;
    }
    if(Input[found+4+i] != ','){
        int foundsum = found+4+i;
//        std::cout<<"Exit 4 \n";
        return 0+ fFind_n_Calc_EnabledMul(foundsum,true,Input);
    }else{
        i++;
        while ( -1 < Input[found+4+i]-'0' && Input[found+4+i]-'0' < 10 ){
//            std::cout<<"input for num2 = "<<Input[found+4+i]<<"\n";
            num2 = num2*10+Input[found+4+i]-'0';
            i++;
        }
    }
//    std::cout<<num1<< " _ "<<num2<<"\n";
    if(Input[found+4+i]==')'){
        int foundsum = found+4+i;
//        std::cout <<num1 << " * "<<num2<< " =  ";
        int mul = num1 * num2;
//        std::cout<< mul << " | " <<foundsum <<"\n";
//        std::cout<<"Exit 5 \n";
        return mul + fFind_n_Calc_EnabledMul(foundsum,true,Input);
    }
    int foundsum = found+4+i;
//    std::cout<<"Exit 6 \n";
    return 0+ fFind_n_Calc_EnabledMul(foundsum,true,Input);
//    std::cout<<num1<< "\n";
}
