#include <iostream>
#include <fstream>
#include <vector>

int CountXmas(std::vector<std::string> Input);
int CountXShapedMAS(std::vector<std::string> Input);

int main(){
    std::ifstream input_file;
    std::vector<std::string> Input;
    int Result1 = 0;
    int Result2 = 0;
    input_file.open("C:\\Users\\USER\\Desktop\\AoC2024Inputs\\aocday4.txt");
//    input_file.open("C:\\Users\\USER\\Desktop\\input.txt");
    if(input_file.is_open()){
        std::string strLine;
        while(std::getline(input_file,strLine))
        {
            Input.push_back(strLine);
        }
    }
    input_file.close();
//    for(int i =0; i< Input.size(); i++){
//        std::cout<<Input[i]<<"\n";
//    }
    Result1 = CountXmas(Input);
    Result2 = CountXShapedMAS(Input);
    std::cout<<"Result1 = " << Result1<<std::endl;
    std::cout<<"Result2 = " << Result2<<std::endl;
    return 0;
}

int CountXmas(std::vector<std::string> Input){
    //cycles , 8 directions, find the X
    int Result = 0;
    std::string TempStr;
    for(int row = 0 ; row < Input.size() ; row++){
        for(int col = 0; col<Input[row].size() ; col++){
            if(Input[row][col] == 'X'){
//                std::cout<< 'X';
                //todo: N
                if (row-3>=0){
                    TempStr = std::string(1,Input[row][col]) + std::string(1,Input[row-1][col]) +  std::string(1,Input[row-2][col]) +  std::string(1,Input[row-3][col]);
                    if (TempStr == "XMAS"){
                        Result ++;
                    }
                }
                //todo: NE
                if (row-3>=0 && (col+3)<Input[row].size()){
                    TempStr = std::string(1,Input[row][col]) + std::string(1,Input[row-1][col+1]) +  std::string(1,Input[row-2][col+2]) +  std::string(1,Input[row-3][col+3]);
                    if (TempStr == "XMAS"){
                        Result ++;
                    }
                }
                //todo: E
                if (col+3 < Input[row].size()){
                    TempStr = std::string(1,Input[row][col]) + std::string(1,Input[row][col+1]) +  std::string(1,Input[row][col+2]) +  std::string(1,Input[row][col+3]);
                    if (TempStr == "XMAS"){
                        Result ++;
                    }
                }
                //todo: SE
                if (col+3 < Input[row].size() && row+3 < Input.size()){
                    TempStr = std::string(1,Input[row][col]) + std::string(1,Input[row+1][col+1]) +  std::string(1,Input[row+2][col+2]) +  std::string(1,Input[row+3][col+3]);
                    if (TempStr == "XMAS"){
                        Result ++;
                    }
                }




                //todo: S
                if (row+3 < Input.size()){
                    TempStr = std::string(1,Input[row][col]) + std::string(1,Input[row+1][col]) +  std::string(1,Input[row+2][col]) +  std::string(1,Input[row+3][col]);
                    if (TempStr == "XMAS"){
                        Result ++;
                    }
                }
                //todo: SW
                if (row+3 < Input.size() && (col-3) >= 0){
                    TempStr = std::string(1,Input[row][col]) + std::string(1,Input[row+1][col-1]) +  std::string(1,Input[row+2][col-2]) +  std::string(1,Input[row+3][col-3]);
                    if (TempStr == "XMAS"){
                        Result ++;
                    }
                }
                //todo: W
                if (col-3 >= 0){
                    TempStr = std::string(1,Input[row][col]) + std::string(1,Input[row][col-1]) +  std::string(1,Input[row][col-2]) +  std::string(1,Input[row][col-3]);
                    if (TempStr == "XMAS"){
                        Result ++;
                    }
                }
                //todo: NW
                if (col-3 >= 0 && row - 3 >= 0){
                    TempStr = std::string(1,Input[row][col]) + std::string(1,Input[row-1][col-1]) +  std::string(1,Input[row-2][col-2]) +  std::string(1,Input[row-3][col-3]);
                    if (TempStr == "XMAS"){
                        Result ++;
                    }
                }
            }
            else {
               // std::cout<< Input[row][col];
            }
        }
      //  std::cout<<'\n';
    }

    return Result;
}

int CountXShapedMAS(std::vector<std::string> Input){
    //cycles , 8 directions, find the X
    int Result = 0;
    bool is_NW_SE_MAS = false;
    bool is_NE_SW_MAS = false;
    std::string TempStr;
    for(int row = 0 ; row < Input.size() ; row++){
        for(int col = 0; col<Input[row].size() ; col++){
            if(Input[row][col] == 'A'){
//                std::cout<< 'X';
                //todo: N
                if (row-1>=0 && col -1 >= 0 && row+1 < Input.size() && col+1 < Input[row+1].size()){
                    TempStr = std::string(1,Input[row-1][col-1]) + std::string(1,Input[row][col]) +  std::string(1,Input[row+1][col+1]);
                    if (TempStr == "MAS" || TempStr == "SAM"){
//                        std::cout<<TempStr <<"\n";
                        //std::cout<<"is MAS/SAM \n";
                        is_NW_SE_MAS = true;
                    }
                }
                if (row-1>=0 && col -1 >= 0 && row+1 < Input.size() && col+1 < Input[row+1].size()){
                    TempStr = std::string(1,Input[row+1][col-1]) + std::string(1,Input[row][col]) +  std::string(1,Input[row-1][col+1]);
                    //std::cout<<TempStr <<"\n";
                    if (TempStr == "MAS" || TempStr == "SAM"){
//                        std::cout<<TempStr <<"\n";
                        is_NE_SW_MAS = true;
                    }
                }
                if (is_NE_SW_MAS && is_NW_SE_MAS){
                    Result++;
                }
                is_NE_SW_MAS = false;
                is_NW_SE_MAS = false;
            }
            else {
               // std::cout<< Input[row][col];
            }
        }
      //  std::cout<<'\n';
    }

    return Result;
}
