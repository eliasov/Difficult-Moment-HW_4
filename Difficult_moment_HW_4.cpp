#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <ostream>
#include <stdlib.h>
#include <vector>

// Author: Ilya Ovsyannikov
// Home Work 4

using namespace std;

//Template function for displaying a vector on the screen
template<class VEC>
void Print_array(VEC const& vec)
{
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
}

//Template function to insert a new number into a vector
template<class VEC, class T>
void InsertSorted(VEC& vec, const T inum)
{
	typename VEC::iterator it;
	it = std::upper_bound(vec.begin(), vec.end(), inum);
	vec.insert(it, inum);
}


int main(int argc, char* argv[])
{
	// Task_1 
	srand(time(NULL));
	std::vector<int32_t> sort_array(10); // Create a vector of numbers
	generate(sort_array.begin(), sort_array.end(), []() {return rand() % 50; }); // Filling a Vector with Random Numbers
	sort(sort_array.begin(), sort_array.end());// Sorting the vector
	Print_array(sort_array); // Displaying the sorted vector
	InsertSorted(sort_array, 25); // Adding the number 25 to the middle of the vector
	Print_array(sort_array);// We display a vector with the number 25 on the screen

	std::deque<int32_t> sorted_deque(10);
	generate(sorted_deque.begin(), sorted_deque.end(), []() {return rand() % 50; });
	sort(sorted_deque.begin(), sorted_deque.end());
	Print_array(sorted_deque);
	InsertSorted(sorted_deque, 25);
	Print_array(sorted_deque);
	cout << endl;


	//Task_2
	std::cout << "------------------------------------ Task 2 ------------------------------------" << endl;
	cout << endl;
	std::vector<double> signal_analogue(100); // Create a vector of analog signal numbers
	std::vector<int32_t> signal_digital(100); // Create a vector of digital signal numbers
	
	generate(signal_analogue.begin(), signal_analogue.end(), []() { return 3 * sin(rand() * 2.0 * 3.14 / 100); });// We generate a vector of numbers according to the formula
	Print_array(signal_analogue);// Displaying the result
	cout << endl;

	transform(signal_analogue.begin(), signal_analogue.end(), signal_digital.begin(), [](double x)
		{return static_cast<int32_t>(round(x)); });// Rounding to integers and returning values ​​in a different range
	Print_array(signal_digital);
	cout << endl;

	const auto result = std::inner_product(signal_digital.begin(), signal_digital.end(),
		signal_analogue.begin(), 0.0, std::plus<>(), std::minus<>()); //counting the number of errors
	std::cout << "Error " << result * result << "\n"; 

	return 0;
}