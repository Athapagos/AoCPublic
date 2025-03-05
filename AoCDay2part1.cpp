#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

std::vector<int> fSplit_Line(std::string Line)
{
    std::vector<int> vctrReturnValue;
    int inputNum = 0;
    for(int i = 0; i < Line.size(); i++)
        {
            if(Line[i] == ' ')
            {
                vctrReturnValue.push_back(inputNum);
                inputNum =  0;
            }
            else
            {
                inputNum = inputNum*10 + (Line[i]- '0');
            }
        }
    vctrReturnValue.push_back(inputNum);
    return vctrReturnValue;
}

bool fis_safe(std::vector<int> vctrLine)
{
//    printf("Enter is safe \n");
    if( vctrLine.size() > 1)
    {
    //    printf("enter is_safe if condition \n");
        bool Dampener = false;
        int growthdir = int(vctrLine[0] > vctrLine [1]) * 2 - 1;
        //std::cout<<growthdir<<std::endl;

        for ( int i = 0 ; i < vctrLine.size() - 1; i++)
        {
         //   printf("enter is_safe while loop and i = %d while vctrLinesize is %d \n", i,vctrLine.size() );
            if ( (abs(vctrLine[i] -vctrLine[i+1]) == 0)
                        ||  (abs(vctrLine[i] -vctrLine[i+1]) >= 4)
                        ||  ((vctrLine [i] - vctrLine[i+1])*growthdir < 0))
                        {
                            if (Dampener && i > 0)
                            {
                                //std::cout<<i<<std::endl;
                                for(int j = 0;j<vctrLine.size();j++)
                                {
                                    std::cout<<vctrLine[j]<<" ";
                                }
                                std::cout<<std::endl;

                                vctrLine.erase(vctrLine.begin()+i+1);
                                Dampener = false;
                                for(int j = 0 ; j < vctrLine.size() ; j++)
                                {
                                    std::cout<<vctrLine[j]<<" ";
                                }
                                std::cout<<std::endl;
                                i--;

                            }
                            else
                            {
                                //printf("is_safe returns false\n");
                                return false;
                            }

                        }
        }

    }
   // printf("is_safe returns true\n");
    return true;
}


int main()
{
    std::ifstream input_file;//puzzle file
    std::vector<std::vector<int>> vctrRecord;
    input_file.open("C:\\Users\\USER\\Desktop\\AoC2024Inputs\\aocday2.txt");
    //printf("main start \n");
    if(input_file.is_open())//fill vector's vectors
        {
            //printf("File is open\n");
            std::string strLine;

            while(std::getline(input_file,strLine))
            {
                std::vector<int> temp = fSplit_Line(strLine);
//                for (int j = 0; j < temp.size() ; j++)
//               {
//                    printf("Cycle Files lines. Current %d \n", temp[j]);
//                }
                vctrRecord.push_back(temp);
            }
        }
    input_file.close();
    //check if safe
    std::string sResult;
    //printf("vrecordsize is: %d", vctrRecord.size());
    int CountSafe = 0;
    for( int i = 0; i < vctrRecord.size() ; i++)
    {
        //printf("enter part 2\n");
        if(fis_safe(vctrRecord[i]))
           {
              // printf("True\n");
                //sResult = "SAFE";
                CountSafe++;
           }
        else
            {
               // printf("False\n");
                //sResult = "UNSAFE";
            };

        //std::cout<<"Report #" << i << " is " << sResult <<std::endl;
    }
    std::cout<<CountSafe<<std::endl;
    return 0;
}
