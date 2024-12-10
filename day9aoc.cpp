#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

void FillVectorWtihStringLine(std::vector<std::string>& Vector)
{
    int Last = Vector.size()-1;
    for(int i = 0 ; i < Vector.size() ; i++)
    {
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
}

unsigned long int GenerateCheckSum(std::vector<std::string> & Vector)
{
    unsigned long int Checksum = 0;
    for(int i = 0 ; i < Vector.size()&&Vector[i] != "" && Vector[i] != "."; i++)
    {
        Checksum += stoi(Vector[i])*i;
    }
    return Checksum;
}

int main()
{
    std::ifstream flInput_file;
    std::vector<std::string> vctrDiskmap;
    std::string strInput_Line;
    //std::cin>> strInput_Line;
    flInput_file.open("C:\\Users\\USER\\Desktop\\AoC2024Inputs\\aocday9.txt");
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
    strInput_Line = "";
    for(int j=0;j<vctrDiskmap.size();j++)
    {
        //std::cout<<vctrDiskmap[j];
    }
    std::cout<<std::endl;
    FillVectorWtihStringLine(vctrDiskmap);
    for(int j=0;j<vctrDiskmap.size();j++)
    {
        //std::cout<<vctrDiskmap[j]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<GenerateCheckSum(vctrDiskmap)<<std::endl;
    return 0;
}
