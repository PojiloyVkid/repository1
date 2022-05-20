#include<stdio.h> 
#include<math.h> 
#include <thread>
#include <random>

using namespace std;

#define limit_Nmax 1e7 //Максимальное количество точек
#define limit_R 1e6    //Максиальный радиус круга
#define min_R 100      //Начальный радиус

double circle(double, double);         

void foo(long long int& i, long long int& R, double& x, double& y, double& Ncirc)
{
    x = (rand() % (R * 1000)) / 1000;  //Рандомный Х с 3 знаками после запятой
    y = (rand() % (R * 1000)) / 1000;  //Рандомный Y с 3 знаками после запятой
    if (y * y <= circle(x, (R / 2)))   //Условие принадлежности точки к кругу
    {
        Ncircle++;
    }
}

int main()
{

    double x, y, Pi;
    long long int R = min_R;   //Сторона квадарата
    long long int counter = 0;     
    double Ncircle = 0;        //Количество точек в кругt 
    double Npoints = R;        //Всего точек
    while (R < limit_R)      
    {
        Npoints = R;
        
        while (Npoints <= limit_Nmax) 
        {
            Ncircle = 0;
            long long int counter = 0; 
            while (i < Npoints)
            {
                thread th(foo, ref(counter), ref(R), ref(x), ref(y), ref(Ncircle));
                th.detach();
                counter++;
            }

            Pi = (Ncircle / Npoints) * 4;
            Npoints *= 2;

            printf("\n%lld,%.0f,%f", R, Npoints, Pi);
        }
        R *= 2;
    }

}

double circle(double x, double r)
{
    double y = r * r  - x * x;
    return y;
}
