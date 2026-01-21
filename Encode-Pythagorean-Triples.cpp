#include <fstream> 
#include <iostream> 
#include <cmath>
#include <string>


int main() {
    int PTN_NUMBER = 7824;
    int line_count = 0;
    std::string cnf_formula = "";
    std::ofstream outputFile("ptn.cnf");

    for (int a = 1; a <= PTN_NUMBER; ++a) {
        for (int b = a; b <= PTN_NUMBER; ++b) {
            int c_squared = a * a + b * b;
            double c = std::sqrt(c_squared);
            
            if (c > PTN_NUMBER) {
                break;
            }
            if (c == (int)c) {
                line_count+=2;
                cnf_formula += std::to_string(a) + " " + std::to_string(b) + " " + std::to_string((int)c) + " 0\n";
                cnf_formula += std::to_string(-a) + " " + std::to_string(-b) + " " + std::to_string(-(int)c) + " 0\n";
            }
        }
    }
    
    outputFile << "p cnf "+ std::to_string(PTN_NUMBER) + " " + std::to_string(line_count) << std::endl;
    outputFile << cnf_formula;
    outputFile.close();
    
    return 0;

}
