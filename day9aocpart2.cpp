#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

    std::string strInput_Line;

void FillVectorWithStringLine(std::vector<std::string>& Vector)
{
    int Last = Vector.size()-1;
    for (int i = 0 ; i > Vector.size() ; i++)// > turned off, < turned on
    {
        printf("dont enter here");
        if ( Vector[i] == "." && i < Last && Last > 0 )
        {
            while(Vector[Last]=="."&& i+1 < Last && Last>0)
            {
                Last--;
            }
            std::string temp = Vector[Last];
            Vector[Last] = Vector[i];
            Vector[i] = temp;
        }
    }
    int InverseCount = Vector.size();
    printf("InverseCount = %i \n", InverseCount);
    for (int j = 0 ; j < strInput_Line.size() ;  j+=2)
    {

        int LastUsedOfSize[10] = {0,0,0,0,0,0,0,0,0,0};
        int FileSize = strInput_Line[strInput_Line.size()-j-1]-'0';
        InverseCount -= FileSize;
        //printf("enter j loop, \n FileSize = %i, \n InverseCount = %i \n", FileSize,InverseCount);
        for (int k = 0; k < InverseCount ; k++)
        {
           // printf("enter k loop \n");
            int freespaces = 0;
            if (Vector[k] == "."){
                while (Vector[k+freespaces]== "."){
                        freespaces++;
            }}
           // printf("freespaces = %i & filesize = %i \n",freespaces,FileSize);
            if (freespaces >= FileSize){
            //    printf("TRUE \n\n\n");
                int diff = freespaces - FileSize;
                for (diff; diff>= 0; diff--){
                        LastUsedOfSize[diff] = k;
                    }
                std::vector<std::string> TempVctr;

                for(int l=0; l < FileSize ; l++){
                        //printf("inversecount = %i , \n k = %i , \n l = %i \n",InverseCount,k,l);
                        Vector[k+l]= Vector[InverseCount+l];
                        Vector[InverseCount+l] = ".";

                }

                break;
            }
            k+=freespaces;
                //printf("\n");
        }
        //printf("%c \n",strInput_Line[strInput_Line.size()-j-2]);
        InverseCount -= strInput_Line[strInput_Line.size()-j-2]-'0';

    }
}

unsigned long long int GenerateCheckSum(std::vector<std::string> & Vector)
{
    unsigned long long int Checksum = 0;
    for(int i = 0 ; i < Vector.size()&&Vector[i] != "" ; i++)
    {
        if(Vector[i] != "."){
            unsigned long long int vectori = stoi(Vector[i]);
            Checksum += vectori*i;
        }

        //printf("%llu \n", Checksum);
    }
    return Checksum;
}

int main()
{
    std::ifstream flInput_file;
    std::vector<std::string> vctrDiskmap;

    //std::cin>> strInput_Line;


    flInput_file.open("C:\\Users\\USER\\Desktop\\AoC2024Inputs\\aocday9.txt");
    //flInput_file.open("C:\\Users\\USER\\Desktop\\input.txt");
    if (flInput_file.is_open())
    {
        std::getline(flInput_file,strInput_Line);
    }
    flInput_file.close();
    int ID =0;
    for(int i = 0; i < strInput_Line.size(); i++)
    {
        int temp = 0;
        temp = strInput_Line[i] - '0';
        if( i%2 == 0)
        {
            std::string strTemp = std::to_string(ID);
            for(int j=0; j<temp ;j++)
            {
                vctrDiskmap.push_back(strTemp);
            }
            ID++;
        }
        else
        {
            for(int j=0;j<temp;j++)
            {
                vctrDiskmap.push_back(".");
            }
        }
    }
   // strInput_Line = "";
    for(int j=0;j<vctrDiskmap.size();j++)
    {
        //std::cout<<vctrDiskmap[j];
    }
    std::cout<<std::endl;
    FillVectorWithStringLine(vctrDiskmap);
    for(int j=0;j<vctrDiskmap.size();j++)
    {
        //std::string tempstr= vctrDiskmap[j];
        //printf("%s",tempstr);
    }
    std::cout<<std::endl;
    std::cout<<GenerateCheckSum(vctrDiskmap)<<std::endl;
    return 0;
}
