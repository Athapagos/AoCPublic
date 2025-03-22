#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

std::vector<int> fSplit_Line(std::string Line);
int fSimilarityScore(int& a,std::vector<int>& Vector);

int main(){
    std::ifstream input_file;
    std::vector<int> vctrG1;
    std::vector<int> vctrG2;
    int Result1 = 0;
    int Result2 = 0;
    input_file.open("C:\\Users\\USER\\Desktop\\AoC2024Inputs\\aocday1.txt");
//    input_file.open("C:\\Users\\USER\\Desktop\\input.txt");
    if(input_file.is_open()){
        //printf("File is open\n");
        std::string strLine;
        while(std::getline(input_file,strLine))
        {
//            std::cout << "strLine  = " << strLine << "\n";
            std::vector<int> temp = fSplit_Line(strLine);
//          for (int j = 0; j < temp.size() ; j++){
//          1     printf("Cycle Files lines. Current %d \n", temp[j]);
//          }
          //  std::cout<<temp[0]<< "                    " << temp[1] <<"\n";
            vctrG1.push_back(temp[0]);
            vctrG2.push_back(temp[1]);
        }
    }
    std::sort (vctrG1.begin(), vctrG1.end());
    std::sort (vctrG2.begin(), vctrG2.end());
    for(int i = 0 ; i< vctrG1.size() ;i++){
        Result1 += abs(abs(vctrG1[i])-abs(vctrG2[i]));
        Result2 += fSimilarityScore(vctrG1[i],vctrG2);
     //std::cout << vctrG1[i] << "      " << vctrG2[i] <<"\n";
    }
    std::cout << Result1 <<" " << Result2<<"\n";
    return 0;
}

std::vector<int> fSplit_Line(std::string Line){
    std::vector<int> vctrReturnValue;
    int inputNum = 0;
//    std::cout<<Line<<"\n";
    for(int i = 0; i < Line.size(); i++){
        if(Line[i] == ' '&& inputNum != 0){
            vctrReturnValue.push_back(inputNum);
            inputNum =  0;
        }
        else{
            if (Line[i] != ' '){
                inputNum = inputNum*10 + (Line[i]- '0');
            }
        }
    }

  // if(inputNum!=0){
        vctrReturnValue.push_back(inputNum);
  // }
//    for(int i =0 ; i < vctrReturnValue.size();i++){
//        std::cout<<vctrReturnValue[i]<<" . ";
//    }
//    std::cout <<"\n";
    return vctrReturnValue;
}

int fSimilarityScore(int& a,std::vector<int>& Vector){
    int Count = 0;
    for(int i = 0 ; i < Vector.size() ; i++){
     //  std::cout <<a << "    " << Vector[i];
        if (a == Vector[i]){
            Count++;
        }
    }
//    std::cout <<"a = " << a << " Count = " << Count << " Result = " << a*Count <<"\n";
    return a*Count;
}
