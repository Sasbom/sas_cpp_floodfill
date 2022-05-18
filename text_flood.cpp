#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

//lets try and do a recursive flood fill in c++

struct Vector2
{
    int x,y;
    //constructors
    Vector2(int xx,int yy){x = xx; y = yy;};
    Vector2(){x = 0; y = 0;};
    Vector2(std::string inputstring)
    {
        std::string number1, number2;
        std::size_t pos = inputstring.find(",");
        number1 = inputstring.substr(0,pos);
        number2 = inputstring.substr(pos+1,inputstring.length()-pos);
        x = std::atoi(number1.c_str());
        y = std::atoi(number2.c_str());
    };

    void print()
    {
        std::cout << "[" << x << " , " << y << " ]" << std::endl;
    }

    std::string format()
    {
        std::stringstream s;
        s << "[" << x << " , " << y << " ]";
        return s.str();
    }
};

//build a 2D matrix based on a text file. IDK man.
std::vector<std::vector<int>> build_matrix_fromfile(std::string &filename)
{
    std::vector<std::vector<int>> gather_total;
    std::vector<int> gather_line;
    std::string read_string;
    std::ifstream file(filename);

    while(std::getline(file,read_string))
    {
        // insert iterated chars from string into vector gather_line through a lambda using the atoi function to get the right integer instead of the ASCII integer >:)
        // also, we need to reference the char in the lambda because that'll get us the pointer, which atoi expects.
        std::transform(read_string.begin(),read_string.end(),std::back_inserter(gather_line), [](const char x){return std::atoi(&x);});
        //put the line on the main vector of vectors and clear the currently gathered line of text.
        gather_total.push_back(gather_line);
        gather_line.clear();
    };
    return gather_total;
}
//bunch of printing functions

//print an integer vector array
void print_vector(std::vector<int> &vector)
{
    for (int i : vector)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

//print an array of arrays.
void print_matrix(std::vector<std::vector<int>> &matrix)
{
    for (std::vector<int> i : matrix)
    {
        print_vector(i);
    }
}

void print_matrix_value(std::vector<std::vector<int>> &matrix, Vector2 &location)
{
    std::cout << matrix[location.y][location.x] << std::endl;
}

void print_matrix_value(std::vector<std::vector<int>> &matrix, int x, int y)
{
    std::cout << matrix[y][x] << std::endl;
}

//getting functions for 2D matrix using both seperate cartesian coords or struct.
int matrix_value(std::vector<std::vector<int>> &matrix, int x, int y)
{
    return matrix[y][x];
}

int matrix_value(std::vector<std::vector<int>> &matrix, Vector2 &location)
{
    return matrix[location.y][location.x];
}

//setting functions for 2D matrix using both seperate cartesian coords or struct.
void set_matrix_value(std::vector<std::vector<int>> &matrix, Vector2 &location, int value)
{
    matrix[location.y][location.x] = value;
}

void set_matrix_value(std::vector<std::vector<int>> &matrix, int x, int y, int value)
{
    matrix[y][x] = value;
}

void flood_fill(std::vector<std::vector<int>> &matrix, Vector2 point,int oldvalue, int newvalue)
{
    //check bounds
    if (point.x < 0 | point.y < 0 | point.y >= matrix.size() | point.x >= matrix[0].size())
    {
        return;
    }

    if (matrix_value(matrix,point) == oldvalue)
        {
            set_matrix_value(matrix,point,newvalue);
            flood_fill(matrix,Vector2(point.x+1,point.y),oldvalue,newvalue);
            flood_fill(matrix,Vector2(point.x,point.y+1),oldvalue,newvalue);
            flood_fill(matrix,Vector2(point.x-1,point.y),oldvalue,newvalue);
            flood_fill(matrix,Vector2(point.x,point.y-1),oldvalue,newvalue);
        }
}

//overload that samples value whereever the point lands.
void flood_fill(std::vector<std::vector<int>> &matrix, Vector2 point, int newvalue)
{
    int oldvalue = matrix_value(matrix,point);
    flood_fill(matrix,point,oldvalue,newvalue);
}

int main()
{
    std::string file = "image.txt";
    std::vector<std::vector<int>> image_matrix = build_matrix_fromfile(file);

    std::string get_start;
    std::cout << "Sample coordinate, e.g. 1,2: ";
    std::cin>>get_start;

    Vector2 fillstart(get_start);

    std::cout << fillstart.format() << std::endl;

    std::cout << "'image' to fill, starting at " << fillstart.format() << std::endl;
    std::cout << std::endl;

    

    print_matrix(image_matrix);
    
    //set_matrix_value(image_matrix,fillstart,2);
    std::cout << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;

    flood_fill(image_matrix,fillstart,4);
    print_matrix(image_matrix);
}