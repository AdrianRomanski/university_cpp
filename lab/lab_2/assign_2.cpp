#include <iostream>
#include <string>
#include <ctime>
#include <utility>

using namespace std;

template <typename T>
void printTab(const T* t, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
}

template <typename T, typename FUN>
size_t part(T* arr, size_t size, FUN f) {
    T even_numbers[size];
    T odd_numbers[size];
    int even_numbers_counter = 0;
    int odd_numbers_counter = 0;
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if(f(arr[i])) {
            even_numbers[even_numbers_counter++]=arr[i];
        } else {
            odd_numbers[odd_numbers_counter++]=arr[i];
        }
    }
    for (int i = even_numbers_counter; i < size; i++) {
        even_numbers[i]=odd_numbers[counter++];
    }
    for (int i = 0; i < size; i++) {
        arr[i]=even_numbers[i];
    }
    return even_numbers_counter;
}

auto isEven = [](int e) {
 return e%2 == 0;
};

auto isDivisibleBySeven = [](int e) {
    return e%7 == 0;
};

auto isNotEven =[](int e) {
    return !isEven(e);
};

int main() {
     size_t ind = 0;

     // lambda as argument: a predicate checking
     // if the given number is odd
     cout << "Checking if a given number is odd" << endl;
     int a1[] = {1,2,3,4,5,6};
     ind = part(a1,6,isEven);
     cout<<"index="<<ind<<"" << endl;
     printTab(a1,6);

     // lambda as argument: a predicate checking
     // if the given name is in the range [mn,mx]
     cout << "Checking if a given number is even" << endl;
     int a2[] = {1,2,3,4,5,6};
     ind = part(a2, sizeof(a2)/sizeof(a2[0]), isNotEven),
     cout<<"index="<<ind<<"" << endl;
     printTab(a2, sizeof(a2)/sizeof(a2[0]));

     // lambda as argument: a predicate checking
     // if the given name is in the range [mn,mx]
     cout << "Checking if a given name is in range" << endl;
     string a3[] = {"Ala", "Ula", "Ela", "Ola", "Maja"};
     string min = "Bea";
     string max = "Sue";
     ind = part(a3, sizeof(a3)/sizeof(a3[0]),
                [min, max](const string& str) -> bool {
                        return str < max && str > min;
     });
     std::cout<<"index="<<ind<<""<<endl;
     printTab(a3,sizeof(a3)/sizeof(a3[0]));

     // lambda as argument: a predicate checking
     // if the given number is divisible by 7
     cout << "Checking if a given number is divisible by 7" << endl;
     constexpr size_t DIM = 500000;
     int* a4 = new int[DIM];
     srand(unsigned(time(0)));
     for (size_t i = 0; i < DIM; ++i) a4[i] = rand()%21+1;
     ind = part(a4, DIM, isDivisibleBySeven);
     std::cout << "ind = " << ind << std::endl;
     delete [] a4;
 }


