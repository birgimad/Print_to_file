#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#include <iomanip>
using std::setw;

ofstream ofile;

int main ()
{
    double x = sqrt(2);
    double h[ 10 ]={1,0.1,0.01,0.001,0.0001,0.00001,0.000001,0.0000001,0.00000001,0.0000000001}; // step length, 10 different values
    double div_f1[ 10 ];    //for single: float, for double: double
    double div_f2[ 10 ];    //for single: float, for double: double
    double error_div_f1[ 10 ];
    double error_div_f2[ 10 ];
    for ( int i = 0; i < 10; i++ )
    {
        div_f1[ i ] = (atan(x+h[ i ])-atan(x))/h[i];
        div_f2[ i ] = (atan(x+h[ i ])-atan(x-h[i]))/(2*h[i]);
    }

    // output each array element's value
    cout << "step length" << setw( 9 ) << "div_f1" << setw( 13 )
         << "error" << setw( 13 ) << "div_f2" << setw( 16 ) << "error"  << endl;


    for ( int j = 0; j < 10; j++ )
    {
        error_div_f1[j] = fabs(1.0/3.0 - div_f1[ j ]);
        error_div_f2[j] = fabs(1.0/3.0 - div_f2[ j ]);
        cout << setw( 7 )<< h[ j ] << setw( 13 ) << div_f1[ j ] << setw( 13 )
             << error_div_f1[j] << setw( 13 ) << div_f2[ j ] << setw( 16 )
             << error_div_f2[j] << endl;
    }

      ofstream myfile ("Results2.txt"); //Creates output file
        if (myfile.is_open())           //checkes whether the output file is open.
                                        //if open, the following things are put in the output file
        {
            myfile << "step length" << setw( 9 ) << "div_f1" << setw( 13 )
                   << "error" << setw( 13 ) << "div_f2" << setw( 16 ) << "error"  << endl;
            for ( int j = 0; j < 10; j++ )
            {
                 myfile << setw( 7 )<< h[ j ] << setw( 13 ) << div_f1[ j ] << setw( 13 )
                        << error_div_f1[j] << setw( 13 ) << div_f2[ j ] << setw( 16 )
                        << error_div_f2[j] << endl;
            }
        myfile.close();
        }
        else cout << "Unable to open file";

    return 0;
}

