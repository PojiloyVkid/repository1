#include <iostream>
#include <set>
#include <vector>
#include <cstdlib> 
#include <ctime> 

using namespace std;


unsigned int my_random()
{
	// Наше стартовое число - 4 541
	static unsigned int seed = 4541;

	// Из-за использования очень больших чисел (и переполнения) угадать следующее число исходя из предыдущего - очень сложно
	seed = (8253729 * seed + 2396403);

	// Берем стартовое число и возвращаем значение в диапазоне от 0 до 32767
	return seed % 32768;
}

#include <random>
int getRandomFloatingPointBetween_progressive(int min, int max) {
	random_device rd; // uniformly-distributed integer random number generator
	mt19937 gen(rd()); //инициализируем Вихрь Мерсенна случайным стартовым числом
	uniform_real_distribution<> dis(min, max); //uniform distribution between min and max
	return dis(gen);
}

int test_cases() {
	int a = -1;
	for (int counter = 0; counter < 100; ++counter)
	{
		a = getRandomFloatingPointBetween_progressive(0, 100);
	}
	return a;
}
int main()
{
	vector<int> v;
	for (int i = 0; i < 1000; i++)
	{
		int a = test_cases();
		v.push_back(a);
	}
	double start_v = clock(); //начальное время для вектора
	sort(v.begin(), v.end());
	double end_v = clock(); //конечное
	double time_v = end_v - start_v; 
	
	cout << "vec_time = " << time_v << endl;

	set <int> s;
	double start_s = clock(); // начальное время
	for (int i = 0; i < 1000; i++)
	{
		s.insert(v[i]);
	}
	double end_s = clock(); // конечное
	double time_s = end_s - start_s; 

	cout << "set_time = " << time_s << endl;
}