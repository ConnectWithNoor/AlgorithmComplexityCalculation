#include <iostream>
#include <fstream>

int main(){
    bool nestedCheck = 0;
    int numOfPower = 0, temp = 0;
    std::string line;
    std::ifstream inputFile;
    char FILE[10];

    std::cout<<"Enter the Name of the file (type file.cpp): ";
    gets(FILE);

    inputFile.open(FILE, std::ios::in);     // opening File

    if(inputFile.is_open()){            // checking whether is file exist or not
        while(!inputFile.eof()){        // Run While loop until the inputFile Ends
            std::getline(inputFile,line);   //Get the next file and copy it into string line

            if(line.find("while") != std::string::npos || line.find("for") != std::string::npos){    // find if any loop exist in line, std::string::npos means not found ( value of -1) can also be written directly as -1

                temp = 1;               // to get the correct number of nested loops
                nestedCheck = 1;        // checked whether the loops are nested or single by using it as a while condition

                std::cout<<line<<std::endl;
                std::getline(inputFile,line);   // read the next line to if check the nested loop.

                while(nestedCheck == 1){
                    if(line.find("while") != std::string::npos || line.find("for") != std::string::npos){   // find if any loop exist in line, std::string::npos means not found ( value of -1) can also be written directly as -1
                            temp++;         // if nested loop exist, we increment the temp by 1 to get how many nested loops are present.
                            std::cout<<line<<std::endl; // print the line containing the loop
                            std::getline(inputFile,line); // get the next line to check if another nested loop is present or not.
                    }

                    else{
                        if(line.find("{") != std::string::npos){ // in case opening brace is present so we need to check the next line.

                        std::cout<<line<<std::endl;         // print the opening brace to get a good output
                        std::getline(inputFile,line);       // check the next line of the opening brace

                            if(line.find("while") != std::string::npos || line.find("for") != std::string::npos){ // if the next line of opening brace is a loop

                                temp++;     // so increment temp by 1 to get the nested loop number.
                                std::cout<<line<<std::endl; // print the line to get a good output
                            }
                        }
                        nestedCheck = 0;    // if only one individual loop is present and no loop after very next line or after opening
                                            // brace is present, so mark the while checking condition as false (nestedCheck = 0)
                    }
                }
            }
            if (numOfPower < temp){     // get the maximum number of individual/nested loop in temp variable and compare if the numOfPower
                                        // is less then the temp(containing maximum number of nested loop in a run),
                    numOfPower = temp;  // copy the maximum number of loop in numOfPower.
                                        /* EXAMPLE:
                                             while(i < n )          | 3 nested loop so temp = 3 in a single nested run
                                                while(j <= i)       | and numOfPower = 0 (initially, so numOfPower < temp.
                                                    while(i < n )   | and numOfPower becomes the most number of nested loops in a program
                                                while(j <= i)           | 2 nested loops so temp = 2 in a single nested run. now, as earlier
                                                    while(i < n )       | numOfPower became 3, so condition of if becomes false.
                                        by using this, I get accurate numbers of most loops in a single run  */

            }
        }                               // while end of file loop end
    }                                   // if file open check brace close here
    else{
        std::cout<<"FILE NOT FOUND"<<std::endl;
        return 0;
    }

    inputFile.close();

    if(numOfPower > 0){     // if if any loop is present in the InputFile
    std::cout<<"\nThe Complexity of Algorithm is: O(n^"<<numOfPower<<")"<<std::endl;
    return 0;
    }

    else{   // in case, the inputFile doesn't contain any loop
        std::cout<<"No Loops Found"<<std::endl;
        std::cout<<"\nThe Complexity of Algorithm is: O(1)"<<std::endl;
        return 0;
    }
}
